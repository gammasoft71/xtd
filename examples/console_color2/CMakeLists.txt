cmake_minimum_required(VERSION 3.3)

project(console_color2)
find_package(console REQUIRED)
add_executable(${PROJECT_NAME} src/console_color2.cpp)
target_link_libraries(${PROJECT_NAME} console)
