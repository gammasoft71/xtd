cmake_minimum_required(VERSION 3.5)

project(threading)
find_package(xtd REQUIRED)

add_projects(
  auto_reset_event
  event_wait_handle
  interlocked
  interlocked_decrement
  manual_reset_event
  mixing_std_and_xtd_threads
  monitor
  mutex
  semaphore
  thread
  thread_pool
  timeout
  timer
  wait_handle
)
