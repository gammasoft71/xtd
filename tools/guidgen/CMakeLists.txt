cmake_minimum_required(VERSION 3.20)

# Project
project(guidgen)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_sources("src/guidgen.cpp")
target_type(CONSOLE_APPLICATION)

# Install
install_component()
