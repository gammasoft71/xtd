cmake_minimum_required(VERSION 3.20)

# Project
project(xtdc-gui)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_sources(
  "src/main_form.hpp"
  "src/main_form.cpp"
  "src/project_language.hpp"
  "src/project_platform.hpp"
  "src/project_sdk.hpp"
  "src/project_type.hpp"
  "src/project_type_item.hpp"
  "src/project_type_item_control.hpp"
  "src/project_type_item_control.cpp"
  "src/project_type_items_control.hpp"
  "src/settings_form.hpp"
  "src/settings_form.cpp"
  "src/xtd_example_item.hpp"
)
target_type(GUI_APPLICATION)

# Install
install_component()
