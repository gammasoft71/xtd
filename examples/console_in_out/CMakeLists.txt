cmake_minimum_required(VERSION 3.3)

project(console_in_out)
find_package(console REQUIRED)
add_executable(${PROJECT_NAME} src/console_in_out.cpp)
target_link_libraries(${PROJECT_NAME} console)
