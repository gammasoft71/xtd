cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.3rdparty.call_stack)
include("../../scripts/cmake/xtd_commands.cmake")
add_include_directories(.)
if(MSVC)
  add_references()
elseif (APPLE)
  add_references(dl)
elseif (ANDROID)
  add_references()
elseif (UNIX)
  add_references(dl rt)
endif ()
add_sources(
  module_information.cpp
  module_information.h
  process_information.cpp
  process_information.h
  stack_frame.cpp
  stack_frame.h
  stack_walker.cpp
  stack_walker.h
  thread_information.cpp
  thread_information.h
  call_stack.h
  call_stack_gcc.cpp
  call_stack_msvc.cpp
  stack_exception.h
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(.)
install_component()
