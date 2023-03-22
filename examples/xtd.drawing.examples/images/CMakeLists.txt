cmake_minimum_required(VERSION 3.3)

project(images)
find_package(xtd REQUIRED)

add_projects(
  image
  image_ani
  image_bmp
  image_cur
  image_emf
  image_gif
  image_icns
  image_iif
  image_jpeg
  image_png
  image_xpm
)
