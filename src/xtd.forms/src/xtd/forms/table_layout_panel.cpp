#include "../../../include/xtd/forms/table_layout_panel.h"

using namespace xtd;
using namespace xtd::forms;

table_layout_panel table_layout_panel::create() {
  return table_layout_panel {};
}

table_layout_panel table_layout_panel::create(const drawing::point& location) {
  auto result = table_layout_panel {};
  result.location(location);
  return result;
}

table_layout_panel table_layout_panel::create(const drawing::point& location, const drawing::size& size) {
  auto result = table_layout_panel {};
  result.location(location);
  result.size(size);
  return result;
}

table_layout_panel table_layout_panel::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = table_layout_panel {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

table_layout_panel table_layout_panel::create(const control& parent) {
  auto result = table_layout_panel {};
  result.parent(parent);
  return result;
}

table_layout_panel table_layout_panel::create(const control& parent, const drawing::point& location) {
  auto result = table_layout_panel {};
  result.parent(parent);
  result.location(location);
  return result;
}

table_layout_panel table_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = table_layout_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

table_layout_panel table_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = table_layout_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

xtd::uptr<xtd::object> table_layout_panel::clone() const {
  auto result = xtd::new_uptr<table_layout_panel>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()));
  return result;
}

void table_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
}
