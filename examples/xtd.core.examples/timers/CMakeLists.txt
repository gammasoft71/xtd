cmake_minimum_required(VERSION 3.20)

project(timers)
find_package(xtd REQUIRED)

add_projects(
  timers_timer
  timers_timer_synchronizing_object
)
