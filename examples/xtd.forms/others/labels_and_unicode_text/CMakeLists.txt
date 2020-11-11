cmake_minimum_required(VERSION 3.3)

project(labels_and_unicode_text)
find_package(xtd REQUIRED)
add_sources(src/labels_and_unicode_text.cpp)
target_type(GUI_APPLICATION)
