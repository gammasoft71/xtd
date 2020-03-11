cmake_minimum_required(VERSION 3.3)

project(minesweeper)
find_package(xtd.forms REQUIRED)
application_icon(resources/minesweeper)
add_sources(
  src/cell_state.h
  src/cell.h
  src/form_main.h
  src/high_scores_dialog.h
  src/input_name_dialog.h
  src/level.h
  src/minesweeper.cpp
)
target_type(GUI_APPLICATION)
