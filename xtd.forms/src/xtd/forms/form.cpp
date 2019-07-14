#include <stdexcept>
#include "../../../include/xtd/forms/form.hpp"
#include "../../../include/xtd/forms/window_messages.hpp"
#include "../../native/control_api.hpp"
#include "../../native/form_api.hpp"

xtd::forms::form::form() {
  create_control();
}

void xtd::forms::form::create_handle() {
  this->handle_ = native::form_api::create(this->default_size());
  this->visible_ = false;
  this->location_ = native::control_api::location(this->handle_);
  this->control::create_handle();
}

void xtd::forms::form::parent(const xtd::forms::control& parent) {
  throw std::invalid_argument("Top-level control cannot be added to a control.");
}

