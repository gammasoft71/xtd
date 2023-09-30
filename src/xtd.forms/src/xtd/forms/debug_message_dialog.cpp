#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/debug_message_dialog.h"

using namespace xtd;
using namespace xtd::forms;

debug_message_dialog::debug_message_dialog() {
  dialog_.dialog_closed += [&](object & sender, const dialog_closed_event_args & e) {on_dialog_closed(e);};
  reset();
}

dialog_result debug_message_dialog::dialog_result() const noexcept {
  return dialog_.dialog_result();
}

ustring debug_message_dialog::message() const noexcept {
  return dialog_.message();
}

void debug_message_dialog::reset() {
  dialog_.reset();
  dialog_.buttons(xtd::forms::message_dialog_buttons::ok);
  dialog_.icon(xtd::forms::message_dialog_icon::exclamation);
  dialog_.text(xtd::forms::application::product_name());
}

void debug_message_dialog::on_dialog_closed(const dialog_closed_event_args& e) {
  auto raise_event = dialog_closed;
  if (!raise_event.is_empty()) raise_event(*this, e);
}
