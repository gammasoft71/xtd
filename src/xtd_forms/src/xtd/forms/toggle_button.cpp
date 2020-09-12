#include <xtd/forms/native/button_styles.h>
#include <xtd/forms/native/toggle_button.h>
#include <xtd/forms/window_messages.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/toggle_button.h"
#include "../../../include/xtd/forms/button_renderer.h"
#include "../../../include/xtd/forms/visual_styles/push_button_state.h"

using namespace xtd;
using namespace xtd::forms;

namespace {
  xtd::forms::visual_styles::push_button_state to_push_button_style(xtd::forms::visual_styles::toggle_button_state state) {
    switch (state) {
      case xtd::forms::visual_styles::toggle_button_state::unchecked_normal: return xtd::forms::visual_styles::push_button_state::normal;
      case xtd::forms::visual_styles::toggle_button_state::unchecked_hot: return xtd::forms::visual_styles::push_button_state::hot;
      case xtd::forms::visual_styles::toggle_button_state::unchecked_pressed: return xtd::forms::visual_styles::push_button_state::normal;
      case xtd::forms::visual_styles::toggle_button_state::unchecked_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
      case xtd::forms::visual_styles::toggle_button_state::checked_normal: return xtd::forms::visual_styles::push_button_state::pressed;
      case xtd::forms::visual_styles::toggle_button_state::checked_hot: return xtd::forms::visual_styles::push_button_state::pressed;
      case xtd::forms::visual_styles::toggle_button_state::checked_pressed: return xtd::forms::visual_styles::push_button_state::pressed;
      case xtd::forms::visual_styles::toggle_button_state::checked_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
      case xtd::forms::visual_styles::toggle_button_state::mixed_normal: return xtd::forms::visual_styles::push_button_state::default_state;
      case xtd::forms::visual_styles::toggle_button_state::mixed_hot: return xtd::forms::visual_styles::push_button_state::default_state;
      case xtd::forms::visual_styles::toggle_button_state::mixed_pressed: return xtd::forms::visual_styles::push_button_state::default_state;
      case xtd::forms::visual_styles::toggle_button_state::mixed_disabled: return xtd::forms::visual_styles::push_button_state::disabled;
      default: return xtd::forms::visual_styles::push_button_state::normal;
    }
  }
}

toggle_button::toggle_button() {
  size_ = default_size();
}

toggle_button& toggle_button::auto_check(bool auto_check) {
  if (auto_check_ != auto_check)
    auto_check_ = auto_check;
  return *this;
}

toggle_button& toggle_button::checked(bool checked) {
  check_state(checked ? forms::check_state::checked : forms::check_state::unchecked);
  return *this;
}

toggle_button& toggle_button::check_align(content_alignment check_align) {
  if (check_align_ != check_align) {
    check_align_ = check_align;
    recreate_handle();
  }
  return *this;
}

toggle_button& toggle_button::check_state(forms::check_state check_state) {
  if (check_state_ != check_state) {
    check_state_ = check_state;
    if (checked_ != (check_state_ != forms::check_state::unchecked)) {
      checked_ = check_state_ != forms::check_state::unchecked;
      on_checked_changed(event_args::empty);
    }
    native::toggle_button::check_state(handle(), static_cast<int32_t>(check_state_));
    on_check_state_changed(event_args::empty);
  }
  return *this;
}

toggle_button& toggle_button::three_state(bool three_state) {
  if (three_state_ != three_state) {
    three_state_ = three_state;
    recreate_handle();
  }
  return *this;
}

forms::create_params toggle_button::create_params() const {
  forms::create_params create_params = button_base::create_params();
  
  create_params.class_name("togglebutton");
  if (three_state_) create_params.style(create_params.style() | (auto_check_ ? BS_AUTO3STATE : BS_3STATE));
  else if (auto_check_) create_params.style(create_params.style() | BS_AUTOCHECKBOX);
  else create_params.style(create_params.style() | BS_CHECKBOX);
  create_params.style(create_params.style() | BS_PUSHLIKE);

  switch (check_align_) {
    case content_alignment::top_right:
    case content_alignment::middle_right:
    case content_alignment::bottom_right: create_params.style(create_params.style() | BS_RIGHTBUTTON); break;
    default: break;
  }
  
  return create_params;
}

drawing::size toggle_button::measure_control() const {
  return button_base::measure_text() + drawing::size(18, 0);
}

void toggle_button::on_handle_created(const event_args &e) {
  button_base::on_handle_created(e);
  native::toggle_button::check_state(handle(), static_cast<int32_t>(check_state_));
  if (flat_style_ != xtd::forms::flat_style::system && check_state_ != xtd::forms::check_state::unchecked) invalidate();
}

void toggle_button::on_paint(paint_event_args& e) {
  if (flat_style_ == xtd::forms::flat_style::system)
    control::on_paint(e);
  else {
    text_format_flags flags = to_text_format_flags(text_align_);
    if (flat_style_ == xtd::forms::flat_style::flat) button_renderer::draw_flat_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), to_push_button_style(state_), !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
    else if (flat_style_ == xtd::forms::flat_style::popup) button_renderer::draw_popup_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), to_push_button_style(state_), !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
    else theme_renderers::current_theme().draw_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image_, compute_image_bounds(), focused(), to_push_button_style(state_), !back_color_.has_value() && back_color() != xtd::forms::theme_colors::current_theme().control() ? back_color() : back_color_, !fore_color_.has_value() && fore_color() != xtd::forms::theme_colors::current_theme().control_text() ? fore_color() : fore_color_);
  }
}

void toggle_button::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    default: button_base::wnd_proc(message);
  }
}

void toggle_button::wm_mouse_double_click(message &message) {
  on_double_click(event_args::empty);
}

void toggle_button::wm_mouse_down(message &message) {
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, get_state(state::double_click_fired));
  mouse_buttons_ |= e.button();
  on_mouse_down(e);
  if (message.msg() == WM_LBUTTONDOWN) mouse_left_down_ = true;
}

void toggle_button::wm_mouse_up(message &message) {
  if (auto_check_)
    switch (check_state()) {
      case forms::check_state::unchecked: check_state(forms::check_state::checked); break;
      case forms::check_state::checked: check_state(three_state() ? forms::check_state::indeterminate : forms::check_state::unchecked); break;
      case forms::check_state::indeterminate: check_state(forms::check_state::unchecked); break;
    }
  mouse_event_args e = mouse_event_args::create(message);
  mouse_buttons_ &= ~e.button();
  if (mouse_left_down_ && client_rectangle().contains(e.location())) on_click(event_args::empty);
  if (message.msg() == WM_LBUTTONDOWN) mouse_left_down_ = false;
  on_mouse_click(e);
  on_mouse_up(e);
}
