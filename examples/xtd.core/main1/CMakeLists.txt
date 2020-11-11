cmake_minimum_required(VERSION 3.3)

project(main1)
find_package(xtd.core REQUIRED)
find_package(xtd REQUIRED)
add_sources(main1.cpp)
target_type(CONSOLE_APPLICATION)
