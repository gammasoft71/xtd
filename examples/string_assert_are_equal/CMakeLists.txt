cmake_minimum_required(VERSION 3.3)

project(string_assert_are_equal)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/string_assert_are_equal.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
