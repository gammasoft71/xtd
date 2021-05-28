#include "../../../include/xtd/forms/horizontal_layout_panel.h"

using namespace xtd;
using namespace xtd::forms;

const horizontal_control_layout_style& horizontal_layout_panel::control_layout_style(const control_ref& control) const {
  auto it = control_layout_styles_.find(control);
  if (it == control_layout_styles_.end()) throw argument_exception(caller_info_);
  return it->second;
}

horizontal_layout_panel& horizontal_layout_panel::control_layout_style(const control_ref& control, const horizontal_control_layout_style& value) {
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
  control_layout_styles_[const_cast<xtd::forms::control&>(e.control())] = horizontal_control_layout_style();
}

void horizontal_layout_panel::on_control_removed(const xtd::forms::control_event_args& e) {
  panel::on_control_removed(e);
  control_layout_styles_.erase(const_cast<xtd::forms::control&>(e.control()));
}

void horizontal_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
  if (!parent() && controls().size() == 0) return;
  
  size_t auto_size_control_count = count_if(control_layout_styles_.begin(), control_layout_styles_.end(), [](auto layout_style)->bool {return layout_style.second.size_type() == size_type::auto_size;});
  int32_t auto_size_width = client_size().width() - auto_size_control_count * padding().left() - auto_size_control_count * padding().right();
  
  int32_t absolute_width = 0;
  for (auto& [control, layout_style] : control_layout_styles_)
    if (layout_style.size_type() == size_type::absolute) absolute_width += layout_style.width();
  auto_size_width -= absolute_width;
  
  float total_percent = 0;
  for (auto& [control, layout_style] : control_layout_styles_)
    if (layout_style.size_type() == size_type::percent) total_percent += layout_style.width();
  int32_t percent_width = static_cast<int32_t>(auto_size_width * total_percent);
  auto_size_width -= percent_width;
  
  int32_t left = padding().left();
  int32_t top = padding().top();
  int32_t width = 0;
  int32_t height = 0;
  for (auto& [control, layout_style] : control_layout_styles_) {
    height = layout_style.expanded() ? client_size().height() - padding().top() - padding().bottom() : control.get().height();
    if (layout_style.size_type() == size_type::absolute) width = layout_style.width();
    else if (layout_style.size_type() == size_type::percent) width = static_cast<int32_t>(percent_width * (layout_style.width() / total_percent));
    else if (layout_style.size_type() == size_type::auto_size) width = auto_size_width / auto_size_control_count;
    else throw argument_exception(caller_info_);
    control.get().set_bounds(left, top, width, height);
    left += width + padding().right() + padding().left();
  }
}
