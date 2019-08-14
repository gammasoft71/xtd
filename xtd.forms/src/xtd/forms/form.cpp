#include <stdexcept>
#include <xtd/xtd.diagnostics>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/form.hpp>
#include <xtd/forms/window_messages.hpp>
#include "../../../include/xtd/forms/form.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

form::form() {
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
  this->visible_ = false;
  create_control();
}

void form::create_handle() {
  this->handle_ = native::form::create(this->default_size());
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

