cmake_minimum_required(VERSION 3.3)

project(caller)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/caller.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
