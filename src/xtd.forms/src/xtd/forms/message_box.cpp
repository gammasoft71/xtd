#include "../../../include/xtd/forms/message_box"
#include "../../../include/xtd/forms/message_dialog"

using namespace xtd;
using namespace xtd::forms;

dialog_result message_box::show(const iwin32_window& owner) {
  return show_message_dialog(&owner);
}

dialog_result message_box::show(const iwin32_window& owner, const ustring& text) {
  return show_message_dialog(&owner, text);
}

dialog_result message_box::show(const iwin32_window& owner, const ustring& text, const ustring& caption) {
  return show_message_dialog(&owner, text, caption);
}

dialog_result message_box::show(const iwin32_window& owner, const ustring& text, const ustring& caption, message_box_buttons buttons) {
  return show_message_dialog(&owner, text, caption, buttons);
}

dialog_result message_box::show(const iwin32_window& owner, const ustring& text, const ustring& caption, message_box_buttons buttons, message_box_icon icon) {
  return show_message_dialog(&owner, text, caption, buttons, icon);
}

dialog_result message_box::show(const iwin32_window& owner, const ustring& text, const ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button) {
  return show_message_dialog(&owner, text, caption, buttons, icon, default_button);
}

dialog_result message_box::show(const iwin32_window& owner, const ustring& text, const ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options) {
  return show_message_dialog(&owner, text, caption, buttons, icon, default_button, options);
}

dialog_result message_box::show(const iwin32_window& owner, const ustring& text, const ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {
  return show_message_dialog(&owner, text, caption, buttons, icon, default_button, options, display_help_button);
}

dialog_result message_box::show() {
  return show_message_dialog(nullptr);
}

dialog_result message_box::show(const ustring& text) {
  return show_message_dialog(nullptr, text);
}

dialog_result message_box::show(const ustring& text, const ustring& caption) {
  return show_message_dialog(nullptr, text, caption);
}

dialog_result message_box::show(const ustring& text, const ustring& caption, message_box_buttons buttons) {
  return show_message_dialog(nullptr, text, caption, buttons);
}

dialog_result message_box::show(const ustring& text, const ustring& caption, message_box_buttons buttons, message_box_icon icon) {
  return show_message_dialog(nullptr, text, caption, buttons, icon);
}

dialog_result message_box::show(const ustring& text, const ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button) {
  return show_message_dialog(nullptr, text, caption, buttons, icon, default_button);
}

dialog_result message_box::show(const ustring& text, const ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options) {
  return show_message_dialog(nullptr, text, caption, buttons, icon, default_button, options);
}

dialog_result message_box::show(const ustring& text, const ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {
  return show_message_dialog(nullptr, text, caption, buttons, icon, default_button, options, display_help_button);
}

dialog_result message_box::show_message_dialog(const iwin32_window* owner, const ustring& text, const ustring& caption, message_box_buttons buttons, message_box_icon icon, message_box_default_button default_button, message_box_options options, bool display_help_button) {
  auto dialog = message_dialog {};
  dialog.buttons(buttons);
  dialog.default_button(default_button);
  dialog.display_help_button(display_help_button);
  dialog.icon(icon);
  dialog.message(text);
  dialog.options(options);
  dialog.text(caption);
  return owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
}
