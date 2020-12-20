cmake_minimum_required(VERSION 3.3)

# Project
project(test_application)
find_package(xtd REQUIRED)

# Sources
add_sources(test_application.cpp)

# Target
target_type(TEST_APPLICATION)
