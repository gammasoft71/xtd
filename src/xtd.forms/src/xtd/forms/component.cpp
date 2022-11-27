#include "../../../include/xtd/forms/component.h"

using namespace xtd;
using namespace xtd::forms;

bool component::can_raise_events() const noexcept {
  return data_->can_raise_event;
}

bool component::design_mode() const noexcept {
  return data_->design_mode;
}
