cmake_minimum_required(VERSION 3.20)

# Solution
project(xtd.examples)

# Find xtd package
find_package(xtd REQUIRED)

# Projects
add_projects(
  xtd.cmake.examples
  xtd.core.examples
  xtd.drawing.examples
  xtd.forms.examples
  xtd.tunit.examples
)
