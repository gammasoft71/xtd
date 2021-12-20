#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/month_calendar.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/month_calendar.h"

using namespace xtd;
using namespace xtd::forms;

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
   }
  return *this;
}

forms::create_params month_calendar::create_params() const {
  forms::create_params create_params = control::create_params();
  create_params.class_name("monthcalendar");
  return create_params;
}

void month_calendar::on_date_changed(const event_args& e) {
  if (can_raise_events()) date_changed(*this, e);
}

void month_calendar::on_date_selected(const event_args& e) {
  if (can_raise_events()) date_selected(*this, e);
}

void month_calendar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::month_calendar::value(handle(), value_);
}

void month_calendar::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_NOTIFY: wm_notify(message); break;
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_XBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_XBUTTONUP:
    case WM_LBUTTONDBLCLK:
    case WM_MBUTTONDBLCLK:
    case WM_RBUTTONDBLCLK:
    case WM_XBUTTONDBLCLK: def_wnd_proc(message); break; // Mouse events are not supported
    default: control::wnd_proc(message);
  }
}

void month_calendar::wm_notify(message& message) {
  NMHDR* nmhdr = reinterpret_cast<NMHDR*>(message.lparam());
  switch (nmhdr->code) {
    case MCN_SELECT: wm_date_selected(message); break;
    case MCN_SELCHANGE: wm_date_changed(message); break;
    case MCN_VIEWCHANGE: wm_view_changed(message); break;
    default: break;
  }
}

void month_calendar::wm_date_selected(message& message) {
  value_ = native::month_calendar::value(handle());
  on_date_selected(event_args::empty);
}

void month_calendar::wm_date_changed(message& message) {
  value_ = native::month_calendar::value(handle());
  on_date_changed(event_args::empty);
}

void month_calendar::wm_view_changed(message& message) {
  // Do something or not if view changed
}
