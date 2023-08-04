cmake_minimum_required(VERSION 3.5)

project(threading)
find_package(xtd REQUIRED)

add_projects(
  auto_reset_event
  interlocked
  interlocked_decrement
)
