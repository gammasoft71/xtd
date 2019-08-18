#include <xtd/environment.hpp>
#include <xtd/diagnostics/cdebug.hpp>
#include <xtd/forms/native/radio_button.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/window_button.hpp>
#include "../../../include/xtd/forms/radio_button.hpp"

using namespace xtd;
using namespace xtd::forms;

radio_button& radio_button::appearance(forms::appearance appearance) {
  if (this->appearance_ != appearance) {
    this->appearance_ = appearance;
    this->recreate_handle();
    this->on_appearance_changed(event_args::empty);
  }
  return *this;
}

radio_button& radio_button::auto_check(bool auto_check) {
  if (this->auto_check_ != auto_check) {
    this->auto_check_ = auto_check;
  }
  return *this;
}

radio_button& radio_button::checked(bool checked) {
  if (this->checked_ != checked) {
    this->checked_ = checked;
    native::radio_button::checked(this->handle_, this->checked_);
    this->on_checked_changed(event_args::empty);
    if (this->checked_ == true && this->auto_check_ == true && &this->parent() != &control::null) {
      for (auto control : this->parent().controls()) {
        if (&control.get() != this && dynamic_cast<radio_button*>(&control.get()) != nullptr && static_cast<radio_button&>(control.get()).auto_check_ == true)
          static_cast<radio_button&>(control.get()).checked(false);
      }
    }
  }
  return *this;
}

void radio_button::create_handle() {
  size_t styles = 0;
  size_t ex_styles = 0;
  if (this->auto_check_) styles |= BS_AUTORADIOBUTTON;
  else styles |= BS_RADIOBUTTON;
  if (this->appearance_ == forms::appearance::button) styles |= BS_PUSHLIKE;
  this->handle_ = native::radio_button::create(this->parent_->__get_handle__(), this->default_size(), styles, ex_styles);
  this->control::create_handle();
  native::radio_button::checked(this->handle_, this->checked_);
  if (!environment::os_version().is_osx_platform() && this->back_color() != this->default_back_color()) native::control::back_color(this->handle_, this->back_color());
}

void radio_button::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: break;
    case WM_LBUTTONUP: this->wm_mouse_up(message); break;
    default: this->control::wnd_proc(message);
  }
}

void radio_button::wm_mouse_up(message &message) {
  if (this->auto_check_) this->checked(true);
  this->on_click(event_args::empty);
}

