cmake_minimum_required(VERSION 3.3)

project(point)
find_package(xtd.drawing REQUIRED)
add_executable(${PROJECT_NAME} src/point.cpp)
target_link_libraries(${PROJECT_NAME} xtd.drawing)
