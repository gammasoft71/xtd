cmake_minimum_required(VERSION 3.3)

project(console_read_line)
find_package(xtd.console REQUIRED)
add_executable(${PROJECT_NAME} src/console_read_line.cpp)
target_link_libraries(${PROJECT_NAME} xtd.console)
