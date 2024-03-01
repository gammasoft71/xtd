cmake_minimum_required(VERSION 3.20)

project(user_dialogs)
find_package(xtd REQUIRED)

add_projects(
  about_dialog_with_user_pages
  user_dialog
  user_dialog_show_sheet
)
