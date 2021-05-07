cmake_minimum_required(VERSION 3.3)

project(tunit_config_main)
find_package(xtd REQUIRED)
add_sources(src/tunit_config_main.cpp)
target_type(TEST_APPLICATION)
