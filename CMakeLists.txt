cmake_minimum_required(VERSION 3.16)
project(cppinput CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(KB test/keyboard)

add_executable(mouse test/mouse.cpp)
add_executable(kb ${KB}/keyboard.cpp)


# SDL TESTS

find_package(SDL2 REQUIRED)
add_executable(sdl_kb_test ${KB}/sdl.cpp)
target_link_libraries(sdl_kb_test PRIVATE SDL2::SDL2)

include_directories(cppinput include)
