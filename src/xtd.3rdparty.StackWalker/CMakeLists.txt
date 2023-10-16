cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.3rdparty.StackWalker)
include("../../scripts/cmake/xtd_commands.cmake")
add_include_directories(.)
add_sources(
  StackWalker.cpp
  StackWalker.h
)
target_type(${XTD_LIBRARY_TYPE})

if (MSVC)
  add_compile_options(/wd4324)
endif()

# Install
add_install_include_directories(.)
install_component()
