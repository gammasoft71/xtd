#include "../../../include/xtd/forms/exception_box.h"

using namespace xtd;
using namespace xtd::forms;

dialog_result exception_box::show(const iwin32_window& owner) {
  return show_exception_box(&owner);
}

dialog_result exception_box::show(const iwin32_window& owner, const xtd::ustring& caption) {
  return show_exception_box(&owner, nullptr, caption);
}

dialog_result exception_box::show(const iwin32_window& owner, const std::exception& exception) {
  return show_exception_box(&owner, &exception);
}

dialog_result exception_box::show(const iwin32_window& owner, const std::exception& exception, const xtd::ustring& caption) {
  return show_exception_box(&owner, &exception, caption);
}

dialog_result exception_box::show() {
  return show_exception_box(nullptr);
}

dialog_result exception_box::show(const xtd::ustring& caption) {
  return show_exception_box(nullptr, nullptr, caption);
}

dialog_result exception_box::show(const std::exception& exception) {
  return show_exception_box(nullptr, &exception);
}

dialog_result exception_box::show(const std::exception& exception, const xtd::ustring& caption) {
  return show_exception_box(nullptr, &exception, caption);
}

dialog_result exception_box::show_exception_box(const iwin32_window* owner, const std::exception* exception, const xtd::ustring& caption) {
  exception_dialog dialog;
  if (exception) dialog.exception(*exception);
  dialog.text(caption);
  return owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
}
