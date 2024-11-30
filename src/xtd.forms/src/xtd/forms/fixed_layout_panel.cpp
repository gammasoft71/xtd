#include "../../../include/xtd/forms/fixed_layout_panel.hpp"

using namespace xtd;
using namespace xtd::forms;

fixed_layout_panel fixed_layout_panel::create() {
  return  fixed_layout_panel {};
}

fixed_layout_panel fixed_layout_panel::create(const drawing::point& location) {
  auto result = fixed_layout_panel {};
  result.location(location);
  return result;
}

fixed_layout_panel fixed_layout_panel::create(const drawing::point& location, const drawing::size& size) {
  auto result = fixed_layout_panel {};
  result.location(location);
  result.size(size);
  return result;
}

fixed_layout_panel fixed_layout_panel::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = fixed_layout_panel {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

fixed_layout_panel fixed_layout_panel::create(const control& parent) {
  auto result = fixed_layout_panel {};
  result.parent(parent);
  return result;
}

fixed_layout_panel fixed_layout_panel::create(const control& parent, const drawing::point& location) {
  auto result = fixed_layout_panel {};
  result.parent(parent);
  result.location(location);
  return result;
}

fixed_layout_panel fixed_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = fixed_layout_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

fixed_layout_panel fixed_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = fixed_layout_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

xtd::uptr<xtd::object> fixed_layout_panel::clone() const {
  auto result = xtd::new_uptr<fixed_layout_panel>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()));
  return result;
}

void fixed_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
}
