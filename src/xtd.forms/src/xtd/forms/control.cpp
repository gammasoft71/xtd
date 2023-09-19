#include <codecvt>
#include <iostream>
#include <set>
#include <xtd/invalid_operation_exception.h>
#include <xtd/typeof.h>
#include <xtd/diagnostics/debug.h>
#include <xtd/diagnostics/debugger.h>
#include <xtd/diagnostics/trace_switch.h>
#include <xtd/drawing/system_fonts.h>
#include <xtd/threading/mutex.h>
#include <xtd/threading/thread.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics.h>
#include <xtd/drawing/native/system_colors.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/class_styles.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/create_params.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/mouse_key.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/control.h"
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/control_renderer.h"
#include "../../../include/xtd/forms/enable_debug.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/message_box.h"
#include "../../../include/xtd/forms/screen.h"
#include "../../../include/xtd/forms/visual_styles/control_state.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  class reentrant_layout {
  public:
    explicit reentrant_layout(control* do_layout) : do_layout_(do_layout) {do_layouts.insert(do_layout_);}
    ~reentrant_layout() {do_layouts.erase(do_layout_);}
    static bool is_reentrant(control* do_layout) {return do_layouts.find(do_layout) != do_layouts.end(); }
  private:
    control* do_layout_ = nullptr;
    static set<control*> do_layouts;
  };
  
  set<control*> reentrant_layout::do_layouts;
  
  mouse_buttons wparam_to_mouse_buttons(const message& message) {
    if ((message.wparam() & MK_LBUTTON) == MK_LBUTTON) return mouse_buttons::left;
    else if ((message.wparam() & MK_RBUTTON) == MK_RBUTTON) return mouse_buttons::right;
    else if ((message.wparam() & MK_MBUTTON) == MK_MBUTTON) return mouse_buttons::middle;
    return mouse_buttons::none;
  }
  
  bool is_trace_form_or_control(const ustring& name) {
    return name == "9f5767d6-7a21-4ebe-adfe-2427b2024a55" || name == "d014d407-851c-49c1-a343-3380496a639a";
  }
}

struct control::async_result_invoke::data {
  std::any async_state;
  std::shared_ptr<bool> is_completed = std::make_shared<bool>(false);
  std::shared_ptr<xtd::threading::mutex> async_mutex = std::make_shared<xtd::threading::mutex>();
};

control::async_result_invoke::async_result_invoke(std::any async_state) : data_(std::make_shared<data>()) {
  data_->async_state = async_state;
}

std::any control::async_result_invoke::async_state() const noexcept {
  return data_->async_state;
}

xtd::threading::wait_handle& control::async_result_invoke::async_wait_handle() noexcept {
  return *data_->async_mutex;
}

bool control::async_result_invoke::completed_synchronously() const noexcept {
  return false;
}

bool control::async_result_invoke::is_completed() const noexcept {
  return *data_->is_completed;
}

bool control::check_for_illegal_cross_thread_calls_ = diagnostics::debugger::is_attached();
forms::keys control::modifier_keys_ = forms::keys::none;
forms::mouse_buttons control::mouse_buttons_ = forms::mouse_buttons::none;
map<intptr, control*> control::handles_;
control::control_collection control::top_level_controls_;

control::control_collection::control_collection(const control::control_collection::allocator_type& allocator) : control::control_collection::base(allocator) {
}

control::control_collection::control_collection(const control::control_collection::base& collection) : control::control_collection::base(collection) {}
control::control_collection::control_collection(const control::control_collection& collection) : control::control_collection::base(collection) {}
control::control_collection& control::control_collection::operator =(const control::control_collection& collection) {
  base::operator =(collection);
  return *this;
}

optional<control::control_collection::value_type> control::control_collection::operator [](const ustring& name) const {
  for (auto item : *this)
    if (item.get().name() == name) return item;
  return {};
}

optional<control::control_collection::value_type> control::control_collection::operator [](const ustring& name) {
  for (auto item : *this)
    if (item.get().name() == name) return item;
  return {};
}

struct control::data {
  anchor_styles anchor = anchor_styles::top | anchor_styles::left;
  forms::padding anchoring;
  drawing::point auto_scroll_point;
  forms::auto_size_mode auto_size_mode = forms::auto_size_mode::grow_and_shrink;
  std::optional<drawing::color> back_color;
  xtd::drawing::image background_image = xtd::drawing::image::empty;
  xtd::forms::image_layout background_image_layout = xtd::forms::image_layout::tile;
  bool can_focus = true;
  bool can_raise_events = true;
  drawing::rectangle client_rectangle;
  drawing::size client_size;
  forms::control_appearance control_appearance = forms::control_appearance::standard;
  xtd::forms::visual_styles::control_state control_state = xtd::forms::visual_styles::control_state::normal;
  control_collection controls;
  std::optional<context_menu_ref> context_menu;
  std::optional<forms::cursor> cursor;
  dock_style dock = dock_style::none;
  bool focused = false;
  std::optional<drawing::color> fore_color;
  std::optional<drawing::font> font;
  intptr handle = 0;
  drawing::point location;
  drawing::region region;
  forms::padding margin {3};
  drawing::size maximum_client_size;
  drawing::size maximum_size;
  drawing::size minimum_client_size;
  drawing::size minimum_size;
  forms::padding padding;
  bool mouse_in = false;
  xtd::ustring name;
  intptr parent = 0;
  bool recreate_handle_posted = false;
  std::optional<drawing::size> size;
  control::state state = control::state::empty;
  control_styles style = control_styles::none;
  style_sheets::style_sheet style_sheet;
  bool suppress_key_press = false;
  std::any tag;
  xtd::ustring text;
};

control::control() : data_(std::make_shared<data>()) {
  if (application::use_system_controls()) data_->control_appearance = xtd::forms::control_appearance::system;
  native::application::initialize();
  set_state(state::enabled, true);
  set_state(state::visible, true);
  set_state(state::tab_stop, true);
  set_style(control_styles::all_painting_in_wm_paint | control_styles::user_paint | control_styles::standard_click | control_styles::standard_double_click | control_styles::use_text_for_accessibility | control_styles::selectable, true);
  
  data_->controls.item_added += {*this, &control::on_controls_item_added};
  data_->controls.item_removed += {*this, &control::on_controls_item_removed};
}

control::control(const xtd::ustring& text) : control() {
  this->text(text);
}

control::control(const control& parent, const xtd::ustring& text) : control() {
  this->parent(parent);
  this->text(text);
}

control::control(const xtd::ustring& text, int32 left, int32 top, int32 width, int32 height) : control() {
  this->text(text);
  this->left(left);
  this->top(top);
  this->width(width);
  this->height(height);
}

control::control(const control& parent, const xtd::ustring& text, int32 left, int32 top, int32 width, int32 height) : control() {
  this->parent(parent);
  this->text(text);
  this->left(left);
  this->top(top);
  this->width(width);
  this->height(height);
}

control::~control() {
  destroy_control();
}

anchor_styles control::anchor() const noexcept {
  return data_->anchor;
}

control& control::anchor(anchor_styles anchor) {
  if (data_->anchor == anchor) return *this;
  data_->anchor = anchor;
  set_state(state::docked, false);
  if (handle() && parent()) data_->anchoring = {left(), location().y(), parent().value().get().client_size().width() - width() - left(), parent().value().get().client_size().height() - height() - top()};
  perform_layout();
  return *this;
}

drawing::point control::auto_scroll_point() const noexcept {
  return data_->auto_scroll_point;
}

bool control::auto_size() const noexcept {
  return get_state(state::auto_size);
}

control& control::auto_size(bool auto_size) {
  if (get_state(state::auto_size) == auto_size) return *this;
  set_state(state::auto_size, auto_size);
  on_auto_size_changed(event_args::empty);
  return *this;
}

color control::back_color() const noexcept {
  for (auto control = this; control; control = control->parent().has_value() && !control->get_state(control::state::top_level) ? &control->parent().value().get() : nullptr)
    if (control->data_->back_color.has_value()) return control->data_->back_color.value();
  return default_back_color();
}

control& control::back_color(const color& color) {
  if (back_color() == color) return *this;
  data_->back_color = color;
  if (is_handle_created()) native::control::back_color(handle(), data_->back_color.value());
  for (auto& control : controls())
    if (control.get().data_->parent) control.get().on_parent_back_color_changed(event_args::empty);
  on_back_color_changed(event_args::empty);
  return *this;
}

control& control::back_color(std::nullptr_t) {
  if (!data_->back_color.has_value()) return *this;
  data_->back_color.reset();
  post_recreate_handle();
  for (auto& control : controls())
    if (control.get().data_->parent) control.get().on_parent_back_color_changed(event_args::empty);
  on_back_color_changed(event_args::empty);
  return *this;
}

const xtd::drawing::image& control::background_image() const noexcept {
  return data_->background_image;
}

control& control::background_image(const xtd::drawing::image& background_image) {
  if (data_->background_image == background_image) return *this;
  data_->background_image = background_image;
  on_background_image_changed(event_args::empty);
  return *this;
}

xtd::forms::image_layout control::background_image_layout() const noexcept {
  return data_->background_image_layout;
}

control& control::background_image_layout(xtd::forms::image_layout background_image_layout) {
  if (data_->background_image_layout == background_image_layout) return *this;
  data_->background_image_layout = background_image_layout;
  on_background_image_layout_changed(event_args::empty);
  return *this;
}

int32 control::bottom() const noexcept {
  return top() + height();
}

drawing::rectangle control::bounds() const noexcept {
  return {location(), size()};
}

control& control::bounds(const drawing::rectangle& bounds) {
  set_bounds_core(bounds.x(), bounds.y(), bounds.width(), bounds.height(), bounds_specified::all);
  return *this;
}

bool control::can_focus() const noexcept {
  try {
    bool visible_and_enabled = handle() && get_state(state::visible) && get_state(state::enabled);
    
    auto tlc = optional<control_ref> {const_cast<control&>(*this)};
    while (visible_and_enabled && tlc.has_value() && !tlc.value().get().get_state(state::top_level)) {
      tlc = tlc.value().get().parent();
      if (tlc.has_value()) visible_and_enabled = tlc.value().get().get_state(state::visible) && get_state(state::enabled);
    }
    
    if (!visible_and_enabled) return false;
    return data_->can_focus;
  } catch (...) {
    return false;
  }
}

bool control::can_select() const noexcept {
  return enabled() && visible() && get_style(control_styles::selectable);
}

bool control::can_raise_events() const noexcept {
  return data_->can_raise_events;
}

bool control::check_for_illegal_cross_thread_calls() noexcept {
  return check_for_illegal_cross_thread_calls_;
}

void control::check_for_illegal_cross_thread_calls(bool value) {
  check_for_illegal_cross_thread_calls_ = value;
}

const drawing::rectangle& control::client_rectangle() const noexcept {
  try {
    if (!handle()) data_->client_rectangle = {point {0, 0}, client_size()};
  } catch (...) {
  }
  return data_->client_rectangle;
}

const drawing::size& control::client_size() const noexcept {
  try {
    if (!handle() && data_->client_size.width() == 0 && width() != 0) data_->client_size = {width(), data_->client_size.height()};
    if (!handle() && data_->client_size.height() == 0 && height() != 0) data_->client_size = {data_->client_size.width(), height()};
  } catch (...) {
  }
  return data_->client_size;
}

control& control::client_size(const drawing::size& client_size) {
  if (get_state(state::client_size_setted) && data_->client_size == client_size) return *this;
  set_state(state::client_size_setted, true);
  set_client_size_core(client_size.width(), client_size.height());
  return *this;
}

xtd::ustring control::company_name() const noexcept {
  return "Gammasoft";
}

optional<control::context_menu_ref> control::context_menu() const noexcept {
  return data_->context_menu;
}

control& control::context_menu(xtd::forms::context_menu& value) {
  if (data_->context_menu.has_value() && &data_->context_menu.value().get() == &value) return *this;
  data_->context_menu = const_cast<forms::context_menu&>(value);
  return *this;
}

control& control::context_menu(std::nullptr_t) {
  if (!data_->context_menu.has_value()) return *this;
  data_->context_menu.reset();
  if (is_handle_created()) native::control::context_menu(handle(), 0, xtd::drawing::point::empty);
  return *this;
}

forms::control_appearance control::control_appearance() const noexcept {
  return data_->control_appearance;
}

control& control::control_appearance(forms::control_appearance value) {
  if (data_->control_appearance == value) return *this;
  data_->control_appearance = value;
  on_control_appearance_changed(event_args::empty);
  return *this;
}

control::control_collection& control::controls() noexcept {
  return data_->controls;
}

const control::control_collection& control::controls() const noexcept {
  return data_->controls;
}

bool control::created() const noexcept {
  return get_state(state::created);
}

forms::cursor control::cursor() const noexcept {
  for (auto control = this; control; control = control->parent().has_value() && !control->get_state(control::state::top_level) ? &control->parent().value().get() : nullptr)
    if (control->data_->cursor.has_value()) return control->data_->cursor.value();
  return default_cursor();
}

control& control::cursor(const forms::cursor& cursor) {
  if (data_->cursor == cursor) return *this;
  data_->cursor = cursor;
  if (is_handle_created()) native::control::cursor(handle(), data_->cursor.value().handle());
  for (auto& control : controls())
    if (control.get().data_->parent) control.get().on_parent_cursor_changed(event_args::empty);
  on_cursor_changed(event_args::empty);
  return *this;
}

control& control::cursor(std::nullptr_t) {
  if (!data_->cursor.has_value()) return *this;
  data_->cursor.reset();
  post_recreate_handle();
  for (auto& control : controls())
    if (control.get().data_->parent) control.get().on_parent_cursor_changed(event_args::empty);
  on_cursor_changed(event_args::empty);
  return *this;
}

drawing::rectangle control::display_rectangle() const noexcept {
  return client_rectangle();
}

dock_style control::dock() const noexcept {
  return data_->dock;
}

control& control::dock(dock_style dock) {
  if (data_->dock == dock) return *this;
  data_->dock = dock;
  set_state(state::docked, true);
  on_dock_changed(event_args::empty);
  return *this;
}

bool control::double_buffered() const noexcept {
  return get_state(state::double_buffered);
}

control& control::double_buffered(bool double_buffered) {
  set_state(state::double_buffered, double_buffered);
  return *this;
}

bool control::enabled() const noexcept {
  return get_state(state::enabled);
}

control& control::enabled(bool enabled) {
  if (get_state(state::enabled) == enabled) return *this;
  set_state(state::enabled, enabled);
  if (is_handle_created()) native::control::enabled(handle(), get_state(state::enabled));
  for (auto& control : controls())
    if (control.get().data_->parent) control.get().on_parent_enabled_changed(event_args::empty);
  on_enabled_changed(event_args::empty);
  return *this;
}

bool control::focused() const noexcept {
  return data_->focused;
}

drawing::font control::font() const noexcept {
  for (auto control = this; control; control = control->parent().has_value() && !control->get_state(control::state::top_level) ? &control->parent().value().get() : nullptr)
    if (control->data_->font.has_value()) return control->data_->font.value();
  return default_font();
}

control& control::font(const drawing::font& font) {
  if (data_->font == font) return *this;
  data_->font = font;
  if (is_handle_created()) native::control::font(handle(), data_->font.value());
  for (auto& control : controls())
    if (control.get().data_->parent) control.get().on_parent_font_changed(event_args::empty);
  on_font_changed(event_args::empty);
  return *this;
}

control& control::font(std::nullptr_t) {
  if (!data_->font.has_value()) return *this;
  data_->font.reset();
  post_recreate_handle();
  for (auto& control : controls())
    if (control.get().data_->parent) control.get().on_parent_font_changed(event_args::empty);
  on_font_changed(event_args::empty);
  return *this;
}

color control::fore_color() const noexcept {
  for (auto control = this; control; control = control->parent().has_value() && !control->get_state(control::state::top_level) ? &control->parent().value().get() : nullptr)
    if (control->data_->fore_color.has_value()) return control->data_->fore_color.value();
  return default_fore_color();
}

control& control::fore_color(const color& color) {
  if (data_->fore_color.has_value() && data_->fore_color == color) return *this;
  data_->fore_color = color;
  if (is_handle_created()) native::control::fore_color(handle(), data_->fore_color.value());
  for (auto& control : controls())
    if (control.get().data_->parent) control.get().on_parent_fore_color_changed(event_args::empty);
  on_fore_color_changed(event_args::empty);
  return *this;
}

control& control::fore_color(std::nullptr_t) {
  if (!data_->fore_color.has_value()) return *this;
  data_->fore_color.reset();
  post_recreate_handle();
  for (auto& control : controls())
    if (control.get().data_->parent) control.get().on_parent_fore_color_changed(event_args::empty);
  on_fore_color_changed(event_args::empty);
  return *this;
}

intptr control::handle() const {
  if (check_for_illegal_cross_thread_calls() && invoke_required())
    throw invalid_operation_exception(ustring::format("Cross-thread operation not valid: {}"_t, to_string()), csf_);
  return data_->handle;
}

int32 control::height() const noexcept {
  return size().height();
}

control& control::height(int32 height) {
  if (size().height() == height) return *this;
  set_bounds_core(0, 0, 0, height, bounds_specified::height);
  return *this;
}

bool control::invoke_required() const noexcept {
  return !threading::thread::current_thread().is_main_thread();
}

bool control::is_handle_created() const noexcept {
  return data_->handle != 0;
}

int32 control::left() const noexcept {
  return data_->location.x();
}

control& control::left(int32 left) {
  if (data_->location.x() == left) return *this;
  set_bounds_core(left, 0, 0, 0, bounds_specified::x);
  return *this;
}

drawing::point control::location() const noexcept {
  return data_->location;
}

control& control::location(const drawing::point& location) {
  if (data_->location == location) return *this;
  set_bounds_core(location.x(), location.y(), 0, 0, bounds_specified::location);
  return *this;
}

forms::padding control::margin() const noexcept {
  return data_->margin;
}

control& control::margin(const forms::padding& margin) {
  data_->margin = margin;
  return *this;
}

const drawing::size& control::maximum_client_size() const noexcept {
  return data_->maximum_client_size;
}

control& control::maximum_client_size(const drawing::size& size) {
  if (data_->maximum_client_size == size) return *this;
  data_->maximum_client_size = size;
  client_size({this->client_size().width() > maximum_client_size().width() ? data_->maximum_client_size.width() : client_size().width(), this->client_size().height() > maximum_client_size().height() ? maximum_client_size().height() : client_size().height()});
  if (handle()) native::control::maximum_client_size(handle(), data_->maximum_client_size);
  return *this;
}

const drawing::size& control::maximum_size() const noexcept {
  return data_->maximum_size;
}

control& control::maximum_size(const drawing::size& size) {
  if (data_->maximum_size == size) return *this;
  data_->maximum_size = size;
  this->size({this->size().width() > maximum_size().width() ? maximum_size().width() : this->size().width(), this->size().height() > maximum_size().height() ? maximum_size().height() : this->size().height()});
  if (handle()) native::control::maximum_size(handle(), data_->maximum_size);
  return *this;
}

const drawing::size& control::minimum_client_size() const noexcept {
  return data_->minimum_client_size;
}

control& control::minimum_client_size(const drawing::size& size) {
  if (data_->minimum_client_size == size) return *this;
  data_->minimum_client_size = size;
  client_size({this->client_size().width() < minimum_client_size().width() ? minimum_client_size().width() : client_size().width(), this->client_size().height() < minimum_client_size().height() ? minimum_client_size().height() : client_size().height()});
  if (handle()) native::control::minimum_client_size(handle(), data_->minimum_client_size);
  return *this;
}

const drawing::size& control::minimum_size() const noexcept {
  return data_->minimum_size;
}

control& control::minimum_size(const drawing::size& size) {
  if (data_->minimum_size == size) return *this;
  data_->minimum_size = size;
  this->size({this->size().width() < minimum_size().width() ? minimum_size().width() : this->size().width(), this->size().height() < minimum_size().height() ? minimum_size().height() : this->size().height()});
  if (handle()) native::control::minimum_size(handle(), data_->minimum_size);
  return *this;
}

forms::keys control::modifier_keys() noexcept {
  return modifier_keys_;
}

forms::mouse_buttons control::mouse_buttons() noexcept {
  return mouse_buttons_;
}

xtd::drawing::point control::mouse_position() noexcept {
  return xtd::forms::cursor::position();
}

const xtd::ustring& control::name() const noexcept {
  return data_->name;
}

control& control::name(const xtd::ustring& name) {
  data_->name = name;
  return*this;
}

intptr control::native_handle() const noexcept {
  try {
    return handle() ? native::control::native_handle(handle()) : 0;
  } catch (...) {
    return 0;
  }
}

forms::padding control::padding() const noexcept {
  return data_->padding;
}

control& control::padding(const forms::padding& padding) {
  data_->padding = padding;
  return *this;
}

std::optional<control_ref> control::parent() const noexcept {
  return from_handle(data_->parent);
}

control& control::parent(const control& value) {
  if (value.handle() != data_->parent) {
    if (parent().has_value()) parent(nullptr);
    else on_parent_changed(event_args::empty);
    if (value.is_handle_created()) const_cast<control&>(value).data_->controls.push_back(*this);
  } else if (!value.is_handle_created())
    const_cast<control&>(value).data_->controls.push_back(*this);
  return *this;
}

control& control::parent(std::nullptr_t) {
  if (!is_handle_created() || data_->parent == 0) return *this;
  auto current_parent = from_handle(data_->parent);
  for (auto it = current_parent.value().get().data_->controls.begin(); it != current_parent.value().get().data_->controls.end(); ++it) {
    if (it->get().handle() != handle()) continue;
    auto prev_parent = parent();
    on_parent_changed(event_args::empty);
    parent().value().get().data_->controls.erase(it);
    if (!get_state(state::destroying) && !prev_parent.value().get().get_state(state::destroying)) prev_parent.value().get().refresh();
    break;
  }
  return *this;
}

xtd::ustring control::product_name() const noexcept {
  return "xtd";
}

bool control::recreating_handle() const noexcept {
  return get_state(state::recreate);
}

const xtd::drawing::region& control::region() const noexcept {
  return data_->region;
}

control& control::region(const xtd::drawing::region& value) {
  if (value == data_->region) return *this;
  data_->region = value;
  on_region_changed(event_args::empty);
  return *this;
}

int32 control::right() const noexcept {
  return left() + width();
}

drawing::size control::size() const noexcept {
  return data_->size.value_or(default_size());
}

control& control::size(const drawing::size& size) {
  if (!get_state(state::client_size_setted) && this->size() == size) return *this;
  set_state(state::client_size_setted, false);
  set_bounds_core(0, 0, size.width(), size.height(), bounds_specified::size);
  return *this;
}

style_sheets::style_sheet control::style_sheet() const noexcept {
  return data_->style_sheet;
}

control& control::style_sheet(const style_sheets::style_sheet& value) {
  if (data_->style_sheet == value) return *this;
  data_->style_sheet = value;
  if (data_->style_sheet.theme().name().empty()) data_->style_sheet.theme_name_("-- user style sheet --");
  on_style_sheet_changed(event_args::empty);
  return *this;
}

control& control::style_sheet(std::nullptr_t) {
  if (data_->style_sheet == style_sheets::style_sheet()) return *this;
  data_->style_sheet = style_sheets::style_sheet();
  on_style_sheet_changed(event_args::empty);
  return *this;
}

control& control::style_sheet(const ustring& value) {
  return control::style_sheet(style_sheets::style_sheet(value));
}

bool control::tab_stop() const noexcept {
  return get_state(control::state::tab_stop);
}

control& control::tab_stop(bool value) {
  if (get_state(control::state::tab_stop) == value) return *this;
  set_state(control::state::tab_stop, value);
  on_tab_stop_changed(event_args::empty);
  return *this;
}

std::any control::tag() const noexcept {
  return data_->tag;
}

control& control::tag(std::any tag) {
  data_->tag = tag;
  return*this;
}

const xtd::ustring& control::text() const noexcept {
  return data_->text;
}

control& control::text(const ustring& text) {
  if (data_->text == text) return *this;
  data_->text = text;
  if (is_handle_created()) native::control::text(handle(), data_->text);
  on_text_changed(event_args::empty);
  return *this;
}

intptr control::toolkit_handle() const noexcept {
  try {
    return handle() ? native::control::toolkit_handle(handle()) : 0;
  } catch (...) {
    return 0;
  }
}

int32 control::top() const noexcept {
  return data_->location.y();
}

control& control::top(int32 top) {
  if (data_->location.y() == top) return *this;
  set_bounds_core(0, top, 0, 0, bounds_specified::y);
  return *this;
}

optional<control_ref> control::top_level_control() const noexcept {
  auto top_level_control = optional<control_ref> {const_cast<control&>(*this)};
  while (top_level_control.has_value() && !top_level_control.value().get().get_state(state::top_level))
    top_level_control = top_level_control.value().get().parent();
  if (top_level_control.has_value() && !top_level_control.value().get().get_state(state::top_level)) top_level_control.reset();
  return top_level_control;
}

bool control::visible() const noexcept {
  return get_state(state::visible);
}

control& control::visible(bool visible) {
  if (get_state(state::visible) == visible) return *this;
  set_state(state::visible, visible);
  if (is_handle_created()) native::control::visible(handle(), get_state(state::visible));
  on_visible_changed(event_args::empty);
  return *this;
}

int32 control::width() const noexcept {
  return size().width();
}

control& control::width(int32 width) {
  if (size().width() == width) return *this;
  set_bounds_core(0, 0, width, 0, bounds_specified::width);
  return *this;
}

std::shared_ptr<xtd::iasync_result> control::begin_invoke(delegate<void()> method) {
  return begin_invoke(delegate<void(std::vector<std::any>)>(method), {});
}

shared_ptr<iasync_result> control::begin_invoke(delegate<void(vector<any>)> method, const vector<any>& args) {
  //while (!xtd::forms::application::message_loop()) xtd::threading::thread::sleep(10_ms);
  shared_ptr<async_result_invoke> async = make_shared<async_result_invoke>(std::reference_wrapper(*this));
  async->async_wait_handle().wait_one();
  if (is_handle_created()) native::control::invoke_in_control_thread(data_->handle, method, args, async->data_->async_mutex, async->data_->is_completed);
  threading::thread::yield();
  return async;
}

void control::bring_to_front() {
  focus();
}

int32 control::compare_to(const control& value) const noexcept {
  return this < &value ? -1 : (this > &value ? 1 : 0);
}

control control::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = control {};
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

control control::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = control {};
  result.parent(parent);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

void control::create_control() {
  if (!get_state(state::destroying) && !get_state(state::creating) && !get_state(state::created)) {
    set_state(state::destroyed, false);
    set_state(state::creating, true);
    create_handle();
    send_message(handle(), WM_CREATE, 0, handle());
    set_state(state::created, is_handle_created());
    set_state(state::creating, false);
  }
}

void control::destroy_control() {
  if (!get_state(state::created)) return;
  if (!is_handle_created()) return;
  set_state(state::created, false);
  set_state(state::destroying, true);
  if (parent().has_value() && !parent().value().get().get_state(state::destroying)) {
    auto parent_prev = parent();
    parent_prev.value().get().suspend_layout();
    parent(nullptr);
    parent_prev.value().get().resume_layout(false);
  } else {
    for (size_t index = 0; index < top_level_controls_.size(); index++) {
      if (top_level_controls_[index].get().handle() == handle()) {
        top_level_controls_.erase_at(index);
        break;
      }
    }
  }
  destroy_handle();
  set_state(state::destroyed, true);
  set_state(state::destroying, false);
}

graphics control::create_graphics() const {
  if (!is_handle_created())
    throw invalid_operation_exception {csf_};
  return graphics(native::control::create_graphics(handle()));
}

bool control::focus() {
  if (!is_handle_created() || !data_->can_focus) return false;
  native::control::focus(handle());
  data_->focused = true;
  return true;
}

optional<control_ref> control::from_child_handle(intptr handle) {
  try {
    auto it = handles_.find(handle);
    if (it != handles_.end())
      return it->second->parent();
    return nullopt;
  } catch (...) {
    return nullopt;
  }
}

optional<control_ref> control::from_handle(intptr handle) {
  try {
    auto it = handles_.find(handle);
    if (it != handles_.end())
      return *it->second;
    return nullopt;
  } catch (...) {
    return nullopt;
  }
}

forms::auto_size_mode control::get_auto_size_mode() const {
  return data_->auto_size_mode;
}

std::optional<xtd::drawing::color> control::get_back_color() const noexcept {
  return data_->back_color;
}

std::optional<xtd::drawing::font> control::get_font() const noexcept {
  return data_->font;
}

std::optional<xtd::drawing::color> control::get_fore_color() const noexcept {
  return data_->fore_color;
}

size_t control::get_child_index(intptr child) const {
  if (child == 0) return control_collection::npos;
  for (size_t index = 0; index < controls().size(); ++index)
    if (controls()[index].get().handle() == child) return index;
  throw xtd::argument_exception {csf_};
}

size_t control::get_child_index(intptr child, bool& throw_exception) const {
  throw_exception = false;
  try {
    return get_child_index(child);
  } catch (...) {
    throw_exception = true;
    return control_collection::npos;
  }
}

void control::hide() {
  visible(false);
}

void control::invalidate() const {
  invalidate(client_rectangle(), false);
}

void control::invalidate(bool invalidate_children) const {
  invalidate(client_rectangle(), invalidate_children);
}

void control::invalidate(const drawing::rectangle& rect) const {
  invalidate(rect, false);
}

void control::invalidate(const drawing::rectangle& rect, bool invalidate_children) const {
  if (is_handle_created()) native::control::invalidate(handle(), rect, invalidate_children);
}

void control::invalidate(const drawing::region& region) const {
  invalidate(region, false);
}

void control::invalidate(const drawing::region& region, bool invalidate_children) const {
  if (is_handle_created()) native::control::invalidate(handle(), region, invalidate_children);
}

std::optional<object_ref> control::invoke(delegate<void()> method) {
  return invoke(delegate<void(std::vector<std::any>)>(method), std::vector<std::any> {});
}

std::optional<object_ref> control::invoke(delegate<void(std::vector<std::any>)> method, const std::vector<std::any>& args) {
  return end_invoke(begin_invoke(method, args));
}

std::optional<object_ref> control::invoke(delegate<void(std::vector<std::any>)> method, std::any arg) {
  return end_invoke(begin_invoke(method, std::vector<std::any> {arg}));
}

bool control::equals(const control& value) const noexcept {
  return this == &value;
}

std::optional<object_ref> control::end_invoke(shared_ptr<iasync_result> async) {
  auto lock = lock_guard<threading::mutex> {as<threading::mutex>(async->async_wait_handle())};
  return *this;
}

xtd::forms::visual_styles::control_state control::control_state() const noexcept {
  return data_->control_state;
}

forms::create_params control::create_params() const noexcept {
  auto create_params = forms::create_params {};
  
  create_params.caption(data_->text);
  create_params.class_style(CS_DBLCLKS);
  
  create_params.style(WS_CHILD);
  if (!enabled()) create_params.style(create_params.style() | WS_DISABLED);
  if (get_state(control::state::tab_stop)) create_params.style(create_params.style() | WS_TABSTOP);
  if (visible()) create_params.style(create_params.style() | WS_VISIBLE);
  
  if (parent().has_value()) create_params.parent(parent().value().get().handle());
  create_params.location(data_->location);
  create_params.size(data_->size.value_or(drawing::size(0, 0)));
  
  return create_params;
}

drawing::color control::default_back_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().control();
}

forms::cursor control::default_cursor() const noexcept {
  return cursors::default_cursor();
}

drawing::font control::default_font() const noexcept {
  return system_fonts::default_font();
}

drawing::color control::default_fore_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().control_text();
}

drawing::size control::default_size() const noexcept {
  return native::control::default_size(create_params().class_name());
}

bool control::get_state(control::state flag) const noexcept {
  return ((int32)data_->state & (int32)flag) == (int32)flag;
}

bool control::get_style(control_styles flag) const noexcept {
  return ((int32)data_->style & (int32)flag) == (int32)flag;
}

drawing::size control::measure_control() const noexcept {
  return data_->client_size;
}

drawing::size control::measure_text() const noexcept {
  return drawing::size::ceiling(screen::create_graphics().measure_string(data_->text, font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces))) + drawing::size(2, 1);
}

void control::on_auto_size_changed(const event_args& e) {
  perform_layout();
  if (can_raise_events()) auto_size_changed(*this, e);
}

void control::on_back_color_changed(const event_args& e) {
  refresh();
  if (can_raise_events()) back_color_changed(*this, e);
}

void control::on_background_image_changed(const event_args& e) {
  refresh();
  if (can_raise_events()) background_image_changed(*this, e);
}

void control::on_background_image_layout_changed(const event_args& e) {
  refresh();
  if (can_raise_events()) background_image_layout_changed(*this, e);
}

void control::on_control_appearance_changed(const event_args& e) {
  post_recreate_handle();
  if (can_raise_events()) control_appearance_changed(*this, e);
}

void control::on_create_control() {
  if (!parent().has_value())
    top_level_controls_.push_back(control_ref(*this));
  for (auto control : data_->controls) {
    control.get().data_->parent = handle();
    control.get().create_control();
  }
  perform_layout();
}

void control::on_click(const event_args& e) {
  if (can_raise_events()) click(*this, e);
}

void control::on_client_size_changed(const event_args& e) {
  if (can_raise_events()) client_size_changed(*this, e);
}

void control::on_control_added(const control_event_args& e) {
  perform_layout();
  size_changed += {e.control(), &control::on_parent_size_changed};
  if (can_raise_events()) control_added(*this, e);
}

void control::on_control_removed(const control_event_args& e) {
  perform_layout();
  size_changed -= {e.control(), &control::on_parent_size_changed};
  if (can_raise_events()) control_removed(*this, e);
}

void control::on_cursor_changed(const event_args& e) {
  if (can_raise_events()) cursor_changed(*this, e);
}

void control::on_destroy_control() {
  /// @todo destroy childs here...
}

void control::on_dock_changed(const event_args& e) {
  if (parent().has_value()) parent().value().get().perform_layout();
  perform_layout();
  if (can_raise_events()) dock_changed(*this, e);
}

void control::on_double_click(const event_args& e) {
  if (can_raise_events()) double_click(*this, e);
}

void control::on_enabled_changed(const event_args& e) {
  if (is_handle_created()) set_state(state::enabled, native::control::enabled(handle()));
  if (control_appearance() == xtd::forms::control_appearance::standard) data_->control_state = enabled() ? xtd::forms::visual_styles::control_state::normal : xtd::forms::visual_styles::control_state::disabled;
  refresh();
  if (can_raise_events()) enabled_changed(*this, e);
}

void control::on_fore_color_changed(const event_args& e) {
  refresh();
  if (can_raise_events()) fore_color_changed(*this, e);
}

void control::on_font_changed(const event_args& e) {
  if (parent().has_value() && parent().value().get().auto_size()) parent().value().get().perform_layout();
  perform_layout();
  if (can_raise_events()) font_changed(*this, e);
}

void control::on_got_focus(const event_args& e) {
  if (can_raise_events()) got_focus(*this, e);
}

void control::on_handle_created(const event_args& e) {
  if (get_state(state::client_size_setted)) {
    native::control::maximum_client_size(handle(), maximum_client_size());
    native::control::minimum_client_size(handle(), minimum_client_size());
    native::control::client_size(handle(), client_size());
  } else {
    native::control::maximum_size(handle(), maximum_size());
    native::control::minimum_size(handle(), minimum_size());
    native::control::size(handle(), this->size());
  }
  if (data_->back_color.has_value() || back_color() != default_back_color()) native::control::back_color(handle(), back_color());
  if (data_->cursor.has_value() || cursor() != default_cursor()) native::control::cursor(handle(), cursor().handle());
  if (data_->fore_color.has_value() || fore_color() != default_fore_color()) native::control::fore_color(handle(), fore_color());
  if (data_->font.has_value() || font() != default_font()) native::control::font(handle(), font());
  native::control::enabled(handle(), enabled());
  native::control::visible(handle(), visible());
  if (focused()) native::control::focus(handle());
  
  data_->client_rectangle = native::control::client_rectangle(handle());
  data_->client_size = native::control::client_size(handle());
  data_->location = native::control::location(handle());
  data_->size = native::control::size(handle());
  
  if (parent().has_value()) data_->anchoring = {left(), location().y(), parent().value().get().client_size().width() - width() - left(), parent().value().get().client_size().height() - height() - top()};
  
  if (can_raise_events()) handle_created(*this, e);
  
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::creation), ustring::format("on handle created control={}, location={}, size={}, client_size={}", *this, location(), this->size(), client_size()));
  
  if (!get_state(control::state::recreate) && parent().has_value()) parent().value().get().perform_layout();
  if (!get_state(control::state::recreate)) perform_layout();
  if (parent().has_value()) parent().value().get().update();
}

void control::on_handle_destroyed(const event_args& e) {
  if (can_raise_events()) handle_destroyed(*this, e);
}

void control::on_help_requested(help_event_args& e) {
  if (can_raise_events()) help_requested(*this, e);
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

void control::on_layout(const event_args& e) {
  do_layout_with_anchor_styles();
  do_layout_with_auto_size_mode();
  do_layout_children_with_dock_style();
  if (can_raise_events()) layout(*this, e);
}

void control::on_location_changed(const event_args& e) {
  if (parent().has_value() && parent().value().get().auto_size()) parent().value().get().perform_layout();
  if (can_raise_events()) location_changed(*this, e);
}

void control::on_lost_focus(const event_args& e) {
  if (can_raise_events()) lost_focus(*this, e);
}

void control::on_mouse_click(const mouse_event_args& e) {
  if (can_raise_events()) mouse_click(*this, e);
}

void control::on_mouse_double_click(const mouse_event_args& e) {
  if (can_raise_events()) mouse_double_click(*this, e);
}

void control::on_mouse_down(const mouse_event_args& e) {
  if (mouse_buttons_ == forms::mouse_buttons::right && data_->context_menu.has_value())
    native::control::context_menu(handle(), data_->context_menu.value().get().handle(), e.location());
  if (control_appearance() == xtd::forms::control_appearance::standard && enabled()) {
    data_->control_state = xtd::forms::visual_styles::control_state::pressed;
    //invalidate();
  }
  if (can_raise_events()) mouse_down(*this, e);
}

void control::on_mouse_horizontal_wheel(const mouse_event_args& e) {
  if (can_raise_events()) mouse_horizontal_wheel(*this, e);
}

void control::on_mouse_enter(const event_args& e) {
  if (control_appearance() == xtd::forms::control_appearance::standard && enabled()) {
    data_->control_state = (mouse_buttons() & mouse_buttons::left) == mouse_buttons::left ? xtd::forms::visual_styles::control_state::pressed : xtd::forms::visual_styles::control_state::hot;
    //invalidate();
  }
  if (can_raise_events()) mouse_enter(*this, e);
}

void control::on_mouse_leave(const event_args& e) {
  if (control_appearance() == xtd::forms::control_appearance::standard && enabled()) {
    data_->control_state = xtd::forms::visual_styles::control_state::normal;
    //invalidate();
  }
  if (can_raise_events()) mouse_leave(*this, e);
}

void control::on_mouse_move(const mouse_event_args& e) {
  if (can_raise_events()) mouse_move(*this, e);
}

void control::on_mouse_up(const mouse_event_args& e) {
  if (control_appearance() == xtd::forms::control_appearance::standard && enabled() && data_->control_state == xtd::forms::visual_styles::control_state::pressed) {
    data_->control_state = xtd::forms::visual_styles::control_state::hot;
    //invalidate();
  }
  if (can_raise_events()) mouse_up(*this, e);
}

void control::on_mouse_wheel(const mouse_event_args& e) {
  if (can_raise_events()) mouse_wheel(*this, e);
}

void control::on_move(const event_args& e) {
  if (can_raise_events()) move(*this, e);
}

void control::on_paint(paint_event_args& e) {
  def_wnd_proc(e.message_);
  if (data_->background_image != xtd::drawing::image::empty) control_paint::draw_image(e.graphics(), data_->background_image, e.clip_rectangle(), data_->background_image_layout);
  if (can_raise_events()) paint(*this, e);
}

void control::on_paint_background(paint_event_args& e) {
  def_wnd_proc(e.message_);
}

void control::on_parent_back_color_changed(const event_args& e) {
  if (!data_->back_color.has_value() || (parent().has_value() && parent().value().get().back_color() != data_->back_color.value())) {
    if (!parent().value().get().data_->back_color.has_value()) post_recreate_handle();
    else if (is_handle_created()) native::control::back_color(handle(), parent().value().get().back_color());
    for (auto control : controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
}

void control::on_parent_changed(const event_args& e) {
  if (!get_state(state::destroying) && parent().has_value() && !parent().value().get().get_state(state::destroying)) perform_layout();
  if (can_raise_events()) parent_changed(*this, e);
}

void control::on_parent_cursor_changed(const event_args& e) {
  if (!data_->cursor.has_value() || (parent().has_value() && parent().value().get().cursor() != data_->cursor.value())) {
    if (!parent().value().get().data_->cursor.has_value()) post_recreate_handle();
    else if (is_handle_created()) native::control::cursor(handle(), parent().value().get().cursor().handle());
    for (auto control : controls())
      control.get().on_parent_back_color_changed(event_args::empty);
  }
}

void control::on_parent_enabled_changed(const event_args& e) {
  if (parent().has_value()) {
    set_state(state::enabled, parent().value().get().enabled());
    if (is_handle_created()) native::control::enabled(handle(), get_state(state::enabled));
    for (auto control : controls())
      control.get().on_parent_enabled_changed(event_args::empty);
  }
}

void control::on_parent_fore_color_changed(const event_args& e) {
  if (!data_->fore_color.has_value() || (parent().has_value() && parent().value().get().fore_color() != data_->fore_color.value())) {
    if (!parent().value().get().data_->fore_color.has_value()) post_recreate_handle();
    else if (is_handle_created()) native::control::fore_color(handle(), parent().value().get().fore_color());
    for (auto control : controls())
      control.get().on_parent_fore_color_changed(event_args::empty);
  }
}

void control::on_parent_font_changed(const event_args& e) {
  if (!data_->font.has_value() || (parent().has_value() && parent().value().get().font() != font())) {
    if (!parent().value().get().data_->font.has_value()) post_recreate_handle();
    else if (is_handle_created()) native::control::font(handle(), parent().value().get().font());
    for (auto control : controls())
      control.get().on_parent_font_changed(event_args::empty);
  }
}

void control::on_region_changed(const event_args& e) {
  if (can_raise_events()) region_changed(*this, e);
}

void control::on_resize(const event_args& e) {
  if (minimum_client_size() != xtd::drawing::size::empty && client_size().width() < minimum_client_size().width())
    client_size({minimum_client_size().width(), client_size().height()});
    
  if (minimum_client_size() != xtd::drawing::size::empty && client_size().height() < minimum_client_size().height())
    client_size({client_size().width(), minimum_client_size().height()});
    
  if (minimum_size() != xtd::drawing::size::empty && size().width() < minimum_size().width())
    size({minimum_size().width(), size().height()});
    
  if (minimum_size() != xtd::drawing::size::empty && size().height() < minimum_size().height())
    size({size().width(), minimum_size().height()});
    
  if (maximum_client_size() != xtd::drawing::size::empty && client_size().width() > maximum_client_size().width())
    client_size({maximum_client_size().width(), client_size().height()});
    
  if (maximum_client_size() != xtd::drawing::size::empty && client_size().height() > maximum_client_size().height())
    client_size({client_size().width(), maximum_client_size().height()});
    
  if (maximum_size() != xtd::drawing::size::empty && size().width() > maximum_size().width())
    size({maximum_size().width(), size().height()});
    
  if (maximum_size() != xtd::drawing::size::empty && size().height() > maximum_size().height())
    size({size().width(), maximum_size().height()});
    
  if (is_handle_created()) data_->client_rectangle = native::control::client_rectangle(handle());
  if (parent().has_value() && parent().value().get().auto_size()) parent().value().get().perform_layout();
  perform_layout();
  invalidate();
  
  if (can_raise_events()) resize(*this, e);
}

void control::on_size_changed(const event_args& e) {
  if (is_handle_created()) data_->client_rectangle = native::control::client_rectangle(handle());
  if (can_raise_events()) size_changed(*this, e);
}

void control::on_style_sheet_changed(const event_args& e) {
  if (control_appearance() == forms::control_appearance::system) {
    back_color(default_back_color());
    cursor(default_cursor());
    font(default_font());
    fore_color(default_fore_color());
  }
  invalidate(true);
  refresh();
  if (can_raise_events()) style_sheet_changed(*this, e);
}

void control::on_tab_stop_changed(const event_args& e) {
  post_recreate_handle();
  if (can_raise_events()) tab_stop_changed(*this, e);
}

void control::on_text_changed(const event_args& e) {
  if (parent().has_value() && parent().value().get().auto_size()) parent().value().get().perform_layout();
  if (data_->control_appearance == forms::control_appearance::standard) invalidate();
  perform_layout();
  if (can_raise_events()) text_changed(*this, e);
}

void control::on_visible_changed(const event_args& e) {
  if (is_handle_created()) set_state(state::visible, native::control::visible(handle()));
  if (focused())
    focus();
  for (auto item : data_->controls)
    if (item.get().focused()) item.get().focus();
  if (parent().has_value() && parent().value().get().auto_size()) parent().value().get().perform_layout();
  if (can_raise_events()) visible_changed(*this, e);
}

void control::perform_layout() {
  if (get_state(state::layout_deferred) || reentrant_layout::is_reentrant(this)) return;
  reentrant_layout reentrant_laout(this);
  on_layout(event_args::empty);
}

drawing::point control::point_to_client(const xtd::drawing::point& p) const {
  return is_handle_created() ? native::control::point_to_client(handle(), p) : drawing::point {};
}

drawing::point control::point_to_screen(const xtd::drawing::point& p) const {
  return is_handle_created() ? native::control::point_to_screen(handle(), p) : drawing::point {};
}

bool control::pre_process_message(xtd::forms::message& message) {
  auto message_processed = false;
  for (auto child : controls()) {
    message_processed = child.get().pre_process_message(message);
    if (message_processed) break;
  }
  return message_processed;
}

void control::resume_layout() {
  resume_layout(true);
}

void control::resume_layout(bool perform_layout) {
  set_state(state::layout_deferred, false);
  native::control::resume_layout(handle());
  if (perform_layout) this->perform_layout();
}

void control::refresh() const {
  invalidate(true);
  update();
}

intptr control::send_message(intptr hwnd, int32 msg, intptr wparam, intptr lparam) const {
  return is_handle_created() ? native::control::send_message(handle(), hwnd, msg, wparam, lparam) : static_cast<intptr>(-1);
}

void control::set_auto_size_mode(forms::auto_size_mode value) {
  if (data_->auto_size_mode != value) {
    data_->auto_size_mode = value;
    perform_layout();
  }
}

void control::set_bounds(int32 x, int32 y, int32 width, int32 height) {
  set_bounds(x, y, width, height, bounds_specified::all);
}

void control::set_bounds(int32 x, int32 y, int32 width, int32 height, bounds_specified specified) {
  set_bounds_core(x, y, width, height, specified);
}

void control::set_state(control::state flag, bool value) {
  data_->state = static_cast<control::state>(value ? (static_cast<int32>(data_->state) | static_cast<int32>(flag)) : (static_cast<int32>(data_->state) & ~ static_cast<int32>(flag)));
}

void control::set_can_focus(bool value) {
  data_->can_focus = value;
}

void control::set_text(const xtd::ustring& text) {
  data_->text = text;
}

void control::set_mouse_buttons(forms::mouse_buttons value) {
  mouse_buttons_ = value;
}

void control::set_parent(intptr handle) {
  data_->parent = handle;
}

void control::set_style(control_styles flag, bool value) {
  data_->style = value ? (control_styles)((int32)data_->style | (int32)flag) : (control_styles)((int32)data_->style & ~(int32)flag);
}

void control::show() {
  visible(true);
}

void control::suspend_layout() {
  set_state(state::layout_deferred, true);
  native::control::suspend_layout(handle());
}

ustring control::to_string() const noexcept {
  if (!data_->name.empty()) return ustring::format("{}, name: {}", get_type().full_name(), data_->name);
  if (!data_->text.empty()) return ustring::format("{}, text: {}", get_type().full_name(), data_->text);
  return get_type().full_name();
}

void control::update() const {
  if (is_handle_created()) native::control::update(handle());
}

control& control::operator <<(control& child) {
  child.parent(*this);
  return *this;
}

control& control::operator >>(control& child) {
  if (child.parent().has_value() && &child.parent().value().get() == this)
    child.parent(nullptr);
  return *this;
}

void control::reflect_message(intptr handle, message& message) { // message parameter can't be const by design.
  if (handle != 0 && from_handle(handle).has_value())
    from_handle(handle).value().get().send_message(handle, WM_REFLECT + message.msg(), message.wparam(), message.lparam());
}

intptr control::wnd_proc_(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr handle) {
  //try {
  auto message = forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
  wnd_proc(message);
  return message.result();
  /*
  } catch(const exception& e) {
    message_box::show(from_handle(hwnd).value(), xtd::ustring::format("message: {}", e.what()), xtd::ustring::format("Exception {}", typeof_(e).name()), message_box_buttons::ok, message_box_icon::error);
  } catch(...) {
    message_box::show(from_handle(hwnd).value(), "message: An unknown exception occur", "Unknown Exception", message_box_buttons::ok, message_box_icon::error);
  }
  return 0;
   */
}

bool control::on_context_menu_item_click(xtd::forms::context_menu& menu, intptr menu_id) const {
  return menu.on_item_click(menu_id);
}

void control::show_context_menu(xtd::forms::context_menu& menu, const xtd::drawing::point& pos) const {
  on_context_menu_item_click(menu, native::control::user_context_menu(handle(), menu.handle(), pos));
}

void control::wnd_proc(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::events), ustring::format("({}) receive message [{}]", *this, message));
  switch (message.msg()) {
    // keyboard events
    case WM_CHAR:
    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSCHAR:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP: wm_key_char(message); break;
    case WM_KILLFOCUS: wm_kill_focus(message); break;
    case WM_SETFOCUS: wm_set_focus(message); break;
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
    case WM_MOUSEHWHEEL:
    case WM_MOUSEWHEEL: wm_mouse_wheel(message); break;
    // Color events
    case WM_CTLCOLORDLG:
    case WM_CTLCOLORMSGBOX:
    case WM_CTLCOLOR:
    case WM_CTLCOLORBTN:
    case WM_CTLCOLORSCROLLBAR:
    case WM_CTLCOLOREDIT:
    case WM_CTLCOLORLISTBOX:
    case WM_CTLCOLORSTATIC: wm_ctlcolor(message); break;
    case WM_ERASEBKGND: wm_erase_background(message); break;
    // Scrolling events
    case WM_HSCROLL:
    case WM_VSCROLL: wm_scroll(message); break;
    // System events
    case WM_CHILDACTIVATE: wm_child_activate(message); break;
    case WM_COMMAND: wm_command(message); break;
    case WM_CREATE: wm_create(message); break;
    case WM_DESTROY: wm_destroy(message); break;
    case WM_HELP: wm_help(message); break;
    case WM_MENUCOMMAND: wm_menu_command(message); break;
    case WM_MOVE: wm_move(message);  break;
    case WM_NOTIFY: wm_notify(message); break;
    case WM_PAINT: wm_paint(message); break;
    case WM_SETTEXT: wm_set_text(message); break;
    case WM_SHOWWINDOW: wm_show(message); break;
    case WM_SIZE: wm_size(message); break;
    case WM_SIZING: wm_sizing(message); break;
    case WM_STYLE_SHEET_CHANGED: wm_style_sheet_changed(message); break;
    case WM_APPIDLE: wm_app_idle(message); break;
    // Reflect events
    case WM_REFLECT + WM_CTLCOLORDLG:
    case WM_REFLECT + WM_CTLCOLORMSGBOX:
    case WM_REFLECT + WM_CTLCOLOR:
    case WM_REFLECT + WM_CTLCOLORBTN:
    case WM_REFLECT + WM_CTLCOLORSCROLLBAR:
    case WM_REFLECT + WM_CTLCOLOREDIT:
    case WM_REFLECT + WM_CTLCOLORLISTBOX:
    case WM_REFLECT + WM_CTLCOLORSTATIC: return wm_ctlcolor_control(message); break;
    case WM_REFLECT + WM_COMMAND: return wm_command_control(message); break;
    case WM_REFLECT + WM_NOTIFY: wm_notify_control(message);  break;
    case WM_REFLECT + WM_HSCROLL:
    case WM_REFLECT + WM_VSCROLL: wm_scroll_control(message); break;
    default: def_wnd_proc(message); break;
  }
}

void control::create_handle() {
  set_state(state::creating_handle, true);
  auto params = create_params();
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::creation), ustring::format("create handle {} with params {}", *this, params));
  
  auto native_params = native::create_params {};
  native_params.caption = params.caption();
  native_params.class_name = params.class_name();
  native_params.class_style = params.class_style();
  native_params.ex_style = params.ex_style();
  native_params.location = params.location();
  native_params.param = params.param();
  native_params.parent = params.parent();
  native_params.style = params.style();
  native_params.size = params.size();
  data_->handle = native::control::create(native_params);
  suspend_layout();
  handles_[handle()] = this;
  native::control::register_wnd_proc(handle(), {*this, &control::wnd_proc_});
  for (auto child : data_->controls) {
    child.get().data_->parent = handle();
    child.get().create_handle();
  }
  on_handle_created(event_args::empty);
  set_state(state::creating_handle, false);
  resume_layout();
}

void control::destroy_handle() {
  if (!is_handle_created()) return;
  native::control::unregister_wnd_proc(handle());
  suspend_layout();
  for (auto child : data_->controls)
    child.get().destroy_handle();
  handles_.erase(handle());
  on_handle_destroyed(event_args::empty);
  native::control::destroy(handle());
  data_->handle = 0;
}

void control::def_wnd_proc(message& message) {
  if (is_handle_created() && message.handle()) message.result(native::control::def_wnd_proc(handle(), message.hwnd(), message.msg(), message.wparam(), message.lparam(), message.result(), message.handle()));
}

void control::recreate_handle() {
  if (is_handle_created()) {
    set_state(state::recreate, true);
    for (auto control : controls())
      control.get().set_state(state::parent_recreating, true);
      
    destroy_handle();
    create_handle();
    
    for (auto control : controls())
      control.get().set_state(state::parent_recreating, false);
    set_state(state::recreate, false);
    data_->recreate_handle_posted = false;
    
    perform_layout();
  }
}

void control::set_bounds_core(int32 x, int32 y, int32 width, int32 height, bounds_specified specified) {
  if ((specified & bounds_specified::x) == bounds_specified::x) data_->location.x(x);
  if ((specified & bounds_specified::y) == bounds_specified::y) data_->location.y(y);
  if ((specified & bounds_specified::width) == bounds_specified::width) {
    if (!data_->size.has_value()) data_->size = default_size();
    data_->size.value().width(width);
  }
  if ((specified & bounds_specified::height) == bounds_specified::height) {
    if (!data_->size.has_value()) data_->size = default_size();
    data_->size.value().height(height);
  }
  
  if ((specified & bounds_specified::width) == bounds_specified::width || (specified & bounds_specified::height) == bounds_specified::height) {
    if (size().width() < minimum_size().width()) data_->size.value().width(minimum_size().width());
    if (size().height() < minimum_size().height()) data_->size.value().height(minimum_size().height());
    if (!maximum_size().is_empty() && size().width() > maximum_size().width()) data_->size.value().width(maximum_size().width());
    if (!maximum_size().is_empty() && size().height() > maximum_size().height()) data_->size.value().height(maximum_size().height());
    
    if (is_handle_created()) native::control::size(handle(), size());
    on_client_size_changed(event_args::empty);
    on_size_changed(event_args::empty);
    on_resize(event_args::empty);
  }
  
  if ((specified & bounds_specified::x) == bounds_specified::x || (specified & bounds_specified::y) == bounds_specified::y) {
    if (is_handle_created()) native::control::location(handle(), location());
    on_location_changed(event_args::empty);
  }
  
  if (specified != bounds_specified::none) {
    if (parent().has_value()) parent().value().get().perform_layout();
    perform_layout();
  }
}

void control::set_client_size_core(int32 width, int32 height) {
  data_->client_size.width(width);
  data_->client_size.height(height);
  
  if (is_handle_created()) native::control::client_size(handle(), data_->client_size);
  on_client_size_changed(event_args::empty);
  on_size_changed(event_args::empty);
  on_resize(event_args::empty);
}

void control::on_controls_item_added(size_t, control_ref item) {
  on_control_added(control_event_args(item.get()));
  item.get().data_->parent = data_->handle;
  if (data_->handle)
    item.get().create_control();
}

void control::on_controls_item_removed(size_t, control_ref item) {
  on_control_removed(control_event_args(item.get()));
  item.get().data_->parent = 0;
  item.get().destroy_control();
}

void control::on_parent_size_changed(object& sender, const event_args& e) {
  if (!get_state(state::layout_deferred) && !reentrant_layout::is_reentrant(this))
    perform_layout();
}

void control::post_recreate_handle() noexcept {
  if (data_->handle)
    data_->recreate_handle_posted = true;
}

void control::do_layout_children_with_dock_style() {
  auto docked = false;
  for (auto control : data_->controls) {
    docked = control.get().get_state(state::docked);
    if (docked) break;
  }
  
  if (docked) {
    auto docking_rect = drawing::rectangle {{0, 0}, client_size()};
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("({}) do_layout :", *this));
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::indent();
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("docking_rect = {}", docking_rect));
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("padding = {}", data_->padding));
    docking_rect.x(docking_rect.left() + data_->padding.left());
    docking_rect.y(docking_rect.top() + data_->padding.top());
    docking_rect.width(docking_rect.width() - data_->padding.left() - data_->padding.right());
    docking_rect.height(docking_rect.height() - data_->padding.top() - data_->padding.bottom());
    for (auto iterator = data_->controls.rbegin(); iterator != data_->controls.rend(); ++iterator) {
      if (!iterator->get().visible()) continue;
      if (iterator->get().dock() == dock_style::top) {
        iterator->get().location({docking_rect.left(), docking_rect.top()});
        iterator->get().width(docking_rect.width());
        docking_rect.y(docking_rect.top() + iterator->get().height());
        docking_rect.height(docking_rect.height() - iterator->get().height());
        if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("top ({}) = location = {}, size = {}", iterator->get().name(), iterator->get().location(), iterator->get().size()));
      } else if (iterator->get().dock() == dock_style::bottom) {
        iterator->get().location({docking_rect.left(), docking_rect.bottom() - iterator->get().height()});
        iterator->get().width(docking_rect.width());
        docking_rect.height(docking_rect.height() - iterator->get().height());
        if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("bottom ({}) = location = {}, size = {}", iterator->get().name(), iterator->get().location(), iterator->get().size()));
      } else if (iterator->get().dock() == dock_style::left) {
        iterator->get().location({docking_rect.left(), docking_rect.top()});
        iterator->get().height(docking_rect.height());
        docking_rect.x(docking_rect.left() + iterator->get().width());
        docking_rect.width(docking_rect.width() - iterator->get().width());
        if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("left ({}) = location = {}, size = {}", iterator->get().name(), iterator->get().location(), iterator->get().size()));
      } else if (iterator->get().dock() == dock_style::right) {
        iterator->get().location({docking_rect.right() - iterator->get().width(), docking_rect.top()});
        iterator->get().height(docking_rect.height());
        docking_rect.width(docking_rect.width() - iterator->get().width());
        if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("right ({}) = location = {}, size = {}", iterator->get().name(), iterator->get().location(), iterator->get().size()));
      } else if (iterator->get().dock() == dock_style::fill) {
        iterator->get().location({docking_rect.left(), docking_rect.top()});
        iterator->get().size({docking_rect.width(), docking_rect.height()});
        if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("fill ({}) = location = {}, size = {}", iterator->get().name(), iterator->get().location(), iterator->get().size()));
      }
    }
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::unindent();
    if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::layout), ustring::format("({}) end do_layout :", *this));
  }
}

void control::do_layout_with_anchor_styles() {
  if (parent().has_value()) {
    if ((data_->anchor & anchor_styles::left) == anchor_styles::left && (data_->anchor & anchor_styles::right) != anchor_styles::right)
      left(left());
    else if ((data_->anchor & anchor_styles::left) == anchor_styles::left && (data_->anchor & anchor_styles::right) == anchor_styles::right)
      width(parent().value().get().client_size().width() - data_->anchoring.right() - left());
    else if ((data_->anchor & anchor_styles::left) != anchor_styles::left && (data_->anchor & anchor_styles::right) == anchor_styles::right)
      left(parent().value().get().client_size().width() - width() - data_->anchoring.right());
    else
      left(parent().value().get().client_size().width() / 2 -  width() / 2);
      
    if ((data_->anchor & anchor_styles::top) == anchor_styles::top && (data_->anchor & anchor_styles::bottom) != anchor_styles::bottom)
      top(top());
    else if ((data_->anchor & anchor_styles::top) == anchor_styles::top && (data_->anchor & anchor_styles::bottom) == anchor_styles::bottom)
      height(parent().value().get().client_size().height() - data_->anchoring.bottom() - top());
    else if ((data_->anchor & anchor_styles::top) != anchor_styles::top && (data_->anchor & anchor_styles::bottom) == anchor_styles::bottom)
      top(parent().value().get().client_size().height() - height() - data_->anchoring.bottom());
    else
      top(parent().value().get().client_size().height() / 2 - height() / 2);
  }
}

void control::do_layout_with_auto_size_mode() {
  if (get_state(state::auto_size)) {
    auto auto_size_size_ = measure_control();
    if (data_->auto_size_mode == auto_size_mode::grow_only && auto_size_size_.width() < data_->client_size.width())
      auto_size_size_.width(data_->client_size.width());
    if (data_->auto_size_mode == auto_size_mode::grow_only && auto_size_size_.height() < data_->client_size.height())
      auto_size_size_.height(data_->client_size.height());
    client_size(auto_size_size_);
  }
}

void control::wm_app_idle(message& message) {
  def_wnd_proc(message);
  for (auto control : controls())
    control.get().wnd_proc(message);
  if (data_->recreate_handle_posted)
    recreate_handle();
}

void control::wm_child_activate(message& message) {
  def_wnd_proc(message);
}

void control::wm_command(message& message) {
  def_wnd_proc(message);
  reflect_message(message.lparam(), message);
}

void control::wm_command_control(message& message) {
  if (HIWORD(message.wparam()) == BN_CLICKED) on_click(event_args::empty);
  def_wnd_proc(message);
}

void control::wm_ctlcolor(message& message) {
  def_wnd_proc(message);
  reflect_message(message.lparam(), message);
}

void control::wm_ctlcolor_control(message& message) {
  def_wnd_proc(message);
}

void control::wm_create(message& message) {
  def_wnd_proc(message);
  on_create_control();
}

void control::wm_destroy(message& message) {
  def_wnd_proc(message);
  on_destroy_control();
}

void control::wm_erase_background(message& message) {
  def_wnd_proc(message);
  paint_event_args e(*this, data_->client_rectangle);
  e.message_ = message;
  on_paint_background(e);
}

void control::wm_help(message& message) {
  def_wnd_proc(message);
  HELPINFO* help_info = reinterpret_cast<HELPINFO*>(message.lparam());
  help_event_args e(point(help_info->MousePos.x, help_info->MousePos.y));
  on_help_requested(e);
  if (!e.handled()) def_wnd_proc(message);
}

void control::wm_key_char(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::key_events), ustring::format("({}) receive message [{}]", *this, message));
  if (message.msg() == WM_KEYDOWN || message.msg() == WM_SYSKEYDOWN) {
    auto key_event_args = forms::key_event_args {static_cast<keys>(message.wparam())};
    modifier_keys_ = key_event_args.modifiers();
    on_key_down(key_event_args);
    data_->suppress_key_press = key_event_args.suppress_key_press();
    if (!key_event_args.handled()) def_wnd_proc(message);
  } else if ((message.msg() == WM_CHAR || message.msg() == WM_SYSCHAR) && data_->suppress_key_press == false && (message.wparam() > 255u || std::iscntrl(static_cast<int32>(message.wparam()))) == 0) {
    auto key_press_event_args = forms::key_press_event_args {static_cast<char32>(message.wparam())};
    on_key_press(key_press_event_args);
    message.result(key_press_event_args.handled());
    if (!key_press_event_args.handled()) def_wnd_proc(message);
  } else if (message.msg() == WM_KEYUP || message.msg() == WM_SYSKEYUP) {
    auto key_event_args = forms::key_event_args {static_cast<keys>(message.wparam())};
    modifier_keys_ = key_event_args.modifiers();
    on_key_up(key_event_args);
    message.result(key_event_args.handled());
    if (!key_event_args.handled()) def_wnd_proc(message);
  } else
    def_wnd_proc(message);
}

void control::wm_kill_focus(message& message) {
  def_wnd_proc(message);
  data_->focused = false;
  on_lost_focus(event_args::empty);
}

void control::wm_menu_command(message& message) {
  def_wnd_proc(message);
  if (data_->context_menu.has_value())
    on_context_menu_item_click(data_->context_menu.value().get(), message.wparam());
}

void control::wm_mouse_down(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  mouse_event_args e = mouse_event_args::create(message, get_state(state::double_click_fired));
  mouse_buttons_ |= e.button();
  def_wnd_proc(message);
  on_mouse_down(e);
}

void control::wm_mouse_double_click(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  def_wnd_proc(message);
  set_state(control::state::double_click_fired, message.msg() == WM_LBUTTONDBLCLK || message.msg() == WM_RBUTTONDBLCLK || message.msg() == WM_MBUTTONDBLCLK || message.msg() == WM_XBUTTONDBLCLK);
  
  if (get_state(control::state::double_click_fired) && get_style(control_styles::standard_double_click))
    on_double_click(event_args::empty);
  on_mouse_double_click(mouse_event_args::create(message, get_state(state::double_click_fired)));
}

void control::wm_mouse_enter(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  data_->mouse_in = true;
  def_wnd_proc(message);
  on_mouse_enter(event_args::empty);
}

void control::wm_mouse_leave(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  data_->mouse_in = false;
  def_wnd_proc(message);
  on_mouse_leave(event_args::empty);
}

void control::wm_mouse_move(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  def_wnd_proc(message);
  mouse_event_args e = mouse_event_args(wparam_to_mouse_buttons(message), get_state(control::state::double_click_fired) ? 2 : 1, {(int16)LOWORD(message.lparam()), (int16)HIWORD(message.lparam())}, 0);
  // Workaround : sometimes mouse enter and/or mouse leave message are not send
  // For example on macos when mouse down in control and mouse is moved out then moved in, the mouse enter message is not send...
  // The two followed line fixed it
  if (!data_->mouse_in && client_rectangle().contains(e.location())) {
    xtd::diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::trace_switch().trace_warning() && enable_debug::get(enable_debug::workaround), "Workaround : mouse enter event !!!");
    wm_mouse_enter(message);
  } else if (data_->mouse_in && !client_rectangle().contains(e.location())) {
    xtd::diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::trace_switch().trace_warning() && enable_debug::get(enable_debug::workaround), "Workaround : mouse leave event !!!");
    wm_mouse_leave(message);
  }
  on_mouse_move(e);
}

void control::wm_mouse_up(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  def_wnd_proc(message);
  mouse_event_args e = mouse_event_args::create(message);
  mouse_buttons_ &= ~e.button();
  if (client_rectangle().contains(e.location())) {
    if (e.button() == mouse_buttons::left && (get_style(control_styles::standard_click) || control_appearance() == control_appearance::standard)) on_click(event_args::empty);
    on_mouse_click(e);
  }
  on_mouse_up(e);
}

void control::wm_mouse_wheel(message& message) {
  if (enable_debug::trace_switch().trace_verbose()) diagnostics::debug::write_line_if(!is_trace_form_or_control(name()) && enable_debug::get(enable_debug::mouse_events), ustring::format("({}) receive message [{}]", *this, message));
  def_wnd_proc(message);
  if (message.msg() == WM_MOUSEHWHEEL)
    on_mouse_horizontal_wheel(mouse_event_args::create(message, get_state(state::double_click_fired), static_cast<int32>(HIWORD(message.wparam()))));
  else
    on_mouse_wheel(mouse_event_args::create(message, get_state(state::double_click_fired), static_cast<int32>(HIWORD(message.wparam()))));
}

void control::wm_move(message& message) {
  def_wnd_proc(message);
  if (data_->location != native::control::location(handle())) {
    data_->location = native::control::location(handle());
    on_location_changed(event_args::empty);
  }
  on_move(event_args::empty);
}

void control::wm_notify(message& message) {
  def_wnd_proc(message);
  reflect_message(reinterpret_cast<intptr>(reinterpret_cast<NMHDR*>(message.lparam())->hwndFrom), message);
}

void control::wm_notify_control(message& message) {
  def_wnd_proc(message);
}

void control::wm_paint(message& message) { // message parameter can't be const by design.
  auto e = paint_event_args {*this, data_->client_rectangle};
  e.message_ = message;
  //auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  //if (control_appearance() == forms::control_appearance::standard) control_renderer::draw_control(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt);
  on_paint(e);
}

void control::wm_scroll(message& message) {
  def_wnd_proc(message);
  reflect_message(message.lparam(), message);
}

void control::wm_scroll_control(message& message) {
  def_wnd_proc(message);
}

void control::wm_set_focus(message& message) {
  def_wnd_proc(message);
  data_->focused = true;
  on_got_focus(event_args::empty);
}

void control::wm_set_text(message& message) {
  def_wnd_proc(message);
  if (data_->text != reinterpret_cast<const wchar*>(message.lparam())) {
    data_->text = reinterpret_cast<const wchar*>(message.lparam());
    on_text_changed(event_args::empty);
  }
}

void control::wm_show(message& message) {
  def_wnd_proc(message);
  set_state(state::visible, message.wparam() != 0);
}

void control::wm_size(message& message) {
  def_wnd_proc(message);
  if (data_->client_size != native::control::client_size(handle())) {
    data_->client_size = native::control::client_size(handle());
    on_client_size_changed(event_args::empty);
  }
  if (size() != native::control::size(handle())) {
    data_->size = native::control::size(handle());
    on_size_changed(event_args::empty);
  }
  on_resize(event_args::empty);
}

void control::wm_sizing(message& message) {
  def_wnd_proc(message);
}

void control::wm_style_sheet_changed(message& message) {
  def_wnd_proc(message);
  on_style_sheet_changed(event_args::empty);
}
