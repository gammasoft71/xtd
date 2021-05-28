#include <xtd/argument_exception.h>
#include "../../../include/xtd/forms/vertical_layout_panel.h"

using namespace xtd;
using namespace xtd::forms;

const vertical_control_layout_style& vertical_layout_panel::control_layout_style(const const_control_ref& control) const {
  auto it = control_layout_styles_.find(control);
  if (it == control_layout_styles_.end()) throw argument_exception(caller_info_);
  return it->second;
}

vertical_layout_panel& vertical_layout_panel::control_layout_style(const const_control_ref& control, const vertical_control_layout_style& value) {
  auto it = control_layout_styles_.find(control);
  if (it == control_layout_styles_.end()) throw argument_exception(caller_info_);
  if (it->second != value) {
    it->second = value;
    perform_layout();
  }
  return *this;
}

void vertical_layout_panel::on_control_added(const xtd::forms::control_event_args& e) {
  panel::on_control_added(e);
  control_layout_styles_[e.control()] = vertical_control_layout_style();
}

void vertical_layout_panel::on_control_removed(const xtd::forms::control_event_args& e) {
  panel::on_control_removed(e);
  control_layout_styles_.erase(e.control());
}

void vertical_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
  if (controls().size() == 0) return;
  int32_t top = padding().top();
  int32_t left = padding().left();
  int32_t width = client_size().width() - padding().left() - padding().right();
  int32_t height = client_size().height() / static_cast<int32_t>(controls().size()) - padding().top() - padding().bottom();
  for (size_t index = 0; index < controls().size(); ++index) {
    controls()[index].get().set_bounds(left, top, width, height);
    top += height + padding().bottom() + padding().top();
  }
}
