cmake_minimum_required(VERSION 3.20)

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
  image_ico
  image_iif
  image_jpeg
  image_pcx
  image_png
  image_pnm
  image_tga
  image_tiff
  image_wmf
  image_xpm
)
