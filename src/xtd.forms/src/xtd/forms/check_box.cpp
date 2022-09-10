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
  set_style(control_styles::standard_click | control_styles::standard_double_click, false);
  text_align(content_alignment::middle_left);
}

check_box& check_box::appearance(forms::appearance appearance) {
  if (data_->appearance != appearance) {
    data_->appearance = appearance;
    post_recreate_handle();
    on_appearance_changed(event_args::empty);
  }
  return *this;
}

check_box& check_box::auto_check(bool auto_check) {
  data_->auto_check = auto_check;
  return *this;
}

check_box& check_box::checked(bool checked) {
  check_state(checked ? forms::check_state::checked : forms::check_state::unchecked);
  return *this;
}

check_box& check_box::check_align(content_alignment check_align) {
  if (data_->check_align != check_align) {
    data_->check_align = check_align;
    post_recreate_handle();
  }
  return *this;
}

check_box& check_box::check_state(forms::check_state check_state) {
  if (data_->check_state != check_state) {
    data_->check_state = check_state;
    if (data_->checked != (data_->check_state != forms::check_state::unchecked)) {
      data_->checked = data_->check_state != forms::check_state::unchecked;
      on_checked_changed(event_args::empty);
    }
    if (is_handle_created() && flat_style() == xtd::forms::flat_style::system) native::check_box::check_state(handle(), static_cast<int32_t>(data_->check_state));
    on_check_state_changed(event_args::empty);
  }
  return *this;
}

check_box& check_box::three_state(bool three_state) {
  if (data_->three_state != three_state) {
    data_->three_state = three_state;
    post_recreate_handle();
  }
  return *this;
}

forms::create_params check_box::create_params() const {
  forms::create_params create_params = button_base::create_params();
  
  create_params.class_name("checkbox");
  if (data_->three_state) create_params.style(create_params.style() | (data_->auto_check ? BS_AUTO3STATE : BS_3STATE));
  else if (data_->auto_check) create_params.style(create_params.style() | BS_AUTOCHECKBOX);
  else create_params.style(create_params.style() | BS_CHECKBOX);
  if (data_->appearance == forms::appearance::button) create_params.style(create_params.style() | BS_PUSHLIKE);
  
  switch (data_->check_align) {
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

void check_box::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  if (flat_style() == xtd::forms::flat_style::system) native::check_box::check_state(handle(), static_cast<int32_t>(data_->check_state));
  if (flat_style() != xtd::forms::flat_style::system && data_->check_state != xtd::forms::check_state::unchecked) invalidate();
}

void check_box::on_paint(paint_event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system) {
    text_format_flags flags = to_text_format_flags(text_align());
    if (data_->appearance == xtd::forms::appearance::normal) {
      if (flat_style() == xtd::forms::flat_style::flat) check_box_renderer::draw_flat_check_box(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds({18, 0, width(), height()}), focused(), data_->state, !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color());
      else if (flat_style() == xtd::forms::flat_style::popup) check_box_renderer::draw_popup_check_box(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds({18, 0, width(), height()}), focused(), data_->state, !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color());
      else check_box_renderer::draw_check_box(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds({18, 0, width(), height()}), focused(), data_->state, !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color());
    } else if (data_->appearance == xtd::forms::appearance::button) {
      if (flat_style() == xtd::forms::flat_style::flat) button_renderer::draw_flat_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), to_push_button_style(data_->state), !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color(), flat_appearance());
      else if (flat_style() == xtd::forms::flat_style::popup) button_renderer::draw_popup_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), to_push_button_style(data_->state), !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color(), flat_appearance());
      else button_renderer::draw_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), to_push_button_style(data_->state), !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color());
    }
  }
  button_base::on_paint(e);
}

void check_box::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    default: button_base::wnd_proc(message);
  }
}

void check_box::wm_mouse_double_click(message& message) {
  on_double_click(event_args::empty);
}

void check_box::wm_mouse_down(message& message) {
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, get_state(state::double_click_fired));
  set_mouse_buttons(mouse_buttons() | e.button());
  on_mouse_down(e);
}

void check_box::wm_mouse_up(message& message) {
  if (data_->auto_check)
    switch (check_state()) {
      case forms::check_state::unchecked: check_state(forms::check_state::checked); break;
      case forms::check_state::checked: check_state(three_state() ? forms::check_state::indeterminate : forms::check_state::unchecked); break;
      case forms::check_state::indeterminate: check_state(forms::check_state::unchecked); break;
    }
  mouse_event_args e = mouse_event_args::create(message);
  set_mouse_buttons(mouse_buttons() & ~e.button());
  if (client_rectangle().contains(e.location())) on_click(event_args::empty);
  on_mouse_click(e);
  on_mouse_up(e);
}
