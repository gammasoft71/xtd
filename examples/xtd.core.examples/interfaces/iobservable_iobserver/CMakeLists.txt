cmake_minimum_required(VERSION 3.3)

project(iobservable_iobserver)
find_package(xtd REQUIRED)
add_sources(src/iobservable_iobserver.cpp)
target_type(CONSOLE_APPLICATION)
