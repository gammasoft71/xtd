#include <xtd/argument_exception.h>
#include "../../../include/xtd/forms/vertical_layout_panel.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

const vertical_control_layout_style& vertical_layout_panel::control_layout_style(const control_ref& control) const {
  auto it = control_layout_styles_.find(control);
  if (it == control_layout_styles_.end()) throw argument_exception(caller_info_);
  return it->second;
}

vertical_layout_panel& vertical_layout_panel::control_layout_style(const control_ref& control, const vertical_control_layout_style& value) {
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
  control_layout_styles_[const_cast<xtd::forms::control&>(e.control())] = vertical_control_layout_style();
}

void vertical_layout_panel::on_control_removed(const xtd::forms::control_event_args& e) {
  panel::on_control_removed(e);
  control_layout_styles_.erase(const_cast<xtd::forms::control&>(e.control()));
}

void vertical_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
  if (!parent() && controls().size() == 0) return;
  
  size_t auto_size_control_count = count_if(control_layout_styles_.begin(), control_layout_styles_.end(), [](auto layout_style)->bool {return layout_style.second.size_type() == size_type::auto_size;});
  int32_t auto_size_height = client_size().height() - static_cast<int32_t>(control_layout_styles().size() * padding().top()) - static_cast<int32_t>(control_layout_styles().size() * padding().bottom());

  int32_t absolute_height = 0;
  for (auto& [control, layout_style] : control_layout_styles_)
    if (layout_style.size_type() == size_type::absolute) absolute_height += layout_style.height();
  auto_size_height -= absolute_height;

  float total_percent = 0;
  for (auto& [control, layout_style] : control_layout_styles_)
    if (layout_style.size_type() == size_type::percent) total_percent += layout_style.height();
  int32_t percent_height = static_cast<int32_t>(auto_size_height * total_percent);
  auto_size_height -= percent_height;

  int32_t left = padding().left();
  int32_t top = padding().top();
  int32_t width = 0;
  int32_t height = 0;
  for (auto& [control, layout_style] : control_layout_styles_) {
    width = layout_style.expanded() ? client_size().width() - padding().left() - padding().right() : control.get().width();
    if (layout_style.size_type() == size_type::absolute) height = layout_style.height();
    else if (layout_style.size_type() == size_type::percent) height = static_cast<int32_t>(percent_height * (layout_style.height() / total_percent));
    else if (layout_style.size_type() == size_type::auto_size) height = auto_size_height / auto_size_control_count;
    else throw argument_exception(caller_info_);
    control.get().set_bounds(left, top, width, height);
    top += height + padding().bottom() + padding().top();
  }
}
