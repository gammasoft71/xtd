cmake_minimum_required(VERSION 3.20)

project(forms)
find_package(xtd REQUIRED)

add_projects(
  debug_form
  dialog
  form
  trace_form
)
