cmake_minimum_required(VERSION 3.3)

# Project
project(sleepfor)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_sources(src/sleepfor.cpp)
target_type(CONSOLE_APPLICATION)

# Install
install_component()
