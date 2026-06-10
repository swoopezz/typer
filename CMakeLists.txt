
cmake_minimum_required(VERSION 3.16)
project(typer VERSION 1.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp src/elements/*.cpp)
add_executable(
    typer
    ${SOURCES}
)
target_include_directories(typer PRIVATE include/)
