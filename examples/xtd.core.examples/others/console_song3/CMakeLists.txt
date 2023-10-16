cmake_minimum_required(VERSION 3.20)

# Project
project(console_song3)
find_package(xtd REQUIRED)
add_sources(README.md src/console_song3.cpp)
target_type(CONSOLE_APPLICATION)
