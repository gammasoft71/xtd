#include "../../../include/xtd/forms/splitter_panel.h"

using namespace xtd;
using namespace xtd::forms;

splitter_panel splitter_panel::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  splitter_panel item;
  if (location != drawing::point {-1, -1}) item.location(location);
  if (size != drawing::size {-1, -1}) item.size(size);
  item.name(name);
  return item;
}

splitter_panel splitter_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  splitter_panel item;
  item.parent(parent);
  if (location != drawing::point {-1, -1}) item.location(location);
  if (size != drawing::size {-1, -1}) item.size(size);
  item.name(name);
  return item;
}
