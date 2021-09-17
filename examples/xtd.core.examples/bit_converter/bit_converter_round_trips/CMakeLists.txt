cmake_minimum_required(VERSION 3.3)

project(bit_converter_round_trips)
find_package(xtd REQUIRED)
add_sources(src/bit_converter_round_trips.cpp)
target_type(CONSOLE_APPLICATION)
