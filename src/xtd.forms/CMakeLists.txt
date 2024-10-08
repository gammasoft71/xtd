cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.forms)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
add_references(${XTD_FORMS_NATIVE_LIBRARY})
add_sources(
  include/xtd/xtd.forms.h
  include/xtd/xtd.forms
  include/xtd/forms/about_box.h
  include/xtd/forms/about_box
  include/xtd/forms/about_dialog.h
  include/xtd/forms/about_dialog
  include/xtd/forms/animation_update_event_args.h
  include/xtd/forms/animation_update_event_args
  include/xtd/forms/animation_update_event_handler.h
  include/xtd/forms/animation_update_event_handler
  include/xtd/forms/animation.h
  include/xtd/forms/animation
  include/xtd/forms/anchor_styles.h
  include/xtd/forms/anchor_styles
  include/xtd/forms/appearance.h
  include/xtd/forms/appearance
  include/xtd/forms/application.h
  include/xtd/forms/application
  include/xtd/forms/application_context.h
  include/xtd/forms/application_context
  include/xtd/forms/arrange_direction.h
  include/xtd/forms/arrange_direction
  include/xtd/forms/arrange_starting_position.h
  include/xtd/forms/arrange_starting_position
  include/xtd/forms/assert_box.h
  include/xtd/forms/assert_box
  include/xtd/forms/assert_dialog.h
  include/xtd/forms/assert_dialog
  include/xtd/forms/auto_size_mode.h
  include/xtd/forms/auto_size_mode
  include/xtd/forms/background_worker.h
  include/xtd/forms/background_worker
  include/xtd/forms/battery_charge_status.h
  include/xtd/forms/battery_charge_status
  include/xtd/forms/boot_mode.h
  include/xtd/forms/boot_mode
  include/xtd/forms/border_sides.h
  include/xtd/forms/border_sides
  include/xtd/forms/border_style.h
  include/xtd/forms/border_style
  include/xtd/forms/bounds_specified.h
  include/xtd/forms/bounds_specified
  include/xtd/forms/box_renderer.h
  include/xtd/forms/box_renderer
  include/xtd/forms/busy_box.h
  include/xtd/forms/busy_box
  include/xtd/forms/busy_dialog.h
  include/xtd/forms/busy_dialog
  include/xtd/forms/button.h
  include/xtd/forms/button
  include/xtd/forms/button_base.h
  include/xtd/forms/button_base
  include/xtd/forms/button_images.h
  include/xtd/forms/button_images
  include/xtd/forms/button_renderer.h
  include/xtd/forms/button_renderer
  include/xtd/forms/button_state.h
  include/xtd/forms/button_state
  include/xtd/forms/buttons.h
  include/xtd/forms/buttons
  include/xtd/forms/cancel_event_args.h
  include/xtd/forms/cancel_event_args
  include/xtd/forms/cancel_event_handler.h
  include/xtd/forms/cancel_event_handler
  include/xtd/forms/character_casing.h
  include/xtd/forms/character_casing
  include/xtd/forms/check_box.h
  include/xtd/forms/check_box
  include/xtd/forms/check_box_renderer.h
  include/xtd/forms/check_box_renderer
  include/xtd/forms/check_boxes.h
  include/xtd/forms/check_boxes
  include/xtd/forms/check_state.h
  include/xtd/forms/check_state
  include/xtd/forms/checked_list_box.h
  include/xtd/forms/checked_list_box
  include/xtd/forms/choice.h
  include/xtd/forms/choice
  include/xtd/forms/close_reason.h
  include/xtd/forms/close_reason
  include/xtd/forms/collapsible_panel.h
  include/xtd/forms/collapsible_panel
  include/xtd/forms/color_box.h
  include/xtd/forms/color_box
  include/xtd/forms/color_box_styles.h
  include/xtd/forms/color_box_styles
  include/xtd/forms/color_dialog.h
  include/xtd/forms/color_dialog
  include/xtd/forms/color_picker.h
  include/xtd/forms/color_picker
  include/xtd/forms/color_picker_event_args.h
  include/xtd/forms/color_picker_event_args
  include/xtd/forms/color_picker_event_handler.h
  include/xtd/forms/color_picker_event_handler
  include/xtd/forms/combo_box.h
  include/xtd/forms/combo_box
  include/xtd/forms/combo_box_style.h
  include/xtd/forms/combo_box_style
  include/xtd/forms/command_link_button.h
  include/xtd/forms/command_link_button
  include/xtd/forms/command_link_buttons.h
  include/xtd/forms/command_link_buttons
  include/xtd/forms/common_dialog.h
  include/xtd/forms/common_dialog
  include/xtd/forms/component.h
  include/xtd/forms/component
  include/xtd/forms/const_control_ref.h
  include/xtd/forms/const_control_ref
  include/xtd/forms/const_control_ref_less.h
  include/xtd/forms/const_control_ref_less
  include/xtd/forms/const_form_ref.h
  include/xtd/forms/const_form_ref
  include/xtd/forms/const_menu_item_ref.h
  include/xtd/forms/const_menu_item_ref
  include/xtd/forms/const_tab_page_ref.h
  include/xtd/forms/const_tab_page_ref
  include/xtd/forms/const_tab_page_ref_less.h
  include/xtd/forms/const_tab_page_ref_less
  include/xtd/forms/container_control.h
  include/xtd/forms/container_control
  include/xtd/forms/content_alignment.h
  include/xtd/forms/content_alignment
  include/xtd/forms/context_menu.h
  include/xtd/forms/context_menu
  include/xtd/forms/control.h
  include/xtd/forms/control
  include/xtd/forms/control_appearance.h
  include/xtd/forms/control_appearance
  include/xtd/forms/control_event_args.h
  include/xtd/forms/control_event_args
  include/xtd/forms/control_event_handler.h
  include/xtd/forms/control_event_handler
  include/xtd/forms/control_layout_style.h
  include/xtd/forms/control_layout_style
  include/xtd/forms/control_paint.h
  include/xtd/forms/control_paint
  include/xtd/forms/control_ref.h
  include/xtd/forms/control_ref
  include/xtd/forms/control_ref_less.h
  include/xtd/forms/control_ref_less
  include/xtd/forms/control_renderer.h
  include/xtd/forms/control_renderer
  include/xtd/forms/control_styles.h
  include/xtd/forms/control_styles
  include/xtd/forms/control_trace_listener.h
  include/xtd/forms/control_trace_listener
  include/xtd/forms/countries.h
  include/xtd/forms/countries
  include/xtd/forms/country.h
  include/xtd/forms/country
  include/xtd/forms/create_params.h
  include/xtd/forms/create_params
  include/xtd/forms/cursor.h
  include/xtd/forms/cursor
  include/xtd/forms/cursors.h
  include/xtd/forms/cursors
  include/xtd/forms/date_range_event_args.h
  include/xtd/forms/date_range_event_args
  include/xtd/forms/date_range_event_handler.h
  include/xtd/forms/date_range_event_handler
  include/xtd/forms/date_time_picker.h
  include/xtd/forms/date_time_picker
  include/xtd/forms/date_time_picker_format.h
  include/xtd/forms/date_time_picker_format
  include/xtd/forms/day.h
  include/xtd/forms/day
  include/xtd/forms/debug_form.h
  include/xtd/forms/debug_form
  include/xtd/forms/debug_message_box.h
  include/xtd/forms/debug_message_box
  include/xtd/forms/debug_message_dialog.h
  include/xtd/forms/debug_message_dialog
  include/xtd/forms/dialog_closed_event_args.h
  include/xtd/forms/dialog_closed_event_args
  include/xtd/forms/dialog_closed_event_handler.h
  include/xtd/forms/dialog_closed_event_handler
  include/xtd/forms/dialog_result.h
  include/xtd/forms/dialog_result
  include/xtd/forms/dialog_appearance.h
  include/xtd/forms/dialog_appearance
  include/xtd/forms/do_work_event_args.h
  include/xtd/forms/do_work_event_args
  include/xtd/forms/do_work_event_handler.h
  include/xtd/forms/do_work_event_handler
  include/xtd/forms/dock_style.h
  include/xtd/forms/dock_style
  include/xtd/forms/domain_up_down.h
  include/xtd/forms/domain_up_down
  include/xtd/forms/dot_matrix_display.h
  include/xtd/forms/dot_matrix_display
  include/xtd/forms/dot_matrix_style.h
  include/xtd/forms/dot_matrix_style
  include/xtd/forms/draw_item_event_args.h
  include/xtd/forms/draw_item_event_args
  include/xtd/forms/draw_item_event_handler.h
  include/xtd/forms/draw_item_event_handler
  include/xtd/forms/draw_item_state.h
  include/xtd/forms/draw_item_state
  include/xtd/forms/emoticon.h
  include/xtd/forms/emoticon
  include/xtd/forms/emoticons.h
  include/xtd/forms/emoticons
  include/xtd/forms/enable_debug.h
  include/xtd/forms/enable_debug
  include/xtd/forms/exception_box.h
  include/xtd/forms/exception_box
  include/xtd/forms/exception_dialog.h
  include/xtd/forms/exception_dialog
  include/xtd/forms/file_dialog.h
  include/xtd/forms/file_dialog
  include/xtd/forms/find_box.h
  include/xtd/forms/find_box
  include/xtd/forms/find_dialog.h
  include/xtd/forms/find_dialog
  include/xtd/forms/find_event_args.h
  include/xtd/forms/find_event_args
  include/xtd/forms/find_event_handler.h
  include/xtd/forms/find_event_handler
  include/xtd/forms/search_direction.h
  include/xtd/forms/search_direction
  include/xtd/forms/fixed_layout_panel.h
  include/xtd/forms/fixed_layout_panel
  include/xtd/forms/flat_button_appearance.h
  include/xtd/forms/flat_button_appearance
  include/xtd/forms/flat_style.h
  include/xtd/forms/flat_style
  include/xtd/forms/flow_layout_panel.h
  include/xtd/forms/flow_layout_panel
  include/xtd/forms/folder_browser_box.h
  include/xtd/forms/folder_browser_box
  include/xtd/forms/folder_browser_dialog.h
  include/xtd/forms/folder_browser_dialog
  include/xtd/forms/font_dialog.h
  include/xtd/forms/font_dialog
  include/xtd/forms/font_box.h
  include/xtd/forms/font_box
  include/xtd/forms/font_box_options.h
  include/xtd/forms/font_box_options
  include/xtd/forms/font_picker.h
  include/xtd/forms/font_picker
  include/xtd/forms/font_picker_event_args.h
  include/xtd/forms/font_picker_event_args
  include/xtd/forms/font_picker_event_handler.h
  include/xtd/forms/font_picker_event_handler
  include/xtd/forms/form.h
  include/xtd/forms/form
  include/xtd/forms/form_collection.h
  include/xtd/forms/form_collection
  include/xtd/forms/form_ref.h
  include/xtd/forms/form_ref
  include/xtd/forms/form_border_style.h
  include/xtd/forms/form_border_style
  include/xtd/forms/form_button_images.h
  include/xtd/forms/form_button_images
  include/xtd/forms/form_closed_event_args.h
  include/xtd/forms/form_closed_event_args
  include/xtd/forms/form_closed_event_handler.h
  include/xtd/forms/form_closed_event_handler
  include/xtd/forms/form_closing_event_args.h
  include/xtd/forms/form_closing_event_args
  include/xtd/forms/form_closing_event_handler.h
  include/xtd/forms/form_closing_event_handler
  include/xtd/forms/form_renderer.h
  include/xtd/forms/form_renderer
  include/xtd/forms/form_start_position.h
  include/xtd/forms/form_start_position
  include/xtd/forms/form_window_state.h
  include/xtd/forms/form_window_state
  include/xtd/forms/fourteen_segment_display.h
  include/xtd/forms/fourteen_segment_display
  include/xtd/forms/group_box.h
  include/xtd/forms/group_box
  include/xtd/forms/help_event_args.h
  include/xtd/forms/help_event_args
  include/xtd/forms/help_event_handler.h
  include/xtd/forms/help_event_handler
  include/xtd/forms/horizontal_alignment.h
  include/xtd/forms/horizontal_alignment
  include/xtd/forms/horizontal_control_layout_style.h
  include/xtd/forms/horizontal_control_layout_style
  include/xtd/forms/horizontal_control_layout_style_collection.h
  include/xtd/forms/horizontal_control_layout_style_collection
  include/xtd/forms/horizontal_layout_panel.h
  include/xtd/forms/horizontal_layout_panel
  include/xtd/forms/h_scroll_bar.h
  include/xtd/forms/h_scroll_bar
  include/xtd/forms/ibutton_control.h
  include/xtd/forms/ibutton_control
  include/xtd/forms/icontrol_trace.h
  include/xtd/forms/icontrol_trace
  include/xtd/forms/image_layout.h
  include/xtd/forms/image_layout
  include/xtd/forms/image_list.h
  include/xtd/forms/image_list
  include/xtd/forms/image_renderer.h
  include/xtd/forms/image_renderer
  include/xtd/forms/images.h
  include/xtd/forms/images
  include/xtd/forms/imessage_filter.h
  include/xtd/forms/imessage_filter
  include/xtd/forms/input_box.h
  include/xtd/forms/input_box
  include/xtd/forms/input_box_style.h
  include/xtd/forms/input_box_style
  include/xtd/forms/input_dialog.h
  include/xtd/forms/input_dialog
  include/xtd/forms/item_check_event_args.h
  include/xtd/forms/item_check_event_args
  include/xtd/forms/item_check_event_handler.h
  include/xtd/forms/item_check_event_handler
  include/xtd/forms/iwin32_window.h
  include/xtd/forms/iwin32_window
  include/xtd/forms/key_event_args.h
  include/xtd/forms/key_event_args
  include/xtd/forms/key_event_handler.h
  include/xtd/forms/key_event_handler
  include/xtd/forms/key_press_event_args.h
  include/xtd/forms/key_press_event_args
  include/xtd/forms/key_press_event_handler.h
  include/xtd/forms/key_press_event_handler
  include/xtd/forms/keys.h
  include/xtd/forms/keys
  include/xtd/forms/known_themed_color.h
  include/xtd/forms/known_themed_color
  include/xtd/forms/label.h
  include/xtd/forms/label
  include/xtd/forms/label_renderer.h
  include/xtd/forms/label_renderer
  include/xtd/forms/labels.h
  include/xtd/forms/labels
  include/xtd/forms/lcd_label.h
  include/xtd/forms/lcd_label
  include/xtd/forms/lcd_style.h
  include/xtd/forms/lcd_style
  include/xtd/forms/left_right_alignment.h
  include/xtd/forms/left_right_alignment
  include/xtd/forms/light_button.h
  include/xtd/forms/light_button
  include/xtd/forms/light_buttons.h
  include/xtd/forms/light_buttons
  include/xtd/forms/link_area.h
  include/xtd/forms/link_area
  include/xtd/forms/link_behavior.h
  include/xtd/forms/link_behavior
  include/xtd/forms/link_label.h
  include/xtd/forms/link_label
  include/xtd/forms/link_label_clicked_event_args.h
  include/xtd/forms/link_label_clicked_event_args
  include/xtd/forms/link_label_clicked_event_handler.h
  include/xtd/forms/link_label_clicked_event_handler
  include/xtd/forms/link.h
  include/xtd/forms/link
  include/xtd/forms/list_box.h
  include/xtd/forms/list_box
  include/xtd/forms/list_control.h
  include/xtd/forms/list_control
  include/xtd/forms/loading_indicator.h
  include/xtd/forms/loading_indicator
  include/xtd/forms/loading_indicators.h
  include/xtd/forms/loading_indicators
  include/xtd/forms/loading_indicator_style.h
  include/xtd/forms/loading_indicator_style
  include/xtd/forms/main_menu.h
  include/xtd/forms/main_menu
  include/xtd/forms/menu.h
  include/xtd/forms/menu
  include/xtd/forms/menu_item.h
  include/xtd/forms/menu_item
  include/xtd/forms/menu_item_kind.h
  include/xtd/forms/menu_item_kind
  include/xtd/forms/menu_item_ref.h
  include/xtd/forms/menu_item_ref
  include/xtd/forms/menu_images.h
  include/xtd/forms/menu_images
  include/xtd/forms/message.h
  include/xtd/forms/message
  include/xtd/forms/message_box.h
  include/xtd/forms/message_box
  include/xtd/forms/message_box_buttons.h
  include/xtd/forms/message_box_buttons
  include/xtd/forms/message_box_default_button.h
  include/xtd/forms/message_box_default_button
  include/xtd/forms/message_box_icon.h
  include/xtd/forms/message_box_icon
  include/xtd/forms/message_box_options.h
  include/xtd/forms/message_box_options
  include/xtd/forms/message_dialog.h
  include/xtd/forms/message_dialog
  include/xtd/forms/message_dialog_buttons.h
  include/xtd/forms/message_dialog_buttons
  include/xtd/forms/message_dialog_default_button.h
  include/xtd/forms/message_dialog_default_button
  include/xtd/forms/message_dialog_icon.h
  include/xtd/forms/message_dialog_icon
  include/xtd/forms/message_dialog_options.h
  include/xtd/forms/message_dialog_options
  include/xtd/forms/message_loop_callback.h
  include/xtd/forms/message_loop_callback
  include/xtd/forms/message_notifier.h
  include/xtd/forms/message_notifier
  include/xtd/forms/message_notifier_button.h
  include/xtd/forms/message_notifier_button
  include/xtd/forms/month_calendar.h
  include/xtd/forms/month_calendar
  include/xtd/forms/mouse_buttons.h
  include/xtd/forms/mouse_buttons
  include/xtd/forms/mouse_event_args.h
  include/xtd/forms/mouse_event_args
  include/xtd/forms/mouse_event_handler.h
  include/xtd/forms/mouse_event_handler
  include/xtd/forms/nine_segment_display.h
  include/xtd/forms/nine_segment_display
  include/xtd/forms/notifier_appearance.h
  include/xtd/forms/notifier_appearance
  include/xtd/forms/numeric_up_down.h
  include/xtd/forms/numeric_up_down
  include/xtd/forms/open_file_box.h
  include/xtd/forms/open_file_box
  include/xtd/forms/open_file_box_options.h
  include/xtd/forms/open_file_box_options
  include/xtd/forms/open_file_dialog.h
  include/xtd/forms/open_file_dialog
  include/xtd/forms/orientation.h
  include/xtd/forms/orientation
  include/xtd/forms/padding.h
  include/xtd/forms/padding
  include/xtd/forms/paint_event_args.h
  include/xtd/forms/paint_event_args
  include/xtd/forms/paint_event_handler.h
  include/xtd/forms/paint_event_handler
  include/xtd/forms/panel.h
  include/xtd/forms/panel
  include/xtd/forms/panel_renderer.h
  include/xtd/forms/panel_renderer
  include/xtd/forms/picture_box.h
  include/xtd/forms/picture_box
  include/xtd/forms/picture_box_size_mode.h
  include/xtd/forms/picture_box_size_mode
  include/xtd/forms/popup_panel.h
  include/xtd/forms/popup_panel
  include/xtd/forms/power_line_status.h
  include/xtd/forms/power_line_status
  include/xtd/forms/power_state.h
  include/xtd/forms/power_state
  include/xtd/forms/power_status.h
  include/xtd/forms/power_status
  include/xtd/forms/progress_bar.h
  include/xtd/forms/progress_bar
  include/xtd/forms/progress_bar_style.h
  include/xtd/forms/progress_bar_style
  include/xtd/forms/progress_box.h
  include/xtd/forms/progress_box
  include/xtd/forms/progress_box_options.h
  include/xtd/forms/progress_box_options
  include/xtd/forms/progress_changed_event_args.h
  include/xtd/forms/progress_changed_event_args
  include/xtd/forms/progress_changed_event_handler.h
  include/xtd/forms/progress_changed_event_handler
  include/xtd/forms/progress_dialog.h
  include/xtd/forms/progress_dialog
  include/xtd/forms/radio_button.h
  include/xtd/forms/radio_button
  include/xtd/forms/radio_button_renderer.h
  include/xtd/forms/radio_button_renderer
  include/xtd/forms/radio_buttons.h
  include/xtd/forms/radio_buttons
  include/xtd/forms/renderer.h
  include/xtd/forms/renderer
  include/xtd/forms/replace_box.h
  include/xtd/forms/replace_box
  include/xtd/forms/replace_dialog.h
  include/xtd/forms/replace_dialog
  include/xtd/forms/replace_event_args.h
  include/xtd/forms/replace_event_args
  include/xtd/forms/replace_event_handler.h
  include/xtd/forms/replace_event_handler
  include/xtd/forms/right_to_left.h
  include/xtd/forms/right_to_left
  include/xtd/forms/run_worker_completed_event_args.h
  include/xtd/forms/run_worker_completed_event_args
  include/xtd/forms/run_worker_completed_event_handler.h
  include/xtd/forms/run_worker_completed_event_handler
  include/xtd/forms/save_file_dialog.h
  include/xtd/forms/save_file_dialog
  include/xtd/forms/save_file_box.h
  include/xtd/forms/save_file_box
  include/xtd/forms/save_file_box_options.h
  include/xtd/forms/save_file_box_options
  include/xtd/forms/screen_orientation.h
  include/xtd/forms/screen_orientation
  include/xtd/forms/scroll_bar.h
  include/xtd/forms/scroll_bar
  include/xtd/forms/scrollable_control.h
  include/xtd/forms/scrollable_control
  include/xtd/forms/screen.h
  include/xtd/forms/screen
  include/xtd/forms/selection_mode.h
  include/xtd/forms/selection_mode
  include/xtd/forms/selection_range.h
  include/xtd/forms/selection_range
  include/xtd/forms/segment_style.h
  include/xtd/forms/segment_style
  include/xtd/forms/segments.h
  include/xtd/forms/segments
  include/xtd/forms/settings.h
  include/xtd/forms/settings
  include/xtd/forms/seven_segment_display.h
  include/xtd/forms/seven_segment_display
  include/xtd/forms/shadow.h
  include/xtd/forms/shadow
  include/xtd/forms/shadows.h
  include/xtd/forms/shadows
  include/xtd/forms/shortcut.h
  include/xtd/forms/shortcut
  include/xtd/forms/sixteen_segment_display.h
  include/xtd/forms/sixteen_segment_display
  include/xtd/forms/size_type.h
  include/xtd/forms/size_type
  include/xtd/forms/split_container.h
  include/xtd/forms/split_container
  include/xtd/forms/splitter.h
  include/xtd/forms/splitter
  include/xtd/forms/splitter_panel.h
  include/xtd/forms/splitter_panel
  include/xtd/forms/splitter_style.h
  include/xtd/forms/splitter_style
  include/xtd/forms/status_bar.h
  include/xtd/forms/status_bar
  include/xtd/forms/system_texts.h
  include/xtd/forms/system_texts
  include/xtd/forms/status_bar_draw_item_event_args.h
  include/xtd/forms/status_bar_draw_item_event_args
  include/xtd/forms/status_bar_draw_item_event_handler.h
  include/xtd/forms/status_bar_draw_item_event_handler
  include/xtd/forms/status_bar_panel.h
  include/xtd/forms/status_bar_panel
  include/xtd/forms/status_bar_panel_auto_size.h
  include/xtd/forms/status_bar_panel_auto_size
  include/xtd/forms/status_bar_panel_border_style.h
  include/xtd/forms/status_bar_panel_border_style
  include/xtd/forms/status_bar_panel_click_event_args.h
  include/xtd/forms/status_bar_panel_click_event_args
  include/xtd/forms/status_bar_panel_click_event_handler.h
  include/xtd/forms/status_bar_panel_click_event_handler
  include/xtd/forms/status_bar_panel_renderer.h
  include/xtd/forms/status_bar_panel_renderer
  include/xtd/forms/status_bar_panel_style.h
  include/xtd/forms/status_bar_panel_style
  include/xtd/forms/status_bar_renderer.h
  include/xtd/forms/status_bar_renderer
  include/xtd/forms/switch_button.h
  include/xtd/forms/switch_button
  include/xtd/forms/switch_button_renderer.h
  include/xtd/forms/switch_button_renderer
  include/xtd/forms/system_information.h
  include/xtd/forms/system_information
  include/xtd/forms/tab_alignment.h
  include/xtd/forms/tab_alignment
  include/xtd/forms/tab_control.h
  include/xtd/forms/tab_control
  include/xtd/forms/tab_page.h
  include/xtd/forms/tab_page
  include/xtd/forms/tab_page_ref.h
  include/xtd/forms/tab_page_ref
  include/xtd/forms/tab_page_ref_less.h
  include/xtd/forms/tab_page_ref_less
  include/xtd/forms/table_layout_panel.h
  include/xtd/forms/table_layout_panel
  include/xtd/forms/text_box_base.h
  include/xtd/forms/text_box_base
  include/xtd/forms/text_box.h
  include/xtd/forms/text_box
  include/xtd/forms/text_format_flags.h
  include/xtd/forms/text_format_flags
  include/xtd/forms/text_renderer.h
  include/xtd/forms/text_renderer
  include/xtd/forms/tick_style.h
  include/xtd/forms/tick_style
  include/xtd/forms/timer.h
  include/xtd/forms/timer
  include/xtd/forms/toggle_button.h
  include/xtd/forms/toggle_button
  include/xtd/forms/toggle_button_renderer.h
  include/xtd/forms/toggle_button_renderer
  include/xtd/forms/toggle_buttons.h
  include/xtd/forms/toggle_buttons
  include/xtd/forms/tool_bar.h
  include/xtd/forms/tool_bar
  include/xtd/forms/tool_bar_appearance.h
  include/xtd/forms/tool_bar_appearance
  include/xtd/forms/tool_bar_button.h
  include/xtd/forms/tool_bar_button
  include/xtd/forms/tool_bar_button_click_event_args.h
  include/xtd/forms/tool_bar_button_click_event_args
  include/xtd/forms/tool_bar_button_click_event_handler.h
  include/xtd/forms/tool_bar_button_click_event_handler
  include/xtd/forms/tool_bar_button_ref.h
  include/xtd/forms/tool_bar_button_ref
  include/xtd/forms/tool_bar_button_renderer.h
  include/xtd/forms/tool_bar_button_renderer
  include/xtd/forms/tool_bar_button_style.h
  include/xtd/forms/tool_bar_button_style
  include/xtd/forms/tool_bar_images.h
  include/xtd/forms/tool_bar_images
  include/xtd/forms/tool_bar_renderer.h
  include/xtd/forms/tool_bar_renderer
  include/xtd/forms/tool_bar_text_align.h
  include/xtd/forms/tool_bar_text_align
  include/xtd/forms/trace_form.h
  include/xtd/forms/trace_form
  include/xtd/forms/trace_form_base.h
  include/xtd/forms/trace_form_base
  include/xtd/forms/trace_message_box.h
  include/xtd/forms/trace_message_box
  include/xtd/forms/trace_message_dialog.h
  include/xtd/forms/trace_message_dialog
  include/xtd/forms/track_bar.h
  include/xtd/forms/track_bar
  include/xtd/forms/up_down_base.h
  include/xtd/forms/up_down_base
  include/xtd/forms/up_down_button.h
  include/xtd/forms/up_down_button
  include/xtd/forms/use_wait_cursor.h
  include/xtd/forms/use_wait_cursor
  include/xtd/forms/user_control.h
  include/xtd/forms/user_control
  include/xtd/forms/user_control_renderer.h
  include/xtd/forms/user_control_renderer
  include/xtd/forms/vertical_control_layout_style.h
  include/xtd/forms/vertical_control_layout_style
  include/xtd/forms/vertical_control_layout_style_collection.h
  include/xtd/forms/vertical_control_layout_style_collection
  include/xtd/forms/vertical_layout_panel.h
  include/xtd/forms/vertical_layout_panel
  include/xtd/forms/v_scroll_bar.h
  include/xtd/forms/v_scroll_bar
  include/xtd/forms/layout/arranged_element_collection.h
  include/xtd/forms/layout/arranged_element_collection
  include/xtd/forms/layout/sorter_none.h
  include/xtd/forms/layout/sorter_none
  include/xtd/forms/properties/resources.h
  include/xtd/forms/properties/resources
  include/xtd/forms/style_sheets/background_image.h
  include/xtd/forms/style_sheets/background_image
  include/xtd/forms/style_sheets/border_color.h
  include/xtd/forms/style_sheets/border_color
  include/xtd/forms/style_sheets/border_radius.h
  include/xtd/forms/style_sheets/border_radius
  include/xtd/forms/style_sheets/border_style.h
  include/xtd/forms/style_sheets/border_style
  include/xtd/forms/style_sheets/border_type.h
  include/xtd/forms/style_sheets/border_type
  include/xtd/forms/style_sheets/border_width.h
  include/xtd/forms/style_sheets/border_width
  include/xtd/forms/style_sheets/button.h
  include/xtd/forms/style_sheets/button
  include/xtd/forms/style_sheets/control.h
  include/xtd/forms/style_sheets/control
  include/xtd/forms/style_sheets/form.h
  include/xtd/forms/style_sheets/form
  include/xtd/forms/style_sheets/ibox_model.h
  include/xtd/forms/style_sheets/ibox_model
  include/xtd/forms/style_sheets/iimage_model.h
  include/xtd/forms/style_sheets/iimage_model
  include/xtd/forms/style_sheets/image_type.h
  include/xtd/forms/style_sheets/image_type
  include/xtd/forms/style_sheets/itext_model.h
  include/xtd/forms/style_sheets/itext_model
  include/xtd/forms/style_sheets/label.h
  include/xtd/forms/style_sheets/label
  include/xtd/forms/style_sheets/length.h
  include/xtd/forms/style_sheets/length
  include/xtd/forms/style_sheets/lengths.h
  include/xtd/forms/style_sheets/lengths
  include/xtd/forms/style_sheets/length_unit.h
  include/xtd/forms/style_sheets/length_unit
  include/xtd/forms/style_sheets/link_label.h
  include/xtd/forms/style_sheets/link_label
  include/xtd/forms/style_sheets/margin.h
  include/xtd/forms/style_sheets/margin
  include/xtd/forms/style_sheets/outline_color.h
  include/xtd/forms/style_sheets/outline_color
  include/xtd/forms/style_sheets/outline_offset.h
  include/xtd/forms/style_sheets/outline_offset
  include/xtd/forms/style_sheets/outline_radius.h
  include/xtd/forms/style_sheets/outline_radius
  include/xtd/forms/style_sheets/outline_style.h
  include/xtd/forms/style_sheets/outline_style
  include/xtd/forms/style_sheets/outline_width.h
  include/xtd/forms/style_sheets/outline_width
  include/xtd/forms/style_sheets/padding.h
  include/xtd/forms/style_sheets/padding
  include/xtd/forms/style_sheets/panel.h
  include/xtd/forms/style_sheets/panel
  include/xtd/forms/style_sheets/pseudo_state.h
  include/xtd/forms/style_sheets/pseudo_state
  include/xtd/forms/style_sheets/shadow.h
  include/xtd/forms/style_sheets/shadow
  include/xtd/forms/style_sheets/shadows.h
  include/xtd/forms/style_sheets/shadows
  include/xtd/forms/style_sheets/status_bar.h
  include/xtd/forms/style_sheets/status_bar
  include/xtd/forms/style_sheets/status_bar_panel.h
  include/xtd/forms/style_sheets/status_bar_panel
  include/xtd/forms/style_sheets/style_sheet.h
  include/xtd/forms/style_sheets/style_sheet
  include/xtd/forms/style_sheets/system_colors.h
  include/xtd/forms/style_sheets/system_colors
  include/xtd/forms/style_sheets/text_decoration.h
  include/xtd/forms/style_sheets/text_decoration
  include/xtd/forms/style_sheets/text_transformation.h
  include/xtd/forms/style_sheets/text_transformation
  include/xtd/forms/style_sheets/theme.h
  include/xtd/forms/style_sheets/theme
  include/xtd/forms/style_sheets/toggle_button.h
  include/xtd/forms/style_sheets/toggle_button
  include/xtd/forms/style_sheets/tool_bar.h
  include/xtd/forms/style_sheets/tool_bar
  include/xtd/forms/style_sheets/tool_bar_button.h
  include/xtd/forms/style_sheets/tool_bar_button
  include/xtd/forms/style_sheets/user_control.h
  include/xtd/forms/style_sheets/user_control
  include/xtd/forms/style_sheets/white_space.h
  include/xtd/forms/style_sheets/white_space
  include/xtd/forms/visual_styles/check_box_state.h
  include/xtd/forms/visual_styles/check_box_state
  include/xtd/forms/visual_styles/control_state.h
  include/xtd/forms/visual_styles/control_state
  include/xtd/forms/visual_styles/form_state.h
  include/xtd/forms/visual_styles/form_state
  include/xtd/forms/visual_styles/label_state.h
  include/xtd/forms/visual_styles/label_state
  include/xtd/forms/visual_styles/link_label_state.h
  include/xtd/forms/visual_styles/link_label_state
  include/xtd/forms/visual_styles/push_button_state.h
  include/xtd/forms/visual_styles/push_button_state
  include/xtd/forms/visual_styles/radio_button_state.h
  include/xtd/forms/visual_styles/radio_button_state
  include/xtd/forms/visual_styles/toggle_button_state.h
  include/xtd/forms/visual_styles/toggle_button_state
  include/xtd/forms/visual_styles/user_control_state.h
  include/xtd/forms/visual_styles/user_control_state
  src/xtd/forms/about_box.cpp
  src/xtd/forms/about_dialog.cpp
  src/xtd/forms/animation.cpp
  src/xtd/forms/application.cpp
  src/xtd/forms/application_context.cpp
  src/xtd/forms/assert_box.cpp
  src/xtd/forms/assert_dialog.cpp
  src/xtd/forms/background_worker.cpp
  src/xtd/forms/box_renderer.cpp
  src/xtd/forms/busy_box.cpp
  src/xtd/forms/busy_dialog.cpp
  src/xtd/forms/button.cpp
  src/xtd/forms/button_base.cpp
  src/xtd/forms/button_renderer.cpp
  src/xtd/forms/buttons.cpp
  src/xtd/forms/check_box.cpp
  src/xtd/forms/check_box_renderer.cpp
  src/xtd/forms/check_boxes.cpp
  src/xtd/forms/checked_list_box.cpp
  src/xtd/forms/choice.cpp
  src/xtd/forms/collapsible_panel.cpp
  src/xtd/forms/color_box.cpp
  src/xtd/forms/color_dialog.cpp
  src/xtd/forms/color_picker.cpp
  src/xtd/forms/combo_box.cpp
  src/xtd/forms/command_link_button.cpp
  src/xtd/forms/command_link_buttons.cpp
  src/xtd/forms/common_dialog.cpp
  src/xtd/forms/component.cpp
  src/xtd/forms/container_control.cpp
  src/xtd/forms/context_menu.cpp
  src/xtd/forms/control.cpp
  src/xtd/forms/control_layout_style.cpp
  src/xtd/forms/control_paint.cpp
  src/xtd/forms/control_renderer.cpp
  src/xtd/forms/countries.cpp
  src/xtd/forms/country.cpp
  src/xtd/forms/create_params.cpp
  src/xtd/forms/cursor.cpp
  src/xtd/forms/cursors.cpp
  src/xtd/forms/date_time_picker.cpp
  src/xtd/forms/debug_form.cpp
  src/xtd/forms/debug_message_dialog.cpp
  src/xtd/forms/domain_up_down.cpp
  src/xtd/forms/dot_matrix_display.cpp
  src/xtd/forms/draw_item_event_args.cpp
  src/xtd/forms/emoticon.cpp
  src/xtd/forms/emoticons.cpp
  src/xtd/forms/enable_debug.cpp
  src/xtd/forms/exception_box.cpp
  src/xtd/forms/exception_dialog.cpp
  src/xtd/forms/flat_button_appearance.cpp
  src/xtd/forms/file_dialog.cpp
  src/xtd/forms/file_dialog_data.h
  src/xtd/forms/find_box.cpp
  src/xtd/forms/find_dialog.cpp
  src/xtd/forms/find_event_args.cpp
  src/xtd/forms/fixed_layout_panel.cpp
  src/xtd/forms/flow_layout_panel.cpp
  src/xtd/forms/folder_browser_box.cpp
  src/xtd/forms/folder_browser_dialog.cpp
  src/xtd/forms/font_box.cpp
  src/xtd/forms/font_dialog.cpp
  src/xtd/forms/font_picker.cpp
  src/xtd/forms/form.cpp
  src/xtd/forms/form_button_images.cpp
  src/xtd/forms/form_renderer.cpp
  src/xtd/forms/fourteen_segment_display.cpp
  src/xtd/forms/group_box.cpp
  src/xtd/forms/horizontal_control_layout_style.cpp
  src/xtd/forms/horizontal_layout_panel.cpp
  src/xtd/forms/h_scroll_bar.cpp
  src/xtd/forms/image_list.cpp
  src/xtd/forms/image_renderer.cpp
  src/xtd/forms/images.cpp
  src/xtd/forms/input_box.cpp
  src/xtd/forms/input_dialog.cpp
  src/xtd/forms/label.cpp
  src/xtd/forms/label_renderer.cpp
  src/xtd/forms/labels.cpp
  src/xtd/forms/lcd_label.cpp
  src/xtd/forms/light_button.cpp
  src/xtd/forms/light_buttons.cpp
  src/xtd/forms/link_area.cpp
  src/xtd/forms/link_label.cpp
  src/xtd/forms/link_label_clicked_event_args.cpp
  src/xtd/forms/link.cpp
  src/xtd/forms/list_box.cpp
  src/xtd/forms/list_control.cpp
  src/xtd/forms/loading_indicator.cpp
  src/xtd/forms/loading_indicator_animation.h
  src/xtd/forms/loading_indicator_animation_bar.h
  src/xtd/forms/loading_indicator_animation_circle_bars.h
  src/xtd/forms/loading_indicator_animation_circle_blinks.h
  src/xtd/forms/loading_indicator_animation_five_lines.h
  src/xtd/forms/loading_indicator_animation_five_lines_center.h
  src/xtd/forms/loading_indicator_animation_five_lines_chronological.h
  src/xtd/forms/loading_indicator_animation_five_lines_pulse.h
  src/xtd/forms/loading_indicator_animation_five_lines_wave.h
  src/xtd/forms/loading_indicator_animation_pulse.h
  src/xtd/forms/loading_indicator_animation_pulse_outline.h
  src/xtd/forms/loading_indicator_animation_standard.h
  src/xtd/forms/loading_indicator_animation_system.h
  src/xtd/forms/loading_indicator_animation_three_balls.h
  src/xtd/forms/loading_indicator_animation_three_balls_bouncing.h
  src/xtd/forms/loading_indicator_animation_three_balls_rotation.h
  src/xtd/forms/loading_indicators.cpp
  src/xtd/forms/main_menu.cpp
  src/xtd/forms/menu.cpp
  src/xtd/forms/menu_data.h
  src/xtd/forms/menu_item.cpp
  src/xtd/forms/message.cpp
  src/xtd/forms/message_box.cpp
  src/xtd/forms/message_dialog.cpp
  src/xtd/forms/message_notifier.cpp
  src/xtd/forms/month_calendar.cpp
  src/xtd/forms/mouse_event_args.cpp
  src/xtd/forms/nine_segment_display.cpp
  src/xtd/forms/numeric_up_down.cpp
  src/xtd/forms/open_file_box.cpp
  src/xtd/forms/open_file_dialog.cpp
  src/xtd/forms/padding.cpp
  src/xtd/forms/panel.cpp
  src/xtd/forms/panel_renderer.cpp
  src/xtd/forms/paint_event_args.cpp
  src/xtd/forms/picture_box.cpp
  src/xtd/forms/popup_panel.cpp
  src/xtd/forms/power_status.cpp
  src/xtd/forms/progress_bar.cpp
  src/xtd/forms/progress_box.cpp
  src/xtd/forms/progress_dialog.cpp
  src/xtd/forms/radio_button.cpp
  src/xtd/forms/radio_button_renderer.cpp
  src/xtd/forms/radio_buttons.cpp
  src/xtd/forms/renderer.cpp
  src/xtd/forms/replace_box.cpp
  src/xtd/forms/replace_dialog.cpp
  src/xtd/forms/save_file_box.cpp
  src/xtd/forms/save_file_dialog.cpp
  src/xtd/forms/screen.cpp
  src/xtd/forms/scroll_bar.cpp
  src/xtd/forms/scrollable_control.cpp
  src/xtd/forms/selection_range.cpp
  src/xtd/forms/seven_segment_display.cpp
  src/xtd/forms/shadow.cpp
  src/xtd/forms/sixteen_segment_display.cpp
  src/xtd/forms/sizing_grip_control.h
  src/xtd/forms/split_container.cpp
  src/xtd/forms/splitter.cpp
  src/xtd/forms/splitter_panel.cpp
  src/xtd/forms/status_bar.cpp
  src/xtd/forms/status_bar_panel.cpp
  src/xtd/forms/status_bar_panel_control.h
  src/xtd/forms/status_bar_panel_data.h
  src/xtd/forms/status_bar_panel_renderer.cpp
  src/xtd/forms/status_bar_renderer.cpp
  src/xtd/forms/switch_button.cpp
  src/xtd/forms/switch_button_renderer.cpp
  src/xtd/forms/system_information.cpp
  src/xtd/forms/tab_control.cpp
  src/xtd/forms/tab_control_data.h
  src/xtd/forms/tab_page.cpp
  src/xtd/forms/table_layout_panel.cpp
  src/xtd/forms/text_box.cpp
  src/xtd/forms/text_box_base.cpp
  src/xtd/forms/text_renderer.cpp
  src/xtd/forms/timer.cpp
  src/xtd/forms/toggle_button.cpp
  src/xtd/forms/toggle_button_renderer.cpp
  src/xtd/forms/toggle_buttons.cpp
  src/xtd/forms/tool_bar.cpp
  src/xtd/forms/tool_bar_button.cpp
  src/xtd/forms/tool_bar_button_control.h
  src/xtd/forms/tool_bar_button_data.h
  src/xtd/forms/tool_bar_button_renderer.cpp
  src/xtd/forms/tool_bar_images.cpp
  src/xtd/forms/tool_bar_renderer.cpp
  src/xtd/forms/trace_form_base.cpp
  src/xtd/forms/trace_form.cpp
  src/xtd/forms/trace_message_dialog.cpp
  src/xtd/forms/track_bar.cpp
  src/xtd/forms/up_down_base.cpp
  src/xtd/forms/up_down_button.cpp
  src/xtd/forms/use_wait_cursor.cpp
  src/xtd/forms/user_control.cpp
  src/xtd/forms/user_control_renderer.cpp
  src/xtd/forms/vertical_control_layout_style.cpp
  src/xtd/forms/vertical_layout_panel.cpp
  src/xtd/forms/v_scroll_bar.cpp
  src/xtd/forms/xtd_forms_common_dialog_closed_caller.h
  src/xtd/forms/xtd_forms_message_dialog_closed_caller.h
  src/xtd/forms/properties/resources.cpp
  src/xtd/forms/style_sheets/border_color.cpp
  src/xtd/forms/style_sheets/border_radius.cpp
  src/xtd/forms/style_sheets/border_style.cpp
  src/xtd/forms/style_sheets/control.cpp
  src/xtd/forms/style_sheets/background_image.cpp
  src/xtd/forms/style_sheets/length.cpp
  src/xtd/forms/style_sheets/lengths.cpp
  src/xtd/forms/style_sheets/shadow.cpp
  src/xtd/forms/style_sheets/style_sheet.cpp
  src/xtd/forms/style_sheets/system_colors.cpp
  src/xtd/forms/style_sheets/system_style_sheet_gnome_dark.cpp
  src/xtd/forms/style_sheets/system_style_sheet_gnome_light.cpp
  src/xtd/forms/style_sheets/system_style_sheet_kde_dark.cpp
  src/xtd/forms/style_sheets/system_style_sheet_kde_light.cpp
  src/xtd/forms/style_sheets/system_style_sheet_macos_dark.cpp
  src/xtd/forms/style_sheets/system_style_sheet_macos_light.cpp
  src/xtd/forms/style_sheets/system_style_sheet_unknown_dark.cpp
  src/xtd/forms/style_sheets/system_style_sheet_unknown_light.cpp
  src/xtd/forms/style_sheets/system_style_sheet_windows_dark.cpp
  src/xtd/forms/style_sheets/system_style_sheet_windows_light.cpp
  src/xtd/forms/style_sheets/theme.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
