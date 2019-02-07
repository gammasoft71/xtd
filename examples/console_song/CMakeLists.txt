cmake_minimum_required(VERSION 3.3)

# Project
project(console_song)
find_package(console REQUIRED)
add_executable(${PROJECT_NAME} src/console_song.cpp)
target_link_libraries(${PROJECT_NAME} console)
