#include "../include/xtd/control.h"
#include "native/control_api.h"

void xtd::forms::control::text(const std::string& text) {
  if (this->text_ != text) {
    native::control_api::text(this->handle_, text);
    this->text_ = text;
  }
}

void xtd::forms::control::create_handle() {
  this->handle_ = native::control_api::create(this->parent_);
}

void xtd::forms::control::show() const {
  native::control_api::visible(this->handle_, true);
}

