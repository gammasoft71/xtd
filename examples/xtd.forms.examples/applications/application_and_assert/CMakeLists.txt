cmake_minimum_required(VERSION 3.3)

project(application_and_assert)
find_package(xtd REQUIRED)
add_sources(src/application_and_assert.cpp)
target_type(GUI_APPLICATION)
