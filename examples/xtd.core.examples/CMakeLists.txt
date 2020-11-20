cmake_minimum_required(VERSION 3.3)

project(xtd.core.examples)
find_package(xtd REQUIRED)

add_projects(
  block_scope
  compare
  compare_ignore_case
  concat
  concat_collection
  contains
  console_background_color
  console_background_color2
  console_background_color3
  console_beep
  console_beep2
  console_beep3
  console_buffer
  console_color
  console_color2
  console_color3
  console_color4
  console_cursor
  console_in_out
  console_read_line
  console_read_line2
  console_song
  delegate
  environment_stack_trace
  event
  format
  format_with_order
  guid
  interface
  interface2
  join
  main
  main1
  main2
  main3
  main4
  main5
  split
  startup
  static
  static2
  static3
  using
  wconsole1
  wconsole2
)

add_projects(
  diagnostics
  hello_worlds
  others
)

