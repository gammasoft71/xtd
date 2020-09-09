#include "../../../include/xtd/forms/button.h"
#include "../../../include/xtd/forms/button_renderer.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/theme_colors.h"
#include "../../../include/xtd/forms/theme_renderers.h"
#include <xtd/drawing/pen.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/string_format.h>
#include <xtd/drawing/system_brushes.h>
#include <xtd/drawing/system_pens.h>
#include <xtd/forms/native/button.h>
#include <xtd/forms/native/button_styles.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/window_messages.h>

using namespace xtd;
using namespace xtd::forms;

button& button::auto_size_mode(forms::auto_size_mode value) {
  this->set_auto_size_mode(value);
  return *this;
}

control& button::dialog_result(forms::dialog_result dialog_result) {
  if (this->dialog_result_ != dialog_result)
    this->dialog_result_ = dialog_result;
  return *this;
}

void button::notify_default(bool value) {
  default_button_ = value;
  if (enabled()) state_ = default_button_ ? xtd::forms::visual_styles::push_button_state::default_state : xtd::forms::visual_styles::push_button_state::normal;
  if (flat_style_ != xtd::forms::flat_style::system) invalidate();
  else {
    if (value) native::button::set_default_button(handle_);
    else recreate_handle();
  }
}

void button::perform_click() {
  this->on_click(event_args::empty);
}

forms::create_params button::create_params() const {
  forms::create_params create_params = this->button_base::create_params();
  
  create_params.class_name("button");
  
  create_params.style(create_params.style() | BS_PUSHBUTTON);
  
  return create_params;
}

void button::on_click(const event_args& e) {
  if (enabled()) button_base::on_click(e);
  if (this->dialog_result_ != forms::dialog_result::none &&  this->top_level_control().has_value() && static_cast<form&>(this->top_level_control().value().get()).modal()) {
    static_cast<form&>(this->top_level_control().value().get()).dialog_result(this->dialog_result());
    static_cast<form&>(this->top_level_control().value().get()).close();
  }
}

void button::on_image_changed(const xtd::event_args& e) {
  if (flat_style_ == xtd::forms::flat_style::system) native::button::image(handle_, image_);
  button_base::on_image_changed(e);
}

void button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  if (flat_style_ == xtd::forms::flat_style::system) {
    if (image_ != drawing::image::empty || (image_list_.images().size() && image_index_ > -1)) {
      native::button::image(handle(), image_ != drawing::image::empty ? image_ : image_list_.images()[image_index_]);
      native::button::image_align(handle(), static_cast<uint32_t>(image_align_));
      if (image_align_ != content_alignment::middle_center) native::control::text(handle(), text_);
      native::control::location(handle(), location_);
      native::control::size(handle(), size_);
    }
    if (default_button_) native::button::set_default_button(handle_);
  }
}

void button::on_paint(paint_event_args& e) {
  if (flat_style_ == xtd::forms::flat_style::system)
    control::on_paint(e);
  else {
    text_format_flags flags = to_text_format_flags(text_align_);
    if (flat_style_ == xtd::forms::flat_style::flat) button_renderer::draw_flat_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), state_, !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
    else if (flat_style_ == xtd::forms::flat_style::popup) button_renderer::draw_popup_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), state_, !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
    else theme_renderers::current_theme().draw_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), xtd::environment::os_version().is_macos_platform() && default_button_ && state_ == xtd::forms::visual_styles::push_button_state::hot ? xtd::forms::visual_styles::push_button_state::default_state  : state_, !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
  }
}

/*
void button::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_REFLECT + WM_COMMAND: wm_click(message); break;
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_XBUTTONUP: this->wm_mouse_up(message); break;
    default: this->control::wnd_proc(message);
  }
}

void button::wm_click(message& message) {
  this->def_wnd_proc(message);
  this->on_click(event_args::empty);
}

void button::wm_mouse_up(message& message) {
  this->def_wnd_proc(message);
  mouse_event_args e = mouse_event_args::create(message);
  this->on_mouse_click(e);
  this->on_mouse_up(e);
}
 */

drawing::size button::measure_control() const {
  drawing::size size = button_base::measure_control();
  if (size.height() < default_size().height()) size.height(default_size().height());
  return size;
}
