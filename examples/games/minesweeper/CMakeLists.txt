cmake_minimum_required(VERSION 3.3)

project(minesweeper)
find_package(xtd.forms REQUIRED)
add_sources(
  src/cell_state.h
  src/cell.h
  src/minesweeper.h
  src/high_scores_dialog.h
  src/input_name_dialog.h
  src/level.h
)
target_type(GUI_APPLICATION)
