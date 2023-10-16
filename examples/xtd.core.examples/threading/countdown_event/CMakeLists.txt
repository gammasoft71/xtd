cmake_minimum_required(VERSION 3.20)

project(countdown_event)
find_package(xtd REQUIRED)
add_sources(README.md src/countdown_event.cpp)
target_type(CONSOLE_APPLICATION)
