cmake_minimum_required(VERSION 3.3)

project(xtd.core.examples)
find_package(xtd REQUIRED)

add_projects(
  hello_worlds
  console
  delegates
  diagnostics
  environment
  format
  guid
  keywords
  mains
  random
  sprintf
  strings
  web
  others
)

