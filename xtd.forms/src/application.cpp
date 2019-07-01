#include "../include/xtd/application.h"
#include "native/application_api.h"

void xtd::forms::application::do_events() {
  native::application_api::do_events();
}

void xtd::forms::application::exit() {
  native::application_api::exit();
}

void xtd::forms::application::run() {
  native::application_api::run();
}

void xtd::forms::application::run(const form& form) {
  native::application_api::main_form(form.handle());
  run();
}
