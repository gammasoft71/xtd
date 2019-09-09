#include <xtd/forms/native/check_box.hpp>
#include <xtd/forms/window_messages.hpp>
#include <xtd/forms/native/window_button.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/check_box.hpp"

using namespace xtd;
using namespace xtd::forms;

check_box::check_box() {
  this->make_control(*this);
}

check_box& check_box::operator=(const check_box& value) {
  this->button_base::operator=(value);
  this->appearance_changed = value.appearance_changed;
  this->checked_changed = value.checked_changed;
  this->check_state_changed = value.check_state_changed;
  this->data_ = value.data_;
  return *this;
}

check_box& check_box::appearance(forms::appearance appearance) {
  if (this->data_->appearance_ != appearance) {
    this->data_->appearance_ = appearance;
    this->recreate_handle();
    this->on_appearance_changed(event_args::empty);
  }
  return *this;
}

check_box& check_box::auto_check(bool auto_check) {
  if (this->data_->auto_check_ != auto_check)
    this->data_->auto_check_ = auto_check;
  return *this;
}

check_box& check_box::checked(bool checked) {
  this->check_state(checked ? forms::check_state::checked : forms::check_state::unchecked);
  return *this;
}

check_box& check_box::check_state(forms::check_state check_state) {
  if (this->data_->check_state_ != check_state) {
    this->data_->check_state_ = check_state;
    if (this->data_->checked_ != (this->data_->check_state_ != forms::check_state::unchecked)) {
      this->data_->checked_ = this->data_->check_state_ != forms::check_state::unchecked;
      this->on_checked_changed(event_args::empty);
    }
    native::check_box::check_state(this->control::data_->handle_, static_cast<int32_t>(this->data_->check_state_));
    this->on_check_state_changed(event_args::empty);
  }
  return *this;
}

check_box& check_box::three_state(bool three_state) {
  if (this->data_->three_state_ != three_state) {
    this->data_->three_state_ = three_state;
    this->recreate_handle();
  }
  return *this;
}

forms::create_params check_box::create_params() const {
  forms::create_params create_params = this->button_base::create_params();
  
  create_params.class_name("checkbox");
  if (this->data_->three_state_) create_params.style(create_params.style() | (this->data_->auto_check_ ? BS_AUTO3STATE : BS_3STATE));
  else if (this->data_->auto_check_) create_params.style(create_params.style() | BS_AUTOCHECKBOX);
  else create_params.style(create_params.style() | BS_CHECKBOX);
  if (this->data_->appearance_ == forms::appearance::button) create_params.style(create_params.style() | BS_PUSHLIKE);

  return create_params;
}

drawing::size check_box::measure_control() const {
  return this->control::measure_text() + drawing::size(20, 0);
}

void check_box::on_handle_created(const event_args &e) {
  this->control::on_handle_created(e);
  native::check_box::check_state(this->control::data_->handle_, static_cast<int32_t>(this->data_->check_state_));
}

void check_box::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: break;
    case WM_LBUTTONUP: this->wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
    default: this->control::wnd_proc(message);
  }
}

void check_box::wm_mouse_double_click(message &message) {
  this->on_double_click(event_args::empty);
}

void check_box::wm_mouse_up(message &message) {
  if (this->data_->auto_check_)
    switch (this->check_state()) {
      case forms::check_state::unchecked: this->check_state(forms::check_state::checked); break;
      case forms::check_state::checked: this->check_state(this->three_state() ? forms::check_state::indeterminate : forms::check_state::unchecked); break;
      case forms::check_state::indeterminate: this->check_state(forms::check_state::unchecked); break;
    }
  this->on_click(event_args::empty);

}
