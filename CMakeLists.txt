cmake_minimum_required(VERSION 3.10)

project(for_cadex VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    cadex_task
    src/main.cpp
    src/curves/circle.cpp
    src/curves/curve.cpp
)

target_compile_options(
    cadex_task PRIVATE
    -Wall -Wextra -pedantic -Werror
)