cmake_minimum_required(VERSION 3.20)

project(delegate_lambda)
find_package(xtd REQUIRED)
add_sources(README.md src/delegate_lambda.cpp)
target_type(CONSOLE_APPLICATION)
