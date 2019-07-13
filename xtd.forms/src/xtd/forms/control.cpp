#include <iostream>
#include <xtd/xtd.strings>
#include "../../../include/xtd/forms/control.hpp"
#include "../../../include/xtd/forms/window_messages.hpp"
#include "../../../include/xtd/forms/window_message_keys.hpp"
#include "../../native/control_api.hpp"

namespace {
  xtd::forms::mouse_buttons message_to_mouse_buttons(const xtd::forms::message& message) {
    if (message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_LBUTTONDOWN || message.msg() == WM_LBUTTONUP)
      return xtd::forms::mouse_buttons::left;
    else if (message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_RBUTTONDOWN || message.msg() == WM_RBUTTONUP)
      return xtd::forms::mouse_buttons::right;
    else if (message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_MBUTTONDOWN || message.msg() == WM_MBUTTONUP)
      return xtd::forms::mouse_buttons::middle;
    else if (message.msg() == WM_XBUTTONDBLCLK || message.msg() == WM_XBUTTONDOWN || message.msg() == WM_XBUTTONUP)
      return (message.wparam() & MK_XBUTTON2) == MK_XBUTTON2 ? xtd::forms::mouse_buttons::x_button2 : xtd::forms::mouse_buttons::x_button1;
    return xtd::forms::mouse_buttons::none;
  }

  xtd::forms::mouse_buttons wparam_to_mouse_buttons(const xtd::forms::message& message) {
    if ((message.wparam() & MK_LBUTTON) == MK_LBUTTON)
      return xtd::forms::mouse_buttons::left;
    else if ((message.wparam() & MK_RBUTTON) == MK_RBUTTON)
      return xtd::forms::mouse_buttons::right;
    else if ((message.wparam() & MK_MBUTTON) == MK_MBUTTON)
      return xtd::forms::mouse_buttons::middle;
    return xtd::forms::mouse_buttons::none;
  }
}

const xtd::forms::control xtd::forms::control::null;

xtd::forms::control::~control() {
  if (this->handle_) {
    native::control_api::unregister_wnd_proc(this->handle_);
    if (this->instance_.use_count() == 1) native::control_api::del(this->handle_);
    this->handle_ = 0;
    this->on_handle_destroyed(xtd::event_args::empty);
  }
}

std::map<intptr_t, xtd::forms::control*> xtd::forms::control::handles_;

void xtd::forms::control::client_size(const xtd::drawing::size& size) {
  if (this->client_size_ != size) {
    this->client_size_ = size;
    native::control_api::client_size(this->handle_, this->client_size_);
  }
}

intptr_t xtd::forms::control::handle() const {
  return native::control_api::handle(this->handle_);
}

void xtd::forms::control::location(const xtd::drawing::point& location) {
  if (this->location_ != location) {
    this->location_ = location;
    native::control_api::location(this->handle_, this->location_);
  }
}

void xtd::forms::control::parent(const xtd::forms::control& parent) {
  if (this->parent_ != &parent) {
    this->parent_ = const_cast<xtd::forms::control*>(&parent);
    if (this->parent_ == &xtd::forms::control::null) {
      this->destroy_handle();
    } else {
      this->create_control();
      //native::control_api::parent(this->handle_, this->parent_);
      //for (xtd::forms::control* control : this->controls_)
      //  control->create_control();
      this->on_parent_changed(xtd::event_args::empty);
    }
  }
}

void xtd::forms::control::size(const xtd::drawing::size& size) {
  if (this->size_ != size) {
    this->size_ = size;
    native::control_api::size(this->handle_, this->size_);
  }
}

void xtd::forms::control::text(const std::string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::control_api::text(this->handle_, this->text_);
  }
}

void xtd::forms::control::visible(bool visible) {
  if (this->visible_ != visible) {
    this->visible_ = visible;
    //for (xtd::forms::control* control : this->controls_)
    //  control->visible(visible);
    native::control_api::visible(this->handle_, this->visible_);
    this->on_visible_changed(xtd::event_args::empty);
  }
}

void xtd::forms::control::create_control() {
  if (!this->handle_) {
    this->create_handle();
    this->on_create_control();
  }
}

void xtd::forms::control::create_handle() {
  if (this->handle_ == 0) this->handle_ = native::control_api::create(this->parent_->handle_, this->default_size());
  native::control_api::register_wnd_proc(this->handle_, {*this, &xtd::forms::control::wnd_proc});
  handles_[native::control_api::handle(this->handle_)] = this;
  this->send_message(native::control_api::handle(this->handle_), WM_CREATE, 0, 0);
  this->on_handle_created(xtd::event_args::empty);
  this->set_properties();
  this->get_properties();
}

void xtd::forms::control::destroy_handle() {
  handles_.erase(this->handle_);
  native::control_api::destroy(this->handle_);
  this->handle_ = 0;
  this->on_handle_destroyed(xtd::event_args::empty);
}

xtd::forms::control& xtd::forms::control::from_child_handle(intptr_t handle) {
  try {
    if (handles_.find(handle) != handles_.end())
      return handles_[handle]->parent();
    return (xtd::forms::control&)xtd::forms::control::null;
  } catch (...) {
    return (xtd::forms::control&)xtd::forms::control::null;
  }
}

xtd::forms::control& xtd::forms::control::from_handle(intptr_t handle) {
  try {
    if (handles_.find(handle) != handles_.end())
      return *handles_[handle];
    return (xtd::forms::control&)xtd::forms::control::null;
  } catch (...) {
    return (xtd::forms::control&)xtd::forms::control::null;
  }
}

bool xtd::forms::control::is_null() const {
  return this == &control::null;
}

void xtd::forms::control::on_create_control() {
}

void xtd::forms::control::on_click(const xtd::event_args &e) {
  this->click(*this, e);
}

void xtd::forms::control::on_client_size_changed(const xtd::event_args &e) {
  this->client_size_ = native::control_api::client_size(this->handle_);
  this->client_size_changed(*this, e);
}

void xtd::forms::control::on_double_click(const xtd::event_args &e) {
  this->double_click(*this, e);
}

void xtd::forms::control::on_got_focus(const xtd::event_args &e) {
  this->got_focus(*this, e);
}

void xtd::forms::control::on_handle_created(const xtd::event_args &e) {
  this->handle_created(*this, e);
}

void xtd::forms::control::on_handle_destroyed(const xtd::event_args &e) {
  this->handle_destroyed(*this, e);
}

void xtd::forms::control::on_location_changed(const xtd::event_args &e) {
  this->location_ = native::control_api::location(this->handle_);
  this->location_changed(*this, e);
}

void xtd::forms::control::on_lost_focus(const xtd::event_args &e) {
  this->lost_focus(*this, e);
}

void xtd::forms::control::on_mouse_click(const xtd::forms::mouse_event_args& e) {
  this->mouse_click(*this, e);
}

void xtd::forms::control::on_mouse_double_click(const xtd::forms::mouse_event_args& e) {
  this->mouse_double_click(*this, e);
}

void xtd::forms::control::on_mouse_down(const xtd::forms::mouse_event_args& e) {
  this->mouse_down(*this, e);
}

void xtd::forms::control::on_mouse_enter(const xtd::event_args &e) {
  this->mouse_enter(*this, e);
}

void xtd::forms::control::on_mouse_leave(const xtd::event_args &e) {
  this->mouse_leave(*this, e);
}

void xtd::forms::control::on_mouse_move(const xtd::forms::mouse_event_args& e) {
  this->mouse_move(*this, e);
}

void xtd::forms::control::on_mouse_up(const xtd::forms::mouse_event_args& e) {
  this->mouse_up(*this, e);
}

void xtd::forms::control::on_mouse_wheel(const xtd::forms::mouse_event_args& e) {
  this->mouse_wheel(*this, e);
}

void xtd::forms::control::on_parent_changed(const xtd::event_args &e) {
  this->parent_changed(*this, e);
}

void xtd::forms::control::on_size_changed(const xtd::event_args &e) {
  this->size_ = native::control_api::size(this->handle_);
  this->size_changed(*this, e);
}

void xtd::forms::control::on_text_changed(const xtd::event_args &e) {
  this->text_ = native::control_api::text(this->handle_);
  this->text_changed(*this, e);
}

void xtd::forms::control::on_visible_changed(const xtd::event_args &e) {
  this->visible_ = native::control_api::visible(this->handle_);
  this->visible_changed(*this, e);
}

void xtd::forms::control::wnd_proc(xtd::forms::message& message) {
  //std::cout << xtd::strings::format("receive message [{}]", message) << std::endl;
  switch (message.msg()) {
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
    case WM_SETFOCUS: this->wm_set_focus(message); break;
    case WM_KILLFOCUS: this->wm_kill_focus(message); break;
    //case WM_CHILDACTIVATE: this->def_wnd_proc(message); break;
    case WM_MOUSEWHEEL: this->wm_mouse_wheel(message); break;

    case WM_COMMAND: this->on_click(xtd::event_args::empty); break;
    case WM_MOVE: this->on_location_changed(xtd::event_args::empty); break;
    case WM_SETTEXT: this->on_text_changed(xtd::event_args::empty); break;
    case WM_SIZE: this->on_size_changed(xtd::event_args::empty); break;
    default: this->def_wnd_proc(message); break;
  }
}

intptr_t xtd::forms::control::send_message(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam) {
  return native::control_api::send_message(this->handle_, hwnd, msg, wparam, lparam);
}

void xtd::forms::control::def_wnd_proc(xtd::forms::message& message) {
  native::control_api::def_wnd_proc(message);
  
}

void xtd::forms::control::get_properties() {
  this->client_size_ = native::control_api::client_size(this->handle_);
  this->location_ = native::control_api::location(this->handle_);
  this->size_ = native::control_api::size(this->handle_);
  this->text_ = native::control_api::text(this->handle_);
  this->visible_ = native::control_api::visible(this->handle_);
}

void xtd::forms::control::set_properties() {
  if (this->client_size_ != xtd::drawing::size(-1, -1)) native::control_api::client_size(this->handle_, this->client_size_);
  if (this->location_ != xtd::drawing::point(-1, -1)) native::control_api::location(this->handle_, this->location_);
  if (this->size_ != xtd::drawing::size(-1, -1)) native::control_api::size(this->handle_, this->size_);
  native::control_api::text(this->handle_, this->text_);
  native::control_api::visible(this->handle_, this->visible_);
}

void xtd::forms::control::wm_kill_focus(xtd::forms::message& message) {
  this->def_wnd_proc(message);
  this->on_got_focus(xtd::event_args::empty);
}

void xtd::forms::control::wm_mouse_down(xtd::forms::message& message) {
  this->set_state(xtd::forms::control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  this->def_wnd_proc(message);
  this->on_mouse_down(xtd::forms::mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, this->get_state(xtd::forms::control::state::double_click_fired) ? 2 : 1, 0));
}

void xtd::forms::control::wm_mouse_double_click(xtd::forms::message& message) {
  this->set_state(xtd::forms::control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  this->def_wnd_proc(message);
  this->on_double_click(xtd::event_args::empty);
  this->on_mouse_double_click(xtd::forms::mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, this->get_state(xtd::forms::control::state::double_click_fired) ? 2 : 1, 0));
}

void xtd::forms::control::wm_mouse_enter(xtd::forms::message& message) {
  this->def_wnd_proc(message);
  this->on_mouse_enter(xtd::event_args::empty);
}

void xtd::forms::control::wm_mouse_leave(xtd::forms::message& message) {
  this->def_wnd_proc(message);
  this->on_mouse_leave(xtd::event_args::empty);
}

void xtd::forms::control::wm_mouse_up(xtd::forms::message& message) {
  /*
  if (this->get_state(xtd::forms::control::state::double_click_fired)) {
    this->on_double_click(xtd::event_args::empty);
    this->on_mouse_double_click(xtd::forms::mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, 2, 0));
  } else {
    this->on_click(xtd::event_args::empty);
    this->on_mouse_click(xtd::forms::mouse_event_args(message_to_mouse_buttons(message),{LOWORD(message.lparam()), HIWORD(message.lparam())}, 1, 0));
  }
   */
  this->on_click(xtd::event_args::empty);
  this->on_mouse_click(xtd::forms::mouse_event_args(message_to_mouse_buttons(message),{LOWORD(message.lparam()), HIWORD(message.lparam())}, 1, 0));
  this->def_wnd_proc(message);
  this->on_mouse_up(xtd::forms::mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, 1, 0));
}

void xtd::forms::control::wm_mouse_move(xtd::forms::message& message) {
  this->def_wnd_proc(message);
  this->on_mouse_move(xtd::forms::mouse_event_args(wparam_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, this->get_state(xtd::forms::control::state::double_click_fired) ? 2 : 1, 0));
}

void xtd::forms::control::wm_set_focus(xtd::forms::message& message) {
  this->def_wnd_proc(message);
  this->on_got_focus(xtd::event_args::empty);
}

void xtd::forms::control::wm_mouse_wheel(xtd::forms::message& message) {
  this->def_wnd_proc(message);
  this->on_mouse_wheel(xtd::forms::mouse_event_args(message_to_mouse_buttons(message), {LOWORD(message.lparam()), HIWORD(message.lparam())}, this->get_state(xtd::forms::control::state::double_click_fired) ? 2 : 1, HIWORD(message.wparam())));
}
