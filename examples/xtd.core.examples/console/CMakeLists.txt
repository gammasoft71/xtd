cmake_minimum_required(VERSION 3.20)

project(console)
find_package(xtd REQUIRED)

add_projects(
  console_background_color
  console_beep
  console_buffer
  console_clear
  console_color
  console_cursor
  console_cursor_size
  console_cursor_visible
  console_firework
  console_in_out
  console_info
  console_key_available
  console_out
  console_read
  console_read_line
  console_read_key
  console_song
  console_title
  console_unicode
  console_window_size
  redirect_output
  wconsole
)
