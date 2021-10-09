cmake_minimum_required(VERSION 3.3)

project(themes)
find_package(xtd REQUIRED)

add_projects(
  application_enable_dark_mode
  application_enable_light_mode
  themes
)
