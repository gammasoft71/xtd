cmake_minimum_required(VERSION 3.3)

project(hello_world_io)
find_package(xtd.io REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world_io.cpp)
target_link_libraries(${PROJECT_NAME} xtd.io)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.io")
