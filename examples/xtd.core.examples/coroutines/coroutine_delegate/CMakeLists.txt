cmake_minimum_required(VERSION 3.20)

project(coroutine_delegate)
find_package(xtd REQUIRED)
add_sources(README.md src/coroutine_delegate.cpp)
target_type(CONSOLE_APPLICATION)
