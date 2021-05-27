cmake_minimum_required(VERSION 3.3)

project(dialogs)
find_package(xtd REQUIRED)

add_projects(
  about_box
  about_dialog
  busy_box
  busy_dialog
  color_box
  color_dialog
  debug_message_box
  exception_box
  exception_dialog
  folder_browser_dialog
  font_dialog
  input_box
  input_dialog
  message_box
  message_dialog
  open_file_dialog
  progress_dialog
  save_file_dialog
  trace_message_box
)
