cmake_minimum_required(VERSION 3.5)
project(sorting)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(tests test/tests.cpp)
target_include_directories(tests PUBLIC test/ ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(app main.cpp)
target_link_libraries(app tests)
