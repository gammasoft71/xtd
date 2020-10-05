cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.forms.h
  include/xtd/xtd.forms
)

set(XTD_FORMS_INCLUDES
  include/xtd/forms/about_dialog.h
  include/xtd/forms/anchor_styles.h
  include/xtd/forms/appearance.h
  include/xtd/forms/application.h
  include/xtd/forms/application_context.h
  include/xtd/forms/application_informations.h
  include/xtd/forms/arrange_direction.h
  include/xtd/forms/arrange_starting_position.h
  include/xtd/forms/auto_size_mode.h
  include/xtd/forms/background_worker.h
  include/xtd/forms/boot_mode.h
  include/xtd/forms/border_style.h
  include/xtd/forms/bounds_specified.h
  include/xtd/forms/button.h
  include/xtd/forms/button_base.h
  include/xtd/forms/button_images.h
  include/xtd/forms/button_renderer.h
  include/xtd/forms/buttons.h
  include/xtd/forms/cancel_event_args.h
  include/xtd/forms/cancel_event_handler.h
  include/xtd/forms/check_box.h
  include/xtd/forms/check_box_renderer.h
  include/xtd/forms/check_boxes.h
  include/xtd/forms/check_state.h
  include/xtd/forms/checked_list_box.h
  include/xtd/forms/choice.h
  include/xtd/forms/close_reason.h
  include/xtd/forms/color_dialog.h
  include/xtd/forms/color_picker.h
  include/xtd/forms/combo_box.h
  include/xtd/forms/combo_box_style.h
  include/xtd/forms/command_link_button.h
  include/xtd/forms/common_dialog.h
  include/xtd/forms/component.h
  include/xtd/forms/container_control.h
  include/xtd/forms/content_alignment.h
  include/xtd/forms/context_menu.h
  include/xtd/forms/control.h
  include/xtd/forms/control_event_args.h
  include/xtd/forms/control_event_handler.h
  include/xtd/forms/control_paint.h
  include/xtd/forms/control_styles.h
  include/xtd/forms/control_trace_listener.h
  include/xtd/forms/countries.h
  include/xtd/forms/country.h
  include/xtd/forms/cursor.h
  include/xtd/forms/cursors.h
  include/xtd/forms/date_time_picker.h
  include/xtd/forms/date_time_picker_format.h
  include/xtd/forms/debug_form.h
  include/xtd/forms/dialog_result.h
  include/xtd/forms/dialog_style.h
  include/xtd/forms/do_work_event_args.h
  include/xtd/forms/do_work_event_handler.h
  include/xtd/forms/dock_style.h
  include/xtd/forms/domain_up_down.h
  include/xtd/forms/dot_matrix_display.h
  include/xtd/forms/dot_matrix_style.h
  include/xtd/forms/emoticon.h
  include/xtd/forms/emoticons.h
  include/xtd/forms/file_dialog.h
  include/xtd/forms/flat_style.h
  include/xtd/forms/folder_browser_dialog.h
  include/xtd/forms/font_dialog.h
  include/xtd/forms/font_picker.h
  include/xtd/forms/form.h
  include/xtd/forms/form_border_style.h
  include/xtd/forms/form_button_images.h
  include/xtd/forms/form_closed_event_args.h
  include/xtd/forms/form_closed_event_handler.h
  include/xtd/forms/form_closing_event_args.h
  include/xtd/forms/form_closing_event_handler.h
  include/xtd/forms/form_start_position.h
  include/xtd/forms/form_window_state.h
  include/xtd/forms/fourteen_segment_display.h
  include/xtd/forms/group_box.h
  include/xtd/forms/help_event_args.h
  include/xtd/forms/help_event_handler.h
  include/xtd/forms/ibutton_control.h
  include/xtd/forms/icontrol_trace.h
  include/xtd/forms/image_list.h
  include/xtd/forms/imessage_filter.h
  include/xtd/forms/input_box.h
  include/xtd/forms/item_check_event_args.h
  include/xtd/forms/item_check_event_handler.h
  include/xtd/forms/iwin32_window.h
  include/xtd/forms/key_event_args.h
  include/xtd/forms/key_event_handler.h
  include/xtd/forms/key_press_event_args.h
  include/xtd/forms/key_press_event_handler.h
  include/xtd/forms/keys.h
  include/xtd/forms/known_themed_color.h
  include/xtd/forms/label.h
  include/xtd/forms/lcd_label.h
  include/xtd/forms/lcd_style.h
  include/xtd/forms/list_box.h
  include/xtd/forms/list_control.h
  include/xtd/forms/main_menu.h
  include/xtd/forms/menu.h
  include/xtd/forms/menu_item.h
  include/xtd/forms/menu_images.h
  include/xtd/forms/message.h
  include/xtd/forms/message_box.h
  include/xtd/forms/message_box_buttons.h
  include/xtd/forms/message_box_default_button.h
  include/xtd/forms/message_box_icon.h
  include/xtd/forms/message_box_options.h
  include/xtd/forms/message_loop_callback.h
  include/xtd/forms/mouse_buttons.h
  include/xtd/forms/mouse_event_args.h
  include/xtd/forms/mouse_event_handler.h
  include/xtd/forms/nine_segment_display.h
  include/xtd/forms/numeric_up_down.h
  include/xtd/forms/open_file_dialog.h
  include/xtd/forms/orientation.h
  include/xtd/forms/padding.h
  include/xtd/forms/paint_event_args.h
  include/xtd/forms/paint_event_handler.h
  include/xtd/forms/panel.h
  include/xtd/forms/picture_box.h
  include/xtd/forms/picture_box_size_mode.h
  include/xtd/forms/progress_bar.h
  include/xtd/forms/progress_bar_style.h
  include/xtd/forms/progress_changed_event_args.h
  include/xtd/forms/progress_changed_event_handler.h
  include/xtd/forms/radio_button.h
  include/xtd/forms/radio_button_renderer.h
  include/xtd/forms/radio_buttons.h
  include/xtd/forms/renderer.h
  include/xtd/forms/run_worker_completed_event_args.h
  include/xtd/forms/run_worker_completed_event_handler.h
  include/xtd/forms/save_file_dialog.h
  include/xtd/forms/scroll_bar.h
  include/xtd/forms/scrollable_control.h
  include/xtd/forms/screen.h
  include/xtd/forms/selection_mode.h
  include/xtd/forms/segment_style.h
  include/xtd/forms/segments.h
  include/xtd/forms/settings.h
  include/xtd/forms/seven_segment_display.h
  include/xtd/forms/shortcut.h
  include/xtd/forms/sixteen_segment_display.h
  include/xtd/forms/split_container.h
  include/xtd/forms/splitter.h
  include/xtd/forms/splitter_panel.h
  include/xtd/forms/splitter_style.h
  include/xtd/forms/switch_button.h
  include/xtd/forms/system_information.h
  include/xtd/forms/tab_alignment.h
  include/xtd/forms/tab_control.h
  include/xtd/forms/tab_page.h
  include/xtd/forms/text_box_base.h
  include/xtd/forms/text_box.h
  include/xtd/forms/text_format_flags.h
  include/xtd/forms/texts.h
  include/xtd/forms/theme.h
  include/xtd/forms/theme_base.h
  include/xtd/forms/theme_colors.h
  include/xtd/forms/theme_images.h
  include/xtd/forms/theme_renderers.h
  include/xtd/forms/theme_style.h
  include/xtd/forms/tick_style.h
  include/xtd/forms/timer.h
  include/xtd/forms/toggle_button.h
  include/xtd/forms/tool_bar_images.h
  include/xtd/forms/trace_form.h
  include/xtd/forms/trace_form_base.h
  include/xtd/forms/track_bar.h
  include/xtd/forms/up_down_base.h
  include/xtd/forms/up_down_button.h
  include/xtd/forms/user_control.h
)

set(XTD_FORMS_LAYOUT_INCLUDES
  include/xtd/forms/layout/arranged_element_collection.h
)

set(XTD_FORMS_PROPERTIES_INCLUDES
  include/xtd/forms/properties/resources.h
)

set(XTD_FORMS_VISUAL_STYLES_INCLUDES
  include/xtd/forms/visual_styles/check_box_state.h
  include/xtd/forms/visual_styles/push_button_state.h
  include/xtd/forms/visual_styles/radio_button_state.h
  include/xtd/forms/visual_styles/toggle_button_state.h
)

set(XTD_FORMS_SOURCES
  src/xtd/forms/about_dialog.cpp
  src/xtd/forms/application.cpp
  src/xtd/forms/background_worker.cpp
  src/xtd/forms/button.cpp
  src/xtd/forms/button_base.cpp
  src/xtd/forms/button_renderer.cpp
  src/xtd/forms/check_box.cpp
  src/xtd/forms/check_box_renderer.cpp
  src/xtd/forms/checked_list_box.cpp
  src/xtd/forms/choice.cpp
  src/xtd/forms/color_dialog.cpp
  src/xtd/forms/color_picker.cpp
  src/xtd/forms/combo_box.cpp
  src/xtd/forms/command_link_button.cpp
  src/xtd/forms/container_control.cpp
  src/xtd/forms/context_menu.cpp
  src/xtd/forms/control.cpp
  src/xtd/forms/control_paint.cpp
  src/xtd/forms/countries.cpp
  src/xtd/forms/country.cpp
  src/xtd/forms/cursor.cpp
  src/xtd/forms/cursors.cpp
  src/xtd/forms/date_time_picker.cpp
  src/xtd/forms/domain_up_down.cpp
  src/xtd/forms/emoticon.cpp
  src/xtd/forms/emoticons.cpp
  src/xtd/forms/file_dialog.cpp
  src/xtd/forms/folder_browser_dialog.cpp
  src/xtd/forms/font_dialog.cpp
  src/xtd/forms/font_picker.cpp
  src/xtd/forms/form.cpp
  src/xtd/forms/group_box.cpp
  src/xtd/forms/image_list.cpp
  src/xtd/forms/input_box.cpp
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
  src/xtd/forms/padding.cpp
  src/xtd/forms/paint_event_args.cpp
  src/xtd/forms/panel.cpp
  src/xtd/forms/picture_box.cpp
  src/xtd/forms/progress_bar.cpp
  src/xtd/forms/radio_button.cpp
  src/xtd/forms/radio_button_renderer.cpp
  src/xtd/forms/renderer.cpp
  src/xtd/forms/save_file_dialog.cpp
  src/xtd/forms/screen.cpp
  src/xtd/forms/scrollable_control.cpp
  src/xtd/forms/settings.cpp
  src/xtd/forms/split_container.cpp
  src/xtd/forms/splitter.cpp
  src/xtd/forms/system_information.cpp
  src/xtd/forms/tab_control.cpp
  src/xtd/forms/tab_page.cpp
  src/xtd/forms/text_box.cpp
  src/xtd/forms/texts.cpp
  src/xtd/forms/theme.cpp
  src/xtd/forms/theme_base.cpp
  src/xtd/forms/theme_colors.cpp
  src/xtd/forms/theme_images.cpp
  src/xtd/forms/theme_renderers.cpp
  src/xtd/forms/timer.cpp
  src/xtd/forms/toggle_button.cpp
  src/xtd/forms/track_bar.cpp
  src/xtd/forms/up_down_base.cpp
  src/xtd/forms/up_down_button.cpp
  src/xtd/forms/user_control.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\forms FILES ${XTD_FORMS_INCLUDES})
source_group(include\\xtd\\forms\\layout FILES ${XTD_FORMS_LAYOUT_INCLUDES})
source_group(include\\xtd\\forms\\properties FILES ${XTD_FORMS_PROPERTIES_INCLUDES})
source_group(include\\xtd\\forms\\visual_styles FILES ${XTD_FORMS_VISUAL_STYLES_INCLUDES})
source_group(src\\xtd\\forms FILES ${XTD_FORMS_SOURCES})
source_group(src\\native FILES ${NATIVE_SOURCES})
source_group(src\\native\\wxwidgets FILES ${NATIVE_WXWIDGETS_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_FORMS_INCLUDES} ${XTD_FORMS_LAYOUT_INCLUDES} ${XTD_FORMS_PROPERTIES_INCLUDES} ${XTD_FORMS_VISUAL_STYLES_INCLUDES} ${XTD_FORMS_SOURCES})
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
