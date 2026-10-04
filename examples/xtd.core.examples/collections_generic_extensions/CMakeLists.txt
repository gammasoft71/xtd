cmake_minimum_required(VERSION 3.20)

project(collections_geneirc_extensions)
find_package(xtd REQUIRED)

add_projects(
  extensions_enumerable_iterator
  extensions_enumerable
)
