cmake_minimum_required(VERSION 3.3)

project(create_your_own_unit_test)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/create_your_own_unit_test.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
