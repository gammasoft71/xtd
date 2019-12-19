cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.forms.hpp
  include/xtd/xtd.forms
)

set(XTD_FORMS_INCLUDES
  include/xtd/forms/anchor_styles.hpp
  include/xtd/forms/appearance.hpp
  include/xtd/forms/application.hpp
  include/xtd/forms/application_context.hpp
  include/xtd/forms/application_informations.hpp
  include/xtd/forms/arrange_direction.hpp
  include/xtd/forms/arrange_starting_position.hpp
  include/xtd/forms/auto_size_mode.hpp
  include/xtd/forms/background_worker.hpp
  include/xtd/forms/boot_mode.hpp
  include/xtd/forms/border_style.hpp
  include/xtd/forms/bounds_specified.hpp
  include/xtd/forms/button.hpp
  include/xtd/forms/button_base.hpp
  include/xtd/forms/cancel_event_args.hpp
  include/xtd/forms/cancel_event_handler.hpp
  include/xtd/forms/check_box.hpp
  include/xtd/forms/check_state.hpp
  include/xtd/forms/checked_list_box.hpp
  include/xtd/forms/choice.hpp
  include/xtd/forms/close_reason.hpp
  include/xtd/forms/color_dialog.hpp
  include/xtd/forms/combo_box.hpp
  include/xtd/forms/combo_box_style.hpp
  include/xtd/forms/common_dialog.hpp
  include/xtd/forms/component.hpp
  include/xtd/forms/container_control.hpp
  include/xtd/forms/content_alignment.hpp
  include/xtd/forms/context_menu.hpp
  include/xtd/forms/control.hpp
  include/xtd/forms/control_event_args.hpp
  include/xtd/forms/control_event_handler.hpp
  include/xtd/forms/control_styles.hpp
  include/xtd/forms/cursor.hpp
  include/xtd/forms/cursors.hpp
  include/xtd/forms/dialog_result.hpp
  include/xtd/forms/do_work_event_args.hpp
  include/xtd/forms/do_work_event_handler.hpp
  include/xtd/forms/dock_style.hpp
  include/xtd/forms/domain_up_down.hpp
  include/xtd/forms/file_dialog.hpp
  include/xtd/forms/folder_browser_dialog.hpp
  include/xtd/forms/font_dialog.hpp
  include/xtd/forms/form.hpp
  include/xtd/forms/form_border_style.hpp
  include/xtd/forms/form_closed_event_args.hpp
  include/xtd/forms/form_closed_event_handler.hpp
  include/xtd/forms/form_closing_event_args.hpp
  include/xtd/forms/form_closing_event_handler.hpp
  include/xtd/forms/form_start_position.hpp
  include/xtd/forms/form_window_state.hpp
  include/xtd/forms/fourteen_segment_display.hpp
  include/xtd/forms/group_box.hpp
  include/xtd/forms/help_event_args.hpp
  include/xtd/forms/help_event_handler.hpp
  include/xtd/forms/ibutton_control.hpp
  include/xtd/forms/image_list.hpp
  include/xtd/forms/imessage_filter.hpp
  include/xtd/forms/item_check_event_args.hpp
  include/xtd/forms/item_check_event_handler.hpp
  include/xtd/forms/iwin32_window.hpp
  include/xtd/forms/key_event_args.hpp
  include/xtd/forms/key_event_handler.hpp
  include/xtd/forms/key_press_event_args.hpp
  include/xtd/forms/key_press_event_handler.hpp
  include/xtd/forms/keys.hpp
  include/xtd/forms/label.hpp
  include/xtd/forms/lcd_label.hpp
  include/xtd/forms/lcd_style.hpp
  include/xtd/forms/list_box.hpp
  include/xtd/forms/list_control.hpp
  include/xtd/forms/main_menu.hpp
  include/xtd/forms/menu.hpp
  include/xtd/forms/menu_item.hpp
  include/xtd/forms/message.hpp
  include/xtd/forms/message_box.hpp
  include/xtd/forms/message_box_buttons.hpp
  include/xtd/forms/message_box_default_button.hpp
  include/xtd/forms/message_box_icon.hpp
  include/xtd/forms/message_box_options.hpp
  include/xtd/forms/message_loop_callback.hpp
  include/xtd/forms/mouse_buttons.hpp
  include/xtd/forms/mouse_event_args.hpp
  include/xtd/forms/mouse_event_handler.hpp
  include/xtd/forms/nine_segment_display.hpp
  include/xtd/forms/numeric_up_down.hpp
  include/xtd/forms/open_file_dialog.hpp
  include/xtd/forms/orientation.hpp
  include/xtd/forms/paint_event_args.hpp
  include/xtd/forms/paint_event_handler.hpp
  include/xtd/forms/panel.hpp
  include/xtd/forms/picture_box.hpp
  include/xtd/forms/picture_box_size_mode.hpp
  include/xtd/forms/progress_bar.hpp
  include/xtd/forms/progress_bar_style.hpp
  include/xtd/forms/progress_changed_event_args.hpp
  include/xtd/forms/progress_changed_event_handler.hpp
  include/xtd/forms/radio_button.hpp
  include/xtd/forms/run_worker_completed_event_args.hpp
  include/xtd/forms/run_worker_completed_event_handler.hpp
  include/xtd/forms/save_file_dialog.hpp
  include/xtd/forms/scroll_bar.hpp
  include/xtd/forms/scrollable_control.hpp
  include/xtd/forms/screen.hpp
  include/xtd/forms/selection_mode.hpp
  include/xtd/forms/segment_style.hpp
  include/xtd/forms/segments.hpp
  include/xtd/forms/seven_segment_display.hpp
  include/xtd/forms/switch_button.hpp
  include/xtd/forms/system_information.hpp
  include/xtd/forms/tab_alignment.hpp
  include/xtd/forms/tab_control.hpp
  include/xtd/forms/tab_page.hpp
  include/xtd/forms/text_box_base.hpp
  include/xtd/forms/text_box.hpp
  include/xtd/forms/tick_style.hpp
  include/xtd/forms/timer.hpp
  include/xtd/forms/track_bar.hpp
  include/xtd/forms/up_down_base.hpp
  include/xtd/forms/up_down_button.hpp
  include/xtd/forms/user_control.hpp
)

set(XTD_FORMS_LAYOUT_INCLUDES
  include/xtd/forms/layout/arranged_element_collection.hpp
)

set(XTD_FORMS_SOURCES
  src/xtd/forms/application.cpp
  src/xtd/forms/background_worker.cpp
  src/xtd/forms/button.cpp
  src/xtd/forms/button_base.cpp
  src/xtd/forms/check_box.cpp
  src/xtd/forms/checked_list_box.cpp
  src/xtd/forms/choice.cpp
  src/xtd/forms/color_dialog.cpp
  src/xtd/forms/combo_box.cpp
  src/xtd/forms/container_control.cpp
  src/xtd/forms/context_menu.cpp
  src/xtd/forms/control.cpp
  src/xtd/forms/cursor.cpp
  src/xtd/forms/cursors.cpp
  src/xtd/forms/domain_up_down.cpp
  src/xtd/forms/file_dialog.cpp
  src/xtd/forms/folder_browser_dialog.cpp
  src/xtd/forms/font_dialog.cpp
  src/xtd/forms/form.cpp
  src/xtd/forms/group_box.cpp
  src/xtd/forms/image_list.cpp
  src/xtd/forms/label.cpp
  src/xtd/forms/list_box.cpp
  src/xtd/forms/list_control.cpp
  src/xtd/forms/main_menu.cpp
  src/xtd/forms/menu.cpp
  src/xtd/forms/menu_item.cpp
  src/xtd/forms/message.cpp
  src/xtd/forms/message_box.cpp
  src/xtd/forms/mouse_event_args.cpp
  src/xtd/forms/numeric_up_down.cpp
  src/xtd/forms/open_file_dialog.cpp
  src/xtd/forms/paint_event_args.cpp
  src/xtd/forms/panel.cpp
  src/xtd/forms/picture_box.cpp
  src/xtd/forms/progress_bar.cpp
  src/xtd/forms/radio_button.cpp
  src/xtd/forms/save_file_dialog.cpp
  src/xtd/forms/screen.cpp
  src/xtd/forms/scrollable_control.cpp
  src/xtd/forms/system_information.cpp
  src/xtd/forms/tab_control.cpp
  src/xtd/forms/tab_page.cpp
  src/xtd/forms/text_box.cpp
  src/xtd/forms/timer.cpp
  src/xtd/forms/track_bar.cpp
  src/xtd/forms/up_down_base.cpp
  src/xtd/forms/up_down_button.cpp
  src/xtd/forms/user_control.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\forms FILES ${XTD_FORMS_INCLUDES})
source_group(include\\xtd\\forms\\layout FILES ${XTD_FORMS_LAYOUT_INCLUDES})
source_group(src\\xtd\\forms FILES ${XTD_FORMS_SOURCES})
source_group(src\\native FILES ${NATIVE_SOURCES})
source_group(src\\native\\wxwidgets FILES ${NATIVE_WXWIDGETS_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_INCLUDES} ${XTD_FORMS_LAYOUT_INCLUDES} ${XTD_FORMS_SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.delegates xtd.diagnostics xtd.drawing xtd.core ${XTD_FORMS_NATIVE_LIBRARY} xtd.io xtd.strings)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS xtd.forms EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
