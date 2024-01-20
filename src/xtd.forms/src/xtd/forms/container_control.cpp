#include "../../../include/xtd/forms/container_control.h"

using namespace xtd;
using namespace xtd::forms;

std::optional<control_ref> container_control::active_control() const noexcept {
  return active_control_;
}

void container_control::active_control(const control& active_control) {
  active_control_ = const_cast<control&>(active_control);
  if (active_control_.has_value() && active_control_.value().get().can_focus())
    active_control_.value().get().focus();
}

void container_control::active_control(std::nullptr_t) {
  active_control_.reset();
}

container_control::container_control() {
  set_style(control_styles::container_control, true);
  set_style(control_styles::all_painting_in_wm_paint, false);
}

drawing::size container_control::measure_control() const noexcept {
  auto bounds = drawing::rectangle {};
  for (auto item : controls()) {
    if (item.get().visible())
      bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  }
  return drawing::size(bounds.location() + bounds.size());
}
