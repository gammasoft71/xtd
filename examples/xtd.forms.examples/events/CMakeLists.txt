cmake_minimum_required(VERSION 3.20)

project(events)
find_package(xtd REQUIRED)

add_projects(
  application_add_message_filter
  application_application_exit
  application_events
  application_idle
  enable_changed_event
  font_changed_event
  form_and_messages
  form_paint
  key_events
  form_click
  form_custom_event
  mouse_events
  move_form
  send_message_to_form
  wnd_proc
)
