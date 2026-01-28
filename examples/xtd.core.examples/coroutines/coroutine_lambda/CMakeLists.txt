cmake_minimum_required(VERSION 3.20)

project(coroutine_lambda)
find_package(xtd REQUIRED)
add_sources(README.md src/coroutine_lambda.cpp)
target_type(CONSOLE_APPLICATION)
