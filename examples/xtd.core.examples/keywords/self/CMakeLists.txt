cmake_minimum_required(VERSION 3.20)

project(self)
find_package(xtd REQUIRED)
add_sources(README.md src/self.cpp)
target_type(CONSOLE_APPLICATION)
