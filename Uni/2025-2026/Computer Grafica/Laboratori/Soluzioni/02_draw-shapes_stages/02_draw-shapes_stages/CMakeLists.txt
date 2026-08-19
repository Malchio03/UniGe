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

add_executable(my_drawing_00 my_drawing_00.cpp)
target_link_libraries(my_drawing_00 PRIVATE SFML::Graphics)

add_executable(my_drawing_01-06 my_drawing_01-06.cpp)
target_link_libraries(my_drawing_01-06 PRIVATE SFML::Graphics)

add_executable(my_drawing_07-08 my_drawing_07-08.cpp)
target_link_libraries(my_drawing_07-08 PRIVATE SFML::Graphics)

add_executable(my_drawing_09-10 my_drawing_09-10.cpp)
target_link_libraries(my_drawing_09-10 PRIVATE SFML::Graphics)


