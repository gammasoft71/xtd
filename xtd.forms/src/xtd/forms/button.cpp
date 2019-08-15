#include <xtd/environment.hpp>
#include <xtd/forms/native/button.hpp>
#include <xtd/forms/native/control.hpp>
#include "../../../include/xtd/forms/button.hpp"

using namespace xtd;
using namespace xtd::forms;

void button::create_handle() {
  this->handle_ = native::button::create(this->parent_->__get_handle__(), this->default_size());
  this->control::create_handle();
}
