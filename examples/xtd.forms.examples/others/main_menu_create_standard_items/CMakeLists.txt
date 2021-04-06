cmake_minimum_required(VERSION 3.3)

project(main_menu_create_standard_items)
find_package(xtd REQUIRED)
add_sources(src/main_menu_create_standard_items.cpp)
target_type(GUI_APPLICATION)
