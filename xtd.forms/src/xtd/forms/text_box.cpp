#include "../../../include/xtd/forms/text_box.hpp"
#include "../../native/text_box_api.hpp"

xtd::forms::text_box::text_box() {
}

void xtd::forms::text_box::text(const std::string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::text_box_api::text(this->handle_, this->text_);
  }
}

void xtd::forms::text_box::create_handle() {
  this->handle_ = native::text_box_api::create(this->parent_->__get_handle__(), this->default_size());
  this->control::create_handle();
  native::text_box_api::text(this->handle_, this->text_);
}

