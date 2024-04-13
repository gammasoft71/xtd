#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/message_dialog.h"
#include "xtd_forms_message_dialog_closed_caller.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/message_box>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/threading/thread>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::threading;

struct message_dialog::data {
  xtd::forms::message_dialog_buttons buttons = xtd::forms::message_dialog_buttons::ok;
  xtd::forms::message_dialog_default_button default_button = xtd::forms::message_dialog_default_button::button1;
  xtd::forms::dialog_result dialog_result = xtd::forms::dialog_result::none;
  xtd::forms::dialog_appearance dialog_appearance = xtd::forms::dialog_appearance::system;
  bool display_help_button = false;
  xtd::forms::message_dialog_icon icon = xtd::forms::message_dialog_icon::none;
  xtd::forms::message_dialog_options options = static_cast<xtd::forms::message_dialog_options>(0);
  xtd::ustring message;
  xtd::ustring text;
};

message_dialog::message_dialog() : data_(std::make_shared<data>()) {
  data_->dialog_appearance = application::system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
}

xtd::forms::message_dialog_buttons message_dialog::buttons() const noexcept {
  return data_->buttons;
}

message_dialog& message_dialog::buttons(xtd::forms::message_dialog_buttons buttons) {
  data_->buttons = buttons;
  return *this;
}

xtd::forms::message_dialog_default_button message_dialog::default_button() const noexcept {
  return data_->default_button;
}

message_dialog& message_dialog::default_button(xtd::forms::message_dialog_default_button default_button) {
  data_->default_button = default_button;
  return *this;
}

bool message_dialog::display_help_button() const noexcept {
  return data_->display_help_button;
}

message_dialog& message_dialog::display_help_button(bool display_help_button) {
  data_->display_help_button = display_help_button;
  return *this;
}

xtd::forms::dialog_result message_dialog::dialog_result() const noexcept {
  return data_->dialog_result;
}

xtd::forms::dialog_appearance message_dialog::dialog_appearance() const noexcept {
  return data_->dialog_appearance;
}

message_dialog& message_dialog::dialog_appearance(xtd::forms::dialog_appearance dialog_appearance) {
  data_->dialog_appearance = dialog_appearance;
  return *this;
}

xtd::forms::message_dialog_icon message_dialog::icon() const noexcept {
  return data_->icon;
}

message_dialog& message_dialog::icon(xtd::forms::message_dialog_icon icon) {
  data_->icon = icon;
  return *this;
}

xtd::forms::message_dialog_options message_dialog::options() const noexcept {
  return data_->options;
}

message_dialog& message_dialog::options(xtd::forms::message_dialog_options options) {
  data_->options = options;
  return *this;
}

xtd::ustring message_dialog::message() const noexcept {
  return data_->message;
}

message_dialog& message_dialog::message(const xtd::ustring& message) {
  data_->message = message;
  return *this;
}

xtd::ustring message_dialog::text() const noexcept {
  return data_->text;
}

message_dialog& message_dialog::text(const xtd::ustring& text) {
  data_->text = text;
  return *this;
}

void message_dialog::reset() {
  data_->buttons = xtd::forms::message_dialog_buttons::ok;
  data_->default_button = xtd::forms::message_dialog_default_button::button1;
  data_->dialog_appearance = application::system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
  data_->display_help_button = false;
  data_->icon = xtd::forms::message_dialog_icon::none;
  data_->options = static_cast<xtd::forms::message_dialog_options>(0);
  data_->message = "";
  data_->text = "";
}

xtd::forms::dialog_result message_dialog::show_dialog() {
  on_dialog_closed(dialog_closed_event_args(static_cast<xtd::forms::dialog_result>(native::message_box::show(0, data_->message, data_->text, static_cast<uint32>(data_->buttons) + static_cast<uint32>(data_->icon) + static_cast<uint32>(data_->default_button) + static_cast<uint32>(data_->options), data_->display_help_button))));
  return data_->dialog_result;
}

xtd::forms::dialog_result message_dialog::show_dialog(const iwin32_window& owner) {
  on_dialog_closed(dialog_closed_event_args(static_cast<xtd::forms::dialog_result>(native::message_box::show(owner.handle(), data_->message, data_->text, static_cast<uint32>(data_->buttons) + static_cast<uint32>(data_->icon) + static_cast<uint32>(data_->default_button) + static_cast<uint32>(data_->options), data_->display_help_button))));
  return data_->dialog_result;
}

void message_dialog::show_sheet(const iwin32_window& owner) {
  data_->dialog_result = xtd::forms::dialog_result::none;
  native::message_box::show_sheet({*new __xtd_forms_message_dialog_closed_caller__(this), &__xtd_forms_message_dialog_closed_caller__::on_dialog_closed}, owner.handle(), data_->message, data_->text, static_cast<uint32>(data_->buttons) + static_cast<uint32>(data_->icon) + static_cast<uint32>(data_->default_button) + static_cast<uint32>(data_->options), data_->display_help_button);
}

xtd::forms::dialog_result message_dialog::show_sheet_dialog(const iwin32_window& owner) {
  show_sheet(owner);
  while (data_->dialog_result == xtd::forms::dialog_result::none) {
    application::do_events();
    thread::sleep(100_ms);
  }
  return data_->dialog_result;
}

void message_dialog::on_dialog_closed(const dialog_closed_event_args& e) {
  data_->dialog_result = e.dialog_result();
  dialog_closed(*this, e);
}
