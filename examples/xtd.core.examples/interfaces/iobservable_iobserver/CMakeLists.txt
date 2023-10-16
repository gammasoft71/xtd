cmake_minimum_required(VERSION 3.20)

project(iobservable_iobserver)
find_package(xtd REQUIRED)
add_sources(README.md src/iobservable_iobserver.cpp)
target_type(CONSOLE_APPLICATION)
