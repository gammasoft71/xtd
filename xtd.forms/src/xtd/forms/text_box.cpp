#include <xtd/forms/native/text_box.hpp>
#include "../../../include/xtd/forms/text_box.hpp"

using namespace std;
using namespace xtd::forms;

void text_box::text(const string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::text_box::text(this->handle_, this->text_);
  }
}

void text_box::create_handle() {
  this->handle_ = native::text_box::create(this->parent_->__get_handle__(), this->default_size());
  this->control::create_handle();
  native::text_box::text(this->handle_, this->text_);
}

