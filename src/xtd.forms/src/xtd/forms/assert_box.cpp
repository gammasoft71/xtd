#include "../../../include/xtd/forms/assert_box.hpp"
#include "../../../include/xtd/forms/assert_dialog.hpp"

using namespace xtd;
using namespace xtd::forms;

dialog_result assert_box::show(const iwin32_window& owner, const xtd::diagnostics::stack_frame& stack_frame) {
  return show_assert_box(&owner, string::empty_string, stack_frame);
}

dialog_result assert_box::show(const iwin32_window& owner, const string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  return show_assert_box(&owner, message, stack_frame);
}

dialog_result assert_box::show(const xtd::diagnostics::stack_frame& stack_frame) {
  return show_assert_box(nullptr, string::empty_string, stack_frame);
}

dialog_result assert_box::show(const string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  return show_assert_box(nullptr, message, stack_frame);
}

dialog_result assert_box::show_assert_box(const iwin32_window* owner, const string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  auto dialog = assert_dialog {};
  dialog.message(message);
  return owner ? dialog.show_sheet_dialog(*owner, stack_frame) : dialog.show_dialog(stack_frame);
}
