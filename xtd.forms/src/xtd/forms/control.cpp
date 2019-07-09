#include <iostream>
#include <xtd/strings>
#include "../../../include/xtd/forms/control.hpp"
#include "../../../include/xtd/forms/window_messages.hpp"
#include "../../native/control_api.hpp"

const xtd::forms::control xtd::forms::control::null;

xtd::forms::control::~control() {
  native::control_api::unregister_wnd_proc(this->handle_);
}

std::map<intptr_t, xtd::forms::control*> xtd::forms::control::handles_;

void xtd::forms::control::client_size(const xtd::drawing::size& size) {
  if (this->client_size_ != size) {
    this->client_size_ = size;
    native::control_api::client_size(this->handle_, this->client_size_);
  }
}

intptr_t xtd::forms::control::handle() const {
  return native::control_api::handle(this->handle_);
}

void xtd::forms::control::location(const xtd::drawing::point& location) {
  if (this->location_ != location) {
    this->location_ = location;
    native::control_api::location(this->handle_, this->location_);
  }
}

void xtd::forms::control::parent(const xtd::forms::control& parent) {
  if (this->parent_ != &parent) {
    this->parent_ = const_cast<xtd::forms::control*>(&parent);
    if (this->parent_ == &xtd::forms::control::null) {
      native::control_api::destroy(this->handle_);
    } else {
      this->create_control();
      //native::control_api::parent(this->handle_, this->parent_);
      //for (xtd::forms::control* control : this->controls_)
      //  control->create_control();
      this->on_parent_changed(xtd::event_args::empty);
    }
  }
}

void xtd::forms::control::size(const xtd::drawing::size& size) {
  if (this->size_ != size) {
    this->size_ = size;
    native::control_api::size(this->handle_, this->size_);
  }
}

void xtd::forms::control::text(const std::string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::control_api::text(this->handle_, this->text_);
    this->on_text_changed(xtd::event_args::empty);
  }
}

void xtd::forms::control::visible(bool visible) {
  if (this->visible_ != visible) {
    this->visible_ = visible;
    //for (xtd::forms::control* control : this->controls_)
    //  control->visible(visible);
    native::control_api::visible(this->handle_, this->visible_);
    this->on_visible_changed(xtd::event_args::empty);
  }
}

void xtd::forms::control::create_control() {
  if (!this->handle_) {
    this->create_handle();
    this->on_create_control();
  }
}

void xtd::forms::control::create_handle() {
  if (this->handle_ == 0) this->handle_ = native::control_api::create(this->parent_->handle_, this->default_size());
  native::control_api::register_wnd_proc(this->handle_, {*this, &xtd::forms::control::wnd_proc});
  handles_[native::control_api::handle(this->handle_)] = this;
  send_message(native::control_api::handle(this->handle_), WM_CREATE, 0, 0);
  this->get_properties();
}

xtd::forms::control& xtd::forms::control::from_child_handle(intptr_t handle) {
  try {
    if (handles_.find(handle) != handles_.end())
      return handles_[handle]->parent();
    return (xtd::forms::control&)xtd::forms::control::null;
  } catch (...) {
    return (xtd::forms::control&)xtd::forms::control::null;
  }
}

xtd::forms::control& xtd::forms::control::from_handle(intptr_t handle) {
  try {
    if (handles_.find(handle) != handles_.end())
      return *handles_[handle];
    return (xtd::forms::control&)xtd::forms::control::null;
  } catch (...) {
    return (xtd::forms::control&)xtd::forms::control::null;
  }
}

void xtd::forms::control::on_create_control() {
}

void xtd::forms::control::on_client_size_changed(const xtd::event_args &e) {
  this->client_size_ = native::control_api::client_size(this->handle_);
  this->client_size_changed(*this, e);
}

void xtd::forms::control::on_handle_created(const xtd::event_args &e) {
  this->handle_created(*this, e);
}

void xtd::forms::control::on_handle_destroyed(const xtd::event_args &e) {
  this->handle_destroyed(*this, e);
}

void xtd::forms::control::on_location_changed(const xtd::event_args &e) {
  this->location_ = native::control_api::location(this->handle_);
  this->location_changed(*this, e);
}

void xtd::forms::control::on_parent_changed(const xtd::event_args &e) {
  this->parent_changed(*this, e);
}

void xtd::forms::control::on_size_changed(const xtd::event_args &e) {
  this->size_ = native::control_api::size(this->handle_);
  this->size_changed(*this, e);
}

void xtd::forms::control::on_text_changed(const xtd::event_args &e) {
  this->text_ = native::control_api::text(this->handle_);
  this->text_changed(*this, e);
}

void xtd::forms::control::on_visible_changed(const xtd::event_args &e) {
  this->visible_ = native::control_api::visible(this->handle_);
  this->visible_changed(*this, e);
}

void xtd::forms::control::wnd_proc(xtd::forms::message& message) {
  std::cout << xtd::strings::format("receive message [{}]", message) << std::endl;
  switch (message.msg()) {
    case WM_MOVE: this->on_location_changed(xtd::event_args::empty); break;
    case WM_SIZE: this->on_size_changed(xtd::event_args::empty); break;
    default: this->def_wnd_proc(message); break;
  }
}

intptr_t xtd::forms::control::send_message(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam) {
  return native::control_api::send_message(this->handle_, hwnd, msg, wparam, lparam);
}

void xtd::forms::control::def_wnd_proc(xtd::forms::message& message) {
  native::control_api::def_wnd_proc(message);
  
}
void xtd::forms::control::get_properties() {
  this->client_size_ = native::control_api::client_size(this->handle_);
  this->location_ = native::control_api::location(this->handle_);
  this->size_ = native::control_api::size(this->handle_);
  this->text_ = native::control_api::text(this->handle_);
  this->visible_ = native::control_api::visible(this->handle_);
}
