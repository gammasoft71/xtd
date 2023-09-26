#include "../../../include/xtd/forms/folder_browser_dialog"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/folder_browser_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "xtd_forms_common_dialog_closed_caller.h"

using namespace xtd;
using namespace xtd::forms;

struct folder_browser_dialog::data {
  xtd::ustring description;
  environment::special_folder root_folder = environment::special_folder::desktop;
  xtd::ustring selected_path;
  size_t options =  BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
};

folder_browser_dialog::folder_browser_dialog() : data_(std::make_shared<data>()) {
}

bool folder_browser_dialog::auto_upgrade_enable() const noexcept {
  return get_option(BIF_USENEWUI);
}

folder_browser_dialog& folder_browser_dialog::auto_upgrade_enable(bool value) {
  set_option(BIF_USENEWUI, value);
  return *this;
}

const xtd::ustring& folder_browser_dialog::description() const noexcept {
  return data_->description;
}

folder_browser_dialog& folder_browser_dialog::description(const xtd::ustring& value) {
  data_->description = value;
  return *this;
}

environment::special_folder folder_browser_dialog::root_folder() const noexcept {
  return data_->root_folder;
}

folder_browser_dialog& folder_browser_dialog::root_folder(environment::special_folder value) {
  data_->root_folder = value;
  return *this;
}

const xtd::ustring& folder_browser_dialog::selected_path() const noexcept {
  return data_->selected_path;
}

folder_browser_dialog& folder_browser_dialog::selected_path(const xtd::ustring& value) {
  data_->selected_path = value;
  return *this;
}

bool folder_browser_dialog::show_new_folder_button() const noexcept {
  return !get_option(BIF_NONEWFOLDERBUTTON);
}

folder_browser_dialog& folder_browser_dialog::show_new_folder_button(bool value) {
  set_option(BIF_NONEWFOLDERBUTTON, !value);
  return *this;
}

void folder_browser_dialog::reset() noexcept {
  set_dialog_result(xtd::forms::dialog_result::none);
  data_->options = BIF_USENEWUI;
}

bool folder_browser_dialog::run_dialog(intptr owner) {
  return native::folder_browser_dialog::run_dialog(owner, data_->description, data_->root_folder, data_->selected_path, data_->options);
}

void folder_browser_dialog::run_sheet(intptr owner) {
  if (!owner) run_dialog(owner);
  else native::folder_browser_dialog::run_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, data_->description, data_->root_folder, data_->selected_path, data_->options);
}

bool folder_browser_dialog::get_option(size_t flag) const noexcept {
  return (data_->options & flag) == flag;
}

void folder_browser_dialog::set_option(size_t flag, bool value) {
  data_->options = value ? data_->options | flag : data_->options & ~flag;
}
