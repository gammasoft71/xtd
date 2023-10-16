cmake_minimum_required(VERSION 3.20)

project(forms)
find_package(xtd REQUIRED)

add_projects(
  circular_form
  debug_form
  dialog
  form
  popup_form
  trace_form
)
