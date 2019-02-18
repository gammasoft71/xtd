cmake_minimum_required(VERSION 3.3)

project(assert_does_not_throws)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/assert_does_not_throws.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
