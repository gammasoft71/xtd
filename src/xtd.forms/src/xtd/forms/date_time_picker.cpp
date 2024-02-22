#include "../../../include/xtd/forms/date_time_picker.h"
#include <xtd/diagnostics/debug>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/date_time_picker>
#include <xtd/forms/native/date_time_picker_styles>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

struct date_time_picker::data {
  date_time_picker_format format = date_time_picker_format::long_format;
  date_time max_date = date_time::max_value;
  date_time min_date = date_time::min_value;
  date_time value = date_time::now();
};

date_time_picker::date_time_picker() : data_(std::make_shared<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  set_style(control_styles::fixed_height, true);
  set_style(control_styles::user_paint | control_styles::standard_click, false);
}

date_time_picker_format date_time_picker::format() const noexcept {
  return data_->format;
}

date_time_picker& date_time_picker::format(date_time_picker_format format) {
  if (data_->format == format) return *this;
  data_->format = format;
  post_recreate_handle();
  return *this;
}

date_time date_time_picker::max_date() const noexcept {
  return data_->max_date;
}

date_time_picker& date_time_picker::max_date(date_time value) {
  if (data_->max_date == value) return *this;
  data_->max_date = value;
  if (data_->max_date < data_->min_date) data_->min_date = data_->max_date;
  if (is_handle_created()) native::date_time_picker::allowable_dates(handle(), data_->min_date, data_->max_date);
  this->value(data_->value);
  return *this;
}

date_time date_time_picker::min_date() const noexcept {
  return data_->min_date;
}

date_time_picker& date_time_picker::min_date(date_time value) {
  if (data_->min_date == value) return *this;
  data_->min_date = value;
  if (data_->max_date < data_->min_date) data_->max_date = data_->min_date;
  if (is_handle_created()) native::date_time_picker::allowable_dates(handle(), data_->min_date, data_->max_date);
  this->value(data_->value);
  return *this;
}

date_time date_time_picker::value() const noexcept {
  return data_->value;
}

date_time_picker& date_time_picker::value(date_time value) {
  if (value < data_->min_date) value = data_->min_date;
  if (value > data_->max_date) value = data_->max_date;
  if (data_->value != value) {
    data_->value = value;
    if (is_handle_created()) native::date_time_picker::value(handle(), data_->value);
    on_value_changed(event_args::empty);
  }
  return *this;
}

date_time_picker date_time_picker::create() {
  return  date_time_picker {};
}

date_time_picker date_time_picker::create(const drawing::point& location) {
  auto result = date_time_picker {};
  result.location(location);
  return result;
}

date_time_picker date_time_picker::create(const drawing::point& location, const drawing::size& size) {
  auto result = date_time_picker {};
  result.location(location);
  result.size(size);
  return result;
}

date_time_picker date_time_picker::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = date_time_picker {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value) {
  auto result = date_time_picker {};
  result.value(value);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const drawing::point& location) {
  auto result = date_time_picker {};
  result.value(value);
  result.location(location);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const drawing::point& location, const drawing::size& size) {
  auto result = date_time_picker {};
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = date_time_picker {};
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const xtd::date_time& min_date) {
  auto result = date_time_picker {};
  result.value(value);
  result.min_date(min_date);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const xtd::date_time& min_date, const drawing::point& location) {
  auto result = date_time_picker {};
  result.value(value);
  result.min_date(min_date);
  result.location(location);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const xtd::date_time& min_date, const drawing::point& location, const drawing::size& size) {
  auto result = date_time_picker {};
  result.value(value);
  result.min_date(min_date);
  result.location(location);
  result.size(size);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const xtd::date_time& min_date, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = date_time_picker {};
  result.value(value);
  result.min_date(min_date);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date) {
  auto result = date_time_picker {};
  result.value(value);
  result.min_date(min_date);
  result.max_date(max_date);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location) {
  auto result = date_time_picker {};
  result.value(value);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size) {
  auto result = date_time_picker {};
  result.value(value);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  return result;
}

date_time_picker date_time_picker::create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = date_time_picker {};
  result.value(value);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

date_time_picker date_time_picker::create(const control& parent) {
  auto result = date_time_picker {};
  result.parent(parent);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const drawing::point& location) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.location(location);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const drawing::point& location) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const drawing::point& location, const drawing::size& size) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.min_date(min_date);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const drawing::point& location) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.min_date(min_date);
  result.location(location);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const drawing::point& location, const drawing::size& size) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.min_date(min_date);
  result.location(location);
  result.size(size);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.min_date(min_date);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.min_date(min_date);
  result.max_date(max_date);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  return result;
}

date_time_picker date_time_picker::create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = date_time_picker {};
  result.parent(parent);
  result.value(value);
  result.min_date(min_date);
  result.max_date(max_date);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

drawing::color date_time_picker::default_back_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color date_time_picker::default_fore_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

forms::create_params date_time_picker::create_params() const noexcept {
  auto create_params = control::create_params();
  create_params.class_name("datetimepicker");
  switch (data_->format) {
    case date_time_picker_format::long_format: create_params.style(create_params.style() | DTS_LONGDATEFORMAT); break;
    case date_time_picker_format::short_format: create_params.style(create_params.style() | DTS_SHORTDATEFORMAT); break;
    case date_time_picker_format::time: create_params.style(create_params.style() | DTS_TIMEFORMAT); break;
    default: create_params.style(create_params.style() | DTS_LONGDATEFORMAT); break;
  }
  return create_params;
}

void date_time_picker::on_close_up(const event_args& e) {
  if (can_raise_events()) close_up(*this, e);
}

void date_time_picker::on_drop_down(const event_args& e) {
  if (can_raise_events()) drop_down(*this, e);
}

void date_time_picker::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::date_time_picker::allowable_dates(handle(), data_->min_date, data_->max_date);
  native::date_time_picker::value(handle(), data_->value);
}

void date_time_picker::on_value_changed(const event_args& e) {
  if (can_raise_events()) value_changed(*this, e);
}

void date_time_picker::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_NOTIFY: wm_nottify_control(message); break;
    default: control::wnd_proc(message);
  }
}

void date_time_picker::wm_nottify_control(message& message) {
  auto nmhdr = reinterpret_cast<NMHDR*>(message.lparam());
  switch (nmhdr->code) {
    case DTN_CLOSEUP: wm_nottify_control_closeup(message); break;
    case DTN_DROPDOWN: wm_nottify_control_dropdown(message); break;
    case DTN_DATETIMECHANGE: wm_nottify_control_datetimechange(message); break;
  }
}

void date_time_picker::wm_nottify_control_closeup(message& message) {
  on_close_up(event_args::empty);
}

void date_time_picker::wm_nottify_control_dropdown(message& message) {
  on_drop_down(event_args::empty);
}

void date_time_picker::wm_nottify_control_datetimechange(message& message) {
  if (native::date_time_picker::value(handle()) < data_->min_date) native::date_time_picker::value(handle(), data_->min_date);
  if (native::date_time_picker::value(handle()) > data_->max_date) native::date_time_picker::value(handle(), data_->max_date);
  if (data_->value != native::date_time_picker::value(handle())) {
    data_->value = native::date_time_picker::value(handle());
    on_value_changed(event_args::empty);
  }
}
