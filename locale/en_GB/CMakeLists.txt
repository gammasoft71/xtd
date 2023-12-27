cmake_minimum_required(VERSION 3.20)

# Project
project(en_GB)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)

add_sources(
  about_dialog.strings
  application.strings
  assert_dialog.strings
  boolean_switch.strings
  busy_box.strings
  checked_list_box.strings
  choice.strings
  color.strings
  combo_box.strings
  control.strings
  countries.strings
  css_reader.strings
  date_time.strings
  domain_up_down.strings
  enumeration.strings
  environment.strings
  exception_dialog.strings
  exceptions.strings
  font.strings
  font_family.strings
  form.strings
  graphics.strings
  guid.strings
  image_list.strings
  lcd_label.strings
  list_box.strings
  menu.strings
  message_box.strings
  paint_event_args.strings
  pen.strings
  process.strings
  splitter.strings
  strings.strings
  text_box_base.strings
  texts.strings
  theme_colors.strings
  version.strings
)

target_type(INTERFACE_LIBRARY)
