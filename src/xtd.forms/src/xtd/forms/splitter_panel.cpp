#include "../../../include/xtd/forms/splitter_panel.h"

using namespace xtd;
using namespace xtd::forms;

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

splitter_panel splitter_panel::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
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

splitter_panel splitter_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = splitter_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}
