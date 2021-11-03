#include <xtd/environment.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button_states.h>
#include <xtd/forms/native/button_styles.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/radio_button.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/radio_button.h"
#include "../../../include/xtd/forms/button_renderer.h"
#include "../../../include/xtd/forms/radio_button_renderer.h"
#include "../../../include/xtd/forms/visual_styles/push_button_state.h"

using namespace xtd;
using namespace xtd::forms;

namespace {
xtd::forms::visual_styles::push_button_state to_push_button_style(xtd::forms::visual_styles::radio_button_state state) {
  switch (state) {
    case xtd::forms::visual_styles::radio_button_state::unchecked_normal: return xtd::forms::visual_styles::push_button_state::normal;
    case xtd::forms::visual_styles::radio_button_state::unchecked_hot: return xtd::forms::visual_styles::push_button_state::hot;
    case xtd::forms::visual_styles::radio_button_state::unchecked_pressed: return xtd::forms::visual_styles::push_button_state::pressed;
    case xtd::forms::visual_styles::radio_button_state::unchecked_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
    case xtd::forms::visual_styles::radio_button_state::checked_normal: return xtd::forms::visual_styles::push_button_state::pressed;
    case xtd::forms::visual_styles::radio_button_state::checked_hot: return xtd::forms::visual_styles::push_button_state::pressed;
    case xtd::forms::visual_styles::radio_button_state::checked_pressed: return xtd::forms::visual_styles::push_button_state::pressed;
    case xtd::forms::visual_styles::radio_button_state::checked_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
    default: return xtd::forms::visual_styles::push_button_state::normal;
  }
}
}

radio_button::radio_button() {
  size_ = default_size();
  text_align_ = content_alignment::middle_left;
}

radio_button& radio_button::appearance(forms::appearance appearance) {
  if (appearance_ != appearance) {
    appearance_ = appearance;
    recreate_handle();
    on_appearance_changed(event_args::empty);
  }
  return *this;
}

radio_button& radio_button::auto_check(bool auto_check) {
  if (auto_check_ != auto_check) {
    auto_check_ = auto_check;
  }
  return *this;
}

radio_button& radio_button::checked(bool checked) {
  if (checked_ != checked) {
    checked_ = checked;
    native::radio_button::checked(handle(), checked_);
    on_checked_changed(event_args::empty);
    if (checked_ == true && auto_check_ == true && parent().has_value()) {
      for (auto control : parent().value().get().controls()) {
        if (dynamic_cast<radio_button*>(&control.get()) != nullptr && &control.get() != this && static_cast<radio_button&>(control.get()).auto_check_ == true)
          static_cast<radio_button&>(control.get()).checked(false);
      }
    }
  }
  return *this;
}

radio_button& radio_button::check_align(content_alignment check_align) {
  if (check_align_ != check_align) {
    check_align_ = check_align;
    recreate_handle();
  }
  return *this;
}

void radio_button::perform_click() {
  on_click(event_args::empty);
}

forms::create_params radio_button::create_params() const {
  forms::create_params create_params = button_base::create_params();
  
  create_params.class_name("radiobutton");
  if (auto_check_) create_params.style(create_params.style() | BS_AUTORADIOBUTTON);
  else create_params.style(create_params.style() | BS_RADIOBUTTON);
  if (appearance_ == forms::appearance::button) create_params.style(create_params.style() | BS_PUSHLIKE);

  switch (check_align_) {
    case content_alignment::top_right:
    case content_alignment::middle_right:
    case content_alignment::bottom_right: create_params.style(create_params.style() | BS_RIGHTBUTTON); break;
    default: break;
  }
  
  return create_params;
}

drawing::size radio_button::measure_control() const {
  return button_base::measure_text() + drawing::size(24, 0);
}

void radio_button::on_handle_created(const event_args &e) {
  button_base::on_handle_created(e);
  native::radio_button::checked(handle(), checked_);
}

void radio_button::on_paint(paint_event_args& e) {
  if (flat_style_ != xtd::forms::flat_style::system) {
    text_format_flags flags = to_text_format_flags(text_align_);
    if (appearance_ == xtd::forms::appearance::normal) {
      if (flat_style_ == xtd::forms::flat_style::flat) radio_button_renderer::draw_flat_radio_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), state_, !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
      else if (flat_style_ == xtd::forms::flat_style::popup) radio_button_renderer::draw_popup_radio_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), state_, !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
      else theme_renderers::current_theme().draw_radio_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds({18, 0, width(), height()}), focused(), state_, !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
    } else if (appearance_ == xtd::forms::appearance::button) {
      if (flat_style_ == xtd::forms::flat_style::flat) button_renderer::draw_flat_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), to_push_button_style(state_), !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_, flat_appearance_);
      else if (flat_style_ == xtd::forms::flat_style::popup) button_renderer::draw_popup_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), to_push_button_style(state_), !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_, flat_appearance_);
      else theme_renderers::current_theme().draw_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), to_push_button_style(state_), !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
    }
  }
  button_base::on_paint(e);
}

void radio_button::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    default: button_base::wnd_proc(message);
  }
}

void radio_button::wm_mouse_double_click(message& message) {
  on_double_click(event_args::empty);
}

void radio_button::wm_mouse_down(message &message) {
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, get_state(state::double_click_fired));
  mouse_buttons_ |= e.button();
  on_mouse_down(e);
}

void radio_button::wm_mouse_up(message& message) {
  if (auto_check_) checked(true);
  mouse_event_args e = mouse_event_args::create(message);
  mouse_buttons_ &= ~e.button();
  if (client_rectangle().contains(e.location())) on_click(event_args::empty);
  on_mouse_click(e);
  on_mouse_up(e);
}
