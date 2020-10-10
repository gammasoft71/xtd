#include <xtd/forms/native/message_box.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/control.h"
#include "../../../include/xtd/forms/message_box.h"

using namespace xtd;
using namespace xtd::forms;

namespace  {
  dialog_result show_message_box(intptr_t hwnd, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {
    return static_cast<dialog_result>(native::message_box::show(hwnd, text, caption, static_cast<uint32_t>(buttons) + static_cast<uint32_t>(icon) + static_cast<uint32_t>(default_button) + static_cast<uint32_t>(options), display_help_button));
  }
}

dialog_result message_box::show(const iwin32_window& owner, const std::string &text) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(owner.handle(), text, "", message_box_buttons::ok, message_box_icon::none, message_box_default_button::button1, static_cast<message_box_options>(0), false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const iwin32_window& owner, const std::string &text, const std::string &caption) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(owner.handle(), text, caption, message_box_buttons::ok, message_box_icon::none, message_box_default_button::button1, static_cast<message_box_options>(0), false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const iwin32_window& owner, const std::string &text, const std::string &caption, message_box_buttons buttons) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(owner.handle(), text, caption, buttons, message_box_icon::none, message_box_default_button::button1, static_cast<message_box_options>(0), false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const iwin32_window& owner, const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(owner.handle(), text, caption, buttons, icon, message_box_default_button::button1, static_cast<message_box_options>(0), false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const iwin32_window& owner, const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(owner.handle(), text, caption, buttons, icon, default_button, static_cast<message_box_options>(0), false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const iwin32_window& owner, const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(owner.handle(), text, caption, buttons, icon, default_button, options, false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const iwin32_window& owner, const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(owner.handle(), text, caption, buttons, icon, default_button, options, display_help_button);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const std::string &text) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(0, text, "", message_box_buttons::ok, message_box_icon::none, message_box_default_button::button1, static_cast<message_box_options>(0), false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const std::string &text, const std::string &caption) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(0, text, caption, message_box_buttons::ok, message_box_icon::none, message_box_default_button::button1, static_cast<message_box_options>(0), false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const std::string &text, const std::string &caption, message_box_buttons buttons) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(0, text, caption, buttons, message_box_icon::none, message_box_default_button::button1, static_cast<message_box_options>(0), false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(0, text, caption, buttons, icon, message_box_default_button::button1, static_cast<message_box_options>(0), false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(0, text, caption, buttons, icon, default_button, static_cast<message_box_options>(0), false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(0, text, caption, buttons, icon, default_button, options, false);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

dialog_result message_box::show(const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {
  application::raise_enter_thread_modal(event_args::empty);
  dialog_result result = show_message_box(0, text, caption, buttons, icon, default_button, options, display_help_button);
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}
