#include "../../../include/xtd/forms/toggle_button.h"
#include "../../../include/xtd/forms/toggle_button_renderer.h"
#include "../../../include/xtd/forms/visual_styles/push_button_state.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button_states>
#include <xtd/forms/native/button_styles>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/toggle_button>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages>

using namespace xtd;
using namespace xtd::forms;

struct toggle_button::data {
  bool auto_check = true;
  bool three_state = 0;
  bool checked = false;
  content_alignment check_align = content_alignment::middle_left;
  forms::check_state check_state = forms::check_state::unchecked;
  xtd::forms::visual_styles::toggle_button_state state = xtd::forms::visual_styles::toggle_button_state::unchecked_normal;
};

toggle_button::toggle_button() : data_(std::make_shared<data>()) {
  set_style(control_styles::standard_click | control_styles::standard_double_click, false);
}

bool toggle_button::auto_check() const noexcept {
  return data_->auto_check;
}

toggle_button& toggle_button::auto_check(bool auto_check) {
  data_->auto_check = auto_check;
  return *this;
}

content_alignment toggle_button::check_align() const noexcept {
  return data_->check_align;
}

toggle_button& toggle_button::check_align(content_alignment check_align) {
  if (data_->check_align == check_align) return *this;
  data_->check_align = check_align;
  post_recreate_handle();
  return *this;
}

bool toggle_button::checked() const noexcept {
  return data_->checked;
}

toggle_button& toggle_button::checked(bool checked) {
  check_state(checked ? forms::check_state::checked : forms::check_state::unchecked);
  return *this;
}

forms::check_state toggle_button::check_state() const noexcept {
  return data_->check_state;
}

toggle_button& toggle_button::check_state(forms::check_state check_state) {
  if (data_->check_state == check_state) return *this;
  data_->check_state = check_state;
  if (data_->checked != (data_->check_state != forms::check_state::unchecked)) {
    data_->checked = data_->check_state != forms::check_state::unchecked;
    on_checked_changed(event_args::empty);
  }
  if (is_handle_created() && flat_style() == flat_style::system) native::toggle_button::check_state(handle(), static_cast<int32>(data_->check_state));
  on_check_state_changed(event_args::empty);
  return *this;
}

bool toggle_button::three_state() const noexcept {
  return data_->three_state;
}

toggle_button& toggle_button::three_state(bool three_state) {
  if (data_->three_state == three_state) return *this;
  data_->three_state = three_state;
  post_recreate_handle();
  return *this;
}

toggle_button toggle_button::create() {
  auto result = toggle_button {};
  return result;
}

toggle_button toggle_button::create(const drawing::point& location) {
  auto result = toggle_button {};
  result.location(location);
  return result;
}

toggle_button toggle_button::create(const drawing::point& location, const drawing::size& size) {
  auto result = toggle_button {};
  result.location(location);
  result.size(size);
  return result;
}

toggle_button toggle_button::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = toggle_button {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text) {
  auto result = toggle_button {};
  result.text(text);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, const drawing::point& location) {
  auto result = toggle_button {};
  result.text(text);
  result.location(location);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size) {
  auto result = toggle_button {};
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = toggle_button {};
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, xtd::forms::check_state check_state) {
  auto result = toggle_button {};
  result.text(text);
  result.check_state(check_state);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, xtd::forms::check_state check_state, const drawing::point& location) {
  auto result = toggle_button {};
  result.text(text);
  result.check_state(check_state);
  result.location(location);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, xtd::forms::check_state check_state, const drawing::point& location, const drawing::size& size) {
  auto result = toggle_button {};
  result.text(text);
  result.check_state(check_state);
  result.location(location);
  result.size(size);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, xtd::forms::check_state check_state, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = toggle_button {};
  result.text(text);
  result.check_state(check_state);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, bool three_state, xtd::forms::check_state check_state) {
  auto result = toggle_button {};
  result.text(text);
  result.three_state(three_state);
  result.check_state(check_state);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, bool three_state, xtd::forms::check_state check_state, const drawing::point& location) {
  auto result = toggle_button {};
  result.text(text);
  result.three_state(three_state);
  result.check_state(check_state);
  result.location(location);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, bool three_state, xtd::forms::check_state check_state, const drawing::point& location, const drawing::size& size) {
  auto result = toggle_button {};
  result.text(text);
  result.three_state(three_state);
  result.check_state(check_state);
  result.location(location);
  result.size(size);
  return result;
}

toggle_button toggle_button::create(const xtd::ustring& text, bool three_state, xtd::forms::check_state check_state, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = toggle_button {};
  result.text(text);
  result.three_state(three_state);
  result.check_state(check_state);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

toggle_button toggle_button::create(const control& parent) {
  auto result = toggle_button {};
  return result;
}

toggle_button toggle_button::create(const control& parent, const drawing::point& location) {
  auto result = toggle_button {};
  result.parent(parent);
  result.location(location);
  return result;
}

toggle_button toggle_button::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = toggle_button {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

toggle_button toggle_button::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = toggle_button {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, const drawing::point& location) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, xtd::forms::check_state check_state) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.check_state(check_state);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, xtd::forms::check_state check_state, const drawing::point& location) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.check_state(check_state);
  result.location(location);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, xtd::forms::check_state check_state, const drawing::point& location, const drawing::size& size) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.check_state(check_state);
  result.location(location);
  result.size(size);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, xtd::forms::check_state check_state, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.check_state(check_state);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, bool three_state, xtd::forms::check_state check_state) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.three_state(three_state);
  result.check_state(check_state);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, bool three_state, xtd::forms::check_state check_state, const drawing::point& location) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.three_state(three_state);
  result.check_state(check_state);
  result.location(location);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, bool three_state, xtd::forms::check_state check_state, const drawing::point& location, const drawing::size& size) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.three_state(three_state);
  result.check_state(check_state);
  result.location(location);
  result.size(size);
  return result;
}

toggle_button toggle_button::create(const control& parent, const xtd::ustring& text, bool three_state, xtd::forms::check_state check_state, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = toggle_button {};
  result.parent(parent);
  result.text(text);
  result.three_state(three_state);
  result.check_state(check_state);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

forms::create_params toggle_button::create_params() const noexcept {
  auto create_params = button_base::create_params();
  
  create_params.class_name("togglebutton");
  if (data_->three_state) create_params.style(create_params.style() | (data_->auto_check ? BS_AUTO3STATE : BS_3STATE));
  else if (data_->auto_check) create_params.style(create_params.style() | BS_AUTOCHECKBOX);
  else create_params.style(create_params.style() | BS_CHECKBOX);
  create_params.style(create_params.style() | BS_PUSHLIKE);
  
  switch (data_->check_align) {
    case content_alignment::top_right:
    case content_alignment::middle_right:
    case content_alignment::bottom_right: create_params.style(create_params.style() | BS_RIGHTBUTTON); break;
    default: break;
  }
  
  return create_params;
}

drawing::size toggle_button::measure_control() const noexcept {
  return button_base::measure_text() + drawing::size(18, 0);
}

void toggle_button::on_checked_changed(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system && enabled()) {
    if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = xtd::forms::visual_styles::toggle_button_state::unchecked_normal;
    else if (data_->check_state == xtd::forms::check_state::checked) data_->state = xtd::forms::visual_styles::toggle_button_state::checked_normal;
    else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = xtd::forms::visual_styles::toggle_button_state::mixed_normal;
  }
  checked_changed(*this, e);
  if (flat_style() != xtd::forms::flat_style::system) invalidate();
}

void toggle_button::on_check_state_changed(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system && enabled()) {
    if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = xtd::forms::visual_styles::toggle_button_state::unchecked_normal;
    else if (data_->check_state == xtd::forms::check_state::checked) data_->state = xtd::forms::visual_styles::toggle_button_state::checked_normal;
    else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = xtd::forms::visual_styles::toggle_button_state::mixed_normal;
  }
  check_state_changed(*this, e);
  if (flat_style() != xtd::forms::flat_style::system) invalidate();
}

void toggle_button::on_enabled_changed(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system) {
    if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = enabled() ? xtd::forms::visual_styles::toggle_button_state::unchecked_normal : xtd::forms::visual_styles::toggle_button_state::unchecked_disabled;
    else if (data_->check_state == xtd::forms::check_state::checked) data_->state = enabled() ? xtd::forms::visual_styles::toggle_button_state::checked_normal : xtd::forms::visual_styles::toggle_button_state::checked_disabled;
    else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = enabled() ? xtd::forms::visual_styles::toggle_button_state::mixed_normal : xtd::forms::visual_styles::toggle_button_state::mixed_disabled;
  }
  button_base::on_enabled_changed(e);
}

void toggle_button::on_handle_created(const event_args& e) {
  button_base::on_handle_created(e);
  if (flat_style() == flat_style::system) native::toggle_button::check_state(handle(), static_cast<int32>(data_->check_state));
  if (flat_style() != xtd::forms::flat_style::system && data_->check_state != xtd::forms::check_state::unchecked) invalidate();
}

void toggle_button::on_mouse_down(const mouse_event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system && enabled()) {
    if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = xtd::forms::visual_styles::toggle_button_state::unchecked_pressed;
    else if (data_->check_state == xtd::forms::check_state::checked) data_->state = xtd::forms::visual_styles::toggle_button_state::checked_pressed;
    else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = xtd::forms::visual_styles::toggle_button_state::mixed_pressed;
  }
  button_base::on_mouse_down(e);
}

void toggle_button::on_mouse_enter(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system && enabled()) {
    if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = (mouse_buttons() & mouse_buttons::left) == mouse_buttons::left ? xtd::forms::visual_styles::toggle_button_state::unchecked_pressed : xtd::forms::visual_styles::toggle_button_state::unchecked_hot;
    else if (data_->check_state == xtd::forms::check_state::checked) data_->state = (mouse_buttons() & mouse_buttons::left) == mouse_buttons::left ? xtd::forms::visual_styles::toggle_button_state::checked_pressed : xtd::forms::visual_styles::toggle_button_state::checked_hot;
    else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = (mouse_buttons() & mouse_buttons::left) == mouse_buttons::left ? xtd::forms::visual_styles::toggle_button_state::mixed_pressed : xtd::forms::visual_styles::toggle_button_state::mixed_hot;
  }
  button_base::on_mouse_enter(e);
}

void toggle_button::on_mouse_leave(const event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system && enabled()) {
    if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = xtd::forms::visual_styles::toggle_button_state::unchecked_normal;
    else if (data_->check_state == xtd::forms::check_state::checked) data_->state = xtd::forms::visual_styles::toggle_button_state::checked_normal;
    else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = xtd::forms::visual_styles::toggle_button_state::mixed_normal;
  }
  button_base::on_mouse_leave(e);
}

void toggle_button::on_mouse_up(const mouse_event_args& e) {
  if (flat_style() != xtd::forms::flat_style::system && enabled() && (data_->state == xtd::forms::visual_styles::toggle_button_state::unchecked_pressed || data_->state == xtd::forms::visual_styles::toggle_button_state::checked_pressed || data_->state == xtd::forms::visual_styles::toggle_button_state::mixed_pressed)) {
    if (data_->check_state == xtd::forms::check_state::unchecked) data_->state = xtd::forms::visual_styles::toggle_button_state::unchecked_hot;
    else if (data_->check_state == xtd::forms::check_state::checked) data_->state = xtd::forms::visual_styles::toggle_button_state::checked_hot;
    else if (data_->check_state == xtd::forms::check_state::indeterminate) data_->state = xtd::forms::visual_styles::toggle_button_state::mixed_hot;
  }
  button_base::on_mouse_up(e);
}

void toggle_button::on_paint(paint_event_args& e) {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (flat_style() == xtd::forms::flat_style::standard) toggle_button_renderer::draw_toggle_button(style, e.graphics(), e.clip_rectangle(), state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, image(), image_align());
  if (flat_style() == xtd::forms::flat_style::flat) toggle_button_renderer::draw_flat_toggle_button(style, e.graphics(), e.clip_rectangle(), state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, image(), image_align());
  if (flat_style() == xtd::forms::flat_style::popup) toggle_button_renderer::draw_popup_toggle_button(style, e.graphics(), e.clip_rectangle(), state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, image(), image_align());
  button_base::on_paint(e);
}

xtd::forms::visual_styles::toggle_button_state toggle_button::state() const noexcept {
  return data_->state;
}

void toggle_button::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK: wm_mouse_double_click(message); break;
    default: button_base::wnd_proc(message);
  }
}

void toggle_button::wm_mouse_double_click(message& message) {
  on_double_click(event_args::empty);
}

void toggle_button::wm_mouse_down(message& message) { // message parameter can't be const by design.
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, get_state(state::double_click_fired));
  set_mouse_buttons(mouse_buttons() | e.button());
  on_mouse_down(e);
}

void toggle_button::wm_mouse_up(message& message) { // message parameter can't be const by design.
  if (data_->auto_check)
    switch (check_state()) {
      case forms::check_state::unchecked: check_state(forms::check_state::checked); break;
      case forms::check_state::checked: check_state(three_state() ? forms::check_state::indeterminate : forms::check_state::unchecked); break;
      case forms::check_state::indeterminate: check_state(forms::check_state::unchecked); break;
    }
  auto e = mouse_event_args::create(message);
  set_mouse_buttons(mouse_buttons() & ~e.button());
  if (client_rectangle().contains(e.location())) on_click(event_args::empty);
  on_mouse_click(e);
  on_mouse_up(e);
}
