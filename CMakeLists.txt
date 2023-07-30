cmake_minimum_required(VERSION 3.10)

project(for_cadex VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

add_executable(
    cadex_task
    src/main.cpp
    src/curves/circle.cpp
    src/curves/ellipse.cpp
    src/curves/helix.cpp
)

if(OpenMP_CXX_FOUND)
    target_link_libraries(cadex_task PRIVATE OpenMP::OpenMP_CXX)
endif()

target_compile_options(
    cadex_task PRIVATE
    -Wall -Wextra -pedantic -Werror
)