#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/form_renderer.h"
#include "../../../include/xtd/forms/screen.h"
#include "../../../include/xtd/forms/style_sheets/style_sheet.h"
#include <xtd/diagnostics/debug>
#include <xtd/drawing/system_colors>
#include <xtd/drawing/system_icons>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/class_styles>
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/form>
#include <xtd/forms/native/window_styles>
#include <xtd/forms/native/window_definitions>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/as>
#include <xtd/invalid_operation_exception>
#include <xtd/is>
#include <xtd/literals>
#include <xtd/random>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

struct form::data {
  std::optional<ibutton_control_ref> accept_button;
  std::optional<ibutton_control_ref> cancel_button;
  bool closed = false;
  bool close_box = true;
  bool control_box = true;
  forms::dialog_result dialog_result = forms::dialog_result::none;
  forms::form_border_style form_border_style = form_border_style::sizable;
  bool help_button = false;
  xtd::drawing::icon icon = xtd::drawing::icon::empty;
  bool maximize_box = true;
  std::optional<main_menu_ref> menu;
  bool minimize_box = true;
  double opacity = 1.0;
  const control* owner = nullptr;
  intptr parent_before_show_dialog = 0;
  std::shared_ptr<screen> previous_screen;
  bool show_icon = true;
  bool show_in_taskbar = true;
  form_start_position start_position = form_start_position::windows_default_location;
  std::optional<status_bar_ref> status_bar;
  std::optional<tool_bar_ref> tool_bar;
  bool top_most = false;
  form_window_state window_state = form_window_state::normal;
};

std::optional<form_ref> form::active_form_;

form::form() : data_(std::make_shared<data>()) {
  set_auto_size_mode(forms::auto_size_mode::grow_only);
  data_->icon = system_icons::xtd_forms_logo();
  set_state(state::visible, false);
  set_state(state::top_level, true);
  
  back_color(application::style_sheet().is_system_style_sheet() ? system_colors::control() : default_back_color());
  fore_color(application::style_sheet().is_system_style_sheet() ? system_colors::control_text() : default_fore_color());
  font(default_font());
  create_control();
}

std::optional<form::ibutton_control_ref> form::accept_button() const noexcept {
  return data_->accept_button;
}

form& form::accept_button(const ibutton_control& accept_button) {
  if (data_->accept_button.has_value() && &data_->accept_button.value().get() == &accept_button) return *this;
  if (data_->accept_button.has_value()) data_->accept_button.value().get().notify_default(false);
  data_->accept_button = const_cast<ibutton_control&>(accept_button);
  data_->accept_button.value().get().notify_default(true);
  return *this;
}

form& form::accept_button(std::nullptr_t) {
  if (data_->accept_button.has_value()) data_->accept_button.value().get().notify_default(false);
  data_->accept_button.reset();
  return *this;
}

std::optional<form_ref> form::active_form() noexcept {
  return active_form_;
}

forms::auto_size_mode form::auto_size_mode() const noexcept {
  return get_auto_size_mode();
}

form& form::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

std::optional<form::ibutton_control_ref> form::cancel_button() const noexcept {
  return data_->cancel_button;
}

form& form::cancel_button(const ibutton_control& cancel_button) {
  if (data_->cancel_button.has_value() && &data_->cancel_button.value().get() == &cancel_button) return *this;
  data_->cancel_button = const_cast<ibutton_control&>(cancel_button);
  return *this;
}

form& form::cancel_button(std::nullptr_t) {
  data_->cancel_button.reset();
  return *this;
}

bool form::close_box() const noexcept {
  return data_->close_box;
}

form& form::close_box(bool value) {
  if (data_->close_box == value) return *this;
  data_->close_box = value;
  post_recreate_handle();
  return *this;
}

bool form::control_box() const noexcept {
  return data_->control_box;
}

form& form::control_box(bool value) {
  if (data_->control_box == value) return *this;
  data_->control_box = value;
  post_recreate_handle();
  return *this;
}

forms::dialog_result form::dialog_result() const noexcept {
  return data_->dialog_result;
}

form& form::dialog_result(forms::dialog_result value) {
  data_->dialog_result = value;
  return *this;
}

control& form::font(std::nullptr_t) {
  return container_control::font(system_fonts::default_font());
}

forms::form_border_style form::form_border_style() const noexcept {
  return data_->form_border_style;
}

form& form::form_border_style(forms::form_border_style value) {
  if (data_->form_border_style == value) return *this;
  data_->form_border_style = value;
  post_recreate_handle();
  return *this;
}

bool form::help_button() const {
  return data_->help_button;
}

form& form::help_button(bool value) {
  if (data_->help_button == value) return *this;
  data_->help_button = value;
  post_recreate_handle();
  return *this;
}

const xtd::drawing::icon& form::icon() const noexcept {
  return data_->icon;
}

form& form::icon(const xtd::drawing::icon& value) {
  if (data_->icon == value) return *this;
  data_->icon = value != drawing::icon::empty ? value : system_icons::xtd_forms_logo();
  if (is_handle_created() && data_->show_icon) native::form::icon(handle(), data_->icon);
  return *this;
}

bool form::maximize_box() const noexcept {
  return data_->maximize_box;
}

form& form::maximize_box(bool value) {
  if (data_->maximize_box == value) return *this;
  data_->maximize_box = value;
  post_recreate_handle();
  return *this;
}

std::optional<form::main_menu_ref> form::menu() const noexcept {
  return data_->menu;
}

form& form::menu(const forms::main_menu& value) {
  if (data_->menu.has_value() && &data_->menu.value().get() == &value) return *this;
  data_->menu = const_cast<forms::main_menu&>(value);
  if (is_handle_created()) create_system_menu();
  return *this;
}

form& form::menu(std::nullptr_t) {
  if (!data_->menu.has_value()) return *this;
  if (is_handle_created()) destroy_system_menu();
  data_->menu.reset();
  return *this;
}

bool form::minimize_box() const noexcept {
  return data_->minimize_box;
}

form& form::minimize_box(bool value) {
  if (data_->minimize_box == value) return *this;
  data_->minimize_box = value;
  post_recreate_handle();
  return *this;
}

std::optional<control_ref> form::owner() const noexcept {
  return data_->owner ? std::optional<control_ref>(control_ref(const_cast<control&>(*data_->owner))) : std::optional<control_ref>();
}

bool form::modal() const noexcept {
  return get_state(state::modal);
}

double form::opacity() const noexcept {
  return data_->opacity;
}

form& form::opacity(double opacity) {
  if (data_->opacity == opacity) return *this;
  data_->opacity = opacity;
  if (is_handle_created()) native::form::opacity(handle(), data_->opacity);
  return *this;
}

form& form::owner(const control& value) {
  if (data_->owner && data_->owner->handle() == value.handle()) return *this;
  data_->owner = &value;
  post_recreate_handle();
  return *this;
}

form& form::owner(std::nullptr_t) {
  if (!data_->owner) return *this;
  data_->owner = nullptr;
  post_recreate_handle();
  return *this;
}

control& form::parent(const control& parent) {
  throw invalid_operation_exception("Top-level control cannot be added to a control."_t, csf_);
}

bool form::show_icon() const noexcept {
  return data_->show_icon;
}

form& form::show_icon(bool value) {
  if (data_->show_icon == value) return *this;
  data_->show_icon = value;
  post_recreate_handle();
  return *this;
}

bool form::show_in_taskbar() const noexcept {
  return data_->show_in_taskbar;
}

form& form::show_in_taskbar(bool value) {
  if (data_->show_in_taskbar == value) return *this;
  data_->show_in_taskbar = value;
  post_recreate_handle();
  return *this;
}

form_start_position form::start_position() const noexcept {
  return data_->start_position;
}

form& form::start_position(form_start_position start_position) {
  data_->start_position = start_position;
  return *this;
}

std::optional<form::status_bar_ref> form::status_bar() const noexcept {
  return data_->status_bar;
}

form& form::status_bar(const forms::status_bar& value) {
  if (data_->status_bar.has_value() && &data_->status_bar.value().get() == &value) return *this;
  data_->status_bar = const_cast<forms::status_bar&>(value);
  data_->status_bar.value().get().is_system_status_bar(true);
  return *this;
}

form& form::status_bar(std::nullptr_t) {
  if (!data_->status_bar.has_value()) return *this;
  data_->status_bar.value().get().is_system_status_bar(false);
  data_->status_bar.reset();
  return *this;
}

std::optional<form::tool_bar_ref> form::tool_bar() const noexcept {
  return data_->tool_bar;
}

form& form::tool_bar(const forms::tool_bar& value) {
  if (data_->tool_bar.has_value() && &data_->tool_bar.value().get() == &value) return *this;
  data_->tool_bar = const_cast<forms::tool_bar&>(value);
  data_->tool_bar.value().get().is_system_tool_bar(true);
  return *this;
}

form& form::tool_bar(std::nullptr_t) {
  if (!data_->tool_bar.has_value()) return *this;
  data_->tool_bar.value().get().is_system_tool_bar(false);
  data_->tool_bar.reset();
  return *this;
}

bool form::top_level() const noexcept {
  return get_state(state::top_level);
}

form& form::top_level(bool top_level) {
  if (!get_state(state::top_level) == top_level) return *this;
  set_state(state::top_level, top_level);
  return *this;
}

bool form::top_most() const noexcept {
  return data_->top_most;
}

form& form::top_most(bool value) {
  if (data_->top_most == value) return *this;
  data_->top_most = value;
  post_recreate_handle();
  return *this;
}

control& form::visible(bool visible) {
  std::optional<forms::form_window_state> current_window_state;
  if (!data_->previous_screen) {
    current_window_state = data_->window_state;
    data_->previous_screen = std::make_shared<screen>(screen::from_control(*this));
    recreate_handle();
  }
  
  application::raise_idle(event_args::empty);
  
  container_control::visible(visible);
  if (active_form().has_value() && active_form().value().get().handle() == handle() && active_control_.has_value())
    active_control_.value().get().focus();
    
  if (current_window_state.has_value())
    window_state(current_window_state.value());
  if (visible) {
    internal_set_window_state();
    data_->closed = false;
    if (data_->accept_button.has_value()) data_->accept_button.value().get().notify_default(true);
  }
  return *this;
}

form_window_state form::window_state() const noexcept {
  return data_->window_state;
}

form& form::window_state(form_window_state value) {
  if (data_->window_state != value) {
    data_->window_state = value;
    internal_set_window_state();
  }
  return *this;
}

void form::activate() {
  if (is_handle_created()) native::form::activate(handle());
}

void form::bring_to_front() {
  activate();
  control::focus();
}

void form::center_to_screen() {
  screen screen = screen::from_control(*this);
  left((screen.working_area().width() - width()) / 2);
  top((screen.working_area().height() - height()) / 2);
}

void form::close() {
  if (is_handle_created() && data_->previous_screen) native::form::close(handle());
}

form form::create() {
  return form {};
}

form form::create(const xtd::ustring& text) {
  auto result = form {};
  result.text(text);
  return result;
}

form form::create(const xtd::ustring& text, const drawing::point& location) {
  auto result = form {};
  result.text(text);
  result.start_position(form_start_position::manual);
  result.location(location);
  return result;
}

form form::create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size) {
  auto result = form {};
  result.text(text);
  result.start_position(form_start_position::manual);
  result.location(location);
  result.size(size);
  return result;
}

form form::create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = form {};
  result.text(text);
  result.start_position(form_start_position::manual);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

form form::create(const xtd::ustring& text, const drawing::size& size) {
  auto result = form {};
  result.text(text);
  result.size(size);
  return result;
}

form form::create(const xtd::ustring& text, const drawing::size& size, const xtd::ustring& name) {
  auto result = form {};
  result.text(text);
  result.size(size);
  result.name(name);
  return result;
}

form form::create(const xtd::ustring& text, form_start_position start_position) {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  return result;
}

form form::create(const xtd::ustring& text, form_start_position start_position, const drawing::point& location) {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  result.location(location);
  return result;
}

form form::create(const xtd::ustring& text, form_start_position start_position, const drawing::point& location, const drawing::size& size) {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  result.location(location);
  result.size(size);
  return result;
}

form form::create(const xtd::ustring& text, form_start_position start_position, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

form form::create(const xtd::ustring& text, form_start_position start_position, const drawing::size& size) {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  result.size(size);
  return result;
}

form form::create(const xtd::ustring& text, form_start_position start_position, const drawing::size& size, const xtd::ustring& name) {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  result.size(size);
  result.name(name);
  return result;
}

bool form::pre_process_message(const xtd::forms::message& message) {
  if (message.msg() == WM_KEYUP) {
    auto key_event_args = forms::key_event_args {static_cast<keys>(message.wparam())};
    if (key_event_args.key_data() == keys::enter && data_->accept_button.has_value()) {
      data_->accept_button.value().get().perform_click();
      return true;
    } else if (key_event_args.key_data() == keys::escape && data_->cancel_button.has_value()) {
      data_->cancel_button.value().get().perform_click();
      return true;
    }
  }
  
  return container_control::pre_process_message(message);
}

forms::dialog_result form::show_dialog() {
  data_->closed = false;
  set_state(state::modal, true);
  data_->previous_screen = std::make_shared<screen>(screen::from_control(*this));
  recreate_handle();
  data_->dialog_result = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  forms::dialog_result result = is_handle_created() ? static_cast<forms::dialog_result>(native::form::show_dialog(handle())) : dialog_result::cancel;
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

forms::dialog_result form::show_dialog(const iwin32_window& owner) {
  data_->closed = false;
  data_->parent_before_show_dialog = parent().has_value() ? parent().value().get().handle() : 0;
  set_state(state::modal, true);
  if (owner.handle() != handle()) set_parent(owner.handle());
  data_->previous_screen = std::make_shared<screen>(screen::from_control(*this));
  recreate_handle();
  data_->dialog_result = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  return is_handle_created() ? static_cast<forms::dialog_result>(native::form::show_dialog(handle())) : dialog_result::cancel;
}

void form::show_sheet(const iwin32_window& owner) {
  data_->closed = false;
  data_->parent_before_show_dialog = parent().has_value() ? parent().value().get().handle() : 0;
  set_state(state::modal, true);
  if (owner.handle() != handle()) set_parent(owner.handle());
  data_->previous_screen = std::make_shared<screen>(screen::from_control(*this));
  recreate_handle();
  data_->dialog_result = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  if (is_handle_created()) native::form::show_sheet(handle());
}

forms::dialog_result form::show_sheet_dialog(const iwin32_window& owner) {
  data_->closed = false;
  data_->parent_before_show_dialog = parent().has_value() ? parent().value().get().handle() : 0;
  set_state(state::modal, true);
  if (owner.handle() != handle()) set_parent(owner.handle());
  data_->previous_screen = std::make_shared<screen>(screen::from_control(*this));
  recreate_handle();
  data_->dialog_result = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  return is_handle_created() ? static_cast<forms::dialog_result>(native::form::show_sheet_dialog(handle())) : dialog_result::cancel;
}

forms::create_params form::create_params() const noexcept {
  auto create_params = container_control::create_params();

  create_params.class_name("form");
  
  if (get_state(state::modal)) create_params.ex_style(create_params.ex_style() | WS_EX_MODALWINDOW);
  if (data_->owner != nullptr) create_params.parent(data_->owner->handle());
  if (data_->top_most) create_params.ex_style(create_params.ex_style() | WS_EX_TOPMOST);
  if (!enabled())
    // Forms that are parent of a modal dialog must keep their WS_DISABLED style (VSWhidbey 449309)
    create_params.style(create_params.style() | WS_DISABLED);
  else if (top_level())
    // It doesn't seem to make sense to allow a top-level form to be disabled
    //
    create_params.style(create_params.style() & ~WS_DISABLED);
    
  if (top_level() && opacity() != 0)
    create_params.ex_style(create_params.ex_style() | WS_EX_LAYERED);
    
  fill_in_create_params_border_styles(create_params);
  fill_in_create_params_window_state(create_params);
  fill_in_create_params_border_icons(create_params);
  
  if (data_->show_in_taskbar)
    create_params.ex_style(create_params.ex_style() | WS_EX_APPWINDOW);
    
  xtd::forms::form_border_style border_style = form_border_style();
  if (!data_->show_icon && (border_style == xtd::forms::form_border_style::sizable || border_style == xtd::forms::form_border_style::fixed_3d || border_style == xtd::forms::form_border_style::fixed_single))
    create_params.ex_style(create_params.ex_style() | WS_EX_DLGMODALFRAME);
    
  if (top_level())
    fill_in_create_params_start_position(create_params);
    
  /*
  if (right_to_left == xtd::forms::right_to_left::yes && right_to_left_layout() == true) {
    create_params.ex_style(create_params.ex_style() | WS_EX_LAYOUTRTL | WS_EX_NOINHERITLAYOUT);
    create_params.ex_style(create_params.ex_style() & ~(WS_EX_RTLREADING | WS_EX_RIGHT | WS_EX_LEFTSCROLLBAR));
  }*/
  
  //diagnostics::debug::write_line("create_params = {}, style = {}, ex_style = {}", create_params, __windows_style_to_string__(create_params.style()), __windows_extended_style_to_string__(create_params.ex_style()));
  
  return create_params;
}

drawing::size form::default_size() const noexcept {
  return {300, 300};
}

std::unique_ptr<xtd::object> form::clone() const {
  auto result = make_unique<form>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::ustring::format("The {} does not implement clone method.", typeof_(*this).full_name()), csf_);
  return result;
}

void form::on_activated(const event_args& e) {
  activated(*this, e);
}

void form::on_deactivate(const event_args& e) {
  deactivate(*this, e);
}

void form::on_handle_created(const event_args& e) {
  container_control::on_handle_created(e);
  if (data_->show_icon && data_->icon != drawing::icon::empty) native::form::icon(handle(), data_->icon);
  if (data_->accept_button.has_value()) data_->accept_button.value().get().notify_default(true);
  if (data_->opacity != 1.0) native::form::opacity(handle(), data_->opacity);
  if (!region().is_empty() && !region().is_infinite()) native::form::set_region(handle(), region().handle());
  
  if (data_->menu.has_value()) create_system_menu();
}

void form::on_handle_destroyed(const event_args& e) {
  container_control::on_handle_destroyed(e);
  destroy_system_menu();
}

void form::on_form_closed(const form_closed_event_args& e) {
  static auto closing = false;
  if (closing) return;
  closing = true;
  form_closed(*this, e);
  closing = false;
}

void form::on_form_closing(form_closing_event_args& e) {
  form_closing(*this, e);
}

void form::on_layout(const event_args& e) {
  scrollable_control::on_layout(e);
  if (is_handle_created() && auto_scroll()) native::form::virtual_size(handle(), display_rectangle().size());
}

void form::on_location_changed(const event_args& e) {
  if (handle() && top() < screen::get_working_area(handle()).top()) top(screen::get_working_area(handle()).top());
  container_control::on_location_changed(e);
}

void form::on_paint(paint_event_args& e) {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (control_appearance() == forms::control_appearance::standard) form_renderer::draw_form(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt);
  container_control::on_paint(e);
}

void form::on_region_changed(const event_args& e) {
  native::form::set_region(handle(), region().handle());
  container_control::on_region_changed(e);
}

void form::on_resize(const event_args& e) {
  if (is_handle_created()) {
    if (native::form::minimize(handle()))
      data_->window_state = forms::form_window_state::minimized;
    else if (native::form::maximize(handle()))
      data_->window_state = forms::form_window_state::maximized;
    else if (native::form::full_screen(handle()))
      data_->window_state = forms::form_window_state::full_screen;
    else
      data_->window_state = forms::form_window_state::normal;
  }
  container_control::on_resize(e);
}

void form::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_ACTIVATE: wm_activate(message); break;
    case WM_CLOSE: wm_close(message); break;
    case WM_MENUCOMMAND: if (data_->menu.has_value()) data_->menu.value().get().wm_click(message); break;
    case WM_SYSCOLORCHANGE: wm_syscolor_change(message); break;
    case WM_RECREATE: wm_recreate(message); break;
    default: container_control::wnd_proc(message); break;
  }
}

bool form::closed_() const noexcept {
  return data_->closed;
}

void form::internal_set_window_state() {
  if (!data_->previous_screen)
    post_recreate_handle();
  else if (is_handle_created()) {
    switch (data_->window_state) {
      case form_window_state::normal: native::form::restore(handle()); break;
      case form_window_state::maximized: native::form::maximize(handle(), true); break;
      case form_window_state::minimized: native::form::minimize(handle(), true); break;
      case form_window_state::full_screen: native::form::full_screen(handle(), true); break;
      default: break;
    }
  }
}

void form::create_system_menu() {
  if (!data_->menu.has_value()) return;
  
  // Workaround : Get client size because afer changing tool bar to system, the client size does not correct.
  auto prev_client_size = client_size();
  
  native::form::menu(handle(), data_->menu.value().get().handle());
  
  // Workaround : Force the client size with the previously saved client size.
  client_size(prev_client_size);
}

void form::destroy_system_menu() {
  if (!data_->menu) return;
  
  // Workaround : Get client size because afer changing tool bar to system, the client size does not correct.
  auto prev_client_size = client_size();
  
  native::form::menu(handle(), 0);
  
  // Workaround : Force the client size with the previously saved client size.
  client_size(prev_client_size);
}

void form::fill_in_create_params_border_styles(xtd::forms::create_params& create_params) const {
  switch (data_->form_border_style) {
    case xtd::forms::form_border_style::none: break;
    case xtd::forms::form_border_style::fixed_single: create_params.style(create_params.style() | WS_BORDER); break;
    case xtd::forms::form_border_style::sizable: create_params.style(create_params.style() | WS_BORDER | WS_THICKFRAME); break;
    case xtd::forms::form_border_style::fixed_3d:
      create_params.style(create_params.style() | WS_BORDER);
      create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);
      break;
    case xtd::forms::form_border_style::fixed_dialog:
      create_params.style(create_params.style() | WS_BORDER);
      create_params.ex_style(create_params.ex_style() | WS_EX_DLGMODALFRAME);
      break;
    case xtd::forms::form_border_style::fixed_tool_window:
      create_params.style(create_params.style() | WS_BORDER);
      create_params.ex_style(create_params.ex_style() | WS_EX_TOOLWINDOW);
      break;
    case xtd::forms::form_border_style::sizable_tool_window:
      create_params.style(create_params.style() | WS_BORDER | WS_THICKFRAME);
      create_params.ex_style(create_params.ex_style() | WS_EX_TOOLWINDOW);
      break;
  }
}

void form::fill_in_create_params_border_icons(xtd::forms::create_params& create_params) const {
  if (data_->form_border_style == xtd::forms::form_border_style::none)
    create_params.class_style(create_params.class_style() | CS_NOCLOSE);
  else {
    if (!text().empty())
      create_params.style(create_params.style() | WS_CAPTION);
      
    if (data_->control_box)
      create_params.style(create_params.style() | WS_SYSMENU | WS_CAPTION);
    else
      create_params.style(create_params.style() & ~WS_SYSMENU);
      
    if (!data_->close_box)
      create_params.class_style(create_params.class_style() | CS_NOCLOSE);
    else
      create_params.class_style(create_params.class_style() & ~CS_NOCLOSE);
      
    if (data_->maximize_box)
      create_params.style(create_params.style() | WS_MAXIMIZEBOX);
    else
      create_params.style(create_params.style() & ~WS_MAXIMIZEBOX);
      
    if (data_->minimize_box)
      create_params.style(create_params.style() | WS_MINIMIZEBOX);
    else
      create_params.style(create_params.style() & ~WS_MINIMIZEBOX);
      
    if (data_->help_button && !data_->maximize_box && !data_->minimize_box && data_->control_box)
      create_params.ex_style(create_params.ex_style() | WS_EX_CONTEXTHELP);
    else
      create_params.ex_style(create_params.ex_style() & ~WS_EX_CONTEXTHELP);
  }
}

void form::fill_in_create_params_start_position(xtd::forms::create_params& create_params) const {
  static auto default_location = 0;
  if (default_location == 0)
    default_location = xtd::random().next(4, 20) * 10;
    
  if (data_->previous_screen) {
    switch (data_->start_position) {
      case form_start_position::manual:
        create_params.location(location());
        create_params.size(size());
        break;
      case form_start_position::center_screen:
        create_params.location({(data_->previous_screen->working_area().width() - width()) / 2, (data_->previous_screen->working_area().height() - height()) / 2});
        create_params.size(size());
        break;
      case form_start_position::windows_default_location:
        create_params.location({default_location, default_location});
        create_params.size(size());
        break;
      case form_start_position::windows_default_bounds:
        create_params.location({default_location, default_location});
        create_params.size({data_->previous_screen->working_area().width() / 4 * 3, data_->previous_screen->working_area().height() / 4 * 3});
        break;
      case form_start_position::center_parent:
        if (parent().has_value())
          create_params.location({parent().value().get().left() + (parent().value().get().width() - width()) / 2, parent().value().get().top() + (parent().value().get().height() - height()) / 2});
        else
          create_params.location({default_location, default_location});
        create_params.size(size());
        break;
    }
    
    if (data_->start_position == form_start_position::windows_default_location || data_->start_position == form_start_position::windows_default_bounds || (data_->start_position == form_start_position::center_parent && parent().has_value()))
      default_location = default_location < 200 ? default_location + 20 : 40;
  }
}

void form::fill_in_create_params_window_state(xtd::forms::create_params& create_params) const {
  switch (data_->window_state) {
    case form_window_state::maximized: create_params.style(create_params.style() | WS_MAXIMIZE); break;
    case form_window_state::minimized: create_params.style(create_params.style() | WS_MINIMIZE); break;
    default: break;
  }
}

void form::wm_activate(message& message) {
  if (message.lparam() == WA_INACTIVE && active_form_.has_value() && &active_form_.value().get() == this) {
    active_form_.reset();
    on_deactivate(event_args::empty);
  } else {
    active_form_ = *this;
    on_activated(event_args::empty);
  }
}

void form::wm_close(message& message) {
  if (data_->closed) return;
  auto event_args = form_closing_event_args {};
  on_form_closing(event_args);
  message.result(event_args.cancel() == true);
  if (event_args.cancel() != true) {
    data_->closed = true;
    if (!get_state(state::modal))
      hide();
    else {
      if (data_->dialog_result == forms::dialog_result::none) data_->dialog_result = forms::dialog_result::cancel;
      native::form::end_dialog(handle(), static_cast<int32>(data_->dialog_result));
      set_parent(data_->parent_before_show_dialog);
      set_state(state::modal, false);
      post_recreate_handle();
    }
    on_form_closed(form_closed_event_args());
  }
}

void form::wm_recreate(message& message) {
  auto current_location = location();
  recreate_handle();
  location(current_location);
}

void form::wm_syscolor_change(message& message) {
  def_wnd_proc(message);
  if (&application::open_forms()[0].get() == this) style_sheets::style_sheet::on_system_colors_changed(event_args::empty);
  on_system_colors_changed(event_args::empty);
}
