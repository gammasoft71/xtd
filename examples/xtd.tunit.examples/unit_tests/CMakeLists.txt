cmake_minimum_required(VERSION 3.20)

project(unit_tests)
find_package(xtd REQUIRED)

add_projects(
  assert_syntax
  console_unit_test
  ostream_unit_test
)
