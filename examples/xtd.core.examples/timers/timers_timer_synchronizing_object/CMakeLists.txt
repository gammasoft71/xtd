cmake_minimum_required(VERSION 3.20)

project(timers_timer_synchronizing_object)
find_package(xtd REQUIRED)
add_sources(README.md src/timers_timer_synchronizing_object.cpp)
add_references(xtd.forms)
target_type(GUI_APPLICATION)
