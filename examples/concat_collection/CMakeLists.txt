cmake_minimum_required(VERSION 3.3)

project(concat_collection)
find_package(xtd.strings REQUIRED)
add_executable(${PROJECT_NAME} src/concat_collection.cpp)
target_link_libraries(${PROJECT_NAME} xtd.strings)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.strings")
