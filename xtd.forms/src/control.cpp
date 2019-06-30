#include "../include/xtd/control.h"
#include "native/control_api.h"

const xtd::forms::control xtd::forms::control::null;

void xtd::forms::control::parent(const xtd::forms::control& parent) {
  if (this->parent_ != &parent) {
    this->parent_ = const_cast<xtd::forms::control*>(&parent);
    this->create_control();
    //for (xtd::forms::control* control : this->controls_)
    //  control->create_control();
  }
}

void xtd::forms::control::text(const std::string& text) {
  if (this->text_ != text) {
    native::control_api::text(this->handle_, text);
    this->text_ = text;
  }
}

void xtd::forms::control::create_handle() {
  this->handle_ = native::control_api::create(this->parent_->handle());
}

void xtd::forms::control::show() const {
  native::control_api::visible(this->handle_, true);
}

