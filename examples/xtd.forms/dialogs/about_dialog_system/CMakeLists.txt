cmake_minimum_required(VERSION 3.3)

project(about_dialog_system)
find_package(xtd.forms REQUIRED)
application_icon(resources/xtd_forms)
add_sources(src/about_dialog_system.cpp)
target_type(GUI_APPLICATION)
