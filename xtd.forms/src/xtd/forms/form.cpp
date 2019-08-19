#include <stdexcept>
#include <xtd/xtd.diagnostics>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/form.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include <xtd/forms/window_messages.hpp>
#include "../../../include/xtd/forms/form.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

form::form() {
  this->visible_ = false;
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
  this->size_ = this->default_size();
}

void form::create_handle() {
  size_t styles = 0;
  size_t ex_styles = 0;
  this->handle_ = native::form::create(this->size_, styles, ex_styles);
  this->location_ = native::control::location(this->handle_);
  this->control::create_handle();
  native::control::back_color(this->handle_, this->back_color());
}

void form::close() {
  native::form::close(this->handle_);
}

control& form::parent(const control& parent) {
  throw std::invalid_argument("Top-level control cannot be added to a control.");
  return *this;
}

control& form::visible(bool visible) {
  if (this->handle_ == 0) this->create_control();
  this->control::visible(visible);
  return *this;
}

forms::create_params form::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.style(WS_OVERLAPPEDWINDOW);
  
  return create_params;
}

void form::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_CLOSE: this->wm_close(message); break;
    default: this->control::wnd_proc(message); break;
  }
}

void form::wm_close(message &message) {
  this->def_wnd_proc(message);
  form_closing_event_args event_args;
  this->on_form_closing(event_args);
  if (event_args.cancel() != true) this->destroy_handle();
  this->on_form_closed(form_closed_event_args());
}

