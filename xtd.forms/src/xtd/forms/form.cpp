#include "../../../include/xtd/forms/form.hpp"
#include "../../native/form_api.hpp"

xtd::forms::form::form() {
  create_control();
}

void xtd::forms::form::create_handle() {
  this->handle_ = native::form_api::create(this->default_size());
  this->visible_ = false;
  this->control::create_handle();
}

