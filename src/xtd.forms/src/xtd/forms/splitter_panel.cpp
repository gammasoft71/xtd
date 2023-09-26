#include "../../../include/xtd/forms/splitter_panel"

using namespace xtd;
using namespace xtd::forms;

splitter_panel splitter_panel::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = splitter_panel {};
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

splitter_panel splitter_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = splitter_panel {};
  result.parent(parent);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}
