cmake_minimum_required(VERSION 3.3)

project(create_your_own_event_listener)
find_package(xtd REQUIRED)
add_sources(src/create_your_own_event_listener.cpp)
target_type(TEST_APPLICATION)
