cmake_minimum_required(VERSION 3.3)

project(hello_worlds)
find_package(xtd REQUIRED)

add_projects(
  hello_world_emoticons
  hello_world_label
  hello_world_message_box
  hello_world_message_box2
  hello_world_message_box3
  hello_world_paint
  hello_world_say
)
