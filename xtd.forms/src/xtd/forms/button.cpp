#include "../../../include/xtd/forms/button.hpp"
#include "../../../include/xtd/forms/form.hpp"
#include <xtd/forms/native/button.hpp>
#include <xtd/forms/native/window_button.hpp>
#include <xtd/forms/window_messages.hpp>

using namespace xtd;
using namespace xtd::forms;

button& button::auto_size_mode(forms::auto_size_mode value) {
  this->set_auto_size_mode(value);
  return *this;
}

control& button::dialog_result(forms::dialog_result dialog_result) {
  if (this->dialog_result_ != dialog_result)
    this->dialog_result_ = dialog_result;
  return *this;
}

void button::notify_default(bool value) {
  native::button::default_button(this->handle_, value);
}

void button::perform_click() {
  this->on_click(event_args::empty);
}

forms::create_params button::create_params() const {
  forms::create_params create_params = this->button_base::create_params();
  
  create_params.style(create_params.style() | BS_PUSHBUTTON);
  
  return create_params;
}

void button::on_click(const event_args& e) {
  this->button_base::on_click(e);
  if (this->dialog_result_ != forms::dialog_result::none &&  dynamic_cast<form*>(&this->top_level_control()) != nullptr && static_cast<form&>(this->top_level_control()).modal()) {
    static_cast<form&>(this->top_level_control()).dialog_result(this->dialog_result());
    static_cast<form&>(this->top_level_control()).close();
  }
}

void button::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_click(message); break;
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_XBUTTONUP: this->wm_mouse_up(message); break;
    default: this->control::wnd_proc(message);
  }
}

void button::wm_click(message& message) {
  this->def_wnd_proc(message);
  this->on_click(event_args::empty);
}

void button::wm_mouse_up(message& message) {
  this->def_wnd_proc(message);
  mouse_event_args e = mouse_event_args::create(message);
  this->on_mouse_click(e);
  this->on_mouse_up(e);
}
