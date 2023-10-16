cmake_minimum_required(VERSION 3.20)

project(menus_and_toolbars)
find_package(xtd REQUIRED)

add_projects(
  context_menu
  main_menu
#  context_menu_strip
#  menu_strip
  status_bar
#  status_strip
  tool_bar
#  tool_strip
# tool_strip_container
)
