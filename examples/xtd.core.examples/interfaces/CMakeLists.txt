cmake_minimum_required(VERSION 3.20)

project(interfaces)
find_package(xtd REQUIRED)

add_projects(
  iformatable
  iobservable_iobserver
  iprogress
)

