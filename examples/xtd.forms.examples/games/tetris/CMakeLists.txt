cmake_minimum_required(VERSION 3.20)

project(tetris)
find_package(xtd REQUIRED)
add_sources(
  README.md 
  src/board_control.hpp
  src/board_control.cpp
  src/shape.hpp
  src/shape.cpp
  src/tetrominoes.hpp
  src/tetris_form.hpp
  src/tetris_form.cpp
)
target_type(GUI_APPLICATION)
