cmake_minimum_required(VERSION 3.3)

project(hello_world_strings)
find_package(xtd.strings REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world_strings.cpp)
target_link_libraries(${PROJECT_NAME} xtd.strings)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.strings")
