#include "../../../include/xtd/forms/splitter_panel.hpp"

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

splitter_panel splitter_panel::create() {
  return splitter_panel {};
}

splitter_panel splitter_panel::create(const drawing::point& location) {
  auto result = splitter_panel {};
  result.location(location);
  return result;
}

splitter_panel splitter_panel::create(const drawing::point& location, const drawing::size& size) {
  auto result = splitter_panel {};
  result.location(location);
  result.size(size);
  return result;
}

splitter_panel splitter_panel::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = splitter_panel {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

splitter_panel splitter_panel::create(const control& parent) {
  auto result = splitter_panel {};
  result.parent(parent);
  return result;
}

splitter_panel splitter_panel::create(const control& parent, const drawing::point& location) {
  auto result = splitter_panel {};
  result.parent(parent);
  result.location(location);
  return result;
}

splitter_panel splitter_panel::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = splitter_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

splitter_panel splitter_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = splitter_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

xtd::uptr<xtd::object> splitter_panel::clone() const {
  auto result = xtd::new_uptr<splitter_panel>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}
