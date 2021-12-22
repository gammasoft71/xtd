#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/date_time_picker.h>
#include <xtd/forms/native/date_time_picker_styles.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/date_time_picker.h"

using namespace xtd;
using namespace xtd::forms;

namespace {
  static std::tm make_tm(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
    std::tm date = {};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    date.tm_hour = hour;
    date.tm_min = minute;
    date.tm_sec = second;
    return date;
  }
}

control& date_time_picker::format(date_time_picker_format format) {
  if (format_ != format) {
    format_ = format;
    recreate_handle();
  }
  return *this;
}

std::chrono::system_clock::time_point date_time_picker::max_date() const {
  return max_date_;
}

control& date_time_picker::max_date(std::chrono::system_clock::time_point value) {
  if (max_date_ != value) {
    max_date_ = value;
    if (max_date_ < min_date_) min_date_ = max_date_;
    this->value(value_);
    if (is_handle_created()) native::date_time_picker::allowable_dates(handle(), min_date_, max_date_);
  }
  return *this;
}

control& date_time_picker::max_date(time_t value) {
  return max_date(std::chrono::system_clock::from_time_t(value));
}

control& date_time_picker::max_date(const std::tm& value) {
  std::tm date = value;
  return this->max_date(mktime(&date));
}


control& date_time_picker::max_date(int32_t year, int32_t month, int32_t day) {
  return max_date(year, month, day, 0, 0, 0);
}

control& date_time_picker::max_date(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
  std::tm date = make_tm(year, month, day, hour, minute, second);
  return max_date(mktime(&date));
}

std::chrono::system_clock::time_point date_time_picker::min_date() const {
  return min_date_;
}

control& date_time_picker::min_date(std::chrono::system_clock::time_point value) {
  if (min_date_ != value) {
    min_date_ = value;
    if (max_date_ < min_date_) max_date_ = min_date_;
    this->value(value_);
    if (is_handle_created()) native::date_time_picker::allowable_dates(handle(), min_date_, max_date_);
  }
  return *this;
}

control& date_time_picker::min_date(time_t value) {
  return this->min_date(std::chrono::system_clock::from_time_t(value));
}

control& date_time_picker::min_date(const std::tm& value) {
  std::tm date = value;
  return this->min_date(mktime(&date));
}

control& date_time_picker::min_date(int32_t year, int32_t month, int32_t day) {
  return min_date(year, month, day, 0, 0, 0);
}


control& date_time_picker::min_date(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
  std::tm date = make_tm(year, month, day, hour, minute, second);
  return min_date(mktime(&date));
}

std::chrono::system_clock::time_point date_time_picker::value() const {
  return value_;
}

control& date_time_picker::value(std::chrono::system_clock::time_point value) {
  if (value < min_date_) value = min_date_;
  if (value > max_date_) value = max_date_;
  if (value_ != value) {
    value_ = value;
    if (is_handle_created()) native::date_time_picker::value(handle(), value_);
    on_value_changed(event_args::empty);
  }
  return *this;
}

control& date_time_picker::value(time_t value) {
  return this->value(std::chrono::system_clock::from_time_t(value));
}

control& date_time_picker::value(const std::tm& value) {
  std::tm date = value;
  return this->value(mktime(&date));
}

control& date_time_picker::value(int32_t year, int32_t month, int32_t day) {
  return value(year, month, day, 0, 0, 0);
}

control& date_time_picker::value(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
  std::tm date = make_tm(year, month, day, hour, minute, second);
  return value(mktime(&date));
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
  native::date_time_picker::allowable_dates(handle(), min_date_, max_date_);
  native::date_time_picker::value(handle(), value_);
}

void date_time_picker::on_value_changed(const event_args& e) {
  if (can_raise_events()) value_changed(*this, e);
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
