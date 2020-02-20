cmake_minimum_required(VERSION 3.3)

project(picker_controls)
find_package(xtd.forms REQUIRED)

add_projects(
  color_picker
  date_time_picker
  font_picker
)
