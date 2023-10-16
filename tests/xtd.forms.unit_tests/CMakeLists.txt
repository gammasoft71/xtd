cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.forms.unit_tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_references(xtd.forms)
add_sources(
  src/main.cpp 
  src/xtd/forms/tests/anchor_styles_tests.cpp 
  src/xtd/forms/tests/button_base_tests.cpp 
  src/xtd/forms/tests/button_tests.cpp 
  src/xtd/forms/tests/check_box_tests.cpp 
  src/xtd/forms/tests/control_tests.cpp 
  src/xtd/forms/tests/form_tests.cpp
  src/xtd/forms/tests/keys_tests.cpp
  src/xtd/forms/tests/lcd_label_tests.cpp
  src/xtd/forms/tests/list_box_tests.cpp
  src/xtd/forms/tests/main_menu_tests.cpp
  src/xtd/forms/tests/progress_bar_tests.cpp 
  src/xtd/forms/tests/radio_button_tests.cpp 
  src/xtd/forms/tests/system_information_tests.cpp
  src/xtd/forms/tests/toggle_button_tests.cpp 
  src/xtd/forms/layout/tests/arranged_element_collection_tests.cpp 
  src/xtd/forms/style_sheets/tests/border_color_tests.cpp 
  src/xtd/forms/style_sheets/tests/background_image_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_gnome_dark_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_gnome_light_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_kde_dark_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_kde_light_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_macos_dark_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_macos_light_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_symbolic_dark_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_symbolic_light_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_windows_dark_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_windows_light_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_xtd_dark_tests.cpp 
  src/xtd/forms/style_sheets/tests/style_sheet_xtd_light_tests.cpp 
)
if (APPLE)
add_sources(
  src/xtd/forms/tests/get_double_click_time.h 
  src/xtd/forms/tests/get_double_click_time.mm 
)
endif()
target_type(TEST_APPLICATION)
