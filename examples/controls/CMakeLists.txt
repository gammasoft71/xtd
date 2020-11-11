cmake_minimum_required(VERSION 3.3)

project(controls)
find_package(xtd.forms REQUIRED)

add_projects(
  dot_matrix_display
  fourteen_segment_display
  lcd_label
  nine_segment_display
  seven_segment_display
  sixteen_segment_display
)
