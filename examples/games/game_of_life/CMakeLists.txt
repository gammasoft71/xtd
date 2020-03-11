cmake_minimum_required(VERSION 3.3)

project(game_of_life)
find_package(xtd.forms REQUIRED)
add_sources(
  src/game_of_life.cpp
  src/cell.h
  src/form_main.h
  src/grid.h
  src/cell_event_args.h
  src/cell_event_handler.h
)
target_type(GUI_APPLICATION)
