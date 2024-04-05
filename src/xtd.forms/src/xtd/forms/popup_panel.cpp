#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/popup_panel.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/tab_control>
#include <xtd/forms/native/popup_panel>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct popup_panel::data {
  bool ignore_mouse_messages = false;
};

popup_panel::popup_panel() : data_(std::make_shared<data>()) {
  visible(false);
}

bool popup_panel::ignore_mouse_messages() const noexcept {
  return data_->ignore_mouse_messages;
}

popup_panel& popup_panel::ignore_mouse_messages(bool value) {
  if (data_->ignore_mouse_messages == value) return *this;
  data_->ignore_mouse_messages = value;
  native::popup_panel::ignore_mouse_messages(handle(), data_->ignore_mouse_messages);
  return *this;
}

popup_panel popup_panel::create() {
  return popup_panel {};
}

popup_panel popup_panel::create(const drawing::point& location) {
  auto result = popup_panel {};
  result.location(location);
  return result;
}

popup_panel popup_panel::create(const drawing::point& location, const drawing::size& size) {
  auto result = popup_panel {};
  result.location(location);
  result.size(size);
  return result;
}

popup_panel popup_panel::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = popup_panel {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

popup_panel popup_panel::create(const control& parent) {
  auto result = popup_panel {};
  result.parent(parent);
  return result;
}

popup_panel popup_panel::create(const control& parent, const drawing::point& location) {
  auto result = popup_panel {};
  result.parent(parent);
  result.location(location);
  return result;
}

popup_panel popup_panel::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = popup_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

popup_panel popup_panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = popup_panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

forms::create_params popup_panel::create_params() const noexcept {
  auto create_params = panel::create_params();
  create_params.class_name("popuppanel");
  return create_params;
}

unique_ptr<xtd::object> popup_panel::clone() const {
  auto result = make_unique<popup_panel>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::ustring::format("The {} does not implement clone method.", typeof_(*this).full_name()), csf_);
  return result;
}

void popup_panel::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::popup_panel::ignore_mouse_messages(handle(), data_->ignore_mouse_messages);
}

void popup_panel::on_layout(const event_args& e) {
  scrollable_control::on_layout(e);
  if (is_handle_created() && auto_scroll()) native::popup_panel::virtual_size(handle(), display_rectangle().size());
}

void popup_panel::on_region_changed(const event_args& e) {
  native::popup_panel::set_region(handle(), region().handle());
  control::on_region_changed(e);
}

void popup_panel::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_SHOWWINDOW: wm_show(message); break;
    default: panel::wnd_proc(message); break;
  }
}

void popup_panel::wm_show(message& message) {
  panel::wnd_proc(message);
  
  auto visible = message.lparam() != 0;
  if (get_state(state::visible) == visible) return;
  set_state(state::visible, visible);
  on_visible_changed(event_args::empty);
}
