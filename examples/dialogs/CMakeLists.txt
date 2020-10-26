cmake_minimum_required(VERSION 3.3)

project(dialogs)
find_package(xtd.forms REQUIRED)

add_projects(
  about_dialog
  about_dialog_system
  busy_dialog
  message_box
  message_box_show_sheet
)
