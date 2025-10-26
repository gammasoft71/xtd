#include "../../../include/xtd/forms/trace_message_dialog.hpp"
#include "../../../include/xtd/forms/application.hpp"

using namespace xtd;
using namespace xtd::forms;

trace_message_dialog::trace_message_dialog() {
  dialog_.dialog_closed += [&](object & sender, const dialog_closed_event_args & e) {on_dialog_closed(e);};
  reset();
}

dialog_result trace_message_dialog::dialog_result() const noexcept {
  return dialog_.dialog_result();
}

string trace_message_dialog::message() const noexcept {
  return dialog_.message();
}

void trace_message_dialog::reset() {
  dialog_.reset();
  dialog_.buttons(message_dialog_buttons::ok);
  dialog_.icon(message_dialog_icon::exclamation);
  dialog_.text(application::product_name());
}

void trace_message_dialog::on_dialog_closed(const dialog_closed_event_args& e) {
  if (!can_raise_events()) return;
  auto safe_dialog_closed = dialog_closed;
  if (safe_dialog_closed.is_empty()) return;
  safe_dialog_closed(*this, e);
}
