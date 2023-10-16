cmake_minimum_required(VERSION 3.20)

project(application_and_assert)
find_package(xtd REQUIRED)
add_sources(README.md src/application_and_assert.cpp)
target_type(GUI_APPLICATION)
