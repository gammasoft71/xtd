cmake_minimum_required(VERSION 3.20)

project(send_message_to_form)
find_package(xtd REQUIRED)
add_sources(README.md src/send_message_to_form.cpp)
target_type(GUI_APPLICATION)
