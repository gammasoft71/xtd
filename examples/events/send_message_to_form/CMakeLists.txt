cmake_minimum_required(VERSION 3.3)

project(send_message_to_form)
find_package(xtd.forms REQUIRED)
add_sources(src/send_message_to_form.cpp)
target_type(GUI_APPLICATION)
