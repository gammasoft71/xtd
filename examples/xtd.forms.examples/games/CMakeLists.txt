cmake_minimum_required(VERSION 3.20)

project(games)
find_package(xtd REQUIRED)

add_projects(
  game_of_life
  minesweeper
)
