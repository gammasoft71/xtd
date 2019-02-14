cmake_minimum_required(VERSION 3.3)

project(test_with_helpers)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/test_with_helpers.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
