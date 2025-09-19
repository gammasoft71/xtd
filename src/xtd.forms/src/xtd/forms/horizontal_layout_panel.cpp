#include "../../../include/xtd/forms/horizontal_layout_panel.hpp"
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

const horizontal_control_layout_style_collection& horizontal_layout_panel::control_layout_styles() const noexcept {
  return control_layout_styles_;
}

const horizontal_control_layout_style& horizontal_layout_panel::control_layout_style(const control_ref& control) const {
  auto it = std::find_if(control_layout_styles_.begin(), control_layout_styles_.end(), [&](const auto & item) {return item.first == control;});
  if (it == control_layout_styles_.end()) throw_helper::throws(exception_case::argument);
  return it->second;
}

horizontal_layout_panel& horizontal_layout_panel::control_layout_style(const control_ref& control, const horizontal_control_layout_style& value) {
  auto it = std::find_if(control_layout_styles_.begin(), control_layout_styles_.end(), [&](const auto & item) {return item.first == control;});
  if (it == control_layout_styles_.end()) throw_helper::throws(exception_case::argument);
  if (it->second != value) {
    it->second = value;
    perform_layout();
  }
  return *this;
}

horizontal_layout_panel horizontal_layout_panel::create() {
  return horizontal_layout_panel {};
}

horizontal_layout_panel horizontal_layout_panel::create(const drawing::point& location) {
  auto result = horizontal_layout_panel {};
  result.location(location);
  return result;
}

horizontal_layout_panel horizontal_layout_panel::create(const drawing::point& location, const drawing::size& size) {
  auto result = horizontal_layout_panel {};
  result.location(location);
  result.size(size);
  return result;
}

horizontal_layout_panel horizontal_layout_panel::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = horizontal_layout_panel {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

horizontal_layout_panel horizontal_layout_panel::create(const control& parent) {
  auto result = horizontal_layout_panel {};
  result.parent(parent);
  return result;
}

horizontal_layout_panel horizontal_layout_panel::create(const control& parent, const drawing::point& location) {
  auto result = horizontal_layout_panel {};
  result.parent(parent);
  result.location(location);
  return result;
}

horizontal_layout_panel horizontal_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = horizontal_layout_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

horizontal_layout_panel horizontal_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = horizontal_layout_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

xtd::uptr<xtd::object> horizontal_layout_panel::clone() const {
  auto result = xtd::new_uptr<horizontal_layout_panel>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).chars().c_str());
  return result;
}

void horizontal_layout_panel::on_control_added(const xtd::forms::control_event_args& e) {
  panel::on_control_added(e);
  control_layout_styles_.emplace_back(control_ref(const_cast<xtd::forms::control&>(e.control())), horizontal_control_layout_style());
}

void horizontal_layout_panel::on_control_removed(const xtd::forms::control_event_args& e) {
  panel::on_control_removed(e);
  auto it = std::find_if(control_layout_styles_.begin(), control_layout_styles_.end(), [&](auto item) {return item.first.get() == e.control();});
  if (it == control_layout_styles_.end()) throw_helper::throws(exception_case::argument);
  control_layout_styles_.erase(it);
}

void horizontal_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
  if (!parent() && controls().count() == 0) return;
  
  auto auto_size_control_count = count_if(control_layout_styles_.begin(), control_layout_styles_.end(), [](auto layout_style)->bool {return layout_style.second.size_type() == size_type::auto_size;});
  auto auto_size_width = client_size().width - static_cast<int32>(control_layout_styles().size() * padding().left()) - static_cast<int32>(control_layout_styles().size() * padding().right());
  
  auto absolute_width = 0;
  for (auto& [control, layout_style] : control_layout_styles_)
    if (layout_style.size_type() == size_type::absolute) absolute_width += static_cast<int32>(layout_style.width().value_or(control.get().default_size().width));
  auto_size_width -= absolute_width;
  
  auto total_percent = .0f;
  for (auto& [control, layout_style] : control_layout_styles_)
    if (layout_style.size_type() == size_type::percent) total_percent += layout_style.width().value_or(0);
  auto percent_width = static_cast<int32>(auto_size_width * total_percent);
  auto_size_width -= percent_width;
  
  auto left = padding().left();
  auto top = 0;
  auto width = 0;
  for (auto& [control, layout_style] : control_layout_styles_) {
    if (layout_style.expanded()) top = padding().top();
    else {
      if (layout_style.align() == content_alignment::top_left || layout_style.align() == content_alignment::top_center || layout_style.align() == content_alignment::top_right) top = padding().top();
      else if (layout_style.align() == content_alignment::bottom_left || layout_style.align() == content_alignment::bottom_center || layout_style.align() == content_alignment::bottom_right) top = client_size().height - padding().bottom() - control.get().height();
      else top = client_size().height / 2 - control.get().height() / 2;
    }
    auto height = layout_style.expanded() ? client_size().height - padding().top() - padding().bottom() : control.get().height();
    if (layout_style.size_type() == size_type::absolute) width = static_cast<int32>(layout_style.width().value_or(control.get().default_size().width));
    else if (layout_style.size_type() == size_type::percent) width = static_cast<int32>(percent_width * (layout_style.width().value_or(0) / total_percent));
    else if (layout_style.size_type() == size_type::auto_size) width = static_cast<int32>(auto_size_width / auto_size_control_count);
    else throw_helper::throws(exception_case::argument);
    control.get().set_bounds(left, top, width, height);
    left += width + padding().right() + padding().left();
  }
}
