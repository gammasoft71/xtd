cmake_minimum_required(VERSION 3.20)

project(dialogs)
find_package(xtd REQUIRED)

add_projects(
  about_box
  about_dialog
  assert_box
  assert_dialog
  busy_box
  busy_dialog
  color_box
  color_dialog
  debug_message_box
  debug_message_dialog
  exception_box
  exception_dialog
  find_box
  find_dialog
  folder_browser_box
  folder_browser_dialog
  font_box
  font_dialog
  input_box
  input_dialog
  message_box
  message_dialog
  open_file_box
  open_file_dialog
  progress_box
  progress_dialog
  replace_box
  replace_dialog
  save_file_box
  save_file_dialog
  trace_message_box
  trace_message_dialog
)
