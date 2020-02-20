cmake_minimum_required(VERSION 3.3)

project(minesweeper)
find_package(xtd.forms REQUIRED)
add_sources(
  src/minesweeper.cpp
  resources/flag.xpm
  resources/mine.xpm
  resources/smiley1.xpm
  resources/smiley2.xpm
  resources/smiley3.xpm
  resources/smiley4.xpm
)
target_type(GUI_APPLICATION)
