cmake_minimum_required(VERSION 3.3)

project(generic_test_class)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/generic_test_class.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
