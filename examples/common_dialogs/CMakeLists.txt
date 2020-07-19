cmake_minimum_required(VERSION 3.3)

project(common_dialogs)
find_package(xtd.forms REQUIRED)

add_projects(
  about_dialog
  color_dialog
  folder_browser_dialog
  font_dialog
  input_box
  message_box
  open_file_dialog
  save_file_dialog
)
