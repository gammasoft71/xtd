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
  StackWalker.cpp
  StackWalker.h
  call_stack.hpp
  call_stack_gcc.cpp
  call_stack_msvc.cpp
  stack_exception.hpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(.)
install_component()
