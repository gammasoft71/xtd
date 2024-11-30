#include "../../../include/xtd/forms/input_box.hpp"
#include "../../../include/xtd/forms/input_dialog.hpp"

using namespace xtd;
using namespace xtd::forms;

dialog_result input_box::show(string& value, const iwin32_window& owner) {
  return show_input_box(value, &owner);
}

dialog_result input_box::show(string& value, const iwin32_window& owner, const string& text) {
  return show_input_box(value, &owner, text);
}

dialog_result input_box::show(string& value, const iwin32_window& owner, const string& text, const string& caption) {
  return show_input_box(value, &owner, text, caption);
}

dialog_result input_box::show(string& value, const iwin32_window& owner, const string& text, const string& caption, input_box_style style) {
  return show_input_box(value, &owner, text, caption, style);
}

dialog_result input_box::show(string& value, const iwin32_window& owner, const string& text, const string& caption, input_box_style style, character_casing casing) {
  return show_input_box(value, &owner, text, caption, style, casing);
}

dialog_result input_box::show(string& value, const iwin32_window& owner, const string& text, const string& caption, input_box_style style, character_casing casing, bool word_wrap) {
  return show_input_box(value, &owner, text, caption, style, casing, word_wrap);
}

dialog_result input_box::show(string& value) {
  return show_input_box(value);
}

dialog_result input_box::show(string& value, const string& text) {
  return show_input_box(value, nullptr, text);
}

dialog_result input_box::show(string& value, const string& text, const string& caption) {
  return show_input_box(value, nullptr, text, caption);
}

dialog_result input_box::show(string& value, const string& text, const string& caption, input_box_style style) {
  return show_input_box(value, nullptr, text, caption, style);
}

dialog_result input_box::show(string& value, const string& text, const string& caption, input_box_style style, character_casing casing, bool word_wrap) {
  return show_input_box(value, nullptr, text, caption, style, casing, word_wrap);
}

dialog_result input_box::show_input_box(string& value, const iwin32_window* owner, const string& text, const string& caption, input_box_style style, character_casing casing, bool word_wrap) {
  auto dialog = input_dialog {};
  dialog.value(value);
  dialog.message(text);
  dialog.text(caption);
  dialog.character_casing(casing);
  dialog.multiline(style == input_box_style::multiline);
  dialog.use_system_password_char(style == input_box_style::password);
  dialog.word_wrap(word_wrap);
  auto result = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
  if (result == dialog_result::ok) value = dialog.value();
  return result;
}
