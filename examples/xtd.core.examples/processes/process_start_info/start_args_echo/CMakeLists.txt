cmake_minimum_required(VERSION 3.20)

project(start_args_echo)
find_package(xtd REQUIRED)
add_sources(README.md src/start_args_echo.cpp)
target_type(CONSOLE_APPLICATION)
