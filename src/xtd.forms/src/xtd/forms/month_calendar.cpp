#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/month_calendar.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/month_calendar.h"

using namespace xtd;
using namespace xtd::forms;

month_calendar::month_calendar() {
  //back_color(default_back_color());
  //fore_color(default_fore_color());
  //set_can_focus(false);
  size(default_size());
}

std::pair<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point> xtd::forms::month_calendar::date_range() const {
  std::chrono::system_clock::time_point from_date{}, to_date{};
  native::month_calendar::get_date_range(handle(), from_date, to_date);
  return std::make_pair(from_date, to_date);
}

control& xtd::forms::month_calendar::date_range(const std::chrono::system_clock::time_point from_date, const std::chrono::system_clock::time_point to_date) {
  native::month_calendar::set_date_range(handle(), from_date, to_date);
#pragma region Questionable
  //TODO
  //min_date(from_date);
  //max_date(to_date);
#pragma endregion
  return *this;
}

control& month_calendar::max_date(std::chrono::system_clock::time_point max_date) {
  if (max_date_ != max_date) {
    max_date_ = max_date;
    if (max_date_ < min_date_) min_date_ = max_date_;
   value(value_);
  }
  return *this;
}

control& month_calendar::min_date(std::chrono::system_clock::time_point min_date) {
  if (min_date_ != min_date) {
    min_date_ = min_date;
    if (max_date_ < min_date_) max_date_ = min_date_;
    value(value_);
  }
  return *this;
}

control& month_calendar::value(std::chrono::system_clock::time_point value) {
  if (value_ != value) {
    if (value < min_date_) value = min_date_;
    if (value > max_date_) value = max_date_;
    value_ = value;
    if (is_handle_created()) native::month_calendar::value(handle(), value_);
    on_value_changed(event_args::empty);
  }
  return *this;
}

forms::create_params month_calendar::create_params() const {
  forms::create_params create_params = control::create_params();
  create_params.class_name("monthcalendar");
  //switch(format_) {
  //  case month_calendar_format::long_format: create_params.style(create_params.style() | DTS_LONGDATEFORMAT); break;
  //  case month_calendar_format::short_format: create_params.style(create_params.style() | DTS_SHORTDATEFORMAT); break;
  //  case month_calendar_format::time: create_params.style(create_params.style() | DTS_TIMEFORMAT); break;
  //  default: create_params.style(create_params.style() | DTS_LONGDATEFORMAT); break;
  //}
  return create_params;
}

void month_calendar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::month_calendar::value(handle(), value_);
}

void month_calendar::on_value_changed(const event_args& e) {
  if (can_raise_events()) value_changed(*this, e);
}

void month_calendar::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_COMMAND: wm_click(message); break;
    default: control::wnd_proc(message);
  }
}

void month_calendar::wm_click(message& message) {
  def_wnd_proc(message);
  value(native::month_calendar::value(handle()));
  on_value_changed(event_args::empty);
}
