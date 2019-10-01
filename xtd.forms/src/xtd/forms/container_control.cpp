#include "../../../include/xtd/forms/container_control.hpp"

using namespace xtd;
using namespace xtd::forms;

void container_control::active_control(const control& active_control) {
  this->active_control_ = const_cast<control&>(active_control);
}
