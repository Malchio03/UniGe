#!/bin/bash

# Stages Management Script for Git-based C++ CMake Projects
# Usage: ./stages.sh {t|tag|x|export|c|compile|xc|extract_compile} [arguments]

# ============================================================================
# UTILITY FUNCTIONS
# ============================================================================

print_error() {
    echo -e "\033[31mERROR:\033[0m $1" >&2
}

print_warning() {
    echo -e "\033[33mWARNING:\033[0m $1" >&2
}

print_info() {
    echo -e "\033[32mINFO:\033[0m $1"
}

check_git_repo() {
    if ! git rev-parse --git-dir > /dev/null 2>&1; then
        print_error "Not in a git repository"
        exit 1
    fi
}

check_gitignore() {
    if [ ! -f .gitignore ]; then
        print_error ".gitignore does not exist"
        exit 1
    fi

    if ! grep -q "^FCG_Stages$" .gitignore; then
        print_warning "FCG_Stages not found in .gitignore, adding it..."
        echo "FCG_Stages" >> .gitignore
    fi
}

get_next_stage_number() {
    local tags=$(git tag -l "Stage_*" 2>/dev/null | sort -V)

    if [ -z "$tags" ]; then
        echo "01"
    else
        local latest=$(echo "$tags" | tail -1)
        local num=${latest#Stage_}
        local next=$((10#$num + 1))
        printf "%02d" "$next"
    fi
}

# ============================================================================
# TAG COMMAND
# ============================================================================

tag_command() {
    local description=""

    # Parse arguments
    while [ $# -gt 0 ]; do
        case "$1" in
            -d)
                description="$2"
                shift 2
                ;;
            *)
                shift
                ;;
        esac
    done

    check_git_repo
    check_gitignore

    if [ -z "$description" ]; then
        print_error "Description is mandatory (use -d \"description\")"
        exit 1
    fi

    # Check if there is already a Stage_* tag on this commit
    local existing_tags=$(git tag --points-at HEAD | grep "^Stage_")
    if [ -n "$existing_tags" ]; then
        print_error "This commit already has a Stage_* tag: $existing_tags"
        exit 1
    fi

    local next_num=$(get_next_stage_number)
    local tag_name="Stage_$next_num"

    print_info "Creating annotated tag: $tag_name"
    git tag -a "$tag_name" -m "$description"

    if [ $? -eq 0 ]; then
        print_info "Tag created successfully: $tag_name"
    else
        print_error "Failed to create tag"
        exit 1
    fi
}

# ============================================================================
# EXPORT COMMAND
# ============================================================================

export_command() {
    check_git_repo
    check_gitignore

    local current_branch=$(git branch --show-current)

    # Check if in detached HEAD state
    if [ -z $current_branch ]; then
        print_error "Repository is in detached HEAD state. Please checkout a branch first."
        exit 1
    fi

    # Check if current HEAD is at the tip of the branch
    local branch_tip=$(git rev-parse "$current_branch")
    local current_head=$(git rev-parse HEAD)

    if [ "$branch_tip" != "$current_head" ]; then
        print_error "Current HEAD is not at the tip of branch '$current_branch'. Please ensure all commits are pushed to the branch."
        exit 1
    fi

    local tags=$(git tag -l "Stage_*" 2>/dev/null | sort -V)

    if [ -z "$tags" ]; then
        print_error "No Stage_* tags found"
        exit 1
    fi

    # Check for untracked files that are not ignored
    local untracked=$(git ls-files --others --exclude-standard)
    if [ -n "$untracked" ]; then
        print_error "Repository has untracked files that are not ignored:"
        echo "$untracked" | sed 's/^/  /'
        exit 1
    fi

    # Check if repo is clean
    if ! git diff-index --quiet HEAD --; then
        print_error "Repository has uncommitted changes. Please commit or stash them."
        exit 1
    fi

    # Create FCG_Stages directory if it doesn't exist
    if [ ! -d FCG_Stages ]; then
        mkdir -p FCG_Stages
    fi

    print_info "Exporting stages..."

    for tag in $tags; do
        local stage_num=${tag#Stage_}
        local stage_dir="FCG_Stages/Stage_$stage_num"

        print_info "Exporting $tag to $stage_dir"

        # Checkout tag
        git checkout "$tag" > /dev/null 2>&1
        if [ $? -ne 0 ]; then
            print_error "Failed to checkout tag $tag"
            git checkout "$current_branch" > /dev/null 2>&1
            exit 1
        fi

        # Remove old stage directory
        if [ -d "$stage_dir" ]; then
            rm -rf "$stage_dir"
        fi
        mkdir -p "$stage_dir"

        # Copy files tracked by git, excluding .git* files and directories
        git ls-files | while read -r file; do
            # Skip files matching .git*
            if [[ $(basename "$file") == .git* ]]; then
                continue
            fi
            # Skip this script
            if [[ $(basename "$file") == stages.sh ]]; then
                continue
            fi
            mkdir -p "$(dirname "$stage_dir/$file")"
            cp "$file" "$stage_dir/$file"
        done
    done

    # Return to original branch (not commit hash)
    print_info "Returning to branch '$current_branch'"
    git checkout "$current_branch" > /dev/null 2>&1

    print_info "Export completed successfully"
}

# ============================================================================
# COMPILE COMMAND
# ============================================================================

compile_command() {
    local original_dir=$(pwd)

    if [ ! -d FCG_Stages ]; then
        print_error "FCG_Stages directory not found. Run export command first."
        exit 1
    fi

    # Get sorted list of stage directories
    local stages=$(find FCG_Stages -maxdepth 1 -type d -name "Stage_*" | sort -V)

    if [ -z "$stages" ]; then
        print_error "No Stage_* directories found in FCG_Stages"
        exit 1
    fi

    print_info "Starting compilation..."

    for stage_dir in $stages; do
        local stage_name=$(basename "$stage_dir")

        print_info "Compiling $stage_name"

        cd "$stage_dir" || {
            print_error "Failed to enter directory $stage_dir"
            cd "$original_dir"
            exit 1
        }

        # Run CMake configure
        print_info "Running: cmake -B build -D CMAKE_BUILD_TYPE=Release"
        cmake -B build -D CMAKE_BUILD_TYPE=Release
        if [ $? -ne 0 ]; then
            print_error "CMake configure failed for $stage_name at $(pwd)"
            print_error "Failed command: cmake -B build -D CMAKE_BUILD_TYPE=Release"
            cd "$original_dir"
            exit 1
        fi

        # Run CMake build
        print_info "Running: cmake --build build"
        cmake --build build
        if [ $? -ne 0 ]; then
            print_error "CMake build failed for $stage_name at $(pwd)"
            print_error "Failed command: cmake --build build"
            cd "$original_dir"
            exit 1
        fi

        cd "$original_dir"
        print_info "$stage_name compiled successfully"
    done

    print_info "All stages compiled successfully"
}

# ============================================================================
# REMOVE COMMAND
# ============================================================================

remove_command() {
    check_git_repo

    local tags=$(git tag -l "Stage_*" 2>/dev/null | sort -V)

    if [ -z "$tags" ]; then
        print_error "No stages found"
        exit 1
    fi

    local last_tag=$(echo "$tags" | tail -1)
    local last_num=${last_tag#Stage_}

    print_warning "Removing tag: $last_tag"
    git tag -d "$last_tag"

    if [ $? -eq 0 ]; then
        print_info "Tag $last_tag removed successfully"
    else
        print_error "Failed to remove tag"
        exit 1
    fi
}

# ============================================================================
# UPDATE COMMAND
# ============================================================================

update_command() {
    local stage_num=""
    local description=""

    # Parse arguments
    while [ $# -gt 0 ]; do
        case "$1" in
            -n)
                stage_num="$2"
                shift 2
                ;;
            -d)
                description="$2"
                shift 2
                ;;
            *)
                shift
                ;;
        esac
    done

    check_git_repo

    if [ -z "$stage_num" ]; then
        print_error "Stage number is mandatory (use -n XX)"
        exit 1
    fi

    if [ -z "$description" ]; then
        print_error "Description is mandatory (use -d \"description\")"
        exit 1
    fi

    local tag_name="Stage_$(printf '%02d' "$stage_num")"

    # Check if tag exists
    if ! git rev-parse "$tag_name" > /dev/null 2>&1; then
        print_error "Tag $tag_name does not exist"
        exit 1
    fi

    print_info "Updating tag: $tag_name"
    git tag -a -f -m "$description" "$tag_name"

    if [ $? -eq 0 ]; then
        print_info "Tag $tag_name updated successfully"
    else
        print_error "Failed to update tag"
        exit 1
    fi
}

# ============================================================================
# PRINT COMMAND
# ============================================================================

print_command() {
    check_git_repo

    local tags=$(git tag -l "Stage_*" 2>/dev/null | sort -V)

    if [ -z "$tags" ]; then
        print_error "No Stage_* tags found"
        exit 1
    fi

    for tag in $tags; do
        local description=$(git tag -l --format='%(contents)' "$tag")
        #     == STAGE_XX ==
        echo ""
        echo "== $tag =="
        echo "$description"
        echo "=============="
        echo ""
    done
}

# ============================================================================
# MAIN DISPATCHER
# ============================================================================

usage() {
    echo ""
    echo "Usage: $0 {t|x|c|a|p|r|u|h} [arguments]"
    echo "Commands:"
    echo "  t|tag -d \"description\"               Create a new stage tag with description"
    echo "  x|export                             Export all stages to FCG_Stages directory"
    echo "  c|compile                            Compile all stages in FCG_Stages directory"
    echo "  a|all                                Export and compile all stages at once"
    echo "  p|print                              Print all stage numbers, with description"
    echo "  r|remove                             Remove last stage"
    echo "  u|update -n NUM -d \"description\"     Update the description of a stage"
    echo "  h|help                               Print usage and exit"
}

main() {
    if [ $# -eq 0 ]; then
        print_error "No command given"
        usage
        exit 1
    fi

    local command="$1"
    shift

    case "$command" in
        t|tag)
            tag_command "$@"
            ;;
        x|"export")
            export_command
            ;;
        c|compile)
            compile_command
            ;;
        a|all)
            export_command && compile_command
            ;;
        p|print)
            print_command
            ;;
        r|remove)
            remove_command
            ;;
        u|update)
            update_command "$@"
            ;;
        h|help)
            usage
            ;;
        *)
            print_error "Unknown command: $command"
            usage
            exit 1
            ;;
    esac
}

main "$@"
