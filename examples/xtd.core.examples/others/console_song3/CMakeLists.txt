cmake_minimum_required(VERSION 3.3)

# Project
project(console_song3)
find_package(xtd REQUIRED)
add_sources(src/console_song3.cpp)
target_type(CONSOLE_APPLICATION)
