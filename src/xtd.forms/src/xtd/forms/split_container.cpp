#include "../../../include/xtd/forms/split_container.hpp"

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

struct split_container::data {
  xtd::forms::orientation orientation = xtd::forms::orientation::vertical;
  splitter_panel panel1;
  splitter_panel panel2;
  xtd::forms::splitter splitter;
  int32 splitter_distance = 50;
  //int32 splitter_increment = 1;
  int32 splitter_width = 4;
};

split_container::split_container() : data_(xtd::new_sptr<data>()) {
  set_can_focus(false);
  set_style(control_styles::supports_transparent_back_color, true);
  set_style(control_styles::optimized_double_buffer, true);
  controls().add_range({data_->panel2, data_->splitter, data_->panel1});
  arrange_children();
}

xtd::forms::orientation split_container::orientation() const noexcept {
  return data_->orientation;
}

split_container& split_container::orientation(xtd::forms::orientation orientation) {
  if (data_->orientation == orientation) return *this;
  data_->orientation = orientation;
  arrange_children();
  return *this;
}

const splitter_panel& split_container::panel1() const noexcept {
  return data_->panel1;
}

splitter_panel& split_container::panel1() noexcept {
  return data_->panel1;
}

const splitter_panel& split_container::panel2() const noexcept {
  return data_->panel2;
}

splitter_panel& split_container::panel2() noexcept {
  return data_->panel2;
}

int32 split_container::splitter_distance() const noexcept {
  return data_->splitter_distance;
}

split_container& split_container::splitter_distance(int32 splitter_distance) {
  if (data_->splitter_distance == splitter_distance) return *this;
  data_->splitter_distance = splitter_distance;
  if (data_->orientation == xtd::forms::orientation::horizontal) data_->panel1.height(splitter_distance);
  else data_->panel1.width(splitter_distance);
  return *this;
}

xtd::forms::splitter_style split_container::splitter_style() const noexcept {
  return data_->splitter.splitter_style();
}

split_container& split_container::splitter_style(xtd::forms::splitter_style splitter_style) {
  if (data_->splitter.splitter_style() == splitter_style) return *this;
  data_->splitter.splitter_style(splitter_style);
  return *this;
}

int32 split_container::splitter_width() const noexcept {
  return data_->splitter_width;
}

split_container& split_container::splitter_width(int32 splitter_width) {
  if (data_->splitter_width == splitter_width) return *this;
  data_->splitter_width = splitter_width;
  arrange_children();
  return *this;
}

split_container split_container::create() {
  return split_container {};
}

split_container split_container::create(const drawing::point& location) {
  auto result = split_container {};
  result.location(location);
  return result;
}

split_container split_container::create(const drawing::point& location, const drawing::size& size) {
  auto result = split_container {};
  result.location(location);
  result.size(size);
  return result;
}

split_container split_container::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = split_container {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

split_container split_container::create(const control& parent) {
  auto result = split_container {};
  result.parent(parent);
  return result;
}

split_container split_container::create(const control& parent, const drawing::point& location) {
  auto result = split_container {};
  result.parent(parent);
  result.location(location);
  return result;
}

split_container split_container::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = split_container {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

split_container split_container::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = split_container {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

drawing::size split_container::default_size() const noexcept {
  return {150, 100};
}

xtd::uptr<xtd::object> split_container::clone() const {
  auto result = xtd::new_uptr<split_container>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).chars().c_str());
  return result;
}

void split_container::on_resize(const event_args& e) {
  xtd::forms::scrollable_control::on_resize(e);
}

void split_container::arrange_children() {
  if (data_->orientation == xtd::forms::orientation::vertical) {
    data_->panel1.dock(xtd::forms::dock_style::left);
    data_->panel1.width(data_->splitter_distance);
    data_->splitter.dock(xtd::forms::dock_style::left);
    data_->splitter.width(data_->splitter_width);
  } else {
    data_->panel1.dock(xtd::forms::dock_style::top);
    data_->panel1.height(data_->splitter_distance);
    data_->splitter.dock(xtd::forms::dock_style::top);
    data_->splitter.height(data_->splitter_width);
  }
  data_->panel2.dock(xtd::forms::dock_style::fill);
}
