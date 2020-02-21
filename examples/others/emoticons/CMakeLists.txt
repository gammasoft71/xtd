cmake_minimum_required(VERSION 3.3)

project(emoticons)
find_package(xtd.forms REQUIRED)
add_sources(src/emoticons.cpp)
target_type(GUI_APPLICATION)
