cmake_minimum_required(VERSION 4.0)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "Minimum policy version for all subprojects")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(text_editor_00_echo src/main_text_editor_00_echo.cpp)
target_link_libraries(text_editor_00_echo PRIVATE SFML::Graphics)

add_executable(text_editor_01-09_write src/main_text_editor_01-09_write.cpp)
target_link_libraries(text_editor_01-09_write PRIVATE SFML::Graphics)

add_executable(text_editor_10_move-view src/main_text_editor_10_move-view.cpp)
target_link_libraries(text_editor_10_move-view PRIVATE SFML::Graphics)

add_executable(text_editor_11_move-cursor src/main_text_editor_11_move-cursor.cpp)
target_link_libraries(text_editor_11_move-cursor PRIVATE SFML::Graphics)

add_executable(text_editor_12_inplace_write src/main_text_editor_12_inplace_write.cpp)
target_link_libraries(text_editor_12_inplace_write PRIVATE SFML::Graphics)

add_executable(text_editor_13_backspace src/main_text_editor_13_backspace.cpp)
target_link_libraries(text_editor_13_backspace PRIVATE SFML::Graphics)

