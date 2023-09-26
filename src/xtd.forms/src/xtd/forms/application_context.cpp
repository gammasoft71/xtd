#include "../../../include/xtd/forms/application_context"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct application_context::data {
  form* main_form = nullptr;
  std::any tag;
};

application_context::application_context() : data_(std::make_shared<data>()) {
}

application_context::application_context(const form& main_form) noexcept : data_(std::make_shared<data>()) {
  this->main_form(main_form);
}

application_context::~application_context() {
  if (data_->main_form != nullptr) data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
}

optional<const_form_ref> application_context::main_form() const noexcept {
  return data_->main_form ? optional<const_form_ref> {*data_->main_form} : nullopt;
}

optional<form_ref> application_context::main_form() noexcept {
  return data_->main_form ? optional<form_ref> {*data_->main_form} : nullopt;
}

void application_context::main_form(const form& main_form) {
  if (data_->main_form != nullptr) data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
  data_->main_form = const_cast<form*>(&main_form);
  data_->main_form->visible_changed += {*this, &application_context::on_main_form_closed};
}

void application_context::main_form(nullptr_t) {
  if (data_->main_form != nullptr) data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
  data_->main_form = nullptr;
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
    if (!data_->main_form->closed_()) data_->main_form->close();
    if (data_->main_form->closed_()) {
      data_->main_form->handle_destroyed -= {*this, &application_context::on_main_form_closed};
      exit_thread_core();
    }
  }
}
