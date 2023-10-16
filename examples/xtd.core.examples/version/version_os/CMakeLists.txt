cmake_minimum_required(VERSION 3.20)

project(version_os)
find_package(xtd REQUIRED)
add_sources(README.md src/version_os.cpp)
target_type(CONSOLE_APPLICATION)
