cmake_minimum_required(VERSION 3.3)

project(hello_world_xtd_forms)
find_package(xtd REQUIRED)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE src/hello_world_xtd_forms.cpp)
target_link_libraries(${PROJECT_NAME} xtd)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd")
