#include "../../../include/xtd/forms/splitter.hpp"

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

struct splitter::data {
  bool default_width = true;
  int32 min_size = 25;
  //int32 min_size_extra = 25;
  //int32 split_position = -1;
  int32 mouse_down_location = -1;
  xtd::forms::splitter_style splitter_style = xtd::forms::splitter_style::update_children;
  xtd::forms::cursor previous_control_cursor;
  xtd::forms::cursor next_control_cursor;
  control* previous_control = nullptr;
  control* next_control = nullptr;
};

splitter::splitter() : data_(xtd::new_sptr<data>()) {
  dock(xtd::forms::dock_style::left);
  set_style(control_styles::selectable, false);
}

control& splitter::dock(dock_style dock) {
  if (dock != dock_style::left && dock != dock_style::right && dock != dock_style::top && dock != dock_style::bottom) throw_helper::throws(exception_case::argument, "splitter control must be docked left, right, top, or bottom."_t);
  control::dock(dock);
  cursor(default_cursor());
  if (data_->default_width && (dock == dock_style::left || dock == dock_style::right)) width(3);
  if (data_->default_width && (dock == dock_style::top || dock == dock_style::bottom)) height(3);
  return *this;
}

int32 splitter::min_size() const noexcept {
  return data_->min_size;
}

splitter& splitter::min_size(int32 min_size) {
  data_->min_size = min_size;
  return *this;
}

xtd::forms::splitter_style splitter::splitter_style() const noexcept {
  return data_->splitter_style;
}

splitter& splitter::splitter_style(xtd::forms::splitter_style splitter_style) {
  data_->splitter_style = splitter_style;
  return *this;
}

forms::cursor splitter::default_cursor() const noexcept {
  return dock() == dock_style::left || dock() == dock_style::right ? xtd::forms::cursors::vsplit() : xtd::forms::cursors::hsplit();
}

splitter splitter::create() {
  return splitter {};
}

splitter splitter::create(const drawing::point& location) {
  auto result = splitter {};
  result.location(location);
  return result;
}

splitter splitter::create(const drawing::point& location, const drawing::size& size) {
  auto result = splitter {};
  result.location(location);
  result.size(size);
  return result;
}

splitter splitter::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = splitter {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

splitter splitter::create(const control& parent) {
  auto result = splitter {};
  result.parent(parent);
  return result;
}

splitter splitter::create(const control& parent, const drawing::point& location) {
  auto result = splitter {};
  result.parent(parent);
  result.location(location);
  return result;
}

splitter splitter::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = splitter {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

splitter splitter::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = splitter {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

drawing::size splitter::default_size() const noexcept {
  return {3, 3};
}

xtd::uptr<xtd::object> splitter::clone() const {
  auto result = xtd::new_uptr<splitter>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}

void splitter::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
}

void splitter::on_mouse_down(const mouse_event_args& e) {
  control::on_mouse_down(e);
  data_->mouse_down_location = control::dock() == dock_style::left || control::dock() == dock_style::right ? cursor::position().x : cursor::position().y;
  if (parent().has_value()) {
    for (auto index = 0_z; index < parent().value().get().controls().size(); ++index) {
      if (parent().value().get().controls()[index].get() == *this) {
        if (index > 0) data_->previous_control_cursor = (data_->previous_control = &parent().value().get().controls()[index - 1].get())->cursor();
        if (index < parent().value().get().controls().size() - 1) data_->next_control_cursor = (data_->next_control = &parent().value().get().controls()[index + 1].get())->cursor();
        break;
      }
    }
  }
  if (data_->previous_control) data_->previous_control->cursor(default_cursor());
  if (data_->next_control) data_->next_control->cursor(default_cursor());
}

void splitter::on_mouse_move(const mouse_event_args& e) {
  control::on_mouse_move(e);
  if (data_->previous_control) data_->previous_control->cursor(default_cursor());
  if (data_->next_control) data_->next_control->cursor(default_cursor());
  if (data_->mouse_down_location != -1 && data_->next_control) {
    if (data_->splitter_style == splitter_style::draw_line) {
    
    } else {
      auto delta_size = control::dock() == dock_style::left || control::dock() == dock_style::right ? (data_->next_control->width() + cursor::position().x) : (data_->next_control->height() + cursor::position().y);
      auto new_size = delta_size - data_->mouse_down_location;
      if (new_size < data_->min_size) new_size = data_->min_size;
      //if (data_->previous_control.size()  < data_->min_size_extra) new_size = data_->min_size;
      if (control::dock() == dock_style::left || control::dock() == dock_style::right) data_->next_control->width(new_size);
      else data_->next_control->height(new_size);
      data_->mouse_down_location = control::dock() == dock_style::left || control::dock() == dock_style::right ? cursor::position().x : cursor::position().y;
    }
  }
}

void splitter::on_mouse_up(const mouse_event_args& e) {
  control::on_mouse_up(e);
  if (data_->previous_control) data_->previous_control->cursor(data_->previous_control_cursor);
  if (data_->next_control) data_->next_control->cursor(data_->previous_control_cursor);
  if (data_->mouse_down_location != -1 && parent().has_value() && data_->next_control) {
    auto new_size = (control::dock() == dock_style::left || control::dock() == dock_style::right ? (data_->next_control->width() + cursor::position().x) : (data_->next_control->height() + cursor::position().y)) - data_->mouse_down_location;
    if (new_size < data_->min_size) new_size = data_->min_size;
    if (control::dock() == dock_style::left || control::dock() == dock_style::right) data_->next_control->width(new_size);
    else data_->next_control->height(new_size);
    data_->mouse_down_location = -1;
  }
  data_->previous_control = nullptr;
  data_->next_control = nullptr;
}
