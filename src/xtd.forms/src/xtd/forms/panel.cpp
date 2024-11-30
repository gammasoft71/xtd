#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/control_paint.hpp"
#include "../../../include/xtd/forms/panel.hpp"
#include "../../../include/xtd/forms/panel_renderer.hpp"
#include <xtd/drawing/pens>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/panel>
#include <xtd/forms/native/toolkit>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

struct panel::data {
  forms::border_sides border_sides = forms::border_sides::all;
  std::optional<forms::border_style> border_style;
};

panel::panel() : data_(xtd::new_sptr<data>()) {
  set_auto_size_mode(forms::auto_size_mode::grow_only);
  set_can_focus(false);
  set_style(control_styles::selectable | control_styles::all_painting_in_wm_paint, false);
  set_style(control_styles::supports_transparent_back_color, true);
}

forms::auto_size_mode panel::auto_size_mode() const noexcept {
  return get_auto_size_mode();
}

panel& panel::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

forms::border_sides panel::border_sides() const noexcept {
  return data_->border_sides;
}

panel& panel::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides == border_sides) return *this;
  data_->border_sides = border_sides;
  if (control_appearance() == forms::control_appearance::standard) invalidate();
  return *this;
}

forms::border_style panel::border_style() const noexcept {
  return data_->border_style.value_or(forms::border_style::none);
}

panel& panel::border_style(forms::border_style border_style) {
  if (this->border_style() == border_style) return *this;
  data_->border_style = border_style;
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

panel& panel::border_style(std::nullptr_t) {
  if (data_->border_style) return *this;
  data_->border_style.reset();
  if (is_handle_created() && control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

panel panel::create() {
  return panel {};
}

panel panel::create(const drawing::point& location) {
  auto result = panel {};
  result.location(location);
  return result;
}

panel panel::create(const drawing::point& location, const drawing::size& size) {
  auto result = panel {};
  result.location(location);
  result.size(size);
  return result;
}

panel panel::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = panel {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

panel panel::create(const control& parent) {
  auto result = panel {};
  result.parent(parent);
  return result;
}

panel panel::create(const control& parent, const drawing::point& location) {
  auto result = panel {};
  result.parent(parent);
  result.location(location);
  return result;
}

panel panel::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

panel panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = panel {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

forms::create_params panel::create_params() const noexcept {
  auto create_params = scrollable_control::create_params();
  
  create_params.class_name("panel");
  
  if (control_appearance() == forms::control_appearance::system) {
    if (border_style() == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (border_style() != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  }
  
  return create_params;
}

xtd::uptr<xtd::object> panel::clone() const {
  auto result = xtd::new_uptr<panel>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()));
  return result;
}

drawing::size panel::measure_control() const noexcept {
  auto bounds = drawing::rectangle {};
  for (auto item : controls()) {
    if (item.get().visible())
      bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  }
  return drawing::size(bounds.location() + bounds.size());
}

void panel::on_layout(const event_args& e) {
  scrollable_control::on_layout(e);
  if (is_handle_created() && auto_scroll()) native::panel::virtual_size(handle(), display_rectangle().size());
}

void panel::on_paint(paint_event_args& e) {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (control_appearance() == forms::control_appearance::standard) panel_renderer::draw_panel(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, data_->border_style, data_->border_sides);
  scrollable_control::on_paint(e);
}
