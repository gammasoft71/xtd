cmake_minimum_required(VERSION 3.3)

project(assert_does_not_throw)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/assert_does_not_throw.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.tunit")
