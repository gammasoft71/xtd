cmake_minimum_required(VERSION 3.3)

project(common_dialogs)
find_package(xtd.forms REQUIRED)

add_projects(
  color_dialog
  folder_browser_dialog
  font_dialog
  message_box
  message_box_show_sheet
  open_file_dialog
  save_file_dialog
)
