cmake_minimum_required(VERSION 3.20)

project(xtd_collection_indexer)
find_package(xtd REQUIRED)
add_sources(README.md src/xtd_collection_indexer.cpp)
target_type(CONSOLE_APPLICATION)
