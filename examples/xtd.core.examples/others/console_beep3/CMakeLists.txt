cmake_minimum_required(VERSION 3.3)

project(console_beep3)
find_package(xtd REQUIRED)
add_sources(src/console_beep3.cpp)
target_type(CONSOLE_APPLICATION)
