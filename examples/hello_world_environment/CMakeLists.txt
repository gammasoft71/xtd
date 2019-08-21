cmake_minimum_required(VERSION 3.3)

project(hello_world_environment)
find_package(xtd.environment REQUIRED)
add_executable(${PROJECT_NAME} src/hello_world_environment.cpp)
target_link_libraries(${PROJECT_NAME} xtd.environment)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.environment")
