cmake_minimum_required(VERSION 3.3)

project(hello_world_console)
find_package(xtd.core REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world_console.cpp)
target_link_libraries(${PROJECT_NAME} xtd.core)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.core")
