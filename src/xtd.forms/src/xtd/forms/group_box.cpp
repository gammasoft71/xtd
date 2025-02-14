#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/group_box.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button_styles>
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/group_box>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

struct group_box::data {
  xtd::forms::flat_style flat_style = xtd::forms::flat_style::system;
};

group_box::group_box() : data_(xtd::new_sptr<data>()) {
  /// @todo Delete the next line when the standard control is developed.
  control_appearance(forms::control_appearance::system);
  if (application::system_controls()) data_->flat_style = xtd::forms::flat_style::system;
  set_auto_size_mode(forms::auto_size_mode::grow_only);
  set_can_focus(false);
  set_state(state::tab_stop, false);
  set_style(control_styles::container_control, true);
  set_style(control_styles::supports_transparent_back_color | control_styles::user_paint | control_styles::resize_redraw, control_appearance() == forms::control_appearance::standard);
  set_style(control_styles::selectable, false);
}

forms::auto_size_mode group_box::auto_size_mode() const noexcept {
  return get_auto_size_mode();
}

group_box& group_box::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

control& group_box::control_appearance(forms::control_appearance value) {
  control::control_appearance(value);
  if (value == forms::control_appearance::system && data_->flat_style != xtd::forms::flat_style::system)
    flat_style(xtd::forms::flat_style::system);
  else if (value == forms::control_appearance::standard && data_->flat_style == xtd::forms::flat_style::system)
    flat_style(xtd::forms::flat_style::standard);
  return *this;
}

xtd::forms::flat_style group_box::flat_style() const noexcept {
  return data_->flat_style;
}

group_box& group_box::flat_style(xtd::forms::flat_style flat_style) {
  if (data_->flat_style == flat_style) return *this;
  data_->flat_style = flat_style;
  control_appearance(data_->flat_style == xtd::forms::flat_style::system ? forms::control_appearance::system : forms::control_appearance::standard);
  recreate_handle();
  return *this;
}

group_box group_box::create() {
  return group_box {};
}

group_box group_box::create(const drawing::point& location) {
  auto result = group_box {};
  result.location(location);
  return result;
}

group_box group_box::create(const drawing::point& location, const drawing::size& size) {
  auto result = group_box {};
  result.location(location);
  result.size(size);
  return result;
}

group_box group_box::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = group_box {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

group_box group_box::create(const xtd::string& text) {
  auto result = group_box {};
  result.text(text);
  return result;
}

group_box group_box::create(const xtd::string& text, const drawing::point& location) {
  auto result = group_box {};
  result.text(text);
  result.location(location);
  return result;
}

group_box group_box::create(const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = group_box {};
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

group_box group_box::create(const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = group_box {};
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

group_box group_box::create(const control& parent) {
  auto result = group_box {};
  result.parent(parent);
  return result;
}

group_box group_box::create(const control& parent, const drawing::point& location) {
  auto result = group_box {};
  result.parent(parent);
  result.location(location);
  return result;
}

group_box group_box::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = group_box {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

group_box group_box::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = group_box {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

group_box group_box::create(const control& parent, const xtd::string& text) {
  auto result = group_box {};
  result.parent(parent);
  result.text(text);
  return result;
}

group_box group_box::create(const control& parent, const xtd::string& text, const drawing::point& location) {
  auto result = group_box {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  return result;
}

group_box group_box::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = group_box {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

group_box group_box::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = group_box {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

forms::create_params group_box::create_params() const noexcept {
  auto create_params = control::create_params();
  
  create_params.class_name("groupbox");
  create_params.style(create_params.style() | BS_GROUPBOX);
  
  return create_params;
}

xtd::uptr<xtd::object> group_box::clone() const {
  auto result = xtd::new_uptr<group_box>(*this);
  if (typeof_(*result) != typeof_(*this)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}

drawing::size group_box::measure_control() const noexcept {
  drawing::rectangle bounds;
  for (auto item : controls()) {
    if (item.get().visible())
      bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  }
  return drawing::size(bounds.location() + bounds.size());
}

void group_box::on_font_changed(const xtd::event_args& e) {
  control::on_font_changed(e);
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
}

void group_box::on_text_changed(const xtd::event_args& e) {
  control::on_text_changed(e);
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
}

void group_box::on_resize(const xtd::event_args& e) {
  control::on_resize(e);
  if (data_->flat_style != xtd::forms::flat_style::system) invalidate();
}
