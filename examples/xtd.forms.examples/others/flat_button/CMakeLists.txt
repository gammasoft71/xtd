cmake_minimum_required(VERSION 3.3)

project(flat_button)
find_package(xtd REQUIRED)
add_sources(
  src/flat_button.cpp
  resources/gammasoft_32x32.xpm
  resources/gammasoft_64x64.xpm
)
target_type(GUI_APPLICATION)
