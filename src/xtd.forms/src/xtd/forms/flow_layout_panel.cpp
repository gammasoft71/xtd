#include "../../../include/xtd/forms/flow_layout_panel.h"

using namespace xtd;
using namespace xtd::forms;

flow_layout_panel flow_layout_panel::create() {
  return flow_layout_panel {};
}

flow_layout_panel flow_layout_panel::create(const drawing::point& location) {
  auto result = flow_layout_panel {};
  result.location(location);
  return result;
}

flow_layout_panel flow_layout_panel::create(const drawing::point& location, const drawing::size& size) {
  auto result = flow_layout_panel {};
  result.location(location);
  result.size(size);
  return result;
}

flow_layout_panel flow_layout_panel::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = flow_layout_panel {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

flow_layout_panel flow_layout_panel::create(const control& parent) {
  auto result = flow_layout_panel {};
  result.parent(parent);
  return result;
}

flow_layout_panel flow_layout_panel::create(const control& parent, const drawing::point& location) {
  auto result = flow_layout_panel {};
  result.parent(parent);
  result.location(location);
  return result;
}

flow_layout_panel flow_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = flow_layout_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

flow_layout_panel flow_layout_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = flow_layout_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void flow_layout_panel::on_layout(const event_args& e) {
  panel::on_layout(e);
}
