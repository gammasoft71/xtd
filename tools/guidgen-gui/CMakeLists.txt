cmake_minimum_required(VERSION 3.20)

# Project
project(guidgen-gui)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_sources("src/main_form.hpp")
target_type(GUI_APPLICATION)

# Install
install_component()
