#include "../../../include/xtd/forms/application"
#include "../../../include/xtd/forms/open_file_dialog"
#include "file_dialog_data.h"
#include "xtd_forms_common_dialog_closed_caller.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/file_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

std::ifstream open_file_dialog::open_file() const noexcept {
  return io::file::open_read(xtd::ustring(data_->file_name));
}

bool open_file_dialog::multiselect() const noexcept {
  return get_option(OFN_ALLOWMULTISELECT);
}

open_file_dialog& open_file_dialog::multiselect(bool value) {
  set_option(OFN_ALLOWMULTISELECT, value);
  return *this;
}

bool open_file_dialog::run_file_dialog(intptr owner) {
  return native::file_dialog::run_open_dialog(owner, data_->default_ext, data_->file_name, data_->file_names, data_->filter, data_->filter_index, data_->initial_directory, data_->options, data_->support_multi_dotted_extensions, data_->title);
}

void open_file_dialog::run_file_sheet(intptr owner) {
  if (!owner) run_file_dialog(owner);
  else native::file_dialog::run_open_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, data_->default_ext, data_->file_name, data_->file_names, data_->filter, data_->filter_index, data_->initial_directory, data_->options, data_->support_multi_dotted_extensions, data_->title);
}
