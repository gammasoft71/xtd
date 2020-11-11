cmake_minimum_required(VERSION 3.3)

project(assert_is_NaN)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/assert_is_NaN.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.tunit")
