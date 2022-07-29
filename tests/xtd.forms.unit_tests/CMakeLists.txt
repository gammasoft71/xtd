cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.unit_tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_references(xtd.forms)
add_sources(
  src/main.cpp 
  src/xtd/forms/button_base_tests.cpp 
  src/xtd/forms/button_tests.cpp 
  src/xtd/forms/check_box_tests.cpp 
  src/xtd/forms/control_tests.cpp 
  src/xtd/forms/form_tests.cpp
  src/xtd/forms/lcd_label_tests.cpp
  src/xtd/forms/list_box_tests.cpp
  src/xtd/forms/main_menu_tests.cpp
  src/xtd/forms/radio_button_tests.cpp 
  src/xtd/forms/system_information_tests.cpp
  src/xtd/forms/toggle_button_tests.cpp 
  src/xtd/forms/layout/arranged_element_collection_tests.cpp 
  src/xtd/forms/style_sheets/border_color_tests.cpp 
  src/xtd/forms/style_sheets/background_image_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_gnome_dark_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_gnome_light_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_kde_dark_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_kde_light_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_macos_dark_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_macos_light_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_symbolic_dark_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_symbolic_light_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_windows_dark_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_windows_light_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_xtd_dark_tests.cpp 
  src/xtd/forms/style_sheets/style_sheet_xtd_light_tests.cpp 
)
if (APPLE)
add_sources(
  src/xtd/forms/get_double_click_time.h 
  src/xtd/forms/get_double_click_time.mm 
)
endif()
target_type(TEST_APPLICATION)
