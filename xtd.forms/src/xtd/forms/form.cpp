#include "../../../include/xtd/forms/form.hpp"
#include "../../native/form_api.hpp"

xtd::forms::form::form() {
  native::form_api::initialize_application(); // Must be first
  create_control();
  this->visible_ = false;
}

void xtd::forms::form::create_handle() {
  this->handle_ = native::form_api::create(this->default_size());
  this->control::create_handle();
}

