#include <stdexcept>
#include "../../../include/xtd/forms/form.hpp"
#include "../../../include/xtd/forms/window_messages.hpp"
#include "../../native/control_api.hpp"
#include "../../native/form_api.hpp"

using namespace xtd::forms;

form::form() {
  create_control();
}

void form::create_handle() {
  this->handle_ = native::form_api::create(this->default_size());
  this->visible_ = false;
  this->location_ = native::control_api::location(this->handle_);
  this->control::create_handle();
}

void form::parent(const control& parent) {
  throw std::invalid_argument("Top-level control cannot be added to a control.");
}

