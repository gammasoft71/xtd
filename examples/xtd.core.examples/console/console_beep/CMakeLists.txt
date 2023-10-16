cmake_minimum_required(VERSION 3.20)

project(console_beep)
find_package(xtd REQUIRED)
add_sources(README.md src/console_beep.cpp)
target_type(CONSOLE_APPLICATION)
