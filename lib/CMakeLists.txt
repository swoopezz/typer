cmake_minimum_required(VERSION 3.16)
project(tui_lib VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*/*.cpp src/*.cpp)
add_library(
    ${PROJECT_NAME}
    STATIC
    ${SOURCES}
)

file(GLOB INCLUDE
    include/elements
	include/pixel
	include/widget
	include/window
	include/loop
	include
)
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${INCLUDE}
)
