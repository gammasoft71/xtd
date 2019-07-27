#include <xtd/forms/native/message_box.hpp>
#include "../../../include/xtd/forms/control.hpp"
#include "../../../include/xtd/forms/message_box.hpp"

using namespace xtd::forms;

namespace  {
  dialog_result show_message_box(intptr_t hwnd, const std::string& text, const std::string& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {
    return static_cast<dialog_result>(native::message_box::show(hwnd, text, caption, static_cast<unsigned int>(buttons) + static_cast<unsigned int>(icon) + static_cast<unsigned int>(default_button) + static_cast<unsigned int>(options), display_help_button));
  }
}

dialog_result message_box::show(const control& owner, const std::string &text, const std::string &caption) {
  return show_message_box(owner.handle(), text, caption, message_box_buttons::ok, message_box_icon::none, message_box_default_button::button1, static_cast<message_box_options>(0), false);
}

dialog_result message_box::show(const control& owner, const std::string &text, const std::string &caption, message_box_buttons buttons) {
  return show_message_box(owner.handle(), text, caption, buttons, message_box_icon::none, message_box_default_button::button1, static_cast<message_box_options>(0), false);
}

dialog_result message_box::show(const control& owner, const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon) {
  return show_message_box(owner.handle(), text, caption, buttons, icon, message_box_default_button::button1, static_cast<message_box_options>(0), false);
}

dialog_result message_box::show(const control& owner, const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button) {
  return show_message_box(owner.handle(), text, caption, buttons, icon, default_button, static_cast<message_box_options>(0), false);
}

dialog_result message_box::show(const control& owner, const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options) {
  return show_message_box(owner.handle(), text, caption, buttons, icon, default_button, options, false);
}

dialog_result message_box::show(const control& owner, const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {
  return show_message_box(owner.handle(), text, caption, buttons, icon, default_button, options, display_help_button);
}

dialog_result message_box::show(const std::string &text, const std::string &caption) {
  return show_message_box(0, text, caption, message_box_buttons::ok, message_box_icon::none, message_box_default_button::button1, static_cast<message_box_options>(0), false);
}

dialog_result message_box::show(const std::string &text, const std::string &caption, message_box_buttons buttons) {
  return show_message_box(0, text, caption, buttons, message_box_icon::none, message_box_default_button::button1, static_cast<message_box_options>(0), false);
}

dialog_result message_box::show(const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon) {
  return show_message_box(0, text, caption, buttons, icon, message_box_default_button::button1, static_cast<message_box_options>(0), false);
}

dialog_result message_box::show(const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button) {
  return show_message_box(0, text, caption, buttons, icon, default_button, static_cast<message_box_options>(0), false);
}

dialog_result message_box::show(const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options) {
  return show_message_box(0, text, caption, buttons, icon, default_button, options, false);
}

dialog_result message_box::show(const std::string &text, const std::string &caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {
  return show_message_box(0, text, caption, buttons, icon, default_button, options, display_help_button);
}

