#include "../../../include/xtd/forms/assert_dialog"
#include "../../../include/xtd/forms/message_dialog"
#include <xtd/diagnostics/debug>
#include <xtd/as>
#include <xtd/literals>

using namespace xtd;
using namespace xtd::forms;

struct assert_dialog::data {
  message_dialog dialog;
  forms::dialog_result dialog_result = forms::dialog_result::none;
  ustring message;
  diagnostics::stack_frame stack_frame = diagnostics::stack_frame::empty();
};

assert_dialog::assert_dialog() : data_(std::make_shared<data>()) {
  data_->dialog.dialog_closed += [this](const object& sender, const dialog_closed_event_args& e) {on_dialog_closed(e);};
  reset();
}

forms::dialog_result assert_dialog::dialog_result() const noexcept {
  return data_->dialog_result;
}

forms::dialog_appearance assert_dialog::dialog_appearance() const noexcept {
  return data_->dialog.dialog_appearance();
}

assert_dialog& assert_dialog::dialog_appearance(forms::dialog_appearance dialog_appearance) {
  data_->dialog.dialog_appearance(dialog_appearance);
  return *this;
}

ustring assert_dialog::message() const noexcept {
  return data_->message;
}

assert_dialog& assert_dialog::message(const ustring& message) {
  if (data_->message == message) return *this;
  data_->message = message;
  set_message();
  return *this;
}

diagnostics::stack_frame assert_dialog::stack_frame() const noexcept {
  return data_->stack_frame;
}

assert_dialog& assert_dialog::stack_frame(const diagnostics::stack_frame& stack_frame) {
  if (data_->stack_frame == stack_frame) return *this;
  data_->stack_frame = stack_frame;
  set_message();
  return *this;
}

void assert_dialog::reset() noexcept {
  data_->dialog.reset();
  data_->dialog.buttons(message_dialog_buttons::abort_retry_ignore);
  data_->dialog.icon(forms::message_dialog_icon::warning);
  data_->dialog.text(diagnostics::debug::assert_dialog_caption());
  data_->dialog_result = forms::dialog_result::none;
  data_->message = "";
  data_->stack_frame = diagnostics::stack_frame::empty();
  set_message();
}

xtd::forms::dialog_result assert_dialog::show_dialog() {
  return data_->dialog.show_dialog();
}

xtd::forms::dialog_result assert_dialog::show_dialog(const iwin32_window& owner) {
  return data_->dialog.show_dialog(owner);
}

void assert_dialog::show_sheet(const iwin32_window& owner) {
  data_->dialog.show_sheet(owner);
}

forms::dialog_result assert_dialog::show_sheet_dialog(const iwin32_window& owner) {
  return data_->dialog.show_sheet_dialog(owner);
}

void assert_dialog::on_dialog_closed(const dialog_closed_event_args& e) {
  data_->dialog_result = e.dialog_result();
  dialog_closed(*this, e);
}

void assert_dialog::set_message() noexcept {
  if (data_->stack_frame == diagnostics::stack_frame::empty() && data_->message == "") data_->dialog.message("");
  else if (data_->stack_frame == diagnostics::stack_frame::empty() && data_->message != "") data_->dialog.message(data_->message);
  else if (data_->stack_frame != diagnostics::stack_frame::empty() && data_->message == "") data_->dialog.message(diagnostics::stack_trace(data_->stack_frame).to_string());
  else data_->dialog.message(ustring::format("{}\n\n{}", data_->message, diagnostics::stack_trace(data_->stack_frame)));
}
