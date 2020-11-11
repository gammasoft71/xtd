cmake_minimum_required(VERSION 3.3)

project(dialogs)
find_package(xtd REQUIRED)

add_projects(
  about_dialog
  about_dialog_system
  busy_box
  busy_dialog
  message_box
  message_dialog
  message_dialog_show_sheet
  input_box
  progress_dialog
)
