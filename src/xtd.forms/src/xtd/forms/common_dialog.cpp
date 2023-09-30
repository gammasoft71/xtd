#include "../../../include/xtd/forms/common_dialog.h"
#include <xtd/threading/thread>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::threading;

struct common_dialog::data {
  std::any tag;
  xtd::forms::dialog_result dialog_result = xtd::forms::dialog_result::none;
};

common_dialog::common_dialog() : data_(std::make_shared<data>()) {
}

xtd::forms::dialog_result common_dialog::dialog_result() const noexcept {
  return data_->dialog_result;
}

std::any common_dialog::tag() const noexcept {
  return data_->tag;
}

common_dialog& common_dialog::tag(const std::any& tag) {
  data_->tag = tag;
  return*this;
}

xtd::forms::dialog_result common_dialog::show_dialog() {
  auto form = form::active_form();
  data_->dialog_result = run_dialog(0) ? dialog_result::ok : dialog_result::cancel;
  on_dialog_closed(dialog_closed_event_args(data_->dialog_result));
  if (form.has_value()) form.value().get().activate();
  return data_->dialog_result;
}

xtd::forms::dialog_result common_dialog::show_dialog(const iwin32_window& owner) {
  auto form = form::active_form();
  data_->dialog_result = run_dialog(owner.handle()) ? dialog_result::ok : dialog_result::cancel;
  on_dialog_closed(dialog_closed_event_args(data_->dialog_result));
  if (form.has_value()) form.value().get().activate();
  return data_->dialog_result;
}

void common_dialog::show_sheet(const iwin32_window& owner) {
  data_->dialog_result = xtd::forms::dialog_result::none;
  run_sheet(owner.handle());
}

xtd::forms::dialog_result common_dialog::show_sheet_dialog(const iwin32_window& owner) {
  show_sheet(owner);
  while (data_->dialog_result == xtd::forms::dialog_result::none) {
    application::do_events();
    thread::sleep(10_ms);
  }
  return data_->dialog_result;
}

void common_dialog::on_dialog_closed(const dialog_closed_event_args& e) {
  data_->dialog_result = e.dialog_result();
  dialog_closed(*this, e);
}

void common_dialog::on_help_request(help_event_args& e) {
  help_request(*this, e);
}

void common_dialog::set_dialog_result(xtd::forms::dialog_result value) {
  data_->dialog_result = value;
}
