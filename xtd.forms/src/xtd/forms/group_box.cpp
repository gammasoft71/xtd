#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/group_box.hpp>
#include "../../../include/xtd/forms/group_box.hpp"

using namespace xtd;
using namespace xtd::forms;

void group_box::create_handle() {
  size_t styles = 0;
  size_t ex_styles = 0;
  this->handle_ = native::group_box::create(this->parent_->__get_handle__(), this->default_size(), styles, ex_styles);
  this->control::create_handle();
}
