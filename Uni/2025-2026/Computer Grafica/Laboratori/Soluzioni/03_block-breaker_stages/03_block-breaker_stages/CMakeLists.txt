cmake_minimum_required(VERSION 4.0)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "Minimum policy version for all subprojects")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_library(common INTERFACE)
target_compile_features(common INTERFACE cxx_std_17)
target_compile_options(common INTERFACE
  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
  $<$<CXX_COMPILER_ID:MSVC>: /W4>
)



# 00_hello
add_executable(00_hello 00_hello.cpp)
target_link_libraries(00_hello PRIVATE SFML::Graphics common)

# 01a_basic_structure
add_executable(01a_basic_structure 01a_basic_structure.cpp)
target_link_libraries(01a_basic_structure PRIVATE SFML::Graphics common)

# 01b_texture_files
add_executable(01b_texture_files 01b_texture_files.cpp)
target_link_libraries(01b_texture_files PRIVATE SFML::Graphics common)

# 01c_texture_embedded
add_executable(01c_texture_embedded 01c_texture_embedded.cpp)
target_link_libraries(01c_texture_embedded PRIVATE SFML::Graphics common)

# 02a_move_ball
add_executable(02a_move_ball 02a_move_ball.cpp)
target_link_libraries(02a_move_ball PRIVATE SFML::Graphics common)

# 02b_startpause
add_executable(02b_startpause 02b_startpause.cpp)
target_link_libraries(02b_startpause PRIVATE SFML::Graphics common)

# 02c_move_paddle
add_executable(02c_move_paddle 02c_move_paddle.cpp)
target_link_libraries(02c_move_paddle PRIVATE SFML::Graphics common)

# 03a_field_limits
add_executable(03a_field_limits 03a_field_limits.cpp)
target_link_libraries(03a_field_limits PRIVATE SFML::Graphics common)

# 03b_robust_field_limits
add_executable(03b_robust_field_limits 03b_robust_field_limits.cpp)
target_link_libraries(03b_robust_field_limits PRIVATE SFML::Graphics common)

# 03c_basic_strike
add_executable(03c_basic_strike 03c_basic_strike.cpp)
target_link_libraries(03c_basic_strike PRIVATE SFML::Graphics common)

# 03d_variable_strike
add_executable(03d_variable_strike 03d_variable_strike.cpp)
target_link_libraries(03d_variable_strike PRIVATE SFML::Graphics common)

# 03e_paddle_edges
add_executable(03e_paddle_edges 03e_paddle_edges.cpp)
target_link_libraries(03e_paddle_edges PRIVATE SFML::Graphics common)

# 04a_blocks
add_executable(04a_blocks 04a_blocks.cpp)
target_link_libraries(04a_blocks PRIVATE SFML::Graphics common)

# 04b_hits
add_executable(04b_hits 04b_hits.cpp)
target_link_libraries(04b_hits PRIVATE SFML::Graphics common)
