cmake_minimum_required(VERSION 3.20)

project(environment_cancel_signal)
find_package(xtd REQUIRED)
add_sources(README.md src/environment_cancel_signal.cpp)
target_type(CONSOLE_APPLICATION)
