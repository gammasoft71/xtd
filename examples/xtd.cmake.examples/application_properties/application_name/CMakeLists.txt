cmake_minimum_required(VERSION 3.3)

# Project
project(application_name)
find_package(xtd REQUIRED)

# Application properties
application_name("xtd_forms_application")

# Sources
add_sources(application_name.cpp)

# Target
target_type(GUI_APPLICATION)
