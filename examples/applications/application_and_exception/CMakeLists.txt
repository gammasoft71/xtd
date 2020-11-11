cmake_minimum_required(VERSION 3.3)

project(application_and_exception)
find_package(xtd.forms REQUIRED)
add_sources(src/application_and_exception.cpp)
target_type(GUI_APPLICATION)
