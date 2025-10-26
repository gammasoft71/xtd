#include "../../../include/xtd/forms/application_context.hpp"

using namespace xtd;
using namespace xtd::forms;

struct application_context::data {
  form* main_form = nullptr;
  any_object tag;
};

application_context::application_context() : data_(xtd::new_sptr<data>()) {
}

application_context::application_context(const form& main_form) noexcept : data_(xtd::new_sptr<data>()) {
  this->main_form(main_form);
}

application_context::~application_context() {
  if (data_->main_form != nullptr) data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
}

std::optional<const_form_ref> application_context::main_form() const noexcept {
  return data_->main_form ? std::optional<const_form_ref> {*data_->main_form} : std::nullopt;
}

std::optional<form_ref> application_context::main_form() noexcept {
  return data_->main_form ? std::optional<form_ref> {*data_->main_form} : std::nullopt;
}

void application_context::main_form(const form& main_form) {
  if (data_->main_form != nullptr) data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
  data_->main_form = const_cast<form*>(&main_form);
  data_->main_form->form_closed += {*this, &application_context::on_main_form_closed};
}

void application_context::main_form(std::nullptr_t) {
  if (data_->main_form != nullptr) data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
  data_->main_form = nullptr;
}

any_object application_context::tag() const noexcept {
  return data_->tag;
}

void application_context::tag(const any_object& tag) {
  data_->tag = tag;
}

void application_context::exit_thread() {
  exit_thread_core();
}

void application_context::exit_thread_core() {
  thread_exit(*this, event_args::empty);
}

void application_context::on_main_form_closed(object& sender, const event_args& e) {
  if (!data_->main_form || data_->main_form->visible()) return;
  if (!data_->main_form->closed_()) data_->main_form->close();
  if (!data_->main_form->closed_()) return;
  data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
  exit_thread_core();
}
