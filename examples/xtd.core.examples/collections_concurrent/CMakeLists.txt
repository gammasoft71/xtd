cmake_minimum_required(VERSION 3.20)

project(collections_concurrent)
find_package(xtd REQUIRED)

add_projects(
  concurrent_bag
  concurrent_dictionary
  concurrent_dictionary_add_or_update
  concurrent_dictionary_add_or_update2
  concurrent_queue
  concurrent_queue2
  concurrent_stack
  concurrent_stack2
)
