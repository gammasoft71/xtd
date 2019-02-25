cmake_minimum_required(VERSION 3.3)

project(many_asserts)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/many_asserts.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
