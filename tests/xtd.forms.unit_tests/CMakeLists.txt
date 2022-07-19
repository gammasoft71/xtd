cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.unit_tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_references(xtd.forms)
add_sources(
  src/main.cpp 
  src/xtd/forms/button_base.cpp 
  src/xtd/forms/button.cpp 
  src/xtd/forms/check_box.cpp 
  src/xtd/forms/control.cpp 
  src/xtd/forms/form.cpp
  src/xtd/forms/lcd_label.cpp
  src/xtd/forms/list_box.cpp
  src/xtd/forms/main_menu.cpp
  src/xtd/forms/radio_button.cpp 
  src/xtd/forms/system_information.cpp
  src/xtd/forms/toggle_button.cpp 
  src/xtd/forms/layout/arranged_element_collection.cpp 
  src/xtd/forms/style_sheets/border_color.cpp 
  src/xtd/forms/style_sheets/background_image.cpp 
  src/xtd/forms/style_sheets/style_sheet.cpp 
  src/xtd/forms/style_sheets/style_sheet_gnome_dark.cpp 
  src/xtd/forms/style_sheets/style_sheet_gnome_light.cpp 
  src/xtd/forms/style_sheets/style_sheet_kde_dark.cpp 
  src/xtd/forms/style_sheets/style_sheet_kde_light.cpp 
  src/xtd/forms/style_sheets/style_sheet_macos_dark.cpp 
  src/xtd/forms/style_sheets/style_sheet_macos_light.cpp 
  src/xtd/forms/style_sheets/style_sheet_symbolic_dark.cpp 
  src/xtd/forms/style_sheets/style_sheet_symbolic_light.cpp 
  src/xtd/forms/style_sheets/style_sheet_windows_dark.cpp 
  src/xtd/forms/style_sheets/style_sheet_windows_light.cpp 
  src/xtd/forms/style_sheets/style_sheet_xtd_dark.cpp 
  src/xtd/forms/style_sheets/style_sheet_xtd_light.cpp 
)
if (APPLE)
add_sources(
  src/xtd/forms/get_double_click_time.h 
  src/xtd/forms/get_double_click_time.mm 
)
endif()
target_type(TEST_APPLICATION)
