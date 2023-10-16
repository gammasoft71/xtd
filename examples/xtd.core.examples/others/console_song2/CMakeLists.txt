cmake_minimum_required(VERSION 3.20)

# Project
project(console_song2)
find_package(xtd REQUIRED)
add_sources(README.md src/console_song2.cpp)
target_type(CONSOLE_APPLICATION)
