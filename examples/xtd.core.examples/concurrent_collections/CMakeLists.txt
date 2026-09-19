cmake_minimum_required(VERSION 3.20)

project(concurrent_collections)
find_package(xtd REQUIRED)

add_projects(
  concurrent_bag
  concurrent_queue
  concurrent_queue2
  concurrent_stack
)
