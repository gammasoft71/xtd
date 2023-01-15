#include "../../../include/xtd/forms/flow_layout_panel.h"

using namespace xtd;
using namespace xtd::forms;

flow_layout_panel flow_layout_panel::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  flow_layout_panel item;
  if (location != drawing::point {-1, -1}) item.location(location);
  if (size != drawing::size {-1, -1}) item.size(size);
  item.name(name);
  return item;
}

flow_layout_panel flow_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  flow_layout_panel item;
  item.parent(parent);
  if (location != drawing::point {-1, -1}) item.location(location);
  if (size != drawing::size {-1, -1}) item.size(size);
  item.name(name);
  return item;
}

void flow_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
}
