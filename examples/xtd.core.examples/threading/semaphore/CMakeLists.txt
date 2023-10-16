cmake_minimum_required(VERSION 3.20)

project(semaphore)
find_package(xtd REQUIRED)
add_sources(README.md src/semaphore.cpp)
target_type(CONSOLE_APPLICATION)
