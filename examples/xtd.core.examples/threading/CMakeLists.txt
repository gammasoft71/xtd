cmake_minimum_required(VERSION 3.5)

project(threading)
find_package(xtd REQUIRED)

add_projects(
  auto_reset_event
  barrier
  barrier_simple
  event_wait_handle
  interlocked
  interlocked_decrement
  lock_guard
  manual_reset_event
  mixing_std_and_xtd_threads
  monitor
  monitor_lock
  mutex
  semaphore
  thread
  thread_pool
  timeout
  timer
  wait_handle
)
