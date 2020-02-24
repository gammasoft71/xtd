cmake_minimum_required(VERSION 3.3)

project(minesweeper)
find_package(xtd.forms REQUIRED)
application_icon(resources/minesweeper)
add_sources(
  src/cell_state.hpp
  src/cell.hpp
  src/form_main.hpp
  src/input_name_dialog.hpp
  src/level.hpp
  src/minesweeper.cpp
)
target_type(GUI_APPLICATION)
