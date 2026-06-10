
cmake_minimum_required(VERSION 3.16)
project(typer VERSION 1.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(lib)
file(GLOB SOURCES src/*.cpp)
add_executable(
    typer
    ${SOURCES}
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	tui_lib
)

