cmake_minimum_required(VERSION 3.3)

project(bitmap_button)
find_package(xtd.forms REQUIRED)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE bitmap_button.cpp gammasoft_16x16.xpm gammasoft_32x32.xpm gammasoft_64x64.xpm)
target_link_libraries(${PROJECT_NAME} xtd.forms)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.forms/others")
