cmake_minimum_required(VERSION 3.3)

# Project
project(console_song)
find_package(xtd.console REQUIRED)
add_executable(${PROJECT_NAME} src/console_song.cpp)
target_link_libraries(${PROJECT_NAME} xtd.console)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.console")
