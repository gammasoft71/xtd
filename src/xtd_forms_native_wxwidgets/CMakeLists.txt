cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.native.wxwidgets VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.forms.native.wxwidgets.h
  include/xtd/xtd.forms.native.wxwidgets
  include/xtd/forms/native/wxwidgets/control_handler.h
  include/xtd/forms/native/wxwidgets/dark_mode.h
  include/xtd/forms/native/wxwidgets/hdc_wrapper.h
  include/xtd/forms/native/wxwidgets/wx_application.h
  include/xtd/forms/native/wxwidgets/wx_button.h
  include/xtd/forms/native/wxwidgets/wx_check_box.h
  include/xtd/forms/native/wxwidgets/wx_checked_list_box.h
  include/xtd/forms/native/wxwidgets/wx_choice.h
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
  include/xtd/forms/native/wxwidgets/wx_menu.h
  include/xtd/forms/native/wxwidgets/wx_numeric_up_down.h
  include/xtd/forms/native/wxwidgets/wx_panel.h
  include/xtd/forms/native/wxwidgets/wx_picture_box.h
  include/xtd/forms/native/wxwidgets/wx_progress_bar.h
  include/xtd/forms/native/wxwidgets/wx_radio_button.h
  include/xtd/forms/native/wxwidgets/wx_tab_control.h
  include/xtd/forms/native/wxwidgets/wx_tab_page.h
  include/xtd/forms/native/wxwidgets/wx_text_box.h
  include/xtd/forms/native/wxwidgets/wx_timer.h
  include/xtd/forms/native/wxwidgets/wx_track_bar.h
  include/xtd/forms/native/wxwidgets/wx_up_down_button.h
  include/xtd/forms/native/wxwidgets/wx_user_control.h
)

set(XTD_FORMS_NATIVE_WXWIDGETS_SOURCES
  src/xtd/forms/native/wxwidgets/about_dialog.cpp
  src/xtd/forms/native/wxwidgets/application.cpp
  src/xtd/forms/native/wxwidgets/button.cpp
  src/xtd/forms/native/wxwidgets/check_box.cpp
  src/xtd/forms/native/wxwidgets/checked_list_box.cpp
  src/xtd/forms/native/wxwidgets/choice.cpp
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
  src/xtd/forms/native/wxwidgets/input_box.cpp
  src/xtd/forms/native/wxwidgets/label.cpp
  src/xtd/forms/native/wxwidgets/list_box.cpp
  src/xtd/forms/native/wxwidgets/main_menu.cpp
  src/xtd/forms/native/wxwidgets/menu.cpp
  src/xtd/forms/native/wxwidgets/menu_item.cpp
  src/xtd/forms/native/wxwidgets/message_box.cpp
  src/xtd/forms/native/wxwidgets/numeric_up_down.cpp
  src/xtd/forms/native/wxwidgets/panel.cpp
  src/xtd/forms/native/wxwidgets/picture_box.cpp
  src/xtd/forms/native/wxwidgets/progress_bar.cpp
  src/xtd/forms/native/wxwidgets/radio_button.cpp
  src/xtd/forms/native/wxwidgets/screen.cpp
  src/xtd/forms/native/wxwidgets/settings.cpp
  src/xtd/forms/native/wxwidgets/system_information.cpp
  src/xtd/forms/native/wxwidgets/tab_control.cpp
  src/xtd/forms/native/wxwidgets/tab_page.cpp
  src/xtd/forms/native/wxwidgets/text_box.cpp
  src/xtd/forms/native/wxwidgets/timer.cpp
  src/xtd/forms/native/wxwidgets/toggle_button.cpp
  src/xtd/forms/native/wxwidgets/track_bar.cpp
  src/xtd/forms/native/wxwidgets/up_down_button.cpp
  src/xtd/forms/native/wxwidgets/user_control.cpp
)

if (APPLE)
  set(XTD_FORMS_NATIVE_WXWIDGETS_SOURCES ${XTD_FORMS_NATIVE_WXWIDGETS_SOURCES}
    src/xtd/forms/native/wxwidgets/application.mm
    src/xtd/forms/native/wxwidgets/button.mm
    src/xtd/forms/native/wxwidgets/cursor.mm
    src/xtd/forms/native/wxwidgets/message_box.mm
  )
endif()

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(src\\xtd\\forms\\native\\wxwidgets FILES ${XTD_FORMS_NATIVE_WXWIDGETS_SOURCES})

# Add packages
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

if (APPLE)
  set(XTD_EXTRA_LIBS "-framework Cocoa")
elseif (UNIX)
  find_package(PkgConfig)
  pkg_check_modules(GTK gtk+-3.0)
  include_directories(${GTK_INCLUDE_DIRS})
  link_directories(${GTK_LIBRARY_DIRS})
  set(XTD_EXTRA_LIBS ${GTK_LIBRARIES})
endif()

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_NATIVE_WXWIDGETS_SOURCES})
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.forms.native ${wxWidgets_LIBRARIES} ${XTD_EXTRA_LIBS})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
