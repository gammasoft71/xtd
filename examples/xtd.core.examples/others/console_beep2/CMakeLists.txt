cmake_minimum_required(VERSION 3.20)

project(console_beep2)
find_package(xtd REQUIRED)
add_sources(README.md src/console_beep2.cpp)
target_type(CONSOLE_APPLICATION)
