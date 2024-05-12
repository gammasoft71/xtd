#include "../../../include/xtd/forms/assert_box.h"
#include "../../../include/xtd/forms/assert_dialog.h"

using namespace xtd;
using namespace xtd::forms;

dialog_result assert_box::show(const iwin32_window& owner) {
  return show_assert_box(&owner);
}

dialog_result assert_box::show(const iwin32_window& owner, const ustring& message) {
  return show_assert_box(&owner, message);
}

dialog_result assert_box::show(const iwin32_window& owner, const xtd::diagnostics::stack_frame& stack_frame) {
  return show_assert_box(&owner, ustring::empty_string, stack_frame);
}

dialog_result assert_box::show(const iwin32_window& owner, const ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  return show_assert_box(&owner, message, stack_frame);
}

dialog_result assert_box::show() {
  return show_assert_box(nullptr);
}

dialog_result assert_box::show(const ustring& message) {
  return show_assert_box(nullptr, message);
}

dialog_result assert_box::show(const xtd::diagnostics::stack_frame& stack_frame) {
  return show_assert_box(nullptr, ustring::empty_string, stack_frame);
}

dialog_result assert_box::show(const ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  return show_assert_box(nullptr, message, stack_frame);
}

dialog_result assert_box::show_assert_box(const iwin32_window* owner, const ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  auto dialog = assert_dialog {};
  dialog.message(message);
  dialog.stack_frame(stack_frame);
  return owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
}
