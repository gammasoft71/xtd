cmake_minimum_required(VERSION 3.20)

project(delegates)
find_package(xtd REQUIRED)

add_projects(
  action
  action1
  action2
  action3
  delegate
  delegate_begin_invoke
  delegate_begin_invoke2
  delegate_lambda
  delegate_member_method
  delegate_multicast
  event
)
