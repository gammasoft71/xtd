#include "../../../include/xtd/forms/application"
#include "../../../include/xtd/forms/user_control"
#include "../../../include/xtd/forms/user_control_renderer"
#include <xtd/drawing/pens>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/user_control>
#include <xtd/forms/native/toolkit>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms;

struct user_control::data {
  forms::border_sides border_sides = forms::border_sides::all;
  std::optional<forms::border_style> border_style;
};

user_control::user_control() : data_(std::make_shared<data>()) {
  set_auto_size_mode(forms::auto_size_mode::grow_only);
  set_style(control_styles::supports_transparent_back_color, true);
}

forms::auto_size_mode user_control::auto_size_mode() const noexcept {
  return get_auto_size_mode();
}

user_control& user_control::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

forms::border_sides user_control::border_sides() const noexcept {
  return data_->border_sides;
}

user_control& user_control::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides == border_sides) return *this;
  data_->border_sides = border_sides;
  if (control_appearance() == forms::control_appearance::standard) invalidate();
  return *this;
}

xtd::forms::border_style user_control::border_style() const noexcept {
  return data_->border_style.value_or(xtd::forms::border_style::none);
}

user_control& user_control::border_style(forms::border_style border_style) {
  if (data_->border_style == border_style) return *this;
  data_->border_style = border_style;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

user_control& user_control::border_style(std::nullptr_t) {
  if (!data_->border_style.has_value()) return *this;
  data_->border_style.reset();
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

forms::create_params user_control::create_params() const noexcept {
  auto create_params = scrollable_control::create_params();
  
  create_params.class_name("usercontrol");
  create_params.style(create_params.style() | WS_CLIPSIBLINGS);
  
  if (control_appearance() == forms::control_appearance::system) {
    if (data_->border_style == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
    else if (data_->border_style != forms::border_style::none) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
  }
  
  return create_params;
}

void user_control::on_layout(const event_args& e) {
  if (!application::message_loop()) return;
  scrollable_control::on_layout(e);
  if (is_handle_created() && auto_scroll()) native::user_control::virtual_size(handle(), display_rectangle().size());
}

void user_control::on_paint(paint_event_args& e) {
  container_control::on_paint(e);
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (control_appearance() == forms::control_appearance::standard) user_control_renderer::draw_user_control(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, data_->border_style, data_->border_sides);
}
