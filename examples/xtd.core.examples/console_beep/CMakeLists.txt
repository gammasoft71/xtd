cmake_minimum_required(VERSION 3.3)

project(console_beep)
find_package(xtd REQUIRED)
add_sources(src/console_beep.cpp)
target_type(CONSOLE_APPLICATION)
