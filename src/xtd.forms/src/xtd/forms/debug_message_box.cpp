#include "../../../include/xtd/forms/debug_message_box.h"

using namespace xtd;
using namespace xtd::forms;

dialog_result debug_message_box::show(const ustring& text) {
  return show_message_dialog(nullptr, text, application::product_name(), message_box_buttons::ok, message_box_icon::error);
}

dialog_result debug_message_box::show(const iwin32_window& owner, const ustring& text) {
  return show_message_dialog(&owner, text, application::product_name(), message_box_buttons::ok, message_box_icon::error);
  
}
