#include <iostream>
#include <xtd/xtd.diagnostics>
#include <xtd/xtd.environment>
#include <xtd/xtd.strings>
#include <xtd/drawing/native/graphics.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/window_message_keys.hpp>
#include <xtd/forms/native/window_styles.hpp>
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

const control control::null {"null", true};

map<intptr_t, control*> control::handles_;
std::map<control::data*, std::shared_ptr<control>> control::controls_;
control::control_collection control::top_level_controls_;

control::control() {
  //make_control(*this);
  native::control::init();
  this->data_->size_ = this->default_size();
  this->data_->controls_.item_added += [&](size_t, std::reference_wrapper<control> item) {
    item.get().data_->parent_ = this->data_->handle_;
    if (this->data_->handle_) {
      item.get().create_control();
      if (item.get().data_->handle_) native::control::parent(item.get().data_->handle_, this->data_->handle_);
      item.get().on_parent_changed(event_args::empty);
    }
  };

  this->data_->controls_.item_erased += [&](size_t, std::reference_wrapper<control> item) {
    item.get().data_->parent_ = 0;
    item.get().destroy_handle();
  };
}

control& control::operator=(const control& value) {
  if (this->data_.use_count() == 1) destroy_control();
  this->back_color_changed = value.back_color_changed;
  this->click = value.click;
  this->auto_size_changed = value.auto_size_changed;
  this->client_size_changed = value.client_size_changed;
  this->double_click = value.double_click;
  this->got_focus = value.got_focus;
  this->handle_created = value.handle_created;
  this->handle_destroyed = value.handle_destroyed;
  this->enabled_changed = value.enabled_changed;
  this->fore_color_changed = value.fore_color_changed;
  this->font_changed = value.font_changed;
  this->key_down = value.key_down;
  this->key_press = value.key_press;
  this->key_up = value.key_up;
  this->location_changed = value.location_changed;
  this->lost_focus = value.lost_focus;
  this->mouse_click = value.mouse_click;
  this->mouse_double_click = value.mouse_double_click;
  this->mouse_down = value.mouse_down;
  this->mouse_enter = value.mouse_enter;
  this->mouse_horizontal_wheel = value.mouse_horizontal_wheel;
  this->mouse_leave = value.mouse_leave;
  this->mouse_move = value.mouse_move;
  this->mouse_up = value.mouse_up;
  this->mouse_wheel = value.mouse_wheel;
  this->paint = value.paint;
  this->parent_changed = value.parent_changed;
  this->size_changed = value.size_changed;
  this->text_changed = value.text_changed;
  this->visible_changed = value.visible_changed;
  this->data_ = value.data_;
  return *this;
}

control::~control() {
  if (this->data_.use_count() == 1)
    destroy_control();
}

control& control::auto_size(bool auto_size) {
  if (this->data_->auto_size_ != auto_size) {
    this->data_->auto_size_ = auto_size;
    this->on_auto_size_changed(event_args::empty);
  }
  return *this;
}

control& control::back_color(const color& color) {
  if (this->data_->back_color_ != color) {
    this->data_->back_color_ = color;
    native::control::back_color(this->data_->handle_, this->data_->back_color_.value());
    this->on_back_color_changed(event_args::empty);
    for (auto control : this->controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
  return *this;
}

control& control::client_size(const drawing::size& size) {
  if (this->data_->client_size_ != size) {
    this->data_->client_size_ = size;
    native::control::client_size(this->data_->handle_, this->data_->client_size_);
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
  if (this->data_->enabled_ != enabled) {
    this->data_->enabled_ = enabled;
    native::control::enabled(this->data_->handle_, this->data_->enabled_);
    this->on_enabled_changed(event_args::empty);
  }
  return *this;
}

control& control::fore_color(const color& color) {
  if (this->data_->fore_color_ != color) {
    this->data_->fore_color_ = color;
    native::control::fore_color(this->data_->handle_, this->data_->fore_color_.value());
    this->on_fore_color_changed(event_args::empty);
    for (auto control : this->controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
  return *this;
}

control& control::font(const drawing::font& font) {
  if (this->data_->font_ != font) {
    this->data_->font_ = font;
    native::control::font(this->data_->handle_, this->data_->font_.value());
    this->on_font_changed(event_args::empty);
    for (auto control : this->controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
  return *this;
}

intptr_t control::handle() const {
  return this->data_->handle_;
}

control& control::location(const point& location) {
  if (this->data_->location_ != location) {
    this->data_->location_ = location;
    native::control::location(this->data_->handle_, this->data_->location_);
  }
  return *this;
}

control& control::parent(const control& parent) {
  if (&this->parent() != &parent) {
    if (this->data_->parent_ != 0) {
      for (size_t index = 0; index < this->parent().data_->controls_.size(); index++) {
        if (this->parent().data_->controls_[index].get().data_.get() == this->data_.get()) {
           this->parent().data_->controls_.erase_at(index);
          break;
        }
      }
    }
    if (&parent != &control::null) const_cast<control&>(parent).data_->controls_.push_back(ref_control(*controls_[this->control::data_.get()]));
  }
  return *this;
}

control& control::size(const drawing::size& size) {
  if (this->data_->size_ != size) {
    this->data_->size_ = size;
    native::control::size(this->data_->handle_, this->data_->size_);
  }
  return *this;
}

control& control::text(const string& text) {
  if (this->data_->text_ != text) {
    this->data_->text_ = text;
    native::control::text(this->data_->handle_, this->data_->text_);
  }
  return *this;
}

control& control::visible(bool visible) {
  if (this->data_->visible_ != visible) {
    this->data_->visible_ = visible;
    native::control::visible(this->data_->handle_, this->data_->visible_);
    this->on_visible_changed(event_args::empty);
  }
  return *this;
}

void control::create_control() {
  if (!this->data_->handle_) {
    this->create_handle();
    if (!this->data_->parent_) top_level_controls_.push_back(ref_control(*controls_[this->control::data_.get()]));
    this->send_message(this->data_->handle_, WM_CREATE, 0, 0);
    this->on_create_control();
  }
}

void control::destroy_control() {
  if (this->data_->handle_) {
    if (this->data_->parent_ == 0) {
      for (size_t index = 0; index < top_level_controls_.size(); index++) {
        if (&top_level_controls_[index].get() == this) {
          top_level_controls_.erase_at(index);
          break;
        }
      }
    }
    native::control::erase(this->data_->handle_);
    this->data_->handle_ = 0;
    this->destroy_handle();
  }
}

graphics control::create_graphics() const {
  return graphics(native::control::create_graphics(this->data_->handle_));
}

void control::create_handle() {
  this->data_->handle_ = native::control::create(this->create_params());
  this->on_handle_created(event_args::empty);
}

void control::destroy_handle() {
  this->internal_destroy_handle(this->data_->handle_);
  this->data_->handle_ = 0;
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
  return this->data_->handle_ != 0;
}

bool control::is_null() const {
  return this == &control::null;
}

forms::create_params control::create_params() const {
  forms::create_params create_params;
  
  create_params.caption(this->data_->text_);
  create_params.style(WS_VISIBLE | WS_CHILD);
  if (this->data_->parent_) create_params.parent(this->parent().data_->handle_);
  create_params.location(this->data_->location_);
  create_params.size(this->data_->size_);

  return create_params;
}

void control::on_auto_size_changed(const event_args& e) {
  this->auto_size_changed(*this, e);
}

void control::on_back_color_changed(const event_args &e) {
  this->refresh();
  this->back_color_changed(*this, e);
}

void control::on_create_control() {
  for (auto control : this->data_->controls_)
    control.get().create_control();
}

void control::on_click(const event_args &e) {
  this->click(*this, e);
}

void control::on_client_size_changed(const event_args &e) {
  this->data_->client_size_ = native::control::client_size(this->data_->handle_);
  this->client_size_changed(*this, e);
}

void control::on_double_click(const event_args &e) {
  this->double_click(*this, e);
}

void control::on_enabled_changed(const event_args &e) {
  this->data_->enabled_ = native::control::enabled(this->data_->handle_);
  this->refresh();
  this->enabled_changed(*this, e);
}

void control::on_fore_color_changed(const event_args &e) {
  this->refresh();
  this->fore_color_changed(*this, e);
}

void control::on_font_changed(const event_args &e) {
  this->refresh();
  this->font_changed(*this, e);
}

void control::on_got_focus(const event_args &e) {
  this->got_focus(*this, e);
}

void control::on_handle_created(const event_args &e) {
  native::control::register_wnd_proc(this->data_->handle_, {*controls_[this->control::data_.get()], &control::wnd_proc_});
  handles_[this->data_->handle_] = controls_[this->control::data_.get()].get();
  if (this->data_->client_size_ != drawing::size(-1, -1)) native::control::client_size(this->data_->handle_, this->client_size());
  if ((this->data_->back_color_.has_value() && this->data_->back_color_.value() != this->default_back_color()) || (!environment::os_version().is_osx_platform() && this->back_color() != this->default_back_color())) native::control::back_color(this->data_->handle_, this->back_color());
  if (this->data_->fore_color_.has_value() || this->fore_color() != this->default_fore_color()) native::control::fore_color(this->data_->handle_, this->fore_color());
  if (this->data_->font_.has_value() || this->font() != this->default_font()) native::control::font(this->data_->handle_, this->font());
  //native::control::visible(this->data_->handle_, this->visible());

  this->data_->client_size_ = native::control::client_size(this->data_->handle_);
  this->data_->location_ = native::control::location(this->data_->handle_);
  this->data_->size_ = native::control::size(this->data_->handle_);

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
  this->data_->location_ = native::control::location(this->data_->handle_);
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
  if (!this->data_->back_color_.has_value()) {
    if (this->back_color() == this->default_back_color())
      this->recreate_handle();
    else if (!environment::os_version().is_osx_platform())
      native::control::back_color(this->data_->handle_, this->back_color());
    for (auto control : this->controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
}

void control::on_parent_changed(const event_args &e) {
  this->parent_changed(*this, e);
}

void control::on_parent_fore_color_changed(const event_args &e) {
  if (!this->data_->fore_color_.has_value()) {
    native::control::fore_color(this->data_->handle_, this->fore_color());
    for (auto control : this->controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
}

void control::on_parent_font_changed(const event_args &e) {
  if (!this->data_->font_.has_value()) {
    native::control::font(this->data_->handle_, this->font());
    for (auto control : this->controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
}

void control::on_size_changed(const event_args &e) {
  this->data_->size_ = native::control::size(this->data_->handle_);
  this->refresh();
  this->size_changed(*this, e);
}

void control::on_text_changed(const event_args &e) {
  this->text_changed(*this, e);
}

void control::on_visible_changed(const event_args &e) {
  this->data_->visible_ = native::control::visible(this->data_->handle_);
  this->refresh();
  this->visible_changed(*this, e);
}

void control::refresh() const {
  native::control::refresh(this->data_->handle_);
}

intptr_t control::send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {
  return native::control::send_message(this->data_->handle_, hwnd, msg, wparam, lparam);
}

string control::to_string() const {
  if (!this->data_->name_.empty()) return strings::format("{}, name: {}", strings::full_class_name(*this), this->data_->name_);
  if (!this->data_->text_.empty()) return strings::format("{}, text: {}", strings::full_class_name(*this), this->data_->text_);
  return strings::full_class_name(*this);
}

intptr_t control::wnd_proc_(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
  message message = forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
  wnd_proc(message);
  return message.result();
}

void control::wnd_proc(message& message) {
  diagnostics::debug::write_line_if(debug_events, strings::format("({}) receive message [{}]", this->data_->name_, message));
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
    default: this->def_wnd_proc(message); break;
  }
}

void control::def_wnd_proc(message& message) {
  message.result(native::control::def_wnd_proc(this->data_->handle_, message.hwnd(), message.msg(),message.wparam(), message.lparam(), message.result(), message.handle()));
}

void control::recreate_handle() {
  if (this->data_->handle_ != 0) {
    intptr_t handle = this->data_->handle_;
    auto controls = this->controls();
    this->internal_destroy_handle(handle);
    this->data_->handle_ = 0;
    this->create_handle();
    for (auto control : controls)
      native::control::parent(control.get().data_->handle_, this->data_->handle_);
  }
}

void control::internal_destroy_handle(intptr_t handle) {
  if (this->data_->handle_) native::control::unregister_wnd_proc(this->data_->handle_, {*controls_[this->control::data_.get()], &control::wnd_proc_});
  handles_.erase(handle);
  native::control::destroy(handle);
  this->on_handle_destroyed(event_args::empty);
}

void control::wm_child_activate(message& message) {
  this->def_wnd_proc(message);
}

void control::wm_command(message& message) {
  this->def_wnd_proc(message);
  if (message.lparam() != 0)
    from_handle(message.lparam()).send_message(message.hwnd(), WM_REFLECT + WM_COMMAND, message.wparam(), message.lparam());
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
  paint_event_args e({{0, 0}, this->client_size()}, *this);
  this->on_paint(e);
}

void control::wm_set_focus(message& message) {
  this->def_wnd_proc(message);
  this->on_got_focus(event_args::empty);
}

void control::wm_set_text(message& message) {
  this->def_wnd_proc(message);
  this->data_->text_ = reinterpret_cast<const char*>(message.lparam());
  this->on_text_changed(event_args::empty);
}

void control::wm_size(message& message) {
  this->def_wnd_proc(message);
  this->on_client_size_changed(event_args::empty);
  this->on_size_changed(event_args::empty);
}
