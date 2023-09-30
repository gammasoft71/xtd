#include "../../../include/xtd/forms/save_file_dialog.h"
#include "file_dialog_data.h"
#include "xtd_forms_common_dialog_closed_caller.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/file_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

std::fstream save_file_dialog::open_file() const noexcept {
  return io::file::open(xtd::ustring(data_->file_name), std::ios::binary | std::ios::in | std::ios::out);
}

bool save_file_dialog::run_file_dialog(intptr owner) {
  return native::file_dialog::run_save_dialog(owner, data_->default_ext, data_->file_name, data_->file_names, data_->filter, data_->filter_index, data_->initial_directory, data_->options, data_->support_multi_dotted_extensions, data_->title);
}

void save_file_dialog::run_file_sheet(intptr owner) {
  if (!owner) run_file_dialog(owner);
  else native::file_dialog::run_save_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, data_->default_ext, data_->file_name, data_->file_names, data_->filter, data_->filter_index, data_->initial_directory, data_->options, data_->support_multi_dotted_extensions, data_->title);
}
