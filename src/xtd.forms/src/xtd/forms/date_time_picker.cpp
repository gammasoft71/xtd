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

date_time_picker::date_time_picker() {
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::fixed_height, true);
  set_style(control_styles::user_paint | control_styles::standard_click, false);  
}

control& date_time_picker::format(date_time_picker_format format) {
  if (format_ != format) {
    format_ = format;
    post_recreate_handle();
  }
  return *this;
}

date_time date_time_picker::max_date() const {
  return max_date_;
}

control& date_time_picker::max_date(date_time value) {
  if (max_date_ != value) {
    max_date_ = value;
    if (max_date_ < min_date_) min_date_ = max_date_;
    if (is_handle_created()) native::date_time_picker::allowable_dates(handle(), min_date_, max_date_);
    this->value(value_);
  }
  return *this;
}

date_time date_time_picker::min_date() const {
  return min_date_;
}

control& date_time_picker::min_date(date_time value) {
  if (min_date_ != value) {
    min_date_ = value;
    if (max_date_ < min_date_) max_date_ = min_date_;
    if (is_handle_created()) native::date_time_picker::allowable_dates(handle(), min_date_, max_date_);
    this->value(value_);
  }
  return *this;
}

date_time date_time_picker::value() const {
  return value_;
}

control& date_time_picker::value(date_time value) {
  if (value < min_date_) value = min_date_;
  if (value > max_date_) value = max_date_;
  if (value_ != value) {
    value_ = value;
    if (is_handle_created()) native::date_time_picker::value(handle(), value_);
    on_value_changed(event_args::empty);
  }
  return *this;
}

drawing::color date_time_picker::default_back_color() const {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color date_time_picker::default_fore_color() const {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

forms::create_params date_time_picker::create_params() const {
  forms::create_params create_params = control::create_params();
  create_params.class_name("datetimepicker");
  switch (format_) {
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

void date_time_picker::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_click(message); break;
    default: control::wnd_proc(message);
  }
}

void date_time_picker::wm_click(message& message) {
  def_wnd_proc(message);
  if (native::date_time_picker::value(handle()) < min_date_) native::date_time_picker::value(handle(), min_date_);
  if (native::date_time_picker::value(handle()) > max_date_) native::date_time_picker::value(handle(), max_date_);
  if (value_ != native::date_time_picker::value(handle())) {
    value_ = native::date_time_picker::value(handle());
    on_value_changed(event_args::empty);
  }
}
