cmake_minimum_required(VERSION 3.3)

project(components)
find_package(xtd.forms REQUIRED)

add_projects(
  background_worker
  button_images
  button_renderer
  check_box_renderer
  cursor
  image_list
  screen
  settings_example
  settings_example2
  system_images
  timer
)
