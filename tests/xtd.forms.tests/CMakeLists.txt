cmake_minimum_required(VERSION 3.20)

project(xtd.forms.tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)

add_projects(
  xtd.forms.buttons.tests
  xtd.forms.forms.tests
  xtd.forms.labels.tests
  xtd.forms.toggle_buttons.tests
  xtd.forms.tool_bars.tests
)
