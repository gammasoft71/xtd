cmake_minimum_required(VERSION 3.3)

# Project
project(console_song)
find_package(xtd REQUIRED)
add_sources(src/console_song.cpp)
target_type(CONSOLE_APPLICATION)
