cmake_minimum_required(VERSION 3.20)

project(drawing)
find_package(xtd REQUIRED)

add_projects(
  draw_ellipse
  draw_image
  draw_line
  draw_point
  draw_rectangle
  draw_rounded_rectangle
  fill_ellipse
  fill_rectangle
  fill_rounded_rectangle
  image_effects
  screenshot
)
