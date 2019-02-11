cmake_minimum_required(VERSION 3.3)

project(hello_world3)
find_package(xtd.console REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world3.cpp)
target_link_libraries(${PROJECT_NAME} xtd.console)
