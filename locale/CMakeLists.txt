cmake_minimum_required(VERSION 3.3)

# Project
project(locale)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

# English
add_sources(
  en/about_dialog.strings
  en/application.strings
  en/busy_box.strings
  en/checked_list_box.strings
  en/choice.strings
  en/color.strings
  en/combo_box.strings
  en/control.strings
  en/countries.strings
  en/domain_up_down.strings
  en/environment.strings
  en/exception_dialog.strings
  en/exceptions.strings
  en/font.strings
  en/font_family.strings
  en/form.strings
  en/graphics.strings
  en/guid.strings
  en/image_list.strings
  en/lcd_label.strings
  en/list_box.strings
  en/menu.strings
  en/pen.strings
  en/splitter.strings
  en/strings.strings
  en/text_box_base.strings
  en/texts.strings
  en/theme_colors.strings
  en/version.strings
)

# French
add_sources(
  fr/about_dialog.strings
  fr/application.strings
  fr/busy_box.strings
  fr/checked_list_box.strings
  fr/choice.strings
  fr/color.strings
  fr/combo_box.strings
  fr/control.strings
  fr/countries.strings
  fr/domain_up_down.strings
  fr/environment.strings
  fr/exception_dialog.strings
  fr/exceptions.strings
  fr/font.strings
  fr/font_family.strings
  fr/form.strings
  fr/graphics.strings
  fr/guid.strings
  fr/image_list.strings
  fr/lcd_label.strings
  fr/list_box.strings
  fr/menu.strings
  fr/pen.strings
  fr/splitter.strings
  fr/strings.strings
  fr/text_box_base.strings
  fr/texts.strings
  fr/theme_colors.strings
  fr/version.strings
)

target_type(INTERFACE_LIBRARY)

# Install
if (XTD_INSTALL_RESOURCES)
  install(DIRECTORY . DESTINATION share/xtd/locale)
endif ()
