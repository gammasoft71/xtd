#include "../../../include/xtd/forms/horizontal_layout_panel.h"

using namespace xtd;
using namespace xtd::forms;

const horizontal_control_layout_style& horizontal_layout_panel::control_layout_style(const const_control_ref& control) const {
  auto it = control_layout_styles_.find(control);
  if (it == control_layout_styles_.end()) throw argument_exception(caller_info_);
  return it->second;
}

horizontal_layout_panel& horizontal_layout_panel::control_layout_style(const const_control_ref& control, const horizontal_control_layout_style& value) {
  auto it = control_layout_styles_.find(control);
  if (it == control_layout_styles_.end()) throw argument_exception(caller_info_);
  if (it->second != value) {
    it->second = value;
    perform_layout();
  }
  return *this;
}

void horizontal_layout_panel::on_control_added(const xtd::forms::control_event_args& e) {
  panel::on_control_added(e);
  control_layout_styles_[e.control()] = horizontal_control_layout_style();
}

void horizontal_layout_panel::on_control_removed(const xtd::forms::control_event_args& e) {
  panel::on_control_removed(e);
  control_layout_styles_.erase(const_control_ref(e.control()));
}

void horizontal_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
  if (controls().size() == 0) return;
  int32_t left = padding().left();
  int32_t top = padding().top();
  int32_t width = client_size().width() / static_cast<int32_t>(controls().size()) - padding().left() - padding().right();;
  int32_t height = client_size().height() - padding().top() - padding().bottom();
  for (size_t index = 0; index < controls().size(); ++index) {
    controls()[index].get().set_bounds(left, top, width, height);
    left += width + padding().right() + padding().left();
  }
}
