#include <xtd/forms/native/label.hpp>
#include "../../../include/xtd/forms/label.hpp"

using namespace xtd::forms;

void label::create_handle() {
  this->handle_ = native::label::create(this->parent_->__get_handle__(), this->default_size());
  this->control::create_handle();
}

