cmake_minimum_required(VERSION 3.16)
project(cppinput CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

<<<<<<< HEAD
set(KB_TEST 
  test/keyboard/specialkeys.cpp
)
add_executable(simkb test/keyboard/keyboard.cpp)
=======
set(KB test/keyboard)

add_executable(mouse test/mouse.cpp)

# SDL TESTS

find_package(SDL2 REQUIRED)
add_executable(sdl_kb_test ${KB}/sdl.cpp)
target_link_libraries(sdl_kb_test PRIVATE SDL2::SDL2)
>>>>>>> afe1a56 (refac : directory structures)

include_directories(cppinput include)
