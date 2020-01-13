#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/date_time_picker.hpp>
#include <xtd/forms/native/date_time_picker_styles.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/date_time_picker.hpp"

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

control& date_time_picker::max_date(const std::tm& max_date) {
  if (max_date_.tm_sec != max_date.tm_sec || max_date_.tm_min != max_date.tm_min || max_date_.tm_hour != max_date.tm_hour || max_date_.tm_mday != max_date.tm_mday || max_date_.tm_mon != max_date.tm_mon || max_date_.tm_year != max_date.tm_year) {
    max_date_ = max_date;
    //native::date_time_picker::max_date(handle_, max_date_);
    //value(native::date_time_picker::value(handle_));
  }
  return *this;
}

control& date_time_picker::min_date(const std::tm& min_date) {
  if (min_date_.tm_sec != min_date.tm_sec || min_date_.tm_min != min_date.tm_min || min_date_.tm_hour != min_date.tm_hour || min_date_.tm_mday != min_date.tm_mday || min_date_.tm_mon != min_date.tm_mon || min_date_.tm_year != min_date.tm_year) {
    min_date_ = min_date;
    //native::date_time_picker::min_date(handle_, min_date_);
    //value(native::date_time_picker::value(handle_));
  }
  return *this;
}

control& date_time_picker::value(const std::tm& value) {
  if (value_.tm_sec != value.tm_sec || value_.tm_min != value.tm_min || value_.tm_hour != value.tm_hour || value_.tm_mday != value.tm_mday || value_.tm_mon != value.tm_mon || value_.tm_year != value.tm_year) {
    value_ = value;
    native::date_time_picker::value(handle_, value_);
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
  native::date_time_picker::value(handle_, value_);
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
  auto new_value = native::date_time_picker::value(handle_);
  if (mktime(&new_value) < mktime(&min_date_))
    native::date_time_picker::value(handle_, min_date_);
  else if (mktime(&new_value) >= mktime(&max_date_))
    native::date_time_picker::value(handle_, max_date_);
  else
    native::date_time_picker::value(handle_, value_);
  on_value_changed(event_args::empty);
}
