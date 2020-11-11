cmake_minimum_required(VERSION 3.3)

project(collection_assert_all_items_are_not_null)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/collection_assert_all_items_are_not_null.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.tunit")
