#include <xtd/environment.hpp>
#include <xtd/forms/native/check_box.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/window_button.hpp>
#include "../../../include/xtd/forms/check_box.hpp"

using namespace xtd;
using namespace xtd::forms;

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

void check_box::create_handle() {
  size_t styles = 0;
  size_t ex_styles = 0;
  if (this->three_state_) styles |= this->auto_check_ ? BS_AUTO3STATE : BS_3STATE;
  else if (this->auto_check_) styles |= BS_AUTOCHECKBOX;
  else styles = BS_CHECKBOX;
  if (this->appearance_ == forms::appearance::button) styles |= BS_PUSHLIKE;
  this->handle_ = native::check_box::create(this->parent_->__get_handle__(), this->default_size(), styles, ex_styles);
  this->control::create_handle();
  native::check_box::check_state(this->handle_, static_cast<int32_t>(this->check_state_));
  if (!environment::os_version().is_osx_platform() && this->back_color() != this->default_back_color()) native::control::back_color(this->handle_, this->back_color());
}

void check_box::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: this->wm_mouse_down(message); break;
    case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
    case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
    default: this->control::wnd_proc(message);
  }
}

void check_box::wm_mouse_down(message &message) {
  if (this->auto_check_)
    this->control::wnd_proc(message);
  else
    this->on_click(event_args::empty);
}

void check_box::wm_mouse_double_click(message &message) {
  if (this->auto_check_)
    this->control::wnd_proc(message);
  else
    this->on_double_click(event_args::empty);
}

void check_box::wm_reflect_command(message &message) {
  this->def_wnd_proc(message);
  this->check_state(static_cast<forms::check_state>(native::check_box::check_state(this->handle_)));
}
