cmake_minimum_required(VERSION 3.3)

project(hello_world_diagnostics)
find_package(xtd.diagnostics REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world_diagnostics.cpp)
target_link_libraries(${PROJECT_NAME} xtd.diagnostics)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.diagnostics")
