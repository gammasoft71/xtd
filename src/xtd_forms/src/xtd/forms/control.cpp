#include <codecvt>
#include <iostream>
#include <set>
#include <xtd/xtd.diagnostics>
#include <xtd/xtd.core>
#include <xtd/xtd.strings>
#include <xtd/drawing/native/graphics.h>
#include <xtd/drawing/native/system_colors.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/message_keys.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/control.h"
#include "../../../include/xtd/forms/form.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  class reentrant_layout {
  public:
    explicit reentrant_layout(control* do_layout) : do_layout_(do_layout) {do_layouts.insert(do_layout_);}
    ~reentrant_layout() {do_layouts.erase(do_layout_);}
    static bool is_reentrant(control* do_laout) {return do_layouts.find(do_laout) != do_layouts.end(); }
  private:
    control* do_layout_ = nullptr;
    static std::set<control*> do_layouts;
  };

  std::set<control*> reentrant_layout::do_layouts;

  bool debug_events = false;
  
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

forms::keys control::modifier_keys_ = forms::keys::none;
forms::mouse_buttons control::mouse_buttons_ = forms::mouse_buttons::none;
map<intptr_t, control*> control::handles_;
control::control_collection control::top_level_controls_;

control::control() {
  native::control::init();
  if (!application::message_loop() && cursor::current() == cursor::none) cursor::current(cursors::wait_cursor());
  this->set_state(state::enabled, true);
  this->set_state(state::visible, true);
  this->set_style(control_styles::all_painting_in_wm_paint | control_styles::user_paint | control_styles::standard_click | control_styles::standard_double_click | control_styles::use_text_for_accessibility | control_styles::selectable, true);
  this->size_ = this->default_size();
  this->controls_.item_added += [&](size_t, std::reference_wrapper<control> item) {
    item.get().parent_ = handle_;
    if (handle_) {
      item.get().create_control();
      item.get().on_parent_changed(event_args::empty);
      this->on_control_added(control_event_args(item.get()));
    }
  };
  
  this->controls_.item_erased += [&](size_t, std::reference_wrapper<control> item) {
    item.get().parent_ = 0;
    item.get().destroy_control();
    this->on_control_removed(control_event_args(item.get()));
  };
}

control::~control() {
  this->destroy_control();
}

control& control::anchor(anchor_styles anchor) {
  if (this->anchor_ != anchor) {
    this->anchor_ = anchor;
    this->set_state(state::docked, false);
    this->on_layout(event_args::empty);
  }
  return *this;
}

control& control::auto_size(bool auto_size) {
  if (this->get_state(state::auto_size) != auto_size) {
    this->set_state(state::auto_size, auto_size);
    this->on_auto_size_changed(event_args::empty);
  }
  return *this;
}

control& control::back_color(const color& color) {
  if (this->back_color_ != color) {
    this->back_color_ = color;
    native::control::back_color(handle_, this->back_color_.value());
    this->on_back_color_changed(event_args::empty);
    for (auto control : this->controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
  return *this;
}

bool control::can_focus() const {
  bool visible_and_enebled = handle_ && this->get_state(state::visible) && this->get_state(state::enabled);

  std::optional<std::reference_wrapper<control>> top_level_control = const_cast<control&>(*this);
  while (visible_and_enebled && top_level_control.has_value() && !top_level_control.value().get().get_state(state::top_level)) {
    top_level_control = top_level_control.value().get().parent();
    if (top_level_control.has_value()) visible_and_enebled = top_level_control.value().get().get_state(state::visible) && this->get_state(state::enabled);
  }
  
  if (!visible_and_enebled) return false;
  return this->can_focus_;
}

control& control::cursor(const forms::cursor &cursor) {
  if (this->cursor_ != cursor) {
    this->cursor_ = cursor;
    native::control::cursor(handle_, this->cursor_.value().handle());
    this->on_cursor_changed(event_args::empty);
    for (auto control : this->controls())
      control.get().on_parent_cursor_changed(event_args::empty);
  }
  return *this;
}

drawing::font control::default_font() const {
  return native::control::default_font();
}

control& control::dock(dock_style dock) {
  if (this->dock_ != dock) {
    this->dock_ = dock;
    this->set_state(state::docked, true);
    this->on_dock_changed(event_args::empty);
  }
  return *this;
}

control& control::enabled(bool enabled) {
  if (this->get_state(state::enabled) != enabled) {
    this->set_state(state::enabled, enabled);
    native::control::enabled(handle_, this->get_state(state::enabled));
    this->on_enabled_changed(event_args::empty);
  }
  return *this;
}

control& control::fore_color(const color& color) {
  if (this->fore_color_ != color) {
    this->fore_color_ = color;
    native::control::fore_color(handle_, this->fore_color_.value());
    this->on_fore_color_changed(event_args::empty);
    for (auto control : this->controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
  return *this;
}

control& control::font(const drawing::font& font) {
  if (this->font_ != font) {
    this->font_ = font;
    native::control::font(handle_, this->font_.value());
    this->on_font_changed(event_args::empty);
    for (auto control : this->controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
  return *this;
}

intptr_t control::handle() const {
  return handle_;
}

control& control::parent(const control& parent) {
  if (parent.handle_ != this->parent_) {
    this->parent(nullptr);
    if (parent.handle_) const_cast<control&>(parent).controls_.push_back(*this);
  } else if (parent.handle_ == 0 && this->parent_ == 0)
    const_cast<control&>(parent).controls_.push_back(*this);
  return *this;
}

control& control::parent(nullptr_t) {
  if (this->parent_ != 0) {
    for (size_t index = 0; index < this->parent().value().get().controls_.size(); index++) {
      if (this->parent().value().get().controls_[index].get().handle_ == handle_) {
        this->parent().value().get().controls_.erase_at(index);
        break;
      }
    }
  }
  return *this;
}

control& control::text(const std::string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    native::control::text(handle_, this->text_);
    this->on_text_changed(event_args::empty);
  }
  return *this;
}

std::optional<std::reference_wrapper<control>> control::top_level_control() const {
  std::optional<std::reference_wrapper<control>> top_level_control = const_cast<control&>(*this);
  while (top_level_control.has_value() && !top_level_control.value().get().get_state(state::top_level))
    top_level_control = top_level_control.value().get().parent();
  if (top_level_control.has_value() && !top_level_control.value().get().get_state(state::top_level)) top_level_control.reset();
  return top_level_control;
}

control& control::visible(bool visible) {
  if (this->get_state(state::visible) != visible) {
    this->set_state(state::visible, visible);
    native::control::visible(handle_, this->get_state(state::visible));
    this->on_visible_changed(event_args::empty);
  }
  return *this;
}

void control::create_control() {
  this->suspend_layout();
  if (!this->get_state(state::destroying) && !this->get_state(state::creating) && !this->get_state(state::created)) {
    this->set_state(state::destroyed, false);
    this->set_state(state::creating, true);
    this->create_handle();
    if (!this->parent_) top_level_controls_.push_back(control_ref(*this));
    this->send_message(handle_, WM_CREATE, 0, 0);
    this->on_create_control();
    this->set_state(state::creating, false);
    this->set_state(state::created, true);
    this->resume_layout();
  }
}

void control::destroy_control() {
  if (this->get_state(state::created)) {
    this->suspend_layout();
    this->set_state(state::created, false);
    this->set_state(state::destroying, true);
    if (handle_) {
      for(control_ref child : this->controls_)
        child.get().destroy_control();
      
      if (this->parent_ != 0 && this->parent().has_value() && !this->parent().value().get().get_state(state::destroying))
        this->parent(nullptr);
      else {
        for (size_t index = 0; index < top_level_controls_.size(); index++) {
          if (top_level_controls_[index].get().handle_ == handle_) {
            top_level_controls_.erase_at(index);
            break;
          }
        }
      }
      this->destroy_handle();
    }
    this->set_state(state::destroying, false);
    this->set_state(state::destroyed, true);
  }
}

graphics control::create_graphics() const {
  return graphics(native::control::create_graphics(handle_));
}

void control::create_handle() {
  this->set_state(state::creating_handle, true);
  handle_ = native::control::create(this->create_params());
  this->on_handle_created(event_args::empty);
  this->set_state(state::creating_handle, false);
}

void control::destroy_handle() {
  if (handle_) native::control::unregister_wnd_proc(handle_, {*this, &control::wnd_proc_});
  handles_.erase(handle_);
  this->on_handle_destroyed(event_args::empty);
  native::control::destroy(handle_);
  handle_ = 0;
}

bool control::focus() {
  if (!handle_ || !this->can_focus_) return false;
  native::control::focus(handle_);
  this->focused_ = true;
  return true;
}

std::optional<std::reference_wrapper<control>> control::from_child_handle(intptr_t handle) {
  try {
    if (handles_.find(handle) != handles_.end())
      return handles_[handle]->parent();
    return std::optional<std::reference_wrapper<control>>();
  } catch (...) {
    return std::optional<std::reference_wrapper<control>>();
  }
}

std::optional<std::reference_wrapper<control>> control::from_handle(intptr_t handle) {
  try {
    if (handles_.find(handle) != handles_.end())
      return *handles_[handle];
    return std::optional<std::reference_wrapper<control>>();
  } catch (...) {
    return std::optional<std::reference_wrapper<control>>();
  }
}

void control::invalidate(const drawing::rectangle& rect, bool invalidate_children) const {
  native::control::invalidate(handle_, rect, true);
  if (invalidate_children)
    for ( auto child : controls_)
      child.get().invalidate(rect, invalidate_children);
}

bool control::is_handle_created() const {
  return handle_ != 0;
}

control::async_result_invoke control::begin_invoke(delegate<void(std::vector<std::any>)> value, const std::vector<std::any>& args) {
  while (!xtd::forms::application::message_loop()) std::this_thread::sleep_for(10ms);
  async_result_invoke async;
  async.async_mutex().lock();
  native::control::invoke_in_control_thread(handle_, value, args, async.async_mutex_);
  std::this_thread::yield();
  return async;
}

void control::end_invoke(async_result_invoke async) {
  std::lock_guard<std::shared_mutex> lock(async.async_mutex());
}

forms::create_params control::create_params() const {
  forms::create_params create_params;
  
  create_params.caption(this->text_);
  create_params.style(WS_VISIBLE | WS_CHILD);
  if (this->parent_) create_params.parent(this->parent().value().get().handle_);
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
  this->on_layout(e);
  if (this->can_raise_events()) this->auto_size_changed(*this, e);
}

void control::on_back_color_changed(const event_args &e) {
  this->refresh();
  if (this->can_raise_events()) this->back_color_changed(*this, e);
}

void control::on_create_control() {
  for (auto control : this->controls_) {
    control.get().parent_ = handle_;
    control.get().create_control();
  }
  this->on_layout(event_args::empty);
}

void control::on_click(const event_args &e) {
  if (this->can_raise_events()) this->click(*this, e);
}

void control::on_client_size_changed(const event_args &e) {
  this->on_layout(e);
  this->refresh();
  if (this->can_raise_events()) this->client_size_changed(*this, e);
}

void control::on_control_added(const control_event_args &e) {
  this->on_layout(event_args::empty);
  this->size_changed += {e.control(), &control::on_parent_size_changed};
  if (this->can_raise_events()) this->control_added(*this, e);
}

void control::on_control_removed(const control_event_args &e) {
  this->on_layout(event_args::empty);
  this->size_changed -= {e.control(), &control::on_parent_size_changed};
  if (this->can_raise_events()) this->control_removed(*this, e);
}

void control::on_cursor_changed(const event_args &e) {
  if (this->can_raise_events()) this->cursor_changed(*this, e);
}

void control::on_dock_changed(const event_args &e) {
  if (this->parent().has_value()) this->parent().value().get().on_layout(e);
  this->on_layout(e);
  if (this->can_raise_events()) this->dock_changed(*this, e);
}

void control::on_double_click(const event_args &e) {
  if (this->can_raise_events()) this->double_click(*this, e);
}

void control::on_enabled_changed(const event_args &e) {
  this->set_state(state::enabled, native::control::enabled(handle_));
  this->refresh();
  if (this->can_raise_events()) this->enabled_changed(*this, e);
}

void control::on_fore_color_changed(const event_args &e) {
  this->refresh();
  if (this->can_raise_events()) this->fore_color_changed(*this, e);
}

void control::on_font_changed(const event_args &e) {
  do_layout_parent();
  this->on_layout(event_args::empty);
  if (this->can_raise_events()) this->font_changed(*this, e);
}

void control::on_got_focus(const event_args &e) {
  this->focused_ = true;
  if (this->can_raise_events()) this->got_focus(*this, e);
}

void control::on_handle_created(const event_args &e) {
  native::control::register_wnd_proc(handle_, {*this, &control::wnd_proc_});
  handles_[handle_] = this;
  if (this->get_state(state::client_size_setted)) native::control::client_size(handle_, this->client_size());
  if (drawing::native::system_colors::force_set_system_color() || (this->back_color_.has_value() && this->back_color_.value() != this->default_back_color()) || (!environment::os_version().is_macos_platform() && this->back_color() != this->default_back_color())) native::control::back_color(handle_, this->back_color());
  if (this->cursor_.has_value() && this->cursor_.value() != this->default_cursor()) native::control::cursor(handle_, this->cursor().handle());
  if (drawing::native::system_colors::force_set_system_color() || this->fore_color_.has_value() || this->fore_color() != this->default_fore_color()) native::control::fore_color(handle_, this->fore_color());
  if (this->font_.has_value() || this->font() != this->default_font()) native::control::font(handle_, this->font());
  native::control::enabled(handle_, this->enabled());
  native::control::visible(handle_, this->visible());
  if (this->focused()) native::control::focus(handle_);

  this->client_rectangle_ = native::control::client_rectangle(handle_);
  this->client_size_ = native::control::client_size(handle_);
  this->location_ = native::control::location(handle_);
  this->size_ = native::control::size(handle_);

  if (this->can_raise_events()) handle_created(*this, e);
  
  do_layout_parent();
  this->on_layout(event_args::empty);
}

void control::on_handle_destroyed(const event_args &e) {
  if (this->can_raise_events()) handle_destroyed(*this, e);
}

void control::on_key_down(key_event_args& e) {
  if (this->can_raise_events()) this->key_down(*this, e);
}

void control::on_key_press(key_press_event_args& e) {
  if (this->can_raise_events()) this->key_press(*this, e);
}

void control::on_key_up(key_event_args& e) {
  if (this->can_raise_events()) this->key_up(*this, e);
}

void control::on_layout(const event_args &e) {
  do_layout();
  if (this->can_raise_events()) this->layout(*this, e);
}

void control::on_location_changed(const event_args &e) {
  do_layout_parent();
  if (this->can_raise_events()) this->location_changed(*this, e);
}

void control::on_lost_focus(const event_args &e) {
  this->focused_ = false;
  if (this->can_raise_events()) this->lost_focus(*this, e);
}

void control::on_mouse_click(const mouse_event_args& e) {
  if (this->can_raise_events()) this->mouse_click(*this, e);
}

void control::on_mouse_double_click(const mouse_event_args& e) {
  if (this->can_raise_events()) this->mouse_double_click(*this, e);
}

void control::on_mouse_down(const mouse_event_args& e) {
  if (this->can_raise_events()) this->mouse_down(*this, e);
}

void control::on_mouse_horizontal_wheel(const mouse_event_args& e) {
  if (this->can_raise_events()) this->mouse_horizontal_wheel(*this, e);
}

void control::on_mouse_enter(const event_args &e) {
  if (this->can_raise_events()) this->mouse_enter(*this, e);
}

void control::on_mouse_leave(const event_args &e) {
  if (this->can_raise_events()) this->mouse_leave(*this, e);
}

void control::on_mouse_move(const mouse_event_args& e) {
  if (this->can_raise_events()) this->mouse_move(*this, e);
}

void control::on_mouse_up(const mouse_event_args& e) {
  if (this->can_raise_events()) this->mouse_up(*this, e);
}

void control::on_mouse_wheel(const mouse_event_args& e) {
  if (this->can_raise_events()) this->mouse_wheel(*this, e);
}

void control::on_paint(paint_event_args &e) {
  if (this->can_raise_events()) this->paint(*this, e);
}

void control::on_parent_back_color_changed(const event_args &e) {
  if (!this->back_color_.has_value()) {
    if (this->back_color() == this->default_back_color())
      this->recreate_handle();
    else if (!environment::os_version().is_macos_platform())
      native::control::back_color(handle_, this->back_color());
    for (auto control : this->controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
}

void control::on_parent_changed(const event_args &e) {
  if (this->parent().has_value()) this->parent_size_ = this->parent().value().get().get_state(state::client_size_setted) ? this->parent().value().get().client_size() :  this->parent().value().get().size();
  if (this->can_raise_events()) this->parent_changed(*this, e);
}

void control::on_parent_cursor_changed(const event_args &e) {
}

void control::on_parent_fore_color_changed(const event_args &e) {
  if (!this->fore_color_.has_value()) {
    native::control::fore_color(handle_, this->fore_color());
    for (auto control : this->controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
}

void control::on_parent_font_changed(const event_args &e) {
  if (!this->font_.has_value()) {
    native::control::font(handle_, this->font());
    for (auto control : this->controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
}

void control::on_resize(const event_args &e) {
  if (this->can_raise_events()) this->resize(*this, e);
}

void control::on_size_changed(const event_args &e) {
  do_layout_parent();
  this->client_rectangle_ = native::control::client_rectangle(handle_);
  this->on_layout(e);
  this->refresh();
  if (this->can_raise_events()) this->size_changed(*this, e);
}

void control::on_text_changed(const event_args &e) {
  do_layout_parent();
  this->on_layout(event_args::empty);
  if (this->can_raise_events()) this->text_changed(*this, e);
}

void control::on_visible_changed(const event_args &e) {
  this->set_state(state::visible, native::control::visible(handle_));
  if (this->focused())
    this->focus();
  for (auto item : this->controls_)
    if (item.get().focused()) item.get().focus();
  do_layout_parent();
  if (this->can_raise_events()) this->visible_changed(*this, e);
}

void control::perform_layout() {
  if (!this->get_state(state::layout_deferred))
    on_layout(event_args::empty);
}

drawing::point control::point_to_client(const xtd::drawing::point &p) {
  return native::control::point_to_client(handle_, p);
}

drawing::point control::point_to_screen(const xtd::drawing::point &p) {
  return native::control::point_to_screen(handle_, p);
}

void control::refresh() const {
  native::control::refresh(handle_);
}

intptr_t control::send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) const {
  return native::control::send_message(handle_, hwnd, msg, wparam, lparam);
}

void control::set_auto_size_mode(auto_size_mode auto_size_mode) {
  if (this->auto_size_mode_ != auto_size_mode) {
    this->auto_size_mode_ = auto_size_mode;
    this->on_layout(event_args::empty);
  }
}

std::string control::to_string() const {
  if (!this->name_.empty()) return strings::format("{}, name: {}", strings::full_class_name(*this), this->name_);
  if (!this->text_.empty()) return strings::format("{}, text: {}", strings::full_class_name(*this), this->text_);
  return strings::full_class_name(*this);
}

void control::update() const {
  native::control::update(handle_);
}

intptr_t control::wnd_proc_(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
  try {
    message message = forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
    wnd_proc(message);
    return message.result();
  } catch(const std::exception& e) {
    message_box::show(xtd::strings::format("message: {}", e.what()), xtd::strings::format("Exception {}", xtd::strings::class_name(e)), message_box_buttons::ok, message_box_icon::error);
  } catch(...) {
    message_box::show("message: An unknown exception occure", "Unknown Exception", message_box_buttons::ok, message_box_icon::error);
  }
  return 0;
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
  message.result(native::control::def_wnd_proc(handle_, message.hwnd(), message.msg(),message.wparam(), message.lparam(), message.result(), message.handle()));
}

void control::recreate_handle() {
  if (handle_ != 0) {
    this->set_state(state::recreate, true);
    for (auto control : this->controls()) control.get().set_state(state::parent_recreating, true);

    this->on_handle_destroyed(event_args::empty);
    intptr_t old_handle = handle_;
    handle_ = 0;
    this->create_handle();
    for (auto control : this->controls()) {
      control.get().parent_ = handle_;
      control.get().recreate_handle();
    }
    intptr_t new_handle = handle_;
    handle_ = old_handle;
    this->destroy_handle();
    handle_ = new_handle;

    for (auto control : this->controls()) control.get().set_state(state::parent_recreating, false);
    this->set_state(state::recreate, false);
  }
}

void control::set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {
  if ((specified & bounds_specified::x) == bounds_specified::x) this->location_.x(x);
  if ((specified & bounds_specified::y) == bounds_specified::y) this->location_.y(y);
  if ((specified & bounds_specified::width) == bounds_specified::width) this->size_.width(width);
  if ((specified & bounds_specified::height) == bounds_specified::height) this->size_.height(height);
  
  if ((specified & bounds_specified::x) == bounds_specified::x || (specified & bounds_specified::y) == bounds_specified::y) {
    native::control::location(handle_, this->location_);
    this->on_location_changed(event_args::empty);
    do_layout_parent();
    this->on_layout(event_args::empty);
  }
  
  if ((specified & bounds_specified::width) == bounds_specified::width || (specified & bounds_specified::height) == bounds_specified::height) {
    native::control::size(handle_, this->size_);
    this->on_client_size_changed(event_args::empty);
    this->on_size_changed(event_args::empty);
    do_layout_parent();
    this->on_layout(event_args::empty);
  }
}

void control::set_client_size_core(int32_t width, int32_t height) {
  this->client_size_.width(width);
  this->client_size_.height(height);
  
  native::control::client_size(handle_, this->client_size_);
  this->on_client_size_changed(event_args::empty);
  this->on_size_changed(event_args::empty);
}

void control::do_layout_parent() {
  if (!this->parent_) return;
  control* parent = &this->parent().value().get();
  if (parent->get_state(state::auto_size))
    parent->on_layout(event_args::empty);
}

void control::do_layout() {
  if (this->get_state(state::layout_deferred) || reentrant_layout::is_reentrant(this)) return;
  reentrant_layout reentrant_laout(this);
  
  // do_layout_parent();
  this->do_layout_childs_with_dock_style();
  this->do_layout_with_anchor_styles();
  this->do_layout_with_auto_size_mode();
}

void control::on_parent_size_changed(const control& sender, const event_args& e) {
  if (!this->get_state(state::layout_deferred)) {
    this->on_layout(event_args::empty);
    this->parent_size_ = this->parent().value().get().get_state(state::client_size_setted) ? this->parent().value().get().client_size() :  this->parent().value().get().size();
  }
}

void control::do_layout_childs_with_dock_style() {
  bool docked = false;
  for(control_ref control : this->controls_) {
    docked = control.get().get_state(state::docked);
    if (docked) break;
  }

  if (docked) {
    drawing::rectangle docking_rect = this->client_rectangle();
    docking_rect.left(docking_rect.left() + padding_.left());
    docking_rect.top(docking_rect.top() + padding_.top());
    docking_rect.width(docking_rect.width() - padding_.left() - padding_.right());
    docking_rect.height(docking_rect.height() - padding_.top() - padding_.bottom());
    for(control_collection::reverse_iterator iterator = this->controls_.rbegin(); iterator != this->controls_.rend(); ++iterator) {
      if (!iterator->get().visible()) continue;
      if (iterator->get().dock() == dock_style::top) {
        iterator->get().location({docking_rect.left(), docking_rect.top()});
        iterator->get().width(docking_rect.width());
        docking_rect.top(docking_rect.top() + iterator->get().height());
        docking_rect.height(docking_rect.height() - iterator->get().height());
      } else if (iterator->get().dock() == dock_style::bottom) {
        iterator->get().location({docking_rect.left(), docking_rect.bottom() - iterator->get().height()});
        iterator->get().width(docking_rect.width());
        docking_rect.height(docking_rect.height() - iterator->get().height());
      } else if (iterator->get().dock() == dock_style::left) {
        iterator->get().location({docking_rect.left(), docking_rect.top()});
        iterator->get().height(docking_rect.height());
        docking_rect.left(docking_rect.left() + iterator->get().width());
        docking_rect.width(docking_rect.width() - iterator->get().width());
      } else if (iterator->get().dock() == dock_style::right) {
        iterator->get().location({docking_rect.right() - iterator->get().width(), docking_rect.top()});
        iterator->get().height(docking_rect.height());
        docking_rect.width(docking_rect.width() - iterator->get().width());
      } else if (iterator->get().dock() == dock_style::fill) {
        iterator->get().location({docking_rect.left(), docking_rect.top()});
        iterator->get().size({docking_rect.width(), docking_rect.height()});
      }
    }
  }
}

void control::do_layout_with_anchor_styles() {
  if (this->parent().has_value()) {
    point diff = (this->parent().value().get().get_state(state::client_size_setted) ? this->parent().value().get().client_size() :  this->parent().value().get().size()) - this->parent_size_;

    if ((this->anchor_ & anchor_styles::left) == anchor_styles::left && (this->anchor_ & anchor_styles::right) != anchor_styles::right)
      this->left(this->left());
    else if ((this->anchor_ & anchor_styles::left) == anchor_styles::left && (this->anchor_ & anchor_styles::right) == anchor_styles::right)
      this->width(this->width() + diff.x());
    else if ((this->anchor_ & anchor_styles::left) != anchor_styles::left && (this->anchor_ & anchor_styles::right) == anchor_styles::right)
      this->left(this->left() + diff.x());
    else
      this->left(this->left() + (diff.x() / 2));

    if ((this->anchor_ & anchor_styles::top) == anchor_styles::top && (this->anchor_ & anchor_styles::bottom) != anchor_styles::bottom)
      this->top(this->top());
    else if ((this->anchor_ & anchor_styles::top) == anchor_styles::top && (this->anchor_ & anchor_styles::bottom) == anchor_styles::bottom)
      this->height(this->height() + diff.y());
    else if ((this->anchor_ & anchor_styles::top) != anchor_styles::top && (this->anchor_ & anchor_styles::bottom) == anchor_styles::bottom)
      this->top(this->top() + diff.y());
    else
      this->top(this->top() + (diff.y() / 2));
  }

}

void control::do_layout_with_auto_size_mode() {
  if (this->get_state(state::auto_size)) {
    drawing::size auto_size_size_ = this->measure_control();
    if (this->auto_size_mode_ == auto_size_mode::grow_only && auto_size_size_.width() < this->client_size_.width())
      auto_size_size_.width(this->client_size_.width());
    if (this->auto_size_mode_ == auto_size_mode::grow_only && auto_size_size_.height() < this->client_size_.height())
      auto_size_size_.height(this->client_size_.height());
    this->client_size(auto_size_size_);
  }
}

void control::wm_child_activate(message& message) {
  this->def_wnd_proc(message);
}

void control::wm_command(message& message) {
  this->def_wnd_proc(message);
  if (message.lparam() != 0)
    from_handle(message.lparam()).value().get().send_message(message.hwnd(), WM_REFLECT + message.msg(), message.wparam(), message.lparam());
}

void control::wm_key_char(message& message) {
  if (message.msg() == WM_KEYDOWN || message.msg ()== WM_SYSKEYDOWN) {
    key_event_args key_event_args(static_cast<keys>(message.wparam()));
    modifier_keys_ = key_event_args.modifiers();
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
    modifier_keys_ = key_event_args.modifiers();
    this->on_key_up(key_event_args);
    message.result(key_event_args.handled());
    if (!key_event_args.handled()) this->def_wnd_proc(message);
  } else
    this->def_wnd_proc(message);
}

void control::wm_kill_focus(message& message) {
  this->def_wnd_proc(message);
  this->on_lost_focus(event_args::empty);
}

void control::wm_mouse_down(message& message) {
  this->def_wnd_proc(message);
  this->set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, this->get_state(state::double_click_fired));
  mouse_buttons_ |= e.button();
  this->on_mouse_down(e);
}

void control::wm_mouse_double_click(message& message) {
  this->def_wnd_proc(message);
  this->set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  this->on_double_click(event_args::empty);
  this->on_mouse_double_click(mouse_event_args::create(message, this->get_state(state::double_click_fired)));
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
  mouse_event_args e = mouse_event_args::create(message);
  mouse_buttons_ &= ~e.button();
  if (e.button() == mouse_buttons::left) this->on_click(event_args::empty);
  this->on_mouse_click(e);
  this->on_mouse_up(e);
}

void control::wm_mouse_move(message& message) {
  this->def_wnd_proc(message);
  this->on_mouse_move(mouse_event_args(wparam_to_mouse_buttons(message), this->point_to_client({(int32_t)LOWORD(message.lparam()), (int32_t)HIWORD(message.lparam())}), this->get_state(control::state::double_click_fired) ? 2 : 1, 0));
}

void control::wm_move(message& message) {
  this->def_wnd_proc(message);
  if (this->location_ != native::control::location(handle_)) {
    this->location_ = native::control::location(handle_);
    this->on_location_changed(event_args::empty);
  }
}

void control::wm_mouse_wheel(message& message) {
  this->def_wnd_proc(message);
  if (message.msg() == WM_MOUSEHWHEEL)
    this->on_mouse_horizontal_wheel(mouse_event_args::create(message, this->get_state(state::double_click_fired), static_cast<int32_t>(HIWORD(message.wparam()))));
  else
    this->on_mouse_wheel(mouse_event_args::create(message, this->get_state(state::double_click_fired), static_cast<int32_t>(HIWORD(message.wparam()))));
}

void control::wm_paint(message& message) {
  this->def_wnd_proc(message);
  paint_event_args e(this->client_rectangle_, *this, get_state(state::double_buffered));
  this->on_paint(e);
}

void control::wm_scroll(message& message) {
  this->def_wnd_proc(message);
  if (message.lparam() != 0)
    from_handle(message.lparam()).value().get().send_message(message.hwnd(), WM_REFLECT + message.msg(), message.wparam(), message.lparam());
}

void control::wm_set_focus(message& message) {
  this->def_wnd_proc(message);
  this->on_got_focus(event_args::empty);
}

void control::wm_set_text(message& message) {
  this->def_wnd_proc(message);
  if (this->text_ != reinterpret_cast<const char*>(message.lparam())) {
    this->text_ = reinterpret_cast<const char*>(message.lparam());
    this->on_text_changed(event_args::empty);
  }
}

void control::wm_size(message& message) {
  this->def_wnd_proc(message);
  if (this->client_size_ != native::control::client_size(handle_)) {
    this->client_size_ = native::control::client_size(handle_);
    this->on_client_size_changed(event_args::empty);
  }
  if (this->size_ != native::control::size(handle_)) {
    this->size_ = native::control::size(handle_);
    this->on_size_changed(event_args::empty);
  }
  this->on_resize(event_args::empty);
}
