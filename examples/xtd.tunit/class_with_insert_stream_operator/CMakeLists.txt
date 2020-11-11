cmake_minimum_required(VERSION 3.3)

project(class_with_insert_stream_operator)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/class_with_insert_stream_operator.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.tunit")
