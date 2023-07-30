cmake_minimum_required(VERSION 3.5)

project(tutorial_environment)
find_package(xtd.console REQUIRED)
add_sources(src/environment.cpp)
target_type(CONSOLE_APPLICATION)
