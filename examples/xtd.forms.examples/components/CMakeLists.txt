cmake_minimum_required(VERSION 3.3)

project(components)
find_package(xtd REQUIRED)

add_projects(
  background_worker
  button_images
  button_renderer
  check_box_renderer
  countries
  cursors
  emoticons
  image_list
  radio_button_renderer
  screen
  settings_example
  system_images
  texts
  timer
  translator
  use_wait_cursor
)
