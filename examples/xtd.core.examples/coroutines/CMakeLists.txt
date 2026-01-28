cmake_minimum_required(VERSION 3.20)

project(coroutines)
find_package(xtd REQUIRED)

add_projects(
  coroutine_delegate
  coroutine_lambda
  coroutine_method
  coroutine_task
)
