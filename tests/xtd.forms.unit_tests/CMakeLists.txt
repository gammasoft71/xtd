cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.unit_tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_references(xtd.forms)
add_sources(
  src/main.cpp 
  src/xtd/forms/button.cpp 
  src/xtd/forms/check_box.cpp 
  src/xtd/forms/control.cpp 
  src/xtd/forms/form.cpp
  src/xtd/forms/lcd_label.cpp
  src/xtd/forms/list_box.cpp
  src/xtd/forms/main_menu.cpp
  src/xtd/forms/system_information.cpp
  src/xtd/forms/layout/arranged_element_collection.cpp 
)
if (APPLE)
add_sources(
  src/xtd/forms/get_double_click_time.h 
  src/xtd/forms/get_double_click_time.mm 
)
endif()
target_type(TEST_APPLICATION)
