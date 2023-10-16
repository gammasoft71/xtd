cmake_minimum_required(VERSION 3.20)

project(about_dialog_from_executing_assembly_informations)
find_package(xtd REQUIRED)
target_icon(resources/xtd_forms)
add_sources(README.md src/about_dialog_from_executing_assembly_informations.cpp)
target_type(GUI_APPLICATION)
