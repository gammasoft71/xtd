cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.native.wxwidgets)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
if (MSVC)
  add_compile_options(/wd5054)
elseif (APPLE)
  set(XTD_EXTRA_LIBS "-framework Cocoa")
elseif (UNIX)
  find_package(PkgConfig)
  pkg_check_modules(GTK gtk+-3.0)
  include_directories(${GTK_INCLUDE_DIRS})
  link_directories(${GTK_LIBRARY_DIRS})
  set(XTD_EXTRA_LIBS ${GTK_LIBRARIES})
endif()
find_package(wxWidgets REQUIRED COMPONENTS base core xrc)
include(${wxWidgets_USE_FILE})
add_include_directories(include)
add_references(xtd.drawing xtd.forms.native ${wxWidgets_LIBRARIES} ${XTD_EXTRA_LIBS})
add_sources(
  include/xtd/xtd.forms.native.wxwidgets.h
  include/xtd/xtd.forms.native.wxwidgets
  include/xtd/forms/native/wxwidgets/control_handler.h
  include/xtd/forms/native/wxwidgets/dark_mode.h
  include/xtd/forms/native/wxwidgets/wx_button.h
  include/xtd/forms/native/wxwidgets/wx_check_box.h
  include/xtd/forms/native/wxwidgets/wx_checked_list_box.h
  include/xtd/forms/native/wxwidgets/wx_choice.h
  include/xtd/forms/native/wxwidgets/wx_collapsible_panel.h
  include/xtd/forms/native/wxwidgets/wx_color_picker.h
  include/xtd/forms/native/wxwidgets/wx_combo_box.h
  include/xtd/forms/native/wxwidgets/wx_command_link_button.h
  include/xtd/forms/native/wxwidgets/wx_control.h
  include/xtd/forms/native/wxwidgets/wx_date_time_picker.h
  include/xtd/forms/native/wxwidgets/wx_domain_up_down.h
  include/xtd/forms/native/wxwidgets/wx_font_picker.h
  include/xtd/forms/native/wxwidgets/wx_form.h
  include/xtd/forms/native/wxwidgets/wx_group_box.h
  include/xtd/forms/native/wxwidgets/wx_label.h
  include/xtd/forms/native/wxwidgets/wx_list_box.h
  include/xtd/forms/native/wxwidgets/wx_loading_indicator.h
  include/xtd/forms/native/wxwidgets/wx_menu.h
  include/xtd/forms/native/wxwidgets/wx_numeric_up_down.h
  include/xtd/forms/native/wxwidgets/wx_panel.h
  include/xtd/forms/native/wxwidgets/wx_picture_box.h
  include/xtd/forms/native/wxwidgets/wx_progress_bar.h
  include/xtd/forms/native/wxwidgets/wx_radio_button.h
  include/xtd/forms/native/wxwidgets/wx_scroll_bar.h
  include/xtd/forms/native/wxwidgets/wx_switch_button.h
  include/xtd/forms/native/wxwidgets/wx_tab_control.h
  include/xtd/forms/native/wxwidgets/wx_tab_page.h
  include/xtd/forms/native/wxwidgets/wx_text_box.h
  include/xtd/forms/native/wxwidgets/wx_timer.h
  include/xtd/forms/native/wxwidgets/wx_toggle_button.h
  include/xtd/forms/native/wxwidgets/wx_track_bar.h
  include/xtd/forms/native/wxwidgets/wx_up_down_button.h
  include/xtd/forms/native/wxwidgets/wx_user_control.h
  include/xtd/forms/native/wxwidgets/wx_user_window.h
  src/xtd/forms/native/wxwidgets/about_dialog.cpp
  src/xtd/forms/native/wxwidgets/application.cpp
  src/xtd/forms/native/wxwidgets/busy_dialog.cpp
  src/xtd/forms/native/wxwidgets/button.cpp
  src/xtd/forms/native/wxwidgets/check_box.cpp
  src/xtd/forms/native/wxwidgets/checked_list_box.cpp
  src/xtd/forms/native/wxwidgets/choice.cpp
  src/xtd/forms/native/wxwidgets/collapsible_panel.cpp
  src/xtd/forms/native/wxwidgets/color_dialog.cpp
  src/xtd/forms/native/wxwidgets/color_picker.cpp
  src/xtd/forms/native/wxwidgets/combo_box.cpp
  src/xtd/forms/native/wxwidgets/command_link_button.cpp
  src/xtd/forms/native/wxwidgets/context_menu.cpp
  src/xtd/forms/native/wxwidgets/control.cpp
  src/xtd/forms/native/wxwidgets/cursor.cpp
  src/xtd/forms/native/wxwidgets/cursors.cpp
  src/xtd/forms/native/wxwidgets/dark_mode.cpp
  src/xtd/forms/native/wxwidgets/date_time_picker.cpp
  src/xtd/forms/native/wxwidgets/domain_up_down.cpp
  src/xtd/forms/native/wxwidgets/file_dialog.cpp
  src/xtd/forms/native/wxwidgets/folder_browser_dialog.cpp
  src/xtd/forms/native/wxwidgets/font_dialog.cpp
  src/xtd/forms/native/wxwidgets/font_picker.cpp
  src/xtd/forms/native/wxwidgets/form.cpp
  src/xtd/forms/native/wxwidgets/group_box.cpp
  src/xtd/forms/native/wxwidgets/gtk_settings.cpp
  src/xtd/forms/native/wxwidgets/image_list.cpp
  src/xtd/forms/native/wxwidgets/input_dialog.cpp
  src/xtd/forms/native/wxwidgets/label.cpp
  src/xtd/forms/native/wxwidgets/list_box.cpp
  src/xtd/forms/native/wxwidgets/loading_indicator.cpp
  src/xtd/forms/native/wxwidgets/main_menu.cpp
  src/xtd/forms/native/wxwidgets/menu.cpp
  src/xtd/forms/native/wxwidgets/menu_item.cpp
  src/xtd/forms/native/wxwidgets/message_box.cpp
  src/xtd/forms/native/wxwidgets/numeric_up_down.cpp
  src/xtd/forms/native/wxwidgets/panel.cpp
  src/xtd/forms/native/wxwidgets/picture_box.cpp
  src/xtd/forms/native/wxwidgets/progress_bar.cpp
  src/xtd/forms/native/wxwidgets/progress_dialog.cpp
  src/xtd/forms/native/wxwidgets/radio_button.cpp
  src/xtd/forms/native/wxwidgets/scroll_bar.cpp
  src/xtd/forms/native/wxwidgets/screen.cpp
  src/xtd/forms/native/wxwidgets/settings.cpp
  src/xtd/forms/native/wxwidgets/switch_button.cpp
  src/xtd/forms/native/wxwidgets/system_information.cpp
  src/xtd/forms/native/wxwidgets/tab_control.cpp
  src/xtd/forms/native/wxwidgets/tab_page.cpp
  src/xtd/forms/native/wxwidgets/text_box.cpp
  src/xtd/forms/native/wxwidgets/timer.cpp
  src/xtd/forms/native/wxwidgets/toggle_button.cpp
  src/xtd/forms/native/wxwidgets/toolkit.cpp
  src/xtd/forms/native/wxwidgets/track_bar.cpp
  src/xtd/forms/native/wxwidgets/up_down_button.cpp
  src/xtd/forms/native/wxwidgets/user_control.cpp
  src/xtd/forms/window_messages.cpp
)

if (APPLE)
add_sources(
    src/xtd/forms/native/wxwidgets/application.mm
    src/xtd/forms/native/wxwidgets/button.mm
    src/xtd/forms/native/wxwidgets/cursor.mm
    src/xtd/forms/native/wxwidgets/form.mm
    src/xtd/forms/native/wxwidgets/message_box.mm
  )
endif()
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
