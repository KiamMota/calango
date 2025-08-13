cmake_minimum_required(VERSION 3.16)
project(cppaudio-lib CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(cppaudio-lib test/main.cpp)
include_directories(cppaudio-lib cppaudio)
