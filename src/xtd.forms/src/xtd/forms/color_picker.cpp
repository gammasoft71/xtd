#include "../../../include/xtd/forms/color_picker.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/color_picker>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/static_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/choose_color_flags>

using namespace xtd;
using namespace xtd::forms;

struct color_picker::data {
  drawing::color color = drawing::color::white;
  bool alpha_color = true;
};

color_picker::color_picker() : data_(std::make_shared<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  set_can_focus(false);
}

bool color_picker::alpha_color() const noexcept {
  return data_->alpha_color;
}

color_picker& color_picker::alpha_color(bool alpha_color) {
  if (data_->alpha_color == alpha_color) return *this;
  data_->alpha_color = alpha_color;
  post_recreate_handle();
  return *this;
}

const drawing::color& color_picker::color() const noexcept {
  return data_->color;
}

color_picker& color_picker::color(const drawing::color& value) {
  if (data_->color == value) return *this;
  data_->color = value;
  if (is_handle_created()) native::color_picker::color(handle(), data_->color);
  on_color_picker_changed(color_picker_event_args(data_->color));
  return *this;
}

color_picker color_picker::create() {
  return color_picker {};
}

color_picker color_picker::create(const drawing::point& location) {
  auto result = color_picker {};
  result.location(location);
  return result;
}

color_picker color_picker::create(const drawing::point& location, const drawing::size& size) {
  auto result = color_picker {};
  result.location(location);
  result.size(size);
  return result;
}

color_picker color_picker::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = color_picker {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

color_picker color_picker::create(const xtd::drawing::color& color) {
  auto result = color_picker {};
  result.color(color);
  return result;
}

color_picker color_picker::create(const xtd::drawing::color& color, const drawing::point& location) {
  auto result = color_picker {};
  result.color(color);
  result.location(location);
  return result;
}

color_picker color_picker::create(const xtd::drawing::color& color, const drawing::point& location, const drawing::size& size) {
  auto result = color_picker {};
  result.color(color);
  result.location(location);
  result.size(size);
  return result;
}

color_picker color_picker::create(const xtd::drawing::color& color, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = color_picker {};
  result.color(color);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

color_picker color_picker::create(const control& parent) {
  auto result = color_picker {};
  result.parent(parent);
  return result;
}

color_picker color_picker::create(const control& parent, const drawing::point& location) {
  auto result = color_picker {};
  result.parent(parent);
  result.location(location);
  return result;
}

color_picker color_picker::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = color_picker {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

color_picker color_picker::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = color_picker {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

color_picker color_picker::create(const control& parent, const xtd::drawing::color& color) {
  auto result = color_picker {};
  result.parent(parent);
  result.color(color);
  return result;
}

color_picker color_picker::create(const control& parent, const xtd::drawing::color& color, const drawing::point& location) {
  auto result = color_picker {};
  result.parent(parent);
  result.color(color);
  result.location(location);
  return result;
}

color_picker color_picker::create(const control& parent, const xtd::drawing::color& color, const drawing::point& location, const drawing::size& size) {
  auto result = color_picker {};
  result.parent(parent);
  result.color(color);
  result.location(location);
  result.size(size);
  return result;
}

color_picker color_picker::create(const control& parent, const xtd::drawing::color& color, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = color_picker {};
  result.parent(parent);
  result.color(color);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

forms::create_params color_picker::create_params() const noexcept {
  auto create_params = control::create_params();
  create_params.class_name("colorpicker");
  if (data_->alpha_color) create_params.style(create_params.style() | CC_ALPHACOLOR);
  return create_params;
}

void color_picker::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  native::color_picker::color(handle(), data_->color);
}

void color_picker::on_color_picker_changed(const color_picker_event_args& e) {
  if (can_raise_events()) color_picker_changed(*this, e);
}

void color_picker::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
    default: control::wnd_proc(message);
  }
}

void color_picker::wm_command_control(message& message) {
  control::wnd_proc(message);
  switch (HIWORD(message.wparam())) {
    case CPN_SELCHANGE: wm_command_control_selchange(message); break;
    default: break;
  }
}

void color_picker::wm_command_control_selchange(message& message) {
  data_->color = native::color_picker::color(handle());
  on_color_picker_changed(color_picker_event_args(data_->color));
}
