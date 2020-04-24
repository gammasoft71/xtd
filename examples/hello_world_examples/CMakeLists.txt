cmake_minimum_required(VERSION 3.3)

project(hello_world_examples)
find_package(xtd.forms REQUIRED)

add_projects(
  hello_world_emoticons
  hello_world_label
  hello_world_message_box
  hello_world_paint
)
