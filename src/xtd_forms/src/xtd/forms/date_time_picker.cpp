#include <xtd/forms/native/control.h>
#include <xtd/forms/native/date_time_picker.h>
#include <xtd/forms/native/date_time_picker_styles.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/date_time_picker.h"

using namespace xtd;
using namespace xtd::forms;

date_time_picker::date_time_picker() {
  can_focus_ = false;
  size_ = default_size();
}

control& date_time_picker::format(date_time_picker_format format) {
  if (format_ != format) {
    format_ = format;
    recreate_handle();
  }
  return *this;
}

control& date_time_picker::max_date(std::chrono::system_clock::time_point max_date) {
  if (max_date_ != max_date) {
    max_date_ = max_date;
    if (max_date_ < min_date_) min_date_ = max_date_;
   value(value_);
  }
  return *this;
}

control& date_time_picker::min_date(std::chrono::system_clock::time_point min_date) {
  if (min_date_ != min_date) {
    min_date_ = min_date;
    if (max_date_ < min_date_) max_date_ = min_date_;
    value(value_);
  }
  return *this;
}

control& date_time_picker::value(std::chrono::system_clock::time_point value) {
  if (value_ != value) {
    if (value < min_date_) value = min_date_;
    if (value > max_date_) value = max_date_;
    value_ = value;
    native::date_time_picker::value(handle(), value_);
    on_value_changed(event_args::empty);
  }
  return *this;
}

forms::create_params date_time_picker::create_params() const {
  forms::create_params create_params = control::create_params();
  create_params.class_name("datetimepicker");
  switch(format_) {
    case date_time_picker_format::long_format: create_params.style(create_params.style() | DTS_LONGDATEFORMAT); break;
    case date_time_picker_format::short_format: create_params.style(create_params.style() | DTS_SHORTDATEFORMAT); break;
    case date_time_picker_format::time: create_params.style(create_params.style() | DTS_TIMEFORMAT); break;
    default: create_params.style(create_params.style() | DTS_LONGDATEFORMAT); break;
  }
  return create_params;
}

void date_time_picker::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::date_time_picker::value(handle(), value_);
}

void date_time_picker::on_value_changed(const event_args& e) {
  if (this->can_raise_events()) this->value_changed(*this, e);
}

void date_time_picker::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_COMMAND: wm_click(message); break;
    default: control::wnd_proc(message);
  }
}

void date_time_picker::wm_click(message& message) {
  def_wnd_proc(message);
  value(native::date_time_picker::value(handle()));
  on_value_changed(event_args::empty);
}
