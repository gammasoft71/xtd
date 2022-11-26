#include "../../../include/xtd/forms/application_context.h"

using namespace xtd;
using namespace xtd::forms;

application_context::application_context(const form& main_form) noexcept {
  this->main_form(main_form);
}

application_context::~application_context() {
  if (data_->main_form != nullptr) data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
}

const form& application_context::main_form() const noexcept {
  return *data_->main_form;
}

form& application_context::main_form() noexcept {
  return *data_->main_form;
}

void application_context::main_form(const form& main_form) {
  if (data_->main_form != nullptr) data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
  data_->main_form = const_cast<form*>(&main_form);
  data_->main_form->visible_changed += {*this, &application_context::on_main_form_closed};
}

std::any application_context::tag() const noexcept {
  return data_->tag;
}

void application_context::tag(std::any tag) {
  data_->tag = tag;
}

void application_context::exit_thread() {
  exit_thread_core();
}

void application_context::exit_thread_core() {
  thread_exit(*this, event_args::empty);
}

void application_context::on_main_form_closed(object& sender, const event_args& e) {
  if (!data_->main_form->visible()) {
    if (!data_->main_form->closed_) data_->main_form->close();
    if (data_->main_form->closed_) {
      data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
      exit_thread_core();
    }
  }
}
