cmake_minimum_required(VERSION 3.17)
project(yacdslib C)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_C_STANDARD 11)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)