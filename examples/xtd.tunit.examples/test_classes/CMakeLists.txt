cmake_minimum_required(VERSION 3.5)

project(test_classes)
find_package(xtd REQUIRED)

add_projects(
  generic_test_class
  test_class
  test_class_without_helpers
)
