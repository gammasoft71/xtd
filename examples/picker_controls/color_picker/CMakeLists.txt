cmake_minimum_required(VERSION 3.3)

project(color_picker)
find_package(xtd.forms REQUIRED)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE color_picker.cpp)
target_link_libraries(${PROJECT_NAME} xtd.forms)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.forms/picker_controls")
