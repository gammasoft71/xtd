cmake_minimum_required(VERSION 3.20)

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
  enable_debug
  forms_timer
  image_list
  images
  process_form
  radio_button_renderer
  screen
  settings_example
  texts
  translator
  translator_with_language
  use_wait_cursor
)
