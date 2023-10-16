cmake_minimum_required(VERSION 3.20)

# Project
project(console_song)
find_package(xtd REQUIRED)
add_sources(README.md src/console_song.cpp)
target_type(CONSOLE_APPLICATION)
