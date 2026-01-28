cmake_minimum_required(VERSION 3.20)

project(tasks)
find_package(xtd REQUIRED)

add_projects(
  tasks
  task
  task_delay
)
