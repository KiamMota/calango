cmake_minimum_required(VERSION 3.16)
project(cppinput CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(mouse test/mouse.cpp)
add_executable(keyboard test/keyboard.cpp)

include_directories(cppinput include)
