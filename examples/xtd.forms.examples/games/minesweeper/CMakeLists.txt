cmake_minimum_required(VERSION 3.20)

project(minesweeper)
find_package(xtd REQUIRED)
add_sources(
  src/cell_state.hpp
  src/cell.hpp
  src/cell.cpp
  src/custom_field_dialog.hpp
  src/custom_field_dialog.cpp
  src/high_scores_dialog.hpp
  src/high_scores_dialog.cpp
  src/input_name_dialog.hpp
  src/input_name_dialog.cpp
  src/level.hpp
  src/minesweeper.hpp
  src/minesweeper.cpp
)
target_type(GUI_APPLICATION)
