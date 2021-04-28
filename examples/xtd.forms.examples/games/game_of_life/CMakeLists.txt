cmake_minimum_required(VERSION 3.3)

project(game_of_life)
find_package(xtd REQUIRED)
add_sources(
  src/cell.h
  src/game_of_life.h
  src/grid.h
)
target_type(GUI_APPLICATION)
