#include "../../../include/xtd/forms/fixed_layout_panel.h"

using namespace xtd;
using namespace xtd::forms;

fixed_layout_panel fixed_layout_panel::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  fixed_layout_panel item;
  if (location != drawing::point {-1, -1}) item.location(location);
  if (size != drawing::size {-1, -1}) item.size(size);
  item.name(name);
  return item;
}

fixed_layout_panel fixed_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  fixed_layout_panel item;
  item.parent(parent);
  if (location != drawing::point {-1, -1}) item.location(location);
  if (size != drawing::size {-1, -1}) item.size(size);
  item.name(name);
  return item;
}

void fixed_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
}
