cmake_minimum_required(VERSION 3.5)

project(monitor_pulse_all)
find_package(xtd REQUIRED)
add_sources(README.md src/monitor_pulse_all.cpp)
target_type(CONSOLE_APPLICATION)
