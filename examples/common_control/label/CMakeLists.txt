cmake_minimum_required(VERSION 3.3)

project(label)
find_package(xtd.forms REQUIRED)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE src/label.cpp)
target_link_libraries(${PROJECT_NAME} xtd.forms)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "CommonControl")
