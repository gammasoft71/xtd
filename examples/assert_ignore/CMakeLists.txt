cmake_minimum_required(VERSION 3.3)

project(assert_ignore)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/assert_ignore.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
