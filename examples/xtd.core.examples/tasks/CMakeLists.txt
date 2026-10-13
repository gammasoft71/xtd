cmake_minimum_required(VERSION 3.20)

project(tasks)
find_package(xtd REQUIRED)

add_projects(
  parallel_for_
  parallel_for_async
  parallel_for_each
  parallel_for_each_async
  task_completion_source
  task_delay
  task_factory
  task
  tasks
)
