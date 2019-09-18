#include <iostream>
#include <xtd/xtd.diagnostics>
#include <xtd/xtd.environment>
#include <xtd/xtd.strings>
#include <xtd/drawing/native/graphics.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/window_message_keys.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/control.hpp"
#include "../../../include/xtd/forms/form.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  bool debug_events = false;
  
  mouse_buttons message_to_mouse_buttons(const message& message) {
    if (message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_LBUTTONDOWN || message.msg() == WM_LBUTTONUP)
      return mouse_buttons::left;
    else if (message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_RBUTTONDOWN || message.msg() == WM_RBUTTONUP)
      return mouse_buttons::right;
    else if (message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_MBUTTONDOWN || message.msg() == WM_MBUTTONUP)
      return mouse_buttons::middle;
    else if (message.msg() == WM_XBUTTONDBLCLK || message.msg() == WM_XBUTTONDOWN || message.msg() == WM_XBUTTONUP)
      return (message.wparam() & MK_XBUTTON2) == MK_XBUTTON2 ? mouse_buttons::x_button2 : mouse_buttons::x_button1;
    return mouse_buttons::none;
  }
  
  mouse_buttons wparam_to_mouse_buttons(const message& message) {
    if ((message.wparam() & MK_LBUTTON) == MK_LBUTTON)
      return mouse_buttons::left;
    else if ((message.wparam() & MK_RBUTTON) == MK_RBUTTON)
      return mouse_buttons::right;
    else if ((message.wparam() & MK_MBUTTON) == MK_MBUTTON)
      return mouse_buttons::middle;
    return mouse_buttons::none;
  }
}

const control control::null {"null", true};

map<intptr_t, control*> control::handles_;
control::control_collection control::top_level_controls_;

control::control() {
  native::control::init();
  this->size_ = this->default_size();
  this->controls_.item_added += [&](size_t, std::reference_wrapper<control> item) {
    item.get().parent_ = this->handle_;
    if (this->handle_) {
      item.get().create_control();
      if (item.get().handle_) native::control::parent(item.get().handle_, this->handle_);
      item.get().on_parent_changed(event_args::empty);
      this->on_control_added(control_event_args(item.get()));
    }
  };
  
  this->controls_.item_erased += [&](size_t, std::reference_wrapper<control> item) {
    item.get().parent_ = 0;
    item.get().destroy_handle();
    this->on_control_removed(control_event_args(item.get()));
  };
}

control::~control() {
  destroy_control();
}

control& control::auto_size(bool auto_size) {
  if (this->auto_size_ != auto_size) {
    this->auto_size_ = auto_size;
    this->on_auto_size_changed(event_args::empty);
  }
  return *this;
}

control& control::back_color(const color& color) {
  if (this->back_color_ != color) {
    this->back_color_ = color;
    native::control::back_color(this->handle_, this->back_color_.value());
    this->on_back_color_changed(event_args::empty);
    for (auto control : this->controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
  return *this;
}

drawing::color control::default_back_color() const {
  return native::control::default_back_color();
}

drawing::color control::default_fore_color() const {
  return native::control::default_fore_color();
}

drawing::font control::default_font() const {
  return native::control::default_font();
}

control& control::enabled(bool enabled) {
  if (this->enabled_ != enabled) {
    this->enabled_ = enabled;
    native::control::enabled(this->handle_, this->enabled_);
    this->on_enabled_changed(event_args::empty);
  }
  return *this;
}

control& control::fore_color(const color& color) {
  if (this->fore_color_ != color) {
    this->fore_color_ = color;
    native::control::fore_color(this->handle_, this->fore_color_.value());
    this->on_fore_color_changed(event_args::empty);
    for (auto control : this->controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
  return *this;
}

control& control::font(const drawing::font& font) {
  if (this->font_ != font) {
    this->font_ = font;
    native::control::font(this->handle_, this->font_.value());
    this->on_font_changed(event_args::empty);
    for (auto control : this->controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
  return *this;
}

intptr_t control::handle() const {
  return this->handle_;
}

control& control::parent(const control& parent) {
  if (&this->parent() != &parent) {
    if (this->parent_ != 0) {
      for (size_t index = 0; index < this->parent().controls_.size(); index++) {
        if (&this->parent().controls_[index].get() == this) {
          this->parent().controls_.erase_at(index);
          break;
        }
      }
    }
    if (&parent != &control::null) const_cast<control&>(parent).controls_.push_back(ref_control(*this));
  }
  return *this;
}

control& control::text(const string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::control::text(this->handle_, this->text_);
  }
  return *this;
}

control& control::top_level_control() const {
  control* top_level_control = const_cast<control*>(this);
  while (dynamic_cast<form*>(top_level_control) == nullptr && top_level_control->parent_ != 0) {
    top_level_control = &top_level_control->parent();
  }
  return *top_level_control;
}

control& control::visible(bool visible) {
  if (this->visible_ != visible) {
    this->visible_ = visible;
    native::control::visible(this->handle_, this->visible_);
    this->on_visible_changed(event_args::empty);
  }
  return *this;
}

void control::create_control() {
  this->created_ = true;
  if (!this->handle_) {
    this->create_handle();
    if (!this->parent_) top_level_controls_.push_back(ref_control(*this));
    this->send_message(this->handle_, WM_CREATE, 0, 0);
    this->on_create_control();
  }
}

void control::destroy_control() {
  this->created_ = false;
  if (this->handle_) {
    if (this->parent_ != 0) {
      for (size_t index = 0; index < this->parent().controls_.size(); index++) {
        if (this->parent().controls_[index].get().handle_ == this->handle_) {
          this->parent().controls_.erase_at(index);
          break;
        }
      }
    } else {
      for (size_t index = 0; index < top_level_controls_.size(); index++) {
        if (top_level_controls_[index].get().handle_ == this->handle_) {
          top_level_controls_.erase_at(index);
          break;
        }
      }
    }
    this->destroy_handle();
  }
}

graphics control::create_graphics() const {
  return graphics(native::control::create_graphics(this->handle_));
}

void control::create_handle() {
  this->handle_ = native::control::create(this->create_params());
  this->on_handle_created(event_args::empty);
}

void control::destroy_handle() {
  this->internal_destroy_handle(this->handle_);
  this->handle_ = 0;
}

control& control::from_child_handle(intptr_t handle) {
  try {
    if (handles_.find(handle) != handles_.end())
      return handles_[handle]->parent();
    return (control&)control::null;
  } catch (...) {
    return (control&)control::null;
  }
}

control& control::from_handle(intptr_t handle) {
  try {
    if (handles_.find(handle) != handles_.end())
      return *handles_[handle];
    return (control&)control::null;
  } catch (...) {
    return (control&)control::null;
  }
}

bool control::is_handle_created() const {
  return this->handle_ != 0;
}

bool control::is_null() const {
  return this == &control::null;
}

forms::create_params control::create_params() const {
  forms::create_params create_params;
  
  create_params.caption(this->text_);
  create_params.style(WS_VISIBLE | WS_CHILD);
  if (this->parent_) create_params.parent(this->parent().handle_);
  create_params.location(this->location_);
  
  create_params.size(this->size_);
  
  return create_params;
}

drawing::size control::measure_control() const {
  return this->client_size_;
}

drawing::size control::measure_text() const {
  return drawing::size::ceiling(this->create_graphics().measure_string(this->text_, this->font())) + drawing::size(2, 1);
}

void control::on_auto_size_changed(const event_args& e) {
  this->set_auto_size_size();
  this->auto_size_changed(*this, e);
}

void control::on_back_color_changed(const event_args &e) {
  this->refresh();
  this->back_color_changed(*this, e);
}

void control::on_create_control() {
  for (auto control : this->controls_)
    control.get().create_control();
}

void control::on_click(const event_args &e) {
  this->click(*this, e);
}

void control::on_client_size_changed(const event_args &e) {
  this->client_size_ = native::control::client_size(this->handle_);
  this->client_size_changed(*this, e);
}

void control::on_control_added(const control_event_args &e) {
  if (this->auto_size_) this->set_auto_size_size();
  this->control_added(*this, e);
}

void control::on_control_removed(const control_event_args &e) {
  if (this->auto_size_) this->set_auto_size_size();
  this->control_removed(*this, e);
}

void control::on_double_click(const event_args &e) {
  this->double_click(*this, e);
}

void control::on_enabled_changed(const event_args &e) {
  this->enabled_ = native::control::enabled(this->handle_);
  this->refresh();
  this->enabled_changed(*this, e);
}

void control::on_fore_color_changed(const event_args &e) {
  this->refresh();
  this->fore_color_changed(*this, e);
}

void control::on_font_changed(const event_args &e) {
  if (this->auto_size_) this->set_auto_size_size();
  if (this->parent_ && this->parent().auto_size_) this->parent().set_auto_size_size();
  this->refresh();
  this->font_changed(*this, e);
}

void control::on_got_focus(const event_args &e) {
  this->got_focus(*this, e);
}

void control::on_handle_created(const event_args &e) {
  native::control::register_wnd_proc(this->handle_, {*this, &control::wnd_proc_});
  handles_[this->handle_] = this;
  if (this->get_state(state::client_size_setted)) native::control::client_size(this->handle_, this->client_size());
  if ((this->back_color_.has_value() && this->back_color_.value() != this->default_back_color()) || (!environment::os_version().is_osx_platform() && this->back_color() != this->default_back_color())) native::control::back_color(this->handle_, this->back_color());
  if (this->fore_color_.has_value() || this->fore_color() != this->default_fore_color()) native::control::fore_color(this->handle_, this->fore_color());
  if (this->font_.has_value() || this->font() != this->default_font()) native::control::font(this->handle_, this->font());
  native::control::visible(this->handle_, this->visible());
  
  this->client_rectangle_ = native::control::client_rectangle(this->handle_);
  this->client_size_ = native::control::client_size(this->handle_);
  this->location_ = native::control::location(this->handle_);
  this->size_ = native::control::size(this->handle_);
  
  this->handle_created(*this, e);
}

void control::on_handle_destroyed(const event_args &e) {
  this->handle_destroyed(*this, e);
}

void control::on_key_down(key_event_args& e) {
  this->key_down(*this, e);
}

void control::on_key_press(key_press_event_args& e) {
  this->key_press(*this, e);
}

void control::on_key_up(key_event_args& e) {
  this->key_up(*this, e);
}

void control::on_location_changed(const event_args &e) {
  if (this->handle_ != 0) this->location_ = native::control::location(this->handle_);
  if (this->parent_ && this->parent().auto_size_) this->parent().set_auto_size_size();
  this->location_changed(*this, e);
}

void control::on_lost_focus(const event_args &e) {
  this->lost_focus(*this, e);
}

void control::on_mouse_click(const mouse_event_args& e) {
  this->mouse_click(*this, e);
}

void control::on_mouse_double_click(const mouse_event_args& e) {
  this->mouse_double_click(*this, e);
}

void control::on_mouse_down(const mouse_event_args& e) {
  this->mouse_down(*this, e);
}

void control::on_mouse_horizontal_wheel(const mouse_event_args& e) {
  this->mouse_horizontal_wheel(*this, e);
}

void control::on_mouse_enter(const event_args &e) {
  this->mouse_enter(*this, e);
}

void control::on_mouse_leave(const event_args &e) {
  this->mouse_leave(*this, e);
}

void control::on_mouse_move(const mouse_event_args& e) {
  this->mouse_move(*this, e);
}

void control::on_mouse_up(const mouse_event_args& e) {
  this->mouse_up(*this, e);
}

void control::on_mouse_wheel(const mouse_event_args& e) {
  this->mouse_wheel(*this, e);
}

void control::on_paint(paint_event_args &e) {
  this->paint(*this, e);
}

void control::on_parent_back_color_changed(const event_args &e) {
  if (!this->back_color_.has_value()) {
    if (this->back_color() == this->default_back_color())
      this->recreate_handle();
    else if (!environment::os_version().is_osx_platform())
      native::control::back_color(this->handle_, this->back_color());
    for (auto control : this->controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
}

void control::on_parent_changed(const event_args &e) {
  this->parent_changed(*this, e);
}

void control::on_parent_fore_color_changed(const event_args &e) {
  if (!this->fore_color_.has_value()) {
    native::control::fore_color(this->handle_, this->fore_color());
    for (auto control : this->controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
}

void control::on_parent_font_changed(const event_args &e) {
  if (!this->font_.has_value()) {
    native::control::font(this->handle_, this->font());
    for (auto control : this->controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
}

void control::on_size_changed(const event_args &e) {
  if (this->handle_ != 0) this->size_ = native::control::size(this->handle_);
  if (this->parent_ && this->parent().auto_size_) this->parent().set_auto_size_size();
  this->refresh();
  this->size_changed(*this, e);
}

void control::on_text_changed(const event_args &e) {
  if (this->auto_size_) this->set_auto_size_size();
  if (this->parent_ && this->parent().auto_size_) this->parent().set_auto_size_size();
  this->text_changed(*this, e);
}

void control::on_visible_changed(const event_args &e) {
  this->visible_ = native::control::visible(this->handle_);
  this->refresh();
  this->visible_changed(*this, e);
}

void control::refresh() const {
  native::control::refresh(this->handle_);
}

intptr_t control::send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) const {
  return native::control::send_message(this->handle_, hwnd, msg, wparam, lparam);
}

void control::set_auto_size_mode(auto_size_mode auto_size_mode) {
  if (this->auto_size_mode_ != auto_size_mode) {
    this->auto_size_mode_ = auto_size_mode;
    this->set_auto_size_size();
  }
}

string control::to_string() const {
  if (!this->name_.empty()) return strings::format("{}, name: {}", strings::full_class_name(*this), this->name_);
  if (!this->text_.empty()) return strings::format("{}, text: {}", strings::full_class_name(*this), this->text_);
  return strings::full_class_name(*this);
}

intptr_t control::wnd_proc_(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
  message message = forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
  wnd_proc(message);
  return message.result();
}

void control::wnd_proc(message& message) {
  diagnostics::debug::write_line_if(debug_events, strings::format("({}) receive message [{}]", this->name_, message));
  switch (message.msg()) {
      // keyboard:
    case WM_CHAR:
    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSCHAR:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP: this->wm_key_char(message); break;
      // mouse events
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_XBUTTONDOWN: this->wm_mouse_down(message); break;
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_XBUTTONUP: this->wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK:
    case WM_MBUTTONDBLCLK:
    case WM_RBUTTONDBLCLK:
    case WM_XBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
    case WM_MOUSEMOVE: this->wm_mouse_move(message); break;
    case WM_MOUSEENTER: this->wm_mouse_enter(message); break;
    case WM_MOUSELEAVE: this->wm_mouse_leave(message); break;
    case WM_CHILDACTIVATE: this->wm_child_activate(message); break;
    case WM_SETFOCUS: this->wm_set_focus(message); break;
    case WM_KILLFOCUS: this->wm_kill_focus(message); break;
    case WM_MOUSEHWHEEL:
    case WM_MOUSEWHEEL: this->wm_mouse_wheel(message); break;
      // System events
    case WM_COMMAND: this->wm_command(message); break;
    case WM_PAINT: this->wm_paint(message); break;
    case WM_MOVE: wm_move(message);  break;
    case WM_SETTEXT: wm_set_text(message); break;
    case WM_SIZE:  this->wm_size(message); break;
    case WM_HSCROLL:
    case WM_VSCROLL: this->wm_scroll(message); break;
    default: this->def_wnd_proc(message); break;
  }
}

void control::def_wnd_proc(message& message) {
  message.result(native::control::def_wnd_proc(this->handle_, message.hwnd(), message.msg(),message.wparam(), message.lparam(), message.result(), message.handle()));
}

void control::recreate_handle() {
  if (this->handle_ != 0) {
    this->set_state(state::recreate, true);
    intptr_t handle = this->handle_;
    auto controls = this->controls();
    this->internal_destroy_handle(handle);
    this->handle_ = 0;
    this->create_handle();
    for (auto control : controls) {
      control.get().parent_ = this->handle_;
      control.get().recreate_handle();
    }
    this->set_state(state::recreate, false);
  }
}

void control::set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {
  if ((specified & bounds_specified::x) == bounds_specified::x) this->location_.x(x);
  if ((specified & bounds_specified::y) == bounds_specified::y) this->location_.y(y);
  if ((specified & bounds_specified::width) == bounds_specified::width) this->size_.width(width);
  if ((specified & bounds_specified::height) == bounds_specified::height) this->size_.height(height);
  
  if (this->auto_size_) this->size_ = this->measure_control();
  
  if ((specified & bounds_specified::x) == bounds_specified::x || (specified & bounds_specified::y) == bounds_specified::y) {
    native::control::location(this->handle_, this->location_);
    this->on_location_changed(event_args::empty);
  }
  
  if ((specified & bounds_specified::width) == bounds_specified::width || (specified & bounds_specified::height) == bounds_specified::height) {
    native::control::size(this->handle_, this->size_);
    this->on_client_size_changed(event_args::empty);
    this->on_size_changed(event_args::empty);
  }
}

void control::set_client_size_core(int32_t width, int32_t height) {
  this->client_size_.width(width);
  this->client_size_.height(height);
  
  native::control::client_size(this->handle_, this->client_size_);
  if (this->auto_size_) {
    this->size_ = native::control::size(this->handle_);
    this->size_ = this->measure_control();
    native::control::size(this->handle_, this->size_);
  }
  this->on_client_size_changed(event_args::empty);
  this->on_size_changed(event_args::empty);
}

void control::internal_destroy_handle(intptr_t handle) {
  if (this->handle_) native::control::unregister_wnd_proc(this->handle_, {*this, &control::wnd_proc_});
  handles_.erase(handle);
  native::control::destroy(handle);
  this->on_handle_destroyed(event_args::empty);
}

void control::set_auto_size_size() {
  drawing::size auto_size_size_ = this->measure_control();
  if (this->auto_size_mode_ == auto_size_mode::grow_only && auto_size_size_.width() < this->client_size_.width())
    auto_size_size_.width(this->client_size_.width());
  if (this->auto_size_mode_ == auto_size_mode::grow_only && auto_size_size_.height() < this->client_size_.height())
    auto_size_size_.height(this->client_size_.height());
  this->client_size(auto_size_size_);
}

void control::wm_child_activate(message& message) {
  this->def_wnd_proc(message);
}

void control::wm_command(message& message) {
  this->def_wnd_proc(message);
  if (message.lparam() != 0)
    from_handle(message.lparam()).send_message(message.hwnd(), WM_REFLECT + message.msg(), message.wparam(), message.lparam());
}

void control::wm_key_char(message& message) {
  if (message.msg() == WM_KEYDOWN || message.msg ()== WM_SYSKEYDOWN) {
    key_event_args key_event_args(static_cast<keys>(message.wparam()));
    this->on_key_down(key_event_args);
    message.result(key_event_args.suppress_key_press());
    if (!key_event_args.handled()) this->def_wnd_proc(message);
  } else if (message.msg() == WM_CHAR || message.msg() == WM_SYSCHAR) {
    key_press_event_args key_press_event_args(static_cast<int32_t>(message.wparam()));
    this->on_key_press(key_press_event_args);
    message.result(key_press_event_args.handled());
    if (!key_press_event_args.handled()) this->def_wnd_proc(message);
  } else if (message.msg() == WM_KEYUP || message.msg() == WM_SYSKEYUP) {
    key_event_args key_event_args(static_cast<keys>(message.wparam()));
    this->on_key_up(key_event_args);
    message.result(key_event_args.handled());
    if (!key_event_args.handled()) this->def_wnd_proc(message);
  } else
    this->def_wnd_proc(message);
}

void control::wm_kill_focus(message& message) {
  this->def_wnd_proc(message);
  this->on_got_focus(event_args::empty);
}

void control::wm_mouse_down(message& message) {
  this->def_wnd_proc(message);
  this->set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  this->on_mouse_down(mouse_event_args(message_to_mouse_buttons(message), {(int32_t)LOWORD(message.lparam()), (int32_t)HIWORD(message.lparam())}, this->get_state(control::state::double_click_fired) ? 2 : 1, 0));
}

void control::wm_mouse_double_click(message& message) {
  this->def_wnd_proc(message);
  this->set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  this->on_double_click(event_args::empty);
  this->on_mouse_double_click(mouse_event_args(message_to_mouse_buttons(message), {(int32_t)LOWORD(message.lparam()), (int32_t)HIWORD(message.lparam())}, this->get_state(control::state::double_click_fired) ? 2 : 1, 0));
}

void control::wm_mouse_enter(message& message) {
  this->def_wnd_proc(message);
  this->on_mouse_enter(event_args::empty);
}

void control::wm_mouse_leave(message& message) {
  this->def_wnd_proc(message);
  this->on_mouse_leave(event_args::empty);
}

void control::wm_mouse_up(message& message) {
  this->def_wnd_proc(message);
  /*
   if (this->get_state(control::state::double_click_fired)) {
   this->on_double_click(event_args::empty);
   this->on_mouse_double_click(mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, 2, 0));
   } else {
   this->on_click(event_args::empty);
   this->on_mouse_click(mouse_event_args(message_to_mouse_buttons(message),{LOWORD(message.lparam()), HIWORD(message.lparam())}, 1, 0));
   }
   */
  if (message_to_mouse_buttons(message) == mouse_buttons::left) this->on_click(event_args::empty);
  this->on_mouse_click(mouse_event_args(message_to_mouse_buttons(message),{(int32_t)LOWORD(message.lparam()), (int32_t)HIWORD(message.lparam())}, 1, 0));
  this->on_mouse_up(mouse_event_args(message_to_mouse_buttons(message), {(int32_t)LOWORD(message.lparam()), (int32_t)HIWORD(message.lparam())}, 1, 0));
}

void control::wm_mouse_move(message& message) {
  this->def_wnd_proc(message);
  this->on_mouse_move(mouse_event_args(wparam_to_mouse_buttons(message), {(int32_t)LOWORD(message.lparam()), (int32_t)HIWORD(message.lparam())}, this->get_state(control::state::double_click_fired) ? 2 : 1, 0));
}

void control::wm_move(message& message) {
  this->def_wnd_proc(message);
  this->on_location_changed(event_args::empty);
}

void control::wm_mouse_wheel(message& message) {
  this->def_wnd_proc(message);
  if (message.msg() == WM_MOUSEHWHEEL)
    this->on_mouse_horizontal_wheel(mouse_event_args(message_to_mouse_buttons(message), { static_cast<int32_t>(LOWORD(message.lparam())), static_cast<int32_t>(HIWORD(message.lparam()))}, this->get_state(control::state::double_click_fired) ? 2 : 1, static_cast<int32_t>(HIWORD(message.wparam()))));
  else
    this->on_mouse_wheel(mouse_event_args(message_to_mouse_buttons(message), {static_cast<int32_t>(LOWORD(message.lparam())),  static_cast<int32_t>(HIWORD(message.lparam()))}, this->get_state(control::state::double_click_fired) ? 2 : 1, static_cast<int32_t>(HIWORD(message.wparam()))));
}

void control::wm_paint(message& message) {
  this->def_wnd_proc(message);
  paint_event_args e(this->client_rectangle_, *this);
  this->on_paint(e);
}

void control::wm_scroll(message& message) {
  this->def_wnd_proc(message);
  if (message.lparam() != 0)
    from_handle(message.lparam()).send_message(message.hwnd(), WM_REFLECT + message.msg(), message.wparam(), message.lparam());
}

void control::wm_set_focus(message& message) {
  this->def_wnd_proc(message);
  this->on_got_focus(event_args::empty);
}

void control::wm_set_text(message& message) {
  this->def_wnd_proc(message);
  this->text_ = reinterpret_cast<const char*>(message.lparam());
  this->on_text_changed(event_args::empty);
}

void control::wm_size(message& message) {
  this->def_wnd_proc(message);
  this->on_client_size_changed(event_args::empty);
  this->on_size_changed(event_args::empty);
}

