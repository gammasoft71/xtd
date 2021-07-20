#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button_styles.h>
#include <xtd/forms/native/check_box.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/check_box.h"
#include "../../../include/xtd/forms/button_renderer.h"
#include "../../../include/xtd/forms/check_box_renderer.h"
#include "../../../include/xtd/forms/visual_styles/push_button_state.h"

using namespace xtd;
using namespace xtd::forms;

namespace {
  xtd::forms::visual_styles::push_button_state to_push_button_style(xtd::forms::visual_styles::check_box_state state) {
    switch (state) {
      case xtd::forms::visual_styles::check_box_state::unchecked_normal: return xtd::forms::visual_styles::push_button_state::normal;
      case xtd::forms::visual_styles::check_box_state::unchecked_hot: return xtd::forms::visual_styles::push_button_state::hot;
      case xtd::forms::visual_styles::check_box_state::unchecked_pressed: return xtd::forms::visual_styles::push_button_state::normal;
      case xtd::forms::visual_styles::check_box_state::unchecked_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
      case xtd::forms::visual_styles::check_box_state::checked_normal: return xtd::forms::visual_styles::push_button_state::pressed;
      case xtd::forms::visual_styles::check_box_state::checked_hot: return xtd::forms::visual_styles::push_button_state::pressed;
      case xtd::forms::visual_styles::check_box_state::checked_pressed: return xtd::forms::visual_styles::push_button_state::pressed;
      case xtd::forms::visual_styles::check_box_state::checked_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
      case xtd::forms::visual_styles::check_box_state::mixed_normal: return xtd::forms::visual_styles::push_button_state::default_state;
      case xtd::forms::visual_styles::check_box_state::mixed_hot: return xtd::forms::visual_styles::push_button_state::default_state;
      case xtd::forms::visual_styles::check_box_state::mixed_pressed: return xtd::forms::visual_styles::push_button_state::default_state;
      case xtd::forms::visual_styles::check_box_state::mixed_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
      default: return xtd::forms::visual_styles::push_button_state::normal;
    }
  }
}

check_box::check_box() {
  size_ = default_size();
  text_align_ = content_alignment::middle_left;
}

check_box& check_box::appearance(forms::appearance appearance) {
  if (appearance_ != appearance) {
    appearance_ = appearance;
    recreate_handle();
    on_appearance_changed(event_args::empty);
  }
  return *this;
}

check_box& check_box::auto_check(bool auto_check) {
  if (auto_check_ != auto_check)
    auto_check_ = auto_check;
  return *this;
}

check_box& check_box::checked(bool checked) {
  check_state(checked ? forms::check_state::checked : forms::check_state::unchecked);
  return *this;
}

check_box& check_box::check_align(content_alignment check_align) {
  if (check_align_ != check_align) {
    check_align_ = check_align;
    recreate_handle();
  }
  return *this;
}

check_box& check_box::check_state(forms::check_state check_state) {
  if (check_state_ != check_state) {
    check_state_ = check_state;
    if (checked_ != (check_state_ != forms::check_state::unchecked)) {
      checked_ = check_state_ != forms::check_state::unchecked;
      on_checked_changed(event_args::empty);
    }
    native::check_box::check_state(handle(), static_cast<int32_t>(check_state_));
    on_check_state_changed(event_args::empty);
  }
  return *this;
}

check_box& check_box::three_state(bool three_state) {
  if (three_state_ != three_state) {
    three_state_ = three_state;
    recreate_handle();
  }
  return *this;
}

forms::create_params check_box::create_params() const {
  forms::create_params create_params = button_base::create_params();
  
  create_params.class_name("checkbox");
  if (three_state_) create_params.style(create_params.style() | (auto_check_ ? BS_AUTO3STATE : BS_3STATE));
  else if (auto_check_) create_params.style(create_params.style() | BS_AUTOCHECKBOX);
  else create_params.style(create_params.style() | BS_CHECKBOX);
  if (appearance_ == forms::appearance::button) create_params.style(create_params.style() | BS_PUSHLIKE);

  switch (check_align_) {
    case content_alignment::top_right:
    case content_alignment::middle_right:
    case content_alignment::bottom_right: create_params.style(create_params.style() | BS_RIGHTBUTTON); break;
    default: break;
  }
  
  return create_params;
}

drawing::size check_box::measure_control() const {
  return button_base::measure_text() + drawing::size(18, 0);
}

void check_box::on_handle_created(const event_args &e) {
  button_base::on_handle_created(e);
  native::check_box::check_state(handle(), static_cast<int32_t>(check_state_));
  if (flat_style_ != xtd::forms::flat_style::system && check_state_ != xtd::forms::check_state::unchecked) invalidate();
}

void check_box::on_paint(paint_event_args& e) {
  if (flat_style_ != xtd::forms::flat_style::system) {
    text_format_flags flags = to_text_format_flags(text_align_);
    if (appearance_ == xtd::forms::appearance::normal) {
      if (flat_style_ == xtd::forms::flat_style::flat) check_box_renderer::draw_flat_check_box(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds({18, 0, width(), height()}), focused(), state_, !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
      else if (flat_style_ == xtd::forms::flat_style::popup) check_box_renderer::draw_popup_check_box(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds({18, 0, width(), height()}), focused(), state_, !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
      else theme_renderers::current_theme().draw_check_box(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds({18, 0, width(), height()}), focused(), state_, !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
    } else if (appearance_ == xtd::forms::appearance::button) {
      if (flat_style_ == xtd::forms::flat_style::flat) button_renderer::draw_flat_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), to_push_button_style(state_), !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_, flat_appearance_);
      else if (flat_style_ == xtd::forms::flat_style::popup) button_renderer::draw_popup_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), to_push_button_style(state_), !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_, flat_appearance_);
      else theme_renderers::current_theme().draw_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), to_push_button_style(state_), !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
    }
  }
  button_base::on_paint(e);
}

void check_box::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    default: button_base::wnd_proc(message);
  }
}

void check_box::wm_mouse_double_click(message &message) {
  on_double_click(event_args::empty);
}

void check_box::wm_mouse_down(message &message) {
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, get_state(state::double_click_fired));
  mouse_buttons_ |= e.button();
  on_mouse_down(e);
}

void check_box::wm_mouse_up(message &message) {
  if (auto_check_)
    switch (check_state()) {
      case forms::check_state::unchecked: check_state(forms::check_state::checked); break;
      case forms::check_state::checked: check_state(three_state() ? forms::check_state::indeterminate : forms::check_state::unchecked); break;
      case forms::check_state::indeterminate: check_state(forms::check_state::unchecked); break;
    }
  mouse_event_args e = mouse_event_args::create(message);
  mouse_buttons_ &= ~e.button();
  if (client_rectangle().contains(e.location())) on_click(event_args::empty);
  on_mouse_click(e);
  on_mouse_up(e);
}
