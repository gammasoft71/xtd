cmake_minimum_required(VERSION 3.3)

project(image)
find_package(xtd.drawing REQUIRED)
add_executable(${PROJECT_NAME} image.cpp logo.xpm)
target_link_libraries(${PROJECT_NAME} xtd.drawing)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.drawing")
