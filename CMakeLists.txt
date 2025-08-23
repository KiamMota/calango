cmake_minimum_required(VERSION 3.16)
project(cppinput CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(KB test/keyboard)
set(MS test/mouse)

add_executable(kb ${KB}/keyboard.cpp)

include_directories(cppinput include)
