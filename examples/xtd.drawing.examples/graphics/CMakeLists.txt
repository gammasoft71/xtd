cmake_minimum_required(VERSION 3.20)

project(graphics)
find_package(xtd REQUIRED)

add_projects(
  graphics
  graphics_clear
  graphics_draw_arc
  graphics_draw_ellipse
  graphics_draw_rectangle
  graphics_fill_ellipse
  graphics_fill_pie
  graphics_fill_rectangle
)
