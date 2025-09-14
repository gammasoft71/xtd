cmake_minimum_required(VERSION 3.20)

project(binary_reader_and_binary_writer)
find_package(xtd REQUIRED)
add_sources(README.md src/binary_reader_and_binary_writer.cpp)
target_type(CONSOLE_APPLICATION)
