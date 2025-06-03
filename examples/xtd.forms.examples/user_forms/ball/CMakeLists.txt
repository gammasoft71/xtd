cmake_minimum_required(VERSION 3.20)

project(ball)
find_package(xtd REQUIRED)
add_sources(
  README.md
  src/ball.hpp
  src/ball.cpp
  src/ball_form.hpp
  src/ball_form.cpp
  src/settings_form.hpp
  src/settings_form.cpp
)
target_type(GUI_APPLICATION)
