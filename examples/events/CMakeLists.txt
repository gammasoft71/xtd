cmake_minimum_required(VERSION 3.3)

project(events)
find_package(xtd.forms REQUIRED)

add_projects(
  application_idle
  form_and_messages
  form_paint
  key_events
  form_click
  mouse_events
  send_message_to_form
)
