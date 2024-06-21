cmake_minimum_required(VERSION 3.20)

project(application_settings)
find_package(xtd REQUIRED)
add_sources(README.md src/application_settings.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.5)
