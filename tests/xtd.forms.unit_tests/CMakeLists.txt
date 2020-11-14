cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.unit_tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_references(xtd.forms)
add_sources(
  src/main.cpp 
  src/forms/button.cpp 
  src/forms/check_box.cpp 
  src/forms/control.cpp 
  src/forms/form.cpp
  src/forms/lcd_label.cpp
  src/forms/list_box.cpp
  src/forms/main_menu.cpp
  src/forms/system_information.cpp
  src/forms/layout/arranged_element_collection.cpp 
)
if (APPLE)
add_sources(
  src/forms/get_double_click_time.h 
  src/forms/get_double_click_time.mm 
)
endif()
target_type(TEST_APPLICATION)
