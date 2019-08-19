#include <xtd/environment.hpp>
#include <xtd/forms/native/check_box.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/window_button.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/check_box.hpp"

using namespace xtd;
using namespace xtd::forms;

check_box::check_box() {
  this->size_ = this->default_size();
}

check_box& check_box::appearance(forms::appearance appearance) {
  if (this->appearance_ != appearance) {
    this->appearance_ = appearance;
    this->recreate_handle();
    this->on_appearance_changed(event_args::empty);
  }
  return *this;
}

check_box& check_box::auto_check(bool auto_check) {
  if (this->auto_check_ != auto_check)
    this->auto_check_ = auto_check;
  return *this;
}

check_box& check_box::checked(bool checked) {
  this->check_state(checked ? forms::check_state::checked : forms::check_state::unchecked);
  return *this;
}

check_box& check_box::check_state(forms::check_state check_state) {
  if (this->check_state_ != check_state) {
    this->check_state_ = check_state;
    if (this->checked_ != (this->check_state_ != forms::check_state::unchecked)) {
      this->checked_ = this->check_state_ != forms::check_state::unchecked;
      this->on_checked_changed(event_args::empty);
    }
    native::check_box::check_state(this->handle_, static_cast<int32_t>(this->check_state_));
    this->on_check_state_changed(event_args::empty);
  }
  return *this;
}

check_box& check_box::three_state(bool three_state) {
  if (this->three_state_ != three_state) {
    this->three_state_ = three_state;
    this->recreate_handle();
  }
  return *this;
}

forms::create_params check_box::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("CHECKBOX"); // "BUTTON" for win32
  if (this->three_state_) create_params.style(create_params.style() | (this->auto_check_ ? BS_AUTO3STATE : BS_3STATE));
  else if (this->auto_check_) create_params.style(create_params.style() | BS_AUTOCHECKBOX);
  else create_params.style(create_params.style() | BS_CHECKBOX);
  if (this->appearance_ == forms::appearance::button) create_params.style(create_params.style() | BS_PUSHLIKE);

  return create_params;
}

void check_box::on_handle_created(const event_args &e) {
  this->control::on_handle_created(e);
  native::check_box::check_state(this->handle_, static_cast<int32_t>(this->check_state_));
}

void check_box::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: this->wm_mouse_down(message); break;
    case WM_LBUTTONUP: this->wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
    default: this->control::wnd_proc(message);
  }
}

void check_box::wm_mouse_double_click(message &message) {
  if (this->auto_check_)
    this->control::wnd_proc(message);
  else
    this->on_double_click(event_args::empty);
}

void check_box::wm_mouse_down(message &message) {
  if (this->auto_check_) {
    this->control::wnd_proc(message);
  } else
    this->on_click(event_args::empty);
}

void check_box::wm_mouse_up(message &message) {
  this->check_state(static_cast<forms::check_state>(native::check_box::check_state(this->handle_)));
}
