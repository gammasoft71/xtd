cmake_minimum_required(VERSION 3.20)

project(background_worker)
find_package(xtd REQUIRED)
add_sources(src/background_worker.cpp)
target_type(GUI_APPLICATION)
