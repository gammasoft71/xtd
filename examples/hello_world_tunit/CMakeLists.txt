cmake_minimum_required(VERSION 3.3)

project(hello_world_tunit)
find_package(xtd REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world_tunit.cpp)
target_link_libraries(${PROJECT_NAME} xtd)
