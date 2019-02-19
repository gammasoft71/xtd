cmake_minimum_required(VERSION 3.3)

project(assert_throws_any)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/assert_throws_any.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
