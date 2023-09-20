#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/panel.h>
#include <xtd/forms/native/toolkit.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/pens.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/panel.h"
#include "../../../include/xtd/forms/panel_renderer.h"

using namespace xtd;
using namespace xtd::forms;

struct panel::data {
  forms::border_sides border_sides = forms::border_sides::all;
  std::optional<forms::border_style> border_style;
};

panel::panel() : data_(std::make_shared<data>()) {
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
  if (data_->border_style == border_style) return *this;
  data_->border_style = border_style;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

panel& panel::border_style(std::nullptr_t) {
  if (data_->border_style) return *this;
  data_->border_style.reset();
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

panel panel::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = panel {};
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

panel panel::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = panel {};
  result.parent(parent);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

forms::create_params panel::create_params() const noexcept {
  auto create_params = scrollable_control::create_params();
  
  create_params.class_name("panel");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  if (control_appearance() == forms::control_appearance::system) {
    if (data_->border_style == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (data_->border_style != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  }
  
  return create_params;
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
