cmake_minimum_required(VERSION 3.3)

project(minesweeper)
find_package(xtd REQUIRED)
add_sources(
  src/cell_state.h
  src/cell.h
  src/cell.cpp
  src/custom_field_dialog.h
  src/custom_field_dialog.cpp
  src/high_scores_dialog.h
  src/high_scores_dialog.cpp
  src/input_name_dialog.h
  src/input_name_dialog.cpp
  src/level.h
  src/minesweeper.h
  src/minesweeper.cpp
)
target_type(GUI_APPLICATION)
