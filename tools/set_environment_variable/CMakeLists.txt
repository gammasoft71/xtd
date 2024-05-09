cmake_minimum_required(VERSION 3.20)

# Project
project(set_environment_variable)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_sources(src/set_environment_variable.cpp)
target_type(CONSOLE_APPLICATION)

# Install
install_component()
