cmake_minimum_required(VERSION 3.5...4.0)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "Minimum policy version for all subprojects")

project(SFMLOpenGLExample LANGUAGES CXX)

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
  $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Wall -DGL_SILENCE_DEPRECATION>
  $<$<CXX_COMPILER_ID:MSVC>: /W4>
)

# Find OpenGL
find_package(OpenGL REQUIRED)

SET( fn00 "00_hello-gl" )
add_executable( ${fn00} ${fn00}.cc )
target_link_libraries( ${fn00} PRIVATE common SFML::Window OpenGL::GL )

SET( fn01 "01_hello-triangle" )
add_executable( ${fn01} ${fn01}.cc )
target_link_libraries( ${fn01} PRIVATE common SFML::Window OpenGL::GL )

SET( fn02 "02_refactor" )
add_executable( ${fn02} ${fn02}.cc )
target_link_libraries( ${fn02} PRIVATE common SFML::Window OpenGL::GL )

SET( fn03 "03_hotshaders" )
add_executable( ${fn03} ${fn03}.cc )
target_link_libraries( ${fn03} PRIVATE common SFML::Window OpenGL::GL )

SET( fn04 "04_uniforms" )
add_executable( ${fn04} ${fn04}.cc )
target_link_libraries( ${fn04} PRIVATE common SFML::Window OpenGL::GL )

SET( fn05 "05_multicolor" )
add_executable( ${fn05} ${fn05}.cc )
target_link_libraries( ${fn05} PRIVATE common SFML::Window OpenGL::GL )

SET( fn06 "06_indexed" )
add_executable( ${fn06} ${fn06}.cc )
target_link_libraries( ${fn06} PRIVATE common SFML::Window OpenGL::GL )

SET( fn07 "07_culling" )
add_executable( ${fn07} ${fn07}.cc )
target_link_libraries( ${fn07} PRIVATE common SFML::Window OpenGL::GL )

SET( fn08 "08_zbuffer" )
add_executable( ${fn08} ${fn08}.cc )
target_link_libraries( ${fn08} PRIVATE common SFML::Window OpenGL::GL )
