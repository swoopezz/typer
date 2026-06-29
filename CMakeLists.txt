
cmake_minimum_required(VERSION 3.16)
project(kbchad VERSION 1.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)
file(GLOB SOURCES src/*.cpp)
add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    tui_lib
)
