#include "../../../include/xtd/forms/vertical_layout_panel.h"
#include <xtd/argument_exception>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

const vertical_control_layout_style_collection& vertical_layout_panel::control_layout_styles() const noexcept {
  return control_layout_styles_;
}

const vertical_control_layout_style& vertical_layout_panel::control_layout_style(const control_ref& control) const {
  auto it = find_if(control_layout_styles_.begin(), control_layout_styles_.end(), [&](auto item) {return item.first.get() == control;});
  if (it == control_layout_styles_.end()) throw argument_exception {csf_};
  return it->second;
}

vertical_layout_panel& vertical_layout_panel::control_layout_style(const control_ref& control, const vertical_control_layout_style& value) {
  auto it = find_if(control_layout_styles_.begin(), control_layout_styles_.end(), [&](auto item) {return item.first.get() == control;});
  if (it == control_layout_styles_.end()) throw argument_exception {csf_};
  if (it->second != value) {
    it->second = value;
    perform_layout();
  }
  return *this;
}

vertical_layout_panel vertical_layout_panel::create() {
  return vertical_layout_panel {};
}

vertical_layout_panel vertical_layout_panel::create(const drawing::point& location) {
  auto result = vertical_layout_panel {};
  result.location(location);
  return result;
}

vertical_layout_panel vertical_layout_panel::create(const drawing::point& location, const drawing::size& size) {
  auto result = vertical_layout_panel {};
  result.location(location);
  result.size(size);
  return result;
}

vertical_layout_panel vertical_layout_panel::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = vertical_layout_panel {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

vertical_layout_panel vertical_layout_panel::create(const control& parent) {
  auto result = vertical_layout_panel {};
  result.parent(parent);
  return result;
}

vertical_layout_panel vertical_layout_panel::create(const control& parent, const drawing::point& location) {
  auto result = vertical_layout_panel {};
  result.parent(parent);
  result.location(location);
  return result;
}

vertical_layout_panel vertical_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = vertical_layout_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

vertical_layout_panel vertical_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = vertical_layout_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void vertical_layout_panel::on_control_added(const xtd::forms::control_event_args& e) {
  panel::on_control_added(e);
  control_layout_styles_.emplace_back(control_ref(const_cast<xtd::forms::control&>(e.control())), vertical_control_layout_style());
}

void vertical_layout_panel::on_control_removed(const xtd::forms::control_event_args& e) {
  panel::on_control_removed(e);
  auto it = find_if(control_layout_styles_.begin(), control_layout_styles_.end(), [&](auto item) {return item.first.get() == e.control();});
  if (it == control_layout_styles_.end()) throw argument_exception {csf_};
  control_layout_styles_.erase(it);
}

void vertical_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
  if (!parent() && controls().size() == 0) return;
  
  auto auto_size_control_count = count_if(control_layout_styles_.begin(), control_layout_styles_.end(), [](auto layout_style)->bool {return layout_style.first.get().visible() && layout_style.second.size_type() == size_type::auto_size;});
  auto auto_size_height = client_size().height() - static_cast<int32>(control_layout_styles().size() * padding().top()) - static_cast<int32>(control_layout_styles().size() * padding().bottom());
  
  auto absolute_height = 0;
  for (auto& [control, layout_style] : control_layout_styles_)
    if (control.get().visible() && layout_style.size_type() == size_type::absolute) absolute_height += static_cast<int32>(layout_style.height().value_or(control.get().default_size().height()));
  auto_size_height -= absolute_height;
  
  auto total_percent = .0f;
  for (auto& [control, layout_style] : control_layout_styles_)
    if (control.get().visible() && layout_style.size_type() == size_type::percent) total_percent += layout_style.height().value_or(0);
  auto percent_height = static_cast<int32>(auto_size_height * total_percent);
  auto_size_height -= percent_height;
  
  auto left = 0;
  auto top = padding().top();
  auto width = 0;
  auto height = 0;
  for (auto& [control, layout_style] : control_layout_styles_) {
    if (!control.get().visible()) continue;
    if (layout_style.expanded()) left = padding().left();
    else {
      if (layout_style.align() == content_alignment::top_left || layout_style.align() == content_alignment::middle_left || layout_style.align() == content_alignment::bottom_left) left = padding().left();
      else if (layout_style.align() == content_alignment::top_right || layout_style.align() == content_alignment::middle_right || layout_style.align() == content_alignment::bottom_right) left =  padding().top() + client_size().width() - padding().left() - padding().right() - control.get().width();
      else left = client_size().width() / 2 - control.get().width() / 2;
    }
    width = layout_style.expanded() ? client_size().width() - padding().left() - padding().right() : control.get().width();
    if (layout_style.size_type() == size_type::absolute) height = static_cast<int32>(layout_style.height().value_or(control.get().default_size().height()));
    else if (layout_style.size_type() == size_type::percent) height = static_cast<int32>(percent_height * (layout_style.height().value_or(0) / total_percent));
    else if (layout_style.size_type() == size_type::auto_size) height = static_cast<int32>(auto_size_height / auto_size_control_count);
    else throw argument_exception {csf_};
    control.get().set_bounds(left, top, width, height);
    top += height + padding().bottom() + padding().top();
  }
}
