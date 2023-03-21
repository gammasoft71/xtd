cmake_minimum_required(VERSION 3.3)

project(images)
find_package(xtd REQUIRED)

add_projects(
  image
  image_bmp
  image_jpeg
  image_png
  image_xpm
)
