cmake_minimum_required(VERSION 3.3)

project(game_of_life)
find_package(xtd.forms REQUIRED)
add_sources(
  src/game_of_life.cpp
  src/cell.hpp
  src/form_main.hpp
  src/grid.hpp
  src/cell_event_args.hpp
  src/cell_event_handler.hpp
)
target_type(GUI_APPLICATION)
