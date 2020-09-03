#include <codecvt>
#include <iostream>
#include <set>
#include <xtd/xtd.diagnostics>
#include <xtd/xtd.core>
#include <xtd/xtd.strings>
#include <xtd/drawing/system_fonts.h>
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
  set_state(state::enabled, true);
  set_state(state::visible, true);
  set_style(control_styles::all_painting_in_wm_paint | control_styles::user_paint | control_styles::standard_click | control_styles::standard_double_click | control_styles::use_text_for_accessibility | control_styles::selectable, true);
  size_ = default_size();
  controls_.item_added += [&](size_t, std::reference_wrapper<control> item) {
    item.get().parent_ = handle_;
    if (handle_) {
      item.get().create_control();
      item.get().on_parent_changed(event_args::empty);
      on_control_added(control_event_args(item.get()));
    }
  };
  
  controls_.item_erased += [&](size_t, std::reference_wrapper<control> item) {
    item.get().parent_ = 0;
    item.get().destroy_control();
    on_control_removed(control_event_args(item.get()));
  };
}

control::~control() {
  destroy_control();
}

control& control::anchor(anchor_styles anchor) {
  if (anchor_ != anchor) {
    anchor_ = anchor;
    set_state(state::docked, false);
    on_layout(event_args::empty);
  }
  return *this;
}

control& control::auto_size(bool auto_size) {
  if (get_state(state::auto_size) != auto_size) {
    set_state(state::auto_size, auto_size);
    on_auto_size_changed(event_args::empty);
  }
  return *this;
}

color control::back_color() const {
  for (const control* control = this; control; control = control->parent().has_value() ? &control->parent().value().get() : nullptr)
    if (control->back_color_.has_value()) return control->back_color_.value();
  return default_back_color();
}

control& control::back_color(const color& color) {
  if (back_color_ != color) {
    back_color_ = color;
    native::control::back_color(handle_, back_color_.value());
    on_back_color_changed(event_args::empty);
    for (auto& control : controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
  return *this;
}

control& control::back_color(nullptr_t) {
  if (back_color_.has_value()) {
    back_color_.reset();
    recreate_handle();
    on_back_color_changed(event_args::empty);
    for (auto& control : controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
  return *this;
}

bool control::can_focus() const {
  bool visible_and_enebled = handle_ && get_state(state::visible) && get_state(state::enabled);

  std::optional<std::reference_wrapper<control>> top_level_control = const_cast<control&>(*this);
  while (visible_and_enebled && top_level_control.has_value() && !top_level_control.value().get().get_state(state::top_level)) {
    top_level_control = top_level_control.value().get().parent();
    if (top_level_control.has_value()) visible_and_enebled = top_level_control.value().get().get_state(state::visible) && get_state(state::enabled);
  }
  
  if (!visible_and_enebled) return false;
  return can_focus_;
}

forms::cursor control::cursor() const {
  for (const control* control = this; control; control = control->parent().has_value() ? &control->parent().value().get() : nullptr)
    if (control->cursor_.has_value()) return control->cursor_.value();
  return default_cursor();
}

control& control::cursor(const forms::cursor &cursor) {
  if (cursor_ != cursor) {
    cursor_ = cursor;
    native::control::cursor(handle_, cursor_.value().handle());
    on_cursor_changed(event_args::empty);
    for (auto& control : controls())
      control.get().on_parent_cursor_changed(event_args::empty);
  }
  return *this;
}

control& control::cursor(nullptr_t) {
  if (cursor_.has_value()) {
    cursor_.reset();
    recreate_handle();
    on_cursor_changed(event_args::empty);
    for (auto& control : controls())
      control.get().on_parent_cursor_changed(event_args::empty);
  }
  return *this;
}

drawing::font control::default_font() const {
  return system_fonts::default_font();
}

control& control::dock(dock_style dock) {
  if (dock_ != dock) {
    dock_ = dock;
    set_state(state::docked, true);
    on_dock_changed(event_args::empty);
  }
  return *this;
}

control& control::enabled(bool enabled) {
  if (get_state(state::enabled) != enabled) {
    set_state(state::enabled, enabled);
    native::control::enabled(handle_, get_state(state::enabled));
    on_enabled_changed(event_args::empty);
  }
  return *this;
}

drawing::font control::font() const {
  for (const control* control = this; control; control = control->parent().has_value() ? &control->parent().value().get() : nullptr)
    if (control->font_.has_value()) return control->font_.value();
  return default_font();
}

control& control::font(const drawing::font& font) {
  if (font_ != font) {
    font_ = font;
    native::control::font(handle_, font_.value());
    on_font_changed(event_args::empty);
    for (auto control : controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
  return *this;
}

control& control::font(nullptr_t) {
  if (font_.has_value()) {
    font_.reset();
    recreate_handle();
    on_font_changed(event_args::empty);
    for (auto& control : controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
  return *this;
}

color control::fore_color() const {
  for (const control* control = this; control; control = control->parent().has_value() ? &control->parent().value().get() : nullptr)
    if (control->fore_color_.has_value()) return control->fore_color_.value();
  return default_fore_color();
}

control& control::fore_color(const color& color) {
  if (fore_color_ != color) {
    fore_color_ = color;
    native::control::fore_color(handle_, fore_color_.value());
    on_fore_color_changed(event_args::empty);
    for (auto& control : controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
  return *this;
}

control& control::fore_color(nullptr_t) {
  if (fore_color_.has_value()) {
    fore_color_.reset();
    recreate_handle();
    on_fore_color_changed(event_args::empty);
    for (auto& control : controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
  return *this;
}

intptr_t control::handle() const {
  return handle_;
}

control& control::parent(const control& parent) {
  if (parent.handle_ != parent_) {
    this->parent(nullptr);
    if (parent.handle_) const_cast<control&>(parent).controls_.push_back(*this);
  } else if (parent.handle_ == 0 && parent_ == 0)
    const_cast<control&>(parent).controls_.push_back(*this);
  return *this;
}

control& control::parent(nullptr_t) {
  if (parent_ != 0) {
    for (size_t index = 0; index < parent().value().get().controls_.size(); index++) {
      if (parent().value().get().controls_[index].get().handle_ == handle_) {
        parent().value().get().controls_.erase_at(index);
        break;
      }
    }
  }
  return *this;
}

control& control::text(const std::string& text) {
  if (text_ != text) {
    text_ = text;
    native::control::text(handle_, text_);
    on_text_changed(event_args::empty);
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
  if (get_state(state::visible) != visible) {
    set_state(state::visible, visible);
    native::control::visible(handle_, get_state(state::visible));
    on_visible_changed(event_args::empty);
  }
  return *this;
}


void control::bring_to_front() {
  focus();
}

void control::create_control() {
  suspend_layout();
  if (!get_state(state::destroying) && !get_state(state::creating) && !get_state(state::created)) {
    set_state(state::destroyed, false);
    set_state(state::creating, true);
    create_handle();
    if (!parent_) top_level_controls_.push_back(control_ref(*this));
    send_message(handle_, WM_CREATE, 0, 0);
    on_create_control();
    set_state(state::creating, false);
    set_state(state::created, true);
    resume_layout();
  }
}

void control::destroy_control() {
  if (get_state(state::created)) {
    suspend_layout();
    set_state(state::created, false);
    set_state(state::destroying, true);
    if (handle_) {
      for(control_ref child : controls_)
        child.get().destroy_control();
      
      if (parent_ != 0 && parent().has_value() && !parent().value().get().get_state(state::destroying))
        parent(nullptr);
      else {
        for (size_t index = 0; index < top_level_controls_.size(); index++) {
          if (top_level_controls_[index].get().handle_ == handle_) {
            top_level_controls_.erase_at(index);
            break;
          }
        }
      }
      destroy_handle();
    }
    set_state(state::destroying, false);
    set_state(state::destroyed, true);
  }
}

graphics control::create_graphics() const {
  return graphics(native::control::create_graphics(handle_));
}

void control::create_handle() {
  set_state(state::creating_handle, true);
  handle_ = native::control::create(create_params());
  on_handle_created(event_args::empty);
  set_state(state::creating_handle, false);
}

void control::destroy_handle() {
  if (handle_) native::control::unregister_wnd_proc(handle_, {*this, &control::wnd_proc_});
  handles_.erase(handle_);
  on_handle_destroyed(event_args::empty);
  native::control::destroy(handle_);
  handle_ = 0;
}

bool control::focus() {
  if (!handle_ || !can_focus_) return false;
  native::control::focus(handle_);
  focused_ = true;
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
  
  create_params.caption(text_);
  create_params.style(WS_VISIBLE | WS_CHILD);
  if (parent_) create_params.parent(parent().value().get().handle_);
  create_params.location(location_);
  create_params.size(size_);
  
  return create_params;
}

drawing::size control::measure_control() const {
  return client_size_;
}

drawing::size control::measure_text() const {
  return drawing::size::ceiling(create_graphics().measure_string(text_, font())) + drawing::size(2, 1);
}

void control::on_auto_size_changed(const event_args& e) {
  on_layout(e);
  if (can_raise_events()) auto_size_changed(*this, e);
}

void control::on_back_color_changed(const event_args &e) {
  refresh();
  if (can_raise_events()) back_color_changed(*this, e);
}

void control::on_create_control() {
  for (auto control : controls_) {
    control.get().parent_ = handle_;
    control.get().create_control();
  }
  on_layout(event_args::empty);
}

void control::on_click(const event_args &e) {
  if (can_raise_events()) click(*this, e);
}

void control::on_client_size_changed(const event_args &e) {
  on_layout(e);
  refresh();
  if (can_raise_events()) client_size_changed(*this, e);
}

void control::on_control_added(const control_event_args &e) {
  on_layout(event_args::empty);
  size_changed += {e.control(), &control::on_parent_size_changed};
  if (can_raise_events()) control_added(*this, e);
}

void control::on_control_removed(const control_event_args &e) {
  on_layout(event_args::empty);
  size_changed -= {e.control(), &control::on_parent_size_changed};
  if (can_raise_events()) control_removed(*this, e);
}

void control::on_cursor_changed(const event_args &e) {
  if (can_raise_events()) cursor_changed(*this, e);
}

void control::on_dock_changed(const event_args &e) {
  if (parent().has_value()) parent().value().get().on_layout(e);
  on_layout(e);
  if (can_raise_events()) dock_changed(*this, e);
}

void control::on_double_click(const event_args &e) {
  if (can_raise_events()) double_click(*this, e);
}

void control::on_enabled_changed(const event_args &e) {
  set_state(state::enabled, native::control::enabled(handle_));
  refresh();
  if (can_raise_events()) enabled_changed(*this, e);
}

void control::on_fore_color_changed(const event_args &e) {
  refresh();
  if (can_raise_events()) fore_color_changed(*this, e);
}

void control::on_font_changed(const event_args &e) {
  if (parent_ && parent().value().get().auto_size()) parent().value().get().perform_layout();
  on_layout(event_args::empty);
  if (can_raise_events()) font_changed(*this, e);
}

void control::on_got_focus(const event_args &e) {
  focused_ = true;
  if (can_raise_events()) got_focus(*this, e);
}

void control::on_handle_created(const event_args &e) {
  native::control::register_wnd_proc(handle_, {*this, &control::wnd_proc_});
  handles_[handle_] = this;
  if (get_state(state::client_size_setted)) native::control::client_size(handle_, client_size());
  if (!xtd::forms::theme_colors::current_theme().is_default() || back_color_.has_value() || back_color() != default_back_color()) native::control::back_color(handle_, back_color());
  if (cursor_.has_value() || cursor() != default_cursor()) native::control::cursor(handle_, cursor().handle());
  if (!xtd::forms::theme_colors::current_theme().is_default() || fore_color_.has_value() || fore_color() != default_fore_color()) native::control::fore_color(handle_, fore_color());
  if (font_.has_value() || font() != default_font()) native::control::font(handle_, font());
  native::control::enabled(handle_, enabled());
  native::control::visible(handle_, visible());
  if (focused()) native::control::focus(handle_);

  client_rectangle_ = native::control::client_rectangle(handle_);
  client_size_ = native::control::client_size(handle_);
  location_ = native::control::location(handle_);
  size_ = native::control::size(handle_);

  if (can_raise_events()) handle_created(*this, e);
  
  if (parent_) parent().value().get().perform_layout();
  on_layout(event_args::empty);
}

void control::on_handle_destroyed(const event_args &e) {
  if (can_raise_events()) handle_destroyed(*this, e);
}

void control::on_key_down(key_event_args& e) {
  if (can_raise_events()) key_down(*this, e);
}

void control::on_key_press(key_press_event_args& e) {
  if (can_raise_events()) key_press(*this, e);
}

void control::on_key_up(key_event_args& e) {
  if (can_raise_events()) key_up(*this, e);
}

void control::on_layout(const event_args &e) {
  if (get_state(state::layout_deferred) || reentrant_layout::is_reentrant(this)) return;
  reentrant_layout reentrant_laout(this);
  
  do_layout_with_anchor_styles();
  do_layout_with_auto_size_mode();
  do_layout_childs_with_dock_style();
  if (can_raise_events()) layout(*this, e);
}

void control::on_location_changed(const event_args &e) {
  if (parent_ && parent().value().get().auto_size()) parent().value().get().perform_layout();
  if (can_raise_events()) location_changed(*this, e);
}

void control::on_lost_focus(const event_args &e) {
  focused_ = false;
  if (can_raise_events()) lost_focus(*this, e);
}

void control::on_mouse_click(const mouse_event_args& e) {
  if (can_raise_events()) mouse_click(*this, e);
}

void control::on_mouse_double_click(const mouse_event_args& e) {
  if (can_raise_events()) mouse_double_click(*this, e);
}

void control::on_mouse_down(const mouse_event_args& e) {
  if (can_raise_events()) mouse_down(*this, e);
}

void control::on_mouse_horizontal_wheel(const mouse_event_args& e) {
  if (can_raise_events()) mouse_horizontal_wheel(*this, e);
}

void control::on_mouse_enter(const event_args &e) {
  if (can_raise_events()) mouse_enter(*this, e);
}

void control::on_mouse_leave(const event_args &e) {
  if (can_raise_events()) mouse_leave(*this, e);
}

void control::on_mouse_move(const mouse_event_args& e) {
  if (can_raise_events()) mouse_move(*this, e);
}

void control::on_mouse_up(const mouse_event_args& e) {
  if (can_raise_events()) mouse_up(*this, e);
}

void control::on_mouse_wheel(const mouse_event_args& e) {
  if (can_raise_events()) mouse_wheel(*this, e);
}

void control::on_paint(paint_event_args &e) {
  if (can_raise_events()) paint(*this, e);
}

void control::on_parent_back_color_changed(const event_args &e) {
  if (!back_color_.has_value() && parent().value().get().back_color() != parent().value().get().default_back_color()) {
    if (!parent().value().get().back_color_.has_value()) recreate_handle();
    else native::control::back_color(handle_, parent().value().get().back_color());
    for (auto control : controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
}

void control::on_parent_changed(const event_args &e) {
  if (parent().has_value()) parent_size_ = parent().value().get().get_state(state::client_size_setted) ? parent().value().get().client_size() :  parent().value().get().size();
  on_layout(event_args::empty);
  if (can_raise_events()) parent_changed(*this, e);
}

void control::on_parent_cursor_changed(const event_args &e) {
  if (!cursor_.has_value() && parent().value().get().cursor() != parent().value().get().default_cursor()) {
    if (!parent().value().get().cursor_.has_value()) recreate_handle();
    else native::control::cursor(handle_, parent().value().get().cursor().handle());
    for (auto control : controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
}

void control::on_parent_fore_color_changed(const event_args &e) {
  if (!fore_color_.has_value() && parent().value().get().fore_color() != parent().value().get().default_fore_color()) {
    if (!parent().value().get().fore_color_.has_value()) recreate_handle();
    else native::control::fore_color(handle_, parent().value().get().fore_color());
    for (auto control : controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
}

void control::on_parent_font_changed(const event_args &e) {
  if (!font_.has_value() && parent().value().get().font() != parent().value().get().default_font()) {
    if (!parent().value().get().font_.has_value()) recreate_handle();
    else native::control::font(handle_, parent().value().get().font());
    for (auto control : controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
}

void control::on_resize(const event_args &e) {
  if (can_raise_events()) resize(*this, e);
}

void control::on_size_changed(const event_args &e) {
  if (parent_ && parent().value().get().auto_size()) parent().value().get().perform_layout();
  client_rectangle_ = native::control::client_rectangle(handle_);
  on_layout(e);
  refresh();
  if (can_raise_events()) size_changed(*this, e);
}

void control::on_text_changed(const event_args &e) {
  if (parent_ && parent().value().get().auto_size()) parent().value().get().perform_layout();
  on_layout(event_args::empty);
  if (can_raise_events()) text_changed(*this, e);
}

void control::on_visible_changed(const event_args &e) {
  set_state(state::visible, native::control::visible(handle_));
  if (focused())
    focus();
  for (auto item : controls_)
    if (item.get().focused()) item.get().focus();
  if (parent_ && parent().value().get().auto_size()) parent().value().get().perform_layout();
  if (can_raise_events()) visible_changed(*this, e);
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
  if (auto_size_mode_ != auto_size_mode) {
    auto_size_mode_ = auto_size_mode;
    on_layout(event_args::empty);
  }
}

std::string control::to_string() const {
  if (!name_.empty()) return strings::format("{}, name: {}", strings::full_class_name(*this), name_);
  if (!text_.empty()) return strings::format("{}, text: {}", strings::full_class_name(*this), text_);
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
  diagnostics::debug::write_line_if(debug_events, strings::format("({}) receive message [{}]", name_, message));
  switch (message.msg()) {
      // keyboard:
    case WM_CHAR:
    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSCHAR:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP: wm_key_char(message); break;
      // mouse events
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_XBUTTONDOWN: wm_mouse_down(message); break;
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_XBUTTONUP: wm_mouse_up(message); break;
    case WM_LBUTTONDBLCLK:
    case WM_MBUTTONDBLCLK:
    case WM_RBUTTONDBLCLK:
    case WM_XBUTTONDBLCLK: wm_mouse_double_click(message); break;
    case WM_MOUSEMOVE: wm_mouse_move(message); break;
    case WM_MOUSEENTER: wm_mouse_enter(message); break;
    case WM_MOUSELEAVE: wm_mouse_leave(message); break;
    case WM_CHILDACTIVATE: wm_child_activate(message); break;
    case WM_SETFOCUS: wm_set_focus(message); break;
    case WM_KILLFOCUS: wm_kill_focus(message); break;
    case WM_MOUSEHWHEEL:
    case WM_MOUSEWHEEL: wm_mouse_wheel(message); break;
      // System events
    case WM_COMMAND: wm_command(message); break;
    case WM_PAINT: wm_paint(message); break;
    case WM_MOVE: wm_move(message);  break;
    case WM_SETTEXT: wm_set_text(message); break;
    case WM_SIZE:  wm_size(message); break;
    case WM_HSCROLL:
    case WM_VSCROLL: wm_scroll(message); break;
    default: def_wnd_proc(message); break;
  }
}

void control::def_wnd_proc(message& message) {
  message.result(native::control::def_wnd_proc(handle_, message.hwnd(), message.msg(),message.wparam(), message.lparam(), message.result(), message.handle()));
}

void control::recreate_handle() {
  if (handle_ != 0) {
    set_state(state::recreate, true);
    for (auto control : controls()) control.get().set_state(state::parent_recreating, true);

    on_handle_destroyed(event_args::empty);
    intptr_t old_handle = handle_;
    handle_ = 0;
    create_handle();
    for (auto control : controls()) {
      control.get().parent_ = handle_;
      control.get().recreate_handle();
    }
    intptr_t new_handle = handle_;
    handle_ = old_handle;
    destroy_handle();
    handle_ = new_handle;

    for (auto control : controls()) control.get().set_state(state::parent_recreating, false);
    set_state(state::recreate, false);
  }
}

void control::set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {
  if ((specified & bounds_specified::x) == bounds_specified::x) location_.x(x);
  if ((specified & bounds_specified::y) == bounds_specified::y) location_.y(y);
  if ((specified & bounds_specified::width) == bounds_specified::width) size_.width(width);
  if ((specified & bounds_specified::height) == bounds_specified::height) size_.height(height);
  
  if ((specified & bounds_specified::x) == bounds_specified::x || (specified & bounds_specified::y) == bounds_specified::y) {
    native::control::location(handle_, location_);
    on_location_changed(event_args::empty);
    if (parent_) parent().value().get().perform_layout();
    on_layout(event_args::empty);
  }
  
  if ((specified & bounds_specified::width) == bounds_specified::width || (specified & bounds_specified::height) == bounds_specified::height) {
    native::control::size(handle_, size_);
    on_client_size_changed(event_args::empty);
    on_size_changed(event_args::empty);
    if (parent_) parent().value().get().perform_layout();
    on_layout(event_args::empty);
  }
}

void control::set_client_size_core(int32_t width, int32_t height) {
  client_size_.width(width);
  client_size_.height(height);
  
  native::control::client_size(handle_, client_size_);
  on_client_size_changed(event_args::empty);
  on_size_changed(event_args::empty);
}

void control::on_parent_size_changed(const control& sender, const event_args& e) {
  if (!get_state(state::layout_deferred) && !reentrant_layout::is_reentrant(this)) {
    on_layout(event_args::empty);
    parent_size_ = parent().value().get().get_state(state::client_size_setted) ? parent().value().get().client_size() :  parent().value().get().size();
  }
}

void control::do_layout_childs_with_dock_style() {
  bool docked = false;
  for(control_ref control : controls_) {
    docked = control.get().get_state(state::docked);
    if (docked) break;
  }

  if (docked) {
    drawing::rectangle docking_rect = client_rectangle();
    docking_rect.left(docking_rect.left() + padding_.left());
    docking_rect.top(docking_rect.top() + padding_.top());
    docking_rect.width(docking_rect.width() - padding_.left() - padding_.right());
    docking_rect.height(docking_rect.height() - padding_.top() - padding_.bottom());
    for(control_collection::reverse_iterator iterator = controls_.rbegin(); iterator != controls_.rend(); ++iterator) {
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
  if (parent().has_value() && parent_size_ != drawing::size::empty) {
    point diff = (parent().value().get().get_state(state::client_size_setted) ? parent().value().get().client_size() :  parent().value().get().size()) - parent_size_;

    if ((anchor_ & anchor_styles::left) == anchor_styles::left && (anchor_ & anchor_styles::right) != anchor_styles::right)
      left(left());
    else if ((anchor_ & anchor_styles::left) == anchor_styles::left && (anchor_ & anchor_styles::right) == anchor_styles::right)
      width(width() + diff.x());
    else if ((anchor_ & anchor_styles::left) != anchor_styles::left && (anchor_ & anchor_styles::right) == anchor_styles::right)
      left(left() + diff.x());
    else
      left(left() + (diff.x() / 2));

    if ((anchor_ & anchor_styles::top) == anchor_styles::top && (anchor_ & anchor_styles::bottom) != anchor_styles::bottom)
      top(top());
    else if ((anchor_ & anchor_styles::top) == anchor_styles::top && (anchor_ & anchor_styles::bottom) == anchor_styles::bottom)
      height(height() + diff.y());
    else if ((anchor_ & anchor_styles::top) != anchor_styles::top && (anchor_ & anchor_styles::bottom) == anchor_styles::bottom)
      top(top() + diff.y());
    else
      top(top() + (diff.y() / 2));
  }

}

void control::do_layout_with_auto_size_mode() {
  if (get_state(state::auto_size)) {
    drawing::size auto_size_size_ = measure_control();
    if (auto_size_mode_ == auto_size_mode::grow_only && auto_size_size_.width() < client_size_.width())
      auto_size_size_.width(client_size_.width());
    if (auto_size_mode_ == auto_size_mode::grow_only && auto_size_size_.height() < client_size_.height())
      auto_size_size_.height(client_size_.height());
    client_size(auto_size_size_);
  }
}

void control::wm_child_activate(message& message) {
  def_wnd_proc(message);
}

void control::wm_command(message& message) {
  def_wnd_proc(message);
  if (message.lparam() != 0)
    from_handle(message.lparam()).value().get().send_message(message.hwnd(), WM_REFLECT + message.msg(), message.wparam(), message.lparam());
}

void control::wm_key_char(message& message) {
  if (message.msg() == WM_KEYDOWN || message.msg ()== WM_SYSKEYDOWN) {
    key_event_args key_event_args(static_cast<keys>(message.wparam()));
    modifier_keys_ = key_event_args.modifiers();
    on_key_down(key_event_args);
    message.result(key_event_args.suppress_key_press());
    if (!key_event_args.handled()) def_wnd_proc(message);
  } else if (message.msg() == WM_CHAR || message.msg() == WM_SYSCHAR) {
    key_press_event_args key_press_event_args(static_cast<int32_t>(message.wparam()));
    on_key_press(key_press_event_args);
    message.result(key_press_event_args.handled());
    if (!key_press_event_args.handled()) def_wnd_proc(message);
  } else if (message.msg() == WM_KEYUP || message.msg() == WM_SYSKEYUP) {
    key_event_args key_event_args(static_cast<keys>(message.wparam()));
    modifier_keys_ = key_event_args.modifiers();
    on_key_up(key_event_args);
    message.result(key_event_args.handled());
    if (!key_event_args.handled()) def_wnd_proc(message);
  } else
    def_wnd_proc(message);
}

void control::wm_kill_focus(message& message) {
  def_wnd_proc(message);
  on_lost_focus(event_args::empty);
}

void control::wm_mouse_down(message& message) {
  def_wnd_proc(message);
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, get_state(state::double_click_fired));
  mouse_buttons_ |= e.button();
  on_mouse_down(e);
  if (message.msg() == WM_LBUTTONDOWN) mouse_left_down_ = true;
}

void control::wm_mouse_double_click(message& message) {
  def_wnd_proc(message);
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  on_double_click(event_args::empty);
  on_mouse_double_click(mouse_event_args::create(message, get_state(state::double_click_fired)));
}

void control::wm_mouse_enter(message& message) {
  def_wnd_proc(message);
  on_mouse_enter(event_args::empty);
}

void control::wm_mouse_leave(message& message) {
  def_wnd_proc(message);
  on_mouse_leave(event_args::empty);
}

void control::wm_mouse_up(message& message) {
  def_wnd_proc(message);
  mouse_event_args e = mouse_event_args::create(message);
  mouse_buttons_ &= ~e.button();
  if (mouse_left_down_ && client_rectangle().contains(e.location())) on_click(event_args::empty);
  if (message.msg() == WM_LBUTTONDOWN) mouse_left_down_ = false;
  on_mouse_click(e);
  on_mouse_up(e);
}

void control::wm_mouse_move(message& message) {
  def_wnd_proc(message);
  on_mouse_move(mouse_event_args(wparam_to_mouse_buttons(message), point_to_client({(int32_t)LOWORD(message.lparam()), (int32_t)HIWORD(message.lparam())}), get_state(control::state::double_click_fired) ? 2 : 1, 0));
}

void control::wm_move(message& message) {
  def_wnd_proc(message);
  if (location_ != native::control::location(handle_)) {
    location_ = native::control::location(handle_);
    on_location_changed(event_args::empty);
  }
}

void control::wm_mouse_wheel(message& message) {
  def_wnd_proc(message);
  if (message.msg() == WM_MOUSEHWHEEL)
    on_mouse_horizontal_wheel(mouse_event_args::create(message, get_state(state::double_click_fired), static_cast<int32_t>(HIWORD(message.wparam()))));
  else
    on_mouse_wheel(mouse_event_args::create(message, get_state(state::double_click_fired), static_cast<int32_t>(HIWORD(message.wparam()))));
}

void control::wm_paint(message& message) {
  def_wnd_proc(message);
  paint_event_args e(client_rectangle_, *this, get_state(state::double_buffered));
  on_paint(e);
}

void control::wm_scroll(message& message) {
  def_wnd_proc(message);
  if (message.lparam() != 0)
    from_handle(message.lparam()).value().get().send_message(message.hwnd(), WM_REFLECT + message.msg(), message.wparam(), message.lparam());
}

void control::wm_set_focus(message& message) {
  def_wnd_proc(message);
  on_got_focus(event_args::empty);
}

void control::wm_set_text(message& message) {
  def_wnd_proc(message);
  if (text_ != reinterpret_cast<const char*>(message.lparam())) {
    text_ = reinterpret_cast<const char*>(message.lparam());
    on_text_changed(event_args::empty);
  }
}

void control::wm_size(message& message) {
  def_wnd_proc(message);
  if (client_size_ != native::control::client_size(handle_)) {
    client_size_ = native::control::client_size(handle_);
    on_client_size_changed(event_args::empty);
  }
  if (size_ != native::control::size(handle_)) {
    size_ = native::control::size(handle_);
    on_size_changed(event_args::empty);
  }
  on_resize(event_args::empty);
}
