#include "../../../include/xtd/forms/container_control.h"

using namespace xtd;
using namespace xtd::forms;

void container_control::active_control(const control& active_control) {
  this->active_control_ = const_cast<control&>(active_control);
  if (active_control_.has_value() && active_control_.value().get().can_focus())
    active_control_.value().get().focus();
}

drawing::size container_control::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : this->controls()) {
    if (item.get().visible())
      bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  }
  return drawing::size(bounds.location() + bounds.size());
}
