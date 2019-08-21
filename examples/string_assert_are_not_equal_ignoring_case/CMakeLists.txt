cmake_minimum_required(VERSION 3.3)

project(string_assert_are_not_equal_ignoring_case)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/string_assert_are_equal_ignoring_case.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.tunit")
