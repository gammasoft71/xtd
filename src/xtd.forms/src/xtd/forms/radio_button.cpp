#include "../../../include/xtd/forms/radio_button.h"
#include "../../../include/xtd/forms/button_renderer.h"
#include "../../../include/xtd/forms/radio_button_renderer.h"
#include "../../../include/xtd/forms/visual_styles/push_button_state.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button_states>
#include <xtd/forms/native/button_styles>
#include <xtd/forms/native/control>
#include <xtd/forms/native/radio_button>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/environment>

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

struct radio_button::data {
  forms::appearance appearance = forms::appearance::normal;
  bool auto_check = true;
  bool checked = false;
  content_alignment check_align = content_alignment::middle_left;
  xtd::forms::visual_styles::radio_button_state state = xtd::forms::visual_styles::radio_button_state::unchecked_normal;
};

radio_button::radio_button() : data_(std::make_shared<data>()) {
  set_style(control_styles::standard_click | control_styles::standard_double_click, false);
  text_align(content_alignment::middle_left);
}

forms::appearance radio_button::appearance() const noexcept {
  return data_->appearance;
}

radio_button& radio_button::appearance(forms::appearance appearance) {
  if (data_->appearance == appearance) return *this;
  data_->appearance = appearance;
  post_recreate_handle();
  on_appearance_changed(event_args::empty);
  return *this;
}

bool radio_button::auto_check() const noexcept {
  return data_->auto_check;
}

radio_button& radio_button::auto_check(bool auto_check) {
  data_->auto_check = auto_check;
  return *this;
}

bool radio_button::checked() const noexcept {
  return data_->checked;
}

radio_button& radio_button::checked(bool checked) {
  if (data_->checked == checked) return *this;
  data_->checked = checked;
  if (is_handle_created() && flat_style() == flat_style::system) native::radio_button::checked(handle(), data_->checked);
  if (flat_style() != flat_style::system) invalidate();
  on_checked_changed(event_args::empty);
  if (data_->checked == true && data_->auto_check == true && parent().has_value()) {
    for (auto control : parent().value().get().controls()) {
      if (dynamic_cast<radio_button*>(&control.get()) != nullptr && &control.get() != this && static_cast<radio_button&>(control.get()).data_->auto_check == true)
        static_cast<radio_button&>(control.get()).checked(false);
    }
  }
  return *this;
}

content_alignment radio_button::check_align() const noexcept {
  return data_->check_align;
}

radio_button& radio_button::check_align(content_alignment check_align) {
  if (data_->check_align == check_align) return *this;
  data_->check_align = check_align;
  post_recreate_handle();
  return *this;
}

radio_button radio_button::create() {
  return radio_button {};
}

radio_button radio_button::create(const drawing::point& location) {
  auto result = radio_button {};
  result.location(location);
  return result;
}

radio_button radio_button::create(const drawing::point& location, const drawing::size& size) {
  auto result = radio_button {};
  result.location(location);
  result.size(size);
  return result;
}

radio_button radio_button::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = radio_button {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

radio_button radio_button::create(const xtd::ustring& text) {
  auto result = radio_button {};
  result.text(text);
  return result;
}

radio_button radio_button::create(const xtd::ustring& text, const drawing::point& location) {
  auto result = radio_button {};
  result.text(text);
  result.location(location);
  return result;
}

radio_button radio_button::create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size) {
  auto result = radio_button {};
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

radio_button radio_button::create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = radio_button {};
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

radio_button radio_button::create(const xtd::ustring& text, bool checked) {
  auto result = radio_button {};
  result.text(text);
  result.checked(checked);
  return result;
}

radio_button radio_button::create(const xtd::ustring& text, bool checked, const drawing::point& location) {
  auto result = radio_button {};
  result.text(text);
  result.checked(checked);
  result.location(location);
  return result;
}

radio_button radio_button::create(const xtd::ustring& text, bool checked, const drawing::point& location, const drawing::size& size) {
  auto result = radio_button {};
  result.text(text);
  result.checked(checked);
  result.location(location);
  result.size(size);
  return result;
}

radio_button radio_button::create(const xtd::ustring& text, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = radio_button {};
  result.text(text);
  result.checked(checked);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

radio_button radio_button::create(const control& parent) {
  auto result = radio_button {};
  result.parent(parent);
  return result;
}

radio_button radio_button::create(const control& parent, const drawing::point& location) {
  auto result = radio_button {};
  result.parent(parent);
  result.location(location);
  return result;
}

radio_button radio_button::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = radio_button {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

radio_button radio_button::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = radio_button {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

radio_button radio_button::create(const control& parent, const xtd::ustring& text) {
  auto result = radio_button {};
  result.parent(parent);
  result.text(text);
  return result;
}

radio_button radio_button::create(const control& parent, const xtd::ustring& text, const drawing::point& location) {
  auto result = radio_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  return result;
}

radio_button radio_button::create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size) {
  auto result = radio_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

radio_button radio_button::create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = radio_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

radio_button radio_button::create(const control& parent, const xtd::ustring& text, bool checked) {
  auto result = radio_button {};
  result.parent(parent);
  result.text(text);
  result.checked(checked);
  return result;
}

radio_button radio_button::create(const control& parent, const xtd::ustring& text, bool checked, const drawing::point& location) {
  auto result = radio_button {};
  result.parent(parent);
  result.text(text);
  result.checked(checked);
  result.location(location);
  return result;
}

radio_button radio_button::create(const control& parent, const xtd::ustring& text, bool checked, const drawing::point& location, const drawing::size& size) {
  auto result = radio_button {};
  result.parent(parent);
  result.text(text);
  result.checked(checked);
  result.location(location);
  result.size(size);
  return result;
}

radio_button radio_button::create(const control& parent, const xtd::ustring& text, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = radio_button {};
  result.parent(parent);
  result.text(text);
  result.checked(checked);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void radio_button::perform_click() {
  on_click(event_args::empty);
}

xtd::ustring radio_button::to_string() const noexcept {
  return ustring::format("{}, checked: {}", get_type().full_name(), data_->checked);
}

forms::create_params radio_button::create_params() const noexcept {
  auto create_params = button_base::create_params();
  
  create_params.class_name("radiobutton");
  if (data_->auto_check) create_params.style(create_params.style() | BS_AUTORADIOBUTTON);
  else create_params.style(create_params.style() | BS_RADIOBUTTON);
  if (data_->appearance == forms::appearance::button) create_params.style(create_params.style() | BS_PUSHLIKE);
  
  switch (data_->check_align) {
    case content_alignment::top_right:
    case content_alignment::middle_right:
    case content_alignment::bottom_right: create_params.style(create_params.style() | BS_RIGHTBUTTON); break;
    default: break;
  }
  
  return create_params;
}

xtd::forms::visual_styles::radio_button_state radio_button::state() const noexcept {
  return data_->state;
}

drawing::size radio_button::measure_control() const noexcept {
  return button_base::measure_text() + drawing::size(24, 0);
}

void radio_button::on_appearance_changed(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system) invalidate();
  appearance_changed(*this, e);
}

void radio_button::on_checked_changed(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system)  {
    if (!data_->checked) data_->state = xtd::forms::visual_styles::radio_button_state::unchecked_normal;
    else data_->state = xtd::forms::visual_styles::radio_button_state::checked_normal;
    invalidate();
  }
  checked_changed(*this, e);
}

void radio_button::on_enabled_changed(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system) {
    if (!data_->checked) data_->state = enabled() ? xtd::forms::visual_styles::radio_button_state::unchecked_normal : xtd::forms::visual_styles::radio_button_state::unchecked_disabled;
    else data_->state = enabled() ? xtd::forms::visual_styles::radio_button_state::checked_normal : xtd::forms::visual_styles::radio_button_state::checked_disabled;
  }
  button_base::on_enabled_changed(e);
}

void radio_button::on_got_focus(const event_args& e) {
  button_base::on_got_focus(e);
  if (flat_style() != xtd::forms::flat_style::system) {
    if (!data_->checked) data_->state = enabled() ? xtd::forms::visual_styles::radio_button_state::unchecked_normal : xtd::forms::visual_styles::radio_button_state::unchecked_disabled;
    else data_->state = enabled() ? xtd::forms::visual_styles::radio_button_state::checked_normal : xtd::forms::visual_styles::radio_button_state::checked_disabled;
  }
}

void radio_button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  if (flat_style() == flat_style::system) native::radio_button::checked(handle(), data_->checked);
}

void radio_button::on_lost_focus(const event_args& e) {
  button_base::on_lost_focus(e);
  if (flat_style() != xtd::forms::flat_style::system) {
    if (!data_->checked) data_->state = enabled() ? xtd::forms::visual_styles::radio_button_state::unchecked_normal : xtd::forms::visual_styles::radio_button_state::unchecked_disabled;
    else data_->state = enabled() ? xtd::forms::visual_styles::radio_button_state::checked_normal : xtd::forms::visual_styles::radio_button_state::checked_disabled;
  }
}

void radio_button::on_mouse_down(const mouse_event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system) {
    if (!data_->checked) data_->state = xtd::forms::visual_styles::radio_button_state::unchecked_pressed;
    else data_->state = xtd::forms::visual_styles::radio_button_state::checked_pressed;
  }
  button_base::on_mouse_down(e);
}

void radio_button::on_mouse_enter(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system) {
    if (!data_->checked) data_->state = xtd::forms::visual_styles::radio_button_state::unchecked_hot;
    else data_->state = xtd::forms::visual_styles::radio_button_state::checked_hot;
  }
  button_base::on_mouse_enter(e);
}

void radio_button::on_mouse_leave(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system) {
    if (!data_->checked) data_->state = xtd::forms::visual_styles::radio_button_state::unchecked_normal;
    else data_->state = xtd::forms::visual_styles::radio_button_state::checked_normal;
  }
  button_base::on_mouse_leave(e);
}

void radio_button::on_mouse_move(const mouse_event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system && (e.button() & mouse_buttons::left) == mouse_buttons::left && !client_rectangle().contains(e.location()) && (data_->state == xtd::forms::visual_styles::radio_button_state::unchecked_pressed || data_->state == xtd::forms::visual_styles::radio_button_state::checked_pressed)) {
    if (!data_->checked) data_->state = xtd::forms::visual_styles::radio_button_state::unchecked_hot;
    else data_->state = xtd::forms::visual_styles::radio_button_state::checked_hot;
  }
  button_base::on_mouse_move(e);
}

void radio_button::on_mouse_up(const mouse_event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system && (data_->state == xtd::forms::visual_styles::radio_button_state::unchecked_pressed || data_->state == xtd::forms::visual_styles::radio_button_state::checked_pressed)) {
    if (!data_->checked) data_->state = xtd::forms::visual_styles::radio_button_state::unchecked_hot;
    else data_->state = xtd::forms::visual_styles::radio_button_state::checked_hot;
  }
  button_base::on_mouse_up(e);
}

void radio_button::on_paint(paint_event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system) {
    text_format_flags flags = to_text_format_flags(text_align());
    if (data_->appearance == xtd::forms::appearance::normal) {
      if (flat_style() == xtd::forms::flat_style::flat) radio_button_renderer::draw_flat_radio_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), data_->state, !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color());
      else if (flat_style() == xtd::forms::flat_style::popup) radio_button_renderer::draw_popup_radio_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), data_->state, !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color());
      else radio_button_renderer::draw_radio_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds({18, 0, width(), height()}), focused(), data_->state, !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color());
    } else if (data_->appearance == xtd::forms::appearance::button) {
      if (flat_style() == xtd::forms::flat_style::flat) button_renderer::draw_flat_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), to_push_button_style(data_->state), !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color(), flat_appearance());
      else if (flat_style() == xtd::forms::flat_style::popup) button_renderer::draw_popup_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), to_push_button_style(data_->state), !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color(), flat_appearance());
      else button_renderer::draw_button(e.graphics(), e.clip_rectangle(), text(), font(), flags, image(), compute_image_bounds(), focused(), to_push_button_style(data_->state), !get_back_color().has_value() && back_color() != application::style_sheet().system_colors().control() ? back_color() : get_back_color(), !get_fore_color().has_value() && fore_color() != application::style_sheet().system_colors().control_text() ? fore_color() : get_fore_color());
    }
  }
  button_base::on_paint(e);
}

void radio_button::wnd_proc(message& message) {
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

void radio_button::wm_mouse_down(const message& message) {
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  auto e = mouse_event_args::create(message, get_state(state::double_click_fired));
  set_mouse_buttons(mouse_buttons() | e.button());
  on_mouse_down(e);
}

void radio_button::wm_mouse_up(const message& message) {
  if (data_->auto_check) checked(true);
  auto e = mouse_event_args::create(message);
  set_mouse_buttons(mouse_buttons() & ~e.button());
  if (client_rectangle().contains(e.location())) on_click(event_args::empty);
  on_mouse_click(e);
  on_mouse_up(e);
}
