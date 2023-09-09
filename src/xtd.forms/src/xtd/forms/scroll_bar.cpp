#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/scroll_bar.h>
#include <xtd/forms/window_messages.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/scroll_bar.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

struct scroll_bar::data {
  int32 large_change = 10;
  int32 maximum = 100;
  int32 minimum = 0;
  int32 small_change = 1;
  int32 value = 0;
  bool v_scroll = true;
};


int32 scroll_bar::large_change() const noexcept {
  return data_->large_change;
}

scroll_bar& scroll_bar::large_change(int32 large_change) {
  if (large_change < 0) throw argument_out_of_range_exception {csf_};
  data_->large_change = large_change;
  return *this;
}

int32 scroll_bar::maximum() const noexcept {
  return data_->maximum;
}

scroll_bar& scroll_bar::maximum(int32 maximum) {
  data_->maximum = maximum;
  return *this;
}

int32 scroll_bar::minimum() const noexcept {
  return data_->minimum;
}

scroll_bar& scroll_bar::minimum(int32 minimum) {
  data_->minimum = minimum;
  return *this;
}

int32 scroll_bar::small_change() const noexcept {
  return data_->small_change;
}

scroll_bar& scroll_bar::small_change(int32 small_change) {
  if (small_change < 0) throw argument_out_of_range_exception {csf_};
  data_->small_change = small_change;
  return *this;
}

int32 scroll_bar::value() const noexcept {
  return data_->value;
}

scroll_bar& scroll_bar::value(int32 value) {
  if (value < data_->minimum || value > data_->maximum) throw argument_out_of_range_exception {csf_};
  if (data_->value != value) {
    data_->value = value;
    if (is_handle_created()) native::scroll_bar::value(handle(), value);
    on_value_changed(event_args::empty);
  }
  return *this;
}

scroll_bar::scroll_bar(bool vertical) : data_(std::make_shared<data>()) {
  set_style(control_styles::user_paint, false);
  set_style(control_styles::standard_click, false);
  set_style(control_styles::use_text_for_accessibility, false);
  data_->v_scroll = vertical;
}

forms::create_params scroll_bar::create_params() const noexcept {
  forms::create_params create_params = control::create_params();
  
  create_params.class_name("scrollbar");
  
  return create_params;
}

void scroll_bar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::scroll_bar::large_change(handle(), data_->large_change);
  native::scroll_bar::maximum(handle(), data_->maximum);
  native::scroll_bar::minimum(handle(), data_->minimum);
  native::scroll_bar::small_change(handle(), data_->small_change);
  native::scroll_bar::value(handle(), data_->value);
}

void scroll_bar::on_scroll(const event_args& e) {
  if (is_handle_created()) data_->value = native::scroll_bar::value(handle());
  scroll(*this, e);
}

void scroll_bar::on_value_changed(const event_args& e) {
  value_changed(*this, e);
}

void scroll_bar::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_HSCROLL:
    case WM_REFLECT + WM_VSCROLL: wm_scroll_control(message); break;
    default: control::wnd_proc(message);
  }
}

void scroll_bar::wm_scroll_control(message& message) {
  on_scroll(event_args::empty);
  on_value_changed(event_args::empty);
}
