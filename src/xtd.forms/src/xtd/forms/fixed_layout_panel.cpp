#include "../../../include/xtd/forms/fixed_layout_panel"

using namespace xtd;
using namespace xtd::forms;

fixed_layout_panel fixed_layout_panel::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = fixed_layout_panel {};
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

fixed_layout_panel fixed_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = fixed_layout_panel {};
  result.parent(parent);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

void fixed_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
}
