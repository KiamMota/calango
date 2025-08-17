cmake_minimum_required(VERSION 3.16)
project(cppinput CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(KB_TEST 
  test/keyboard/specialkeys.cpp
)

add_executable(mouse test/mouse.cpp)
add_executable(keyboard ${KB_TEST})
add_executable(getcaps test/keyboard/getcaps.cpp)

include_directories(cppinput include)
