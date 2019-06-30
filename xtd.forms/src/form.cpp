#include "../include/xtd/form.h"
#include "native/form_api.h"

xtd::forms::form::form() {
  native::form_api::initialize_application(); // Must be first
  create_control();
}

void xtd::forms::form::create_handle() {
  this->handle_ = native::form_api::create();
}

