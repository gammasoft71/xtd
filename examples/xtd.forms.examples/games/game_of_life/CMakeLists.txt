cmake_minimum_required(VERSION 3.20)

project(game_of_life)
find_package(xtd REQUIRED)
add_sources(
  src/cell.hpp
  src/game_of_life.hpp
  src/grid.hpp
)
target_type(GUI_APPLICATION)
