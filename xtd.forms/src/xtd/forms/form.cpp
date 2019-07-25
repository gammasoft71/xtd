#include <stdexcept>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/form.hpp>
#include <xtd/forms/window_messages.hpp>
#include "../../../include/xtd/forms/form.hpp"

using namespace xtd::forms;

form::form() {
  create_control();
}

void form::create_handle() {
  this->handle_ = native::form::create(this->default_size());
  this->visible_ = false;
  this->location_ = native::control::location(this->handle_);
  this->control::create_handle();
}

void form::parent(const control& parent) {
  throw std::invalid_argument("Top-level control cannot be added to a control.");
}

