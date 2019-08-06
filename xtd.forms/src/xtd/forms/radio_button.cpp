#include <xtd/environment.hpp>
#include <xtd/forms/native/radio_button.hpp>
#include <xtd/forms/native/control.hpp>
#include "../../../include/xtd/forms/radio_button.hpp"

using namespace xtd;
using namespace xtd::forms;

void radio_button::auto_check(bool auto_check) {
  if (this->auto_check_ != auto_check) {
    this->auto_check_ = auto_check;
  }
}

void radio_button::checked(bool checked) {
  if (this->checked_ != checked) {
    this->checked_ = checked;
    native::radio_button::checked(this->handle_, this->checked_);
    this->on_checked_changed(event_args::empty);
  }
}

void radio_button::create_handle() {
  this->handle_ = native::radio_button::create(this->parent_->__get_handle__(), this->default_size());
  this->control::create_handle();
  native::radio_button::checked(this->handle_, this->checked_);
  if (!environment::os_version().is_osx_platform() && this->back_color() != this->default_back_color()) native::control::back_color(this->handle_, this->back_color());
}

void radio_button::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
    default: this->control::wnd_proc(message);
  }
}

void radio_button::wm_reflect_command(message &message) {
  this->def_wnd_proc(message);
  if (this->auto_check_) {
    this->checked(native::radio_button::checked(this->handle_));
    if (this->checked_ == true && &this->parent() != &control::null) {
      for (auto control : this->parent().controls()) {
        if (&control.get() != this && dynamic_cast<radio_button*>(&control.get()) != nullptr)
          static_cast<radio_button&>(control.get()).checked(false);
      }
    }
  } else
    native::radio_button::checked(this->handle_, this->checked_);
}
