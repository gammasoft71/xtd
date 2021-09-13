cmake_minimum_required(VERSION 3.3)

project(delegates)
find_package(xtd REQUIRED)

add_projects(
  action
  delegate
  delegate_lambda
  delegate_member_method
  delegate_multicast
  event
)
