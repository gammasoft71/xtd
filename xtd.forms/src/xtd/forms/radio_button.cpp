#include <xtd/environment.hpp>
#include <xtd/diagnostics/cdebug.hpp>
#include <xtd/forms/native/radio_button.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/window_button.hpp>
#include "../../../include/xtd/forms/radio_button.hpp"

using namespace xtd;
using namespace xtd::forms;

radio_button::radio_button() {
  this->make_control(*this);
  this->control::data_->size_ = this->default_size();
}

radio_button& radio_button::operator=(const radio_button& value) {
  this->control::operator=(value);
  this->appearance_changed = value.appearance_changed;
  this->checked_changed = value.checked_changed;
  this->data_ = value.data_;
  return *this;
}

radio_button& radio_button::appearance(forms::appearance appearance) {
  if (this->data_->appearance_ != appearance) {
    this->data_->appearance_ = appearance;
    this->recreate_handle();
    this->on_appearance_changed(event_args::empty);
  }
  return *this;
}

radio_button& radio_button::auto_check(bool auto_check) {
  if (this->data_->auto_check_ != auto_check) {
    this->data_->auto_check_ = auto_check;
  }
  return *this;
}

radio_button& radio_button::checked(bool checked) {
  if (this->data_->checked_ != checked) {
    this->data_->checked_ = checked;
    native::radio_button::checked(this->control::data_->handle_, this->data_->checked_);
    this->on_checked_changed(event_args::empty);
    if (this->data_->checked_ == true && this->data_->auto_check_ == true && &this->parent() != &control::null) {
      for (auto control : this->parent().controls()) {
        if (dynamic_cast<radio_button*>(&control.get()) != nullptr && static_cast<radio_button&>(control.get()).data_ != this->data_ && static_cast<radio_button&>(control.get()).data_->auto_check_ == true)
          static_cast<radio_button&>(control.get()).checked(false);
      }
    }
  }
  return *this;
}

forms::create_params radio_button::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("RADIOBUTTON"); // "BUTTON" for win32
  if (this->data_->auto_check_) create_params.style(create_params.style() | BS_AUTORADIOBUTTON);
  else create_params.style(create_params.style() | BS_RADIOBUTTON);
  if (this->data_->appearance_ == forms::appearance::button) create_params.style(create_params.style() | BS_PUSHLIKE);

  return create_params;
}

drawing::size radio_button::measure_control() const {
  return this->control::measure_text() + drawing::size(20, 0);
}

void radio_button::on_handle_created(const event_args &e) {
  this->control::on_handle_created(e);
  native::radio_button::checked(this->control::data_->handle_, this->data_->checked_);
}

void radio_button::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: break;
    case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
    case WM_LBUTTONUP: this->wm_mouse_up(message); break;
    default: this->control::wnd_proc(message);
  }
}

void radio_button::wm_mouse_double_click(message& message) {
  this->on_double_click(event_args::empty);
}

void radio_button::wm_mouse_up(message& message) {
  if (this->data_->auto_check_) this->checked(true);
  this->on_click(event_args::empty);
}

