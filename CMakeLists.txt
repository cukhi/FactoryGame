cmake_minimum_required(VERSION 3.14)
project(FactoryGame)

include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} main.cpp grid.cpp robot_panel.cpp)
target_link_libraries(${PROJECT_NAME} raylib)

