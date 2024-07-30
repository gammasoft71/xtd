cmake_minimum_required(VERSION 3.20)

project(generic_collections)
find_package(xtd REQUIRED)

add_projects(
  generic_ienumerable
  generic_ienumerator
)
