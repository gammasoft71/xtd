cmake_minimum_required(VERSION 3.3)

project(assert_are_equal_with_tolerence)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/assert_are_equal_with_tolerence.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
