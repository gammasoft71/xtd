cmake_minimum_required(VERSION 3.20)

project(bitmap_button_with_text)
find_package(xtd REQUIRED)
add_sources(
  src/bitmap_button_with_text.cpp
  resources/gammasoft_16x16.xpm
  resources/gammasoft_32x32.xpm
  resources/gammasoft_64x64.xpm
)
target_type(GUI_APPLICATION)
