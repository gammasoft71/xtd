#include <iostream>
#include <xtd/xtd.diagnostics>
#include <xtd/xtd.strings>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/window_message_keys.hpp>
#include "../../../include/xtd/forms/control.hpp"

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

const control control::null;

control::~control() {
  if (this->handle_) {
    native::control::del(this->handle_);
    this->handle_ = 0;
    this->on_handle_destroyed(event_args::empty);
    this->destroy_handle();
  }
}

map<intptr_t, control*> control::handles_;

void control::back_color(const color& color) {
  if (this->back_color_ != color) {
    this->back_color_ = color;
    native::control::back_color(this->handle_, this->back_color_);
    this->on_back_color_changed(event_args::empty);
  }
}

void control::client_size(const drawing::size& size) {
  if (this->client_size_ != size) {
    this->client_size_ = size;
    native::control::client_size(this->handle_, this->client_size_);
  }
}

void control::enabled(bool enabled) {
  if (this->enabled_ != enabled) {
    this->enabled_ = enabled;
    //for (control* control : this->controls_)
    //  control->enabled(enabled);
    native::control::enabled(this->handle_, this->enabled_);
    this->on_enabled_changed(event_args::empty);
  }
}

void control::fore_color(const color& color) {
  if (this->fore_color_ != color) {
    this->fore_color_ = color;
    native::control::fore_color(this->handle_, this->fore_color_);
    this->on_fore_color_changed(event_args::empty);
  }
}

intptr_t control::handle() const {
  return native::control::handle(this->handle_);
}

void control::location(const point& location) {
  if (this->location_ != location) {
    this->location_ = location;
    native::control::location(this->handle_, this->location_);
  }
}

void control::parent(const control& parent) {
  if (this->parent_ != &parent) {
    this->parent_ = const_cast<control*>(&parent);
    if (this->parent_ == &control::null) {
      this->destroy_handle();
    } else {
      this->create_control();
      //native::control::parent(this->handle_, this->parent_);
      //for (control* control : this->controls_)
      //  control->create_control();
      this->on_parent_changed(event_args::empty);
    }
  }
}

void control::size(const drawing::size& size) {
  if (this->size_ != size) {
    this->size_ = size;
    native::control::size(this->handle_, this->size_);
  }
}

void control::text(const string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::control::text(this->handle_, this->text_);
  }
}

void control::visible(bool visible) {
  if (this->visible_ != visible) {
    this->visible_ = visible;
    //for (control* control : this->controls_)
    //  control->visible(visible);
    native::control::visible(this->handle_, this->visible_);
    this->on_visible_changed(event_args::empty);
  }
}

void control::create_control() {
  if (!this->handle_) {
    this->create_handle();
    this->on_create_control();
  }
}

void control::create_handle() {
  if (this->handle_ == 0) this->handle_ = native::control::create(this->parent_->handle_, this->default_size());
  native::control::register_wnd_proc(this->handle_, {*this, &control::wnd_proc_});
  handles_[native::control::handle(this->handle_)] = this;
  this->send_message(native::control::handle(this->handle_), WM_CREATE, 0, 0);
  this->on_handle_created(event_args::empty);
  this->set_properties();
  this->get_properties();
}

void control::destroy_handle() {
  handles_.erase(this->handle_);
  native::control::destroy(this->handle_);
  this->handle_ = 0;
  this->on_handle_destroyed(event_args::empty);
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

bool control::is_null() const {
  return this == &control::null;
}

void control::on_back_color_changed(const event_args &e) {
  this->back_color_changed(*this, e);
}

void control::on_create_control() {
}

void control::on_click(const event_args &e) {
  this->click(*this, e);
}

void control::on_client_size_changed(const event_args &e) {
  this->client_size_ = native::control::client_size(this->handle_);
  this->client_size_changed(*this, e);
}

void control::on_double_click(const event_args &e) {
  this->double_click(*this, e);
}

void control::on_enabled_changed(const event_args &e) {
  this->enabled_ = native::control::enabled(this->handle_);
  this->enabled_changed(*this, e);
}

void control::on_fore_color_changed(const event_args &e) {
  this->fore_color_changed(*this, e);
}

void control::on_got_focus(const event_args &e) {
  this->got_focus(*this, e);
}

void control::on_handle_created(const event_args &e) {
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
  this->location_ = native::control::location(this->handle_);
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

void control::on_parent_changed(const event_args &e) {
  this->parent_changed(*this, e);
}

void control::on_size_changed(const event_args &e) {
  this->size_ = native::control::size(this->handle_);
  this->size_changed(*this, e);
}

void control::on_text_changed(const event_args &e) {
  this->text_changed(*this, e);
}

void control::on_visible_changed(const event_args &e) {
  this->visible_ = native::control::visible(this->handle_);
  this->visible_changed(*this, e);
}

intptr_t control::wnd_proc_(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
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
    case WM_MOVE: wm_move(message);  break;
    case WM_SETTEXT: wm_set_text(message); break;
    case WM_SIZE:  this->wm_size(message); break;
    default: this->def_wnd_proc(message); break;
  }
}

intptr_t control::send_message(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam) {
  return native::control::send_message(this->handle_, hwnd, msg, wparam, lparam);
}

void control::def_wnd_proc(message& message) {
  message.result(native::control::def_wnd_proc(this->handle_, message.hwnd(), message.msg(),message.wparam(), message.lparam(), message.result(), message.handle()));
}

void control::get_properties() {
  this->back_color_ = native::control::back_color(this->handle_);
  this->client_size_ = native::control::client_size(this->handle_);
  this->fore_color_ = native::control::fore_color(this->handle_);
  this->location_ = native::control::location(this->handle_);
  this->size_ = native::control::size(this->handle_);
  this->text_ = native::control::text(this->handle_);
  this->visible_ = native::control::visible(this->handle_);
}

void control::set_properties() {
  if (this->client_size_ != drawing::size(-1, -1)) native::control::client_size(this->handle_, this->client_size_);
  if (this->location_ != point(-1, -1)) native::control::location(this->handle_, this->location_);
  if (this->size_ != drawing::size(-1, -1)) native::control::size(this->handle_, this->size_);
  native::control::text(this->handle_, this->text_);
  native::control::visible(this->handle_, this->visible_);
}

void control::wm_child_activate(message& message) {
  this->def_wnd_proc(message);
}

void control::wm_command(message& message) {
  this->def_wnd_proc(message);
  //this->on_click(event_args::empty);
}

void control::wm_key_char(message& message) {
  if (message.msg() == WM_KEYDOWN || message.msg ()== WM_SYSKEYDOWN) {
    key_event_args key_event_args(static_cast<keys>(message.wparam()));
    on_key_down(key_event_args);
    message.result(key_event_args.suppress_key_press());
    if (!key_event_args.handled()) this->def_wnd_proc(message);
  } else if (message.msg() == WM_CHAR || message.msg() == WM_SYSCHAR) {
    key_press_event_args key_press_event_args(static_cast<int>(message.wparam()));
    on_key_press(key_press_event_args);
    message.result(key_press_event_args.handled());
    if (!key_press_event_args.handled()) this->def_wnd_proc(message);
  } else if (message.msg() == WM_KEYUP || message.msg() == WM_SYSKEYUP) {
    key_event_args key_event_args(static_cast<keys>(message.wparam()));
    on_key_up(key_event_args);
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
  this->set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  this->def_wnd_proc(message);
  this->on_mouse_down(mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, this->get_state(control::state::double_click_fired) ? 2 : 1, 0));
}

void control::wm_mouse_double_click(message& message) {
  this->set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  this->def_wnd_proc(message);
  this->on_double_click(event_args::empty);
  this->on_mouse_double_click(mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, this->get_state(control::state::double_click_fired) ? 2 : 1, 0));
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
  /*
  if (this->get_state(control::state::double_click_fired)) {
    this->on_double_click(event_args::empty);
    this->on_mouse_double_click(mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, 2, 0));
  } else {
    this->on_click(event_args::empty);
    this->on_mouse_click(mouse_event_args(message_to_mouse_buttons(message),{LOWORD(message.lparam()), HIWORD(message.lparam())}, 1, 0));
  }
   */
  this->on_click(event_args::empty);
  this->on_mouse_click(mouse_event_args(message_to_mouse_buttons(message),{LOWORD(message.lparam()), HIWORD(message.lparam())}, 1, 0));
  this->def_wnd_proc(message);
  this->on_mouse_up(mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, 1, 0));
}

void control::wm_mouse_move(message& message) {
  this->def_wnd_proc(message);
  this->on_mouse_move(mouse_event_args(wparam_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, this->get_state(control::state::double_click_fired) ? 2 : 1, 0));
}

void control::wm_move(message& message) {
  this->def_wnd_proc(message);
  this->on_location_changed(event_args::empty);
}

void control::wm_set_focus(message& message) {
  this->def_wnd_proc(message);
  this->on_got_focus(event_args::empty);
}

void control::wm_mouse_wheel(message& message) {
  this->def_wnd_proc(message);
  if (message.msg() == WM_MOUSEHWHEEL)
    this->on_mouse_horizontal_wheel(mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, this->get_state(control::state::double_click_fired) ? 2 : 1, HIWORD(message.wparam())));
  else
    this->on_mouse_wheel(mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, this->get_state(control::state::double_click_fired) ? 2 : 1, HIWORD(message.wparam())));
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
