cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.native VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.forms.native.h
  include/xtd/xtd.forms.native
)

set(XTD_FORMS_INCLUDES
  include/xtd/forms/create_params.h
  include/xtd/forms/color_dialog_flags.h
  include/xtd/forms/file_dialog_flags.h
  include/xtd/forms/folder_browser_dialog_flags.h
  include/xtd/forms/font_dialog_flags.h
  include/xtd/forms/window_messages.h
)

set(XTD_FORMS_NATIVE_INCLUDES
  include/xtd/forms/native/about_dialog.h
  include/xtd/forms/native/application.h
 include/xtd/forms/native/arranged_direction_window.h
  include/xtd/forms/native/button.h
  include/xtd/forms/native/button_styles.h
  include/xtd/forms/native/check_box.h
  include/xtd/forms/native/checked_list_box.h
  include/xtd/forms/native/choice.h
  include/xtd/forms/native/class_styles.h
  include/xtd/forms/native/color_dialog.h
  include/xtd/forms/native/color_picker.h
  include/xtd/forms/native/combo_box.h
  include/xtd/forms/native/combo_box_styles.h
  include/xtd/forms/native/context_menu.h
  include/xtd/forms/native/content_alignment.h
  include/xtd/forms/native/control.h
  include/xtd/forms/native/cursor.h
  include/xtd/forms/native/cursors.h
  include/xtd/forms/native/date_time_picker.h
  include/xtd/forms/native/date_time_picker_styles.h
  include/xtd/forms/native/domain_up_down.h
  include/xtd/forms/native/file_dialog.h
  include/xtd/forms/native/folder_browser_dialog.h
  include/xtd/forms/native/font_dialog.h
  include/xtd/forms/native/font_picker.h
  include/xtd/forms/native/form.h
  include/xtd/forms/native/group_box.h
  include/xtd/forms/native/image_list.h
  include/xtd/forms/native/label.h
  include/xtd/forms/native/list_box.h
  include/xtd/forms/native/list_box_styles.h
  include/xtd/forms/native/main_menu.h
  include/xtd/forms/native/menu.h
  include/xtd/forms/native/menu_item.h
  include/xtd/forms/native/message_box.h
  include/xtd/forms/native/message_box_styles.h
  include/xtd/forms/native/message_keys.h
  include/xtd/forms/native/numeric_up_down.h
  include/xtd/forms/native/panel.h
  include/xtd/forms/native/picture_box.h
  include/xtd/forms/native/progress_bar.h
  include/xtd/forms/native/progress_bar_styles.h
  include/xtd/forms/native/radio_button.h
  include/xtd/forms/native/screen.h
  include/xtd/forms/native/scroll_bar_styles.h
  include/xtd/forms/native/settings.h
  include/xtd/forms/native/static_styles.h
  include/xtd/forms/native/system_information.h
  include/xtd/forms/native/tab_control.h
  include/xtd/forms/native/tab_control_styles.h
  include/xtd/forms/native/tab_page.h
  include/xtd/forms/native/text_box.h
  include/xtd/forms/native/text_box_styles.h
  include/xtd/forms/native/timer.h
  include/xtd/forms/native/track_bar.h
  include/xtd/forms/native/track_bar_styles.h
  include/xtd/forms/native/up_down_button.h
  include/xtd/forms/native/up_down_styles.h
  include/xtd/forms/native/user_control.h
  include/xtd/forms/native/virtual_keys.h
  include/xtd/forms/native/window_styles.h
)

set(SOURCES
  src/xtd.forms.native.cpp
)

set(XTD_FORMS_NATIVE_SOURCES
  src/xtd/forms/window_messages.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\forms FILES ${XTD_FORMS_INCLUDES})
source_group(include\\xtd\\forms\\native FILES ${XTD_FORMS_NATIVE_INCLUDES})
source_group(src FILES ${SOURCES})
source_group(src\\xtd\\forms\\native FILES ${XTD_FORMS_NATIVE_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_INCLUDES} ${XTD_FORMS_NATIVE_INCLUDES} ${SOURCES} ${XTD_FORMS_NATIVE_SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.delegates xtd.diagnostics xtd.drawing xtd.core xtd.io xtd.strings)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
