cmake_minimum_required(VERSION 3.3)

project(create_gtest_like_event_listener)
find_package(xtd REQUIRED)
add_sources(src/create_gtest_like_event_listener.cpp)
target_type(TEST_APPLICATION)
