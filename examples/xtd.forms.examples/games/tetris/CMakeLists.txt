cmake_minimum_required(VERSION 3.20)

project(tetris)
find_package(xtd REQUIRED)
add_sources(
  README.md 
  src/board_control.h
  src/board_control.cpp
  src/shape.h
  src/shape.cpp
  src/tetrominoes.h
  src/tetris_form.h
  src/tetris_form.cpp
)
target_type(GUI_APPLICATION)
