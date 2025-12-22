cmake_minimum_required(VERSION 3.20)

project(sudoku)
find_package(xtd REQUIRED)
add_sources(
  src/sudoku.hpp
  src/sudoku.cpp
)
target_type(GUI_APPLICATION)
