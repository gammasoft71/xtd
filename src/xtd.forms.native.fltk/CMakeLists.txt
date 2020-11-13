cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.native.fltk)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
add_include_directories(include)
add_references(xtd.forms.native ${FLTK_LIBRARIES})
add_sources(
  include/xtd/xtd.forms.native.fltk.h
  include/xtd/xtd.forms.native.fltk
  src/xtd/forms/native/fltk/application.cpp
  src/xtd/forms/native/fltk/button.cpp
  src/xtd/forms/native/fltk/check_box.cpp
  src/xtd/forms/native/fltk/checked_list_box.cpp
  src/xtd/forms/native/fltk/control.cpp
  src/xtd/forms/native/fltk/color_dialog.cpp
  src/xtd/forms/native/fltk/combo_box.cpp
  src/xtd/forms/native/fltk/control_handler.h
  src/xtd/forms/native/fltk/cursor.cpp
  src/xtd/forms/native/fltk/cursors.cpp
  src/xtd/forms/native/fltk/fl_button.h
  src/xtd/forms/native/fltk/fl_check_box.h
  src/xtd/forms/native/fltk/fl_checked_list_box.h
  src/xtd/forms/native/fltk/fl_combo_box.h
  src/xtd/forms/native/fltk/fl_control.h
  src/xtd/forms/native/fltk/fl_font_chooser.h
  src/xtd/forms/native/fltk/fl_form.h
  src/xtd/forms/native/fltk/fl_group_box.h
  src/xtd/forms/native/fltk/fl_label.h
  src/xtd/forms/native/fltk/fl_list_box.h
  src/xtd/forms/native/fltk/fl_panel.h
  src/xtd/forms/native/fltk/fl_progress_bar.h
  src/xtd/forms/native/fltk/fl_radio_button.h
  src/xtd/forms/native/fltk/fl_tab_control.h
  src/xtd/forms/native/fltk/fl_tab_page.h
  src/xtd/forms/native/fltk/fl_text_box.h
  src/xtd/forms/native/fltk/fl_timer.h
  src/xtd/forms/native/fltk/fl_track_bar.h
  src/xtd/forms/native/fltk/fl_user_control.h
  src/xtd/forms/native/fltk/font_dialog.cpp
  src/xtd/forms/native/fltk/form.cpp
  src/xtd/forms/native/fltk/group_box.cpp
  src/xtd/forms/native/fltk/label.cpp
  src/xtd/forms/native/fltk/list_box.cpp
  src/xtd/forms/native/fltk/message_box.cpp
  src/xtd/forms/native/fltk/panel.cpp
  src/xtd/forms/native/fltk/progress_bar.cpp
  src/xtd/forms/native/fltk/radio_button.cpp
  src/xtd/forms/native/fltk/screen.cpp
  src/xtd/forms/native/fltk/tab_control.cpp
  src/xtd/forms/native/fltk/tab_page.cpp
  src/xtd/forms/native/fltk/text_box.cpp
  src/xtd/forms/native/fltk/timer.cpp
  src/xtd/forms/native/fltk/track_bar.cpp
  src/xtd/forms/native/fltk/user_control.cpp
)

if (APPLE)
  add_sources(
    src/xtd/forms/native/fltk/cursor.mm
  )
endif()

target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
