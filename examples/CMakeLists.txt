cmake_minimum_required(VERSION 3.3)

project(forms_examples)
find_package(xtd.forms REQUIRED)

#build_output_directory("${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE}")

add_projects(
  hello_world_examples
  applications
  common_controls
  picker_controls
  controls
  custom_controls
  containers
  menus_and_toolbars
  datas
  components
  painting
  printing
  common_dialogs
  dialogs
  custom_dialogs
  events
  others
  tests
  demos
  games
  tutorial
)
