cmake_minimum_required(VERSION 3.5...4.0)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "Minimum policy version for all subprojects")

project(SFMLOpenGLExample LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)


#############################
### Download project data ###
#############################

set(FETCH_CONTENT_NAME "content")
set(DOWNLOAD_FILENAME "data.zip")
FetchContent_Declare(
    ${FETCH_CONTENT_NAME}

    URL https://www.dropbox.com/scl/fi/xgg0udmvwfp92r34c1oor/data.zip?rlkey=s0vnvqe7qzwyk7lmf58vg4bno&dl=1
    DOWNLOAD_NAME ${DOWNLOAD_FILENAME}
    DOWNLOAD_NO_EXTRACT TRUE
    SOURCE_DIR ${CMAKE_BINARY_DIR}/
)

FetchContent_MakeAvailable(${FETCH_CONTENT_NAME})

# Manual extraction using the filename variable
execute_process(
    COMMAND ${CMAKE_COMMAND} -E tar -xzf "${CMAKE_BINARY_DIR}/${DOWNLOAD_FILENAME}"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Clean up using variables
# file(REMOVE "${CMAKE_BINARY_DIR}/${DOWNLOAD_FILENAME}")
file(REMOVE_RECURSE "${CMAKE_BINARY_DIR}/_deps/${FETCH_CONTENT_NAME}-build")
file(REMOVE_RECURSE "${CMAKE_BINARY_DIR}/_deps/${FETCH_CONTENT_NAME}-tmp")


############################
### Library dependencies ###
############################

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
        GIT_TAG 	1.0.3
)
FetchContent_MakeAvailable(glm)

add_library(common INTERFACE)
target_compile_features(common INTERFACE cxx_std_20)
target_compile_options(common INTERFACE
  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Wall -DGL_SILENCE_DEPRECATION>
  $<$<CXX_COMPILER_ID:MSVC>: /W4>
)

# Find OpenGL
find_package(OpenGL REQUIRED)

#find coregraphics for raw mouse events in macos
if(APPLE)
    find_library(CORE_GRAPHICS_LIB CoreGraphics REQUIRED)
endif()

###############################
### Sources and executables ###
###############################

SET( fn00 "00_refactor" )
add_executable( ${fn00} ${fn00}.cc )
target_link_libraries( ${fn00} PRIVATE common SFML::Window OpenGL::GL glm::glm-header-only)

SET( fn01 "01_trackball" )
add_executable( ${fn01} ${fn01}.cc )
target_link_libraries( ${fn01} PRIVATE common SFML::Window OpenGL::GL glm::glm-header-only)

SET( fn02 "02_modelmatrix" )
add_executable( ${fn02} ${fn02}.cc )
target_link_libraries( ${fn02} PRIVATE common SFML::Window OpenGL::GL glm::glm-header-only)

SET( fn03 "03_multimeshes" )
add_executable( ${fn03} ${fn03}.cc )
target_link_libraries( ${fn03} PRIVATE common SFML::Window OpenGL::GL glm::glm-header-only)

SET( fn04 "04_first_person_view" )
add_executable( ${fn04} ${fn04}.cc )
target_link_libraries( ${fn04} PRIVATE common SFML::Window OpenGL::GL glm::glm-header-only)

SET( fn05 "05_raw_mouse_input" )
add_executable( ${fn05} ${fn05}.cc )
target_link_libraries( ${fn05} PRIVATE common SFML::Window OpenGL::GL glm::glm-header-only ${CORE_GRAPHICS_LIB})
