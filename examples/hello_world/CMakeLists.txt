cmake_minimum_required(VERSION 3.3)

project(hello_world)
find_package(xtd.delegates REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world.cpp)
target_link_libraries(${PROJECT_NAME} xtd.delegates)
