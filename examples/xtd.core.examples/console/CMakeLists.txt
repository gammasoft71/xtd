cmake_minimum_required(VERSION 3.3)

project(console)
find_package(xtd REQUIRED)

add_projects(
  console_background_color
  console_beep
  console_buffer
  console_color
  console_cursor
  console_in_out
  console_read_line
  console_read_key
  console_song
  wconsole
)
