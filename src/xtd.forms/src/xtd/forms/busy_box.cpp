#include "../../../include/xtd/forms/busy_box.hpp"

using namespace xtd;
using namespace xtd::forms;

xtd::uptr<busy_dialog> busy_box::dialog_;

void busy_box::hide() {dialog_.reset();}

void busy_box::show(const iwin32_window& owner) {
  show_busy_dialog(&owner);
}

void busy_box::show(const iwin32_window& owner, const xtd::string& text) {
  show_busy_dialog(&owner, text);
}

void busy_box::show(const iwin32_window& owner, const xtd::string& text, const xtd::string& caption) {
  show_busy_dialog(&owner, text, caption);
}

void busy_box::show(const iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon) {
  show_busy_dialog(&owner, text, caption, icon);
}

void busy_box::show(const iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color) {
  show_busy_dialog(&owner, text, caption, icon, back_color);
}

void busy_box::show(const iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color) {
  show_busy_dialog(&owner, text, caption, icon, back_color, fore_color);
}

void busy_box::show(const iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, float opacity) {
  show_busy_dialog(&owner, text, caption, icon, back_color, fore_color, opacity);
}

void busy_box::show() {
  show_busy_dialog(nullptr);
}

void busy_box::show(const xtd::string& text) {
  show_busy_dialog(nullptr, text);
}

void busy_box::show(const xtd::string& text, const xtd::string& caption) {
  show_busy_dialog(nullptr, text, caption);
}

void busy_box::show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon) {
  show_busy_dialog(nullptr, text, caption, icon);
}

void busy_box::show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color) {
  show_busy_dialog(nullptr, text, caption, icon, back_color);
}

void busy_box::show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color) {
  show_busy_dialog(nullptr, text, caption, icon, back_color, fore_color);
}

void busy_box::show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, float opacity) {
  show_busy_dialog(nullptr, text, caption, icon, back_color, fore_color, opacity);
}

void busy_box::show_busy_dialog(const iwin32_window* owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, float opacity) {
  if (dialog_) return;
  dialog_ = xtd::new_uptr<busy_dialog>();
  dialog_->description(text);
  dialog_->text(caption);
  dialog_->icon(icon);
  dialog_->back_color(back_color);
  dialog_->fore_color(fore_color);
  dialog_->opacity(opacity);
  owner ? dialog_->show(*owner) : dialog_->show();
}
