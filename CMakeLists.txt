cmake_minimum_required(VERSION 3.10)
project(roguelike)

set(CMAKE_CXX_STANDARD 17)
find_package(Curses REQUIRED)

add_executable(roguelike src/main.cpp src/Map.cpp)
target_link_libraries(roguelike ${CURSES_LIBRARIES})
