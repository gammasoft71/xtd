cmake_minimum_required(VERSION 3.3)

project(background_worker)
find_package(xtd.forms REQUIRED)
add_sources(src/background_worker.cpp)
target_type(GUI_APPLICATION)
