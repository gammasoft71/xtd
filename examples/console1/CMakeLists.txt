cmake_minimum_required(VERSION 3.3)

project(console1)
find_package(console REQUIRED)
add_executable(${PROJECT_NAME} src/console1.cpp)
target_link_libraries(${PROJECT_NAME} console)
