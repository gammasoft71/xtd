cmake_minimum_required(VERSION 3.20)

project(tunit_config_main)
find_package(xtd REQUIRED)
add_sources(README.md src/tunit_config_main.cpp)
target_type(TEST_APPLICATION)
