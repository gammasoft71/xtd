#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/form.hpp"
#include "../../../include/xtd/forms/form_renderer.hpp"
#include "../../../include/xtd/forms/screen.hpp"
#include "../../../include/xtd/forms/style_sheets/style_sheet.hpp"
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
#include <xtd/random>
#include <xtd/globalization/translator>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::helpers;

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
  xtd::sptr<screen> previous_screen;
  bool show_icon = true;
  bool show_in_taskbar = true;
  form_start_position start_position = form_start_position::windows_default_location;
  std::optional<status_bar_ref> status_bar;
  std::optional<tool_bar_ref> tool_bar;
  bool top_most = false;
  form_window_state window_state = form_window_state::normal;
};

std::optional<form_ref> form::active_form_;

form::form() : data_(xtd::new_sptr<data>()) {
  set_auto_size_mode(forms::auto_size_mode::grow_only);
  data_->icon = system_icons::xtd_forms_logo();
  set_state(state::visible, false);
  set_state(state::top_level, true);
  
  back_color(application::style_sheet().is_system_style_sheet() ? system_colors::control() : default_back_color());
  fore_color(application::style_sheet().is_system_style_sheet() ? system_colors::control_text() : default_fore_color());
  font(default_font());
  create_control();
}

auto form::accept_button() const noexcept -> std::optional<form::ibutton_control_ref> {
  return data_->accept_button;
}

auto form::accept_button(const ibutton_control& accept_button) -> form& {
  if (data_->accept_button.has_value() && &data_->accept_button.value().get() == &accept_button) return *this;
  if (data_->accept_button.has_value()) data_->accept_button.value().get().notify_default(false);
  data_->accept_button = const_cast<ibutton_control&>(accept_button);
  data_->accept_button.value().get().notify_default(true);
  return *this;
}

auto form::accept_button(std::nullptr_t) -> form& {
  if (data_->accept_button.has_value()) data_->accept_button.value().get().notify_default(false);
  data_->accept_button.reset();
  return *this;
}

auto form::active_form() noexcept -> std::optional<form_ref> {
  return active_form_;
}

auto form::auto_size_mode() const noexcept -> xtd::forms::auto_size_mode {
  return get_auto_size_mode();
}

auto form::auto_size_mode(xtd::forms::auto_size_mode value) -> form& {
  set_auto_size_mode(value);
  return *this;
}

auto form::cancel_button() const noexcept -> std::optional<ibutton_control_ref> {
  return data_->cancel_button;
}

auto form::cancel_button(const ibutton_control& cancel_button) -> form& {
  if (data_->cancel_button.has_value() && &data_->cancel_button.value().get() == &cancel_button) return *this;
  data_->cancel_button = const_cast<ibutton_control&>(cancel_button);
  return *this;
}

auto form::cancel_button(std::nullptr_t) -> form& {
  data_->cancel_button.reset();
  return *this;
}

auto form::close_box() const noexcept -> bool {
  return data_->close_box;
}

auto form::close_box(bool value) -> form& {
  if (data_->close_box == value) return *this;
  data_->close_box = value;
  post_recreate_handle();
  return *this;
}

auto form::control_box() const noexcept -> bool {
  return data_->control_box;
}

auto form::control_box(bool value) -> form& {
  if (data_->control_box == value) return *this;
  data_->control_box = value;
  post_recreate_handle();
  return *this;
}

auto form::dialog_result() const noexcept -> xtd::forms::dialog_result {
  return data_->dialog_result;
}

auto form::dialog_result(xtd::forms::dialog_result value) -> form& {
  data_->dialog_result = value;
  return *this;
}

auto form::font(null_ptr) -> control& {
  return container_control::font(system_fonts::default_font());
}

auto form::form_border_style() const noexcept -> xtd::forms::form_border_style {
  return data_->form_border_style;
}

auto form::form_border_style(forms::form_border_style value) -> form& {
  if (data_->form_border_style == value) return *this;
  data_->form_border_style = value;
  post_recreate_handle();
  return *this;
}

auto form::help_button() const -> bool {
  return data_->help_button;
}

auto form::help_button(bool value) -> form& {
  if (data_->help_button == value) return *this;
  data_->help_button = value;
  post_recreate_handle();
  return *this;
}

auto form::icon() const noexcept -> const xtd::drawing::icon& {
  return data_->icon;
}

auto form::icon(const xtd::drawing::icon& value) -> form& {
  if (data_->icon == value) return *this;
  data_->icon = value != xtd::drawing::icon::empty ? value : system_icons::xtd_forms_logo();
  if (is_handle_created() && data_->show_icon) native::form::icon(handle(), data_->icon);
  return *this;
}

auto form::maximize_box() const noexcept -> bool {
  return data_->maximize_box;
}

auto form::maximize_box(bool value) -> form& {
  if (data_->maximize_box == value) return *this;
  data_->maximize_box = value;
  post_recreate_handle();
  return *this;
}

auto form::menu() const noexcept -> std::optional<main_menu_ref> {
  return data_->menu;
}

auto form::menu(const xtd::forms::main_menu& value) -> form& {
  if (data_->menu.has_value() && &data_->menu.value().get() == &value) return *this;
  data_->menu = const_cast<forms::main_menu&>(value);
  if (is_handle_created()) create_system_menu();
  return *this;
}

auto form::menu(null_ptr) -> form& {
  if (!data_->menu.has_value()) return *this;
  if (is_handle_created()) destroy_system_menu();
  data_->menu.reset();
  return *this;
}

auto form::minimize_box() const noexcept -> bool {
  return data_->minimize_box;
}

auto form::minimize_box(bool value) -> form& {
  if (data_->minimize_box == value) return *this;
  data_->minimize_box = value;
  post_recreate_handle();
  return *this;
}

auto form::owner() const noexcept -> std::optional<control_ref> {
  return data_->owner ? std::optional<control_ref>(control_ref(const_cast<control&>(*data_->owner))) : std::optional<control_ref>();
}

auto form::modal() const noexcept -> bool {
  return get_state(state::modal);
}

auto form::opacity() const noexcept -> double {
  return data_->opacity;
}

auto form::opacity(double opacity) -> form& {
  if (data_->opacity == opacity) return *this;
  data_->opacity = opacity;
  if (is_handle_created()) native::form::opacity(handle(), data_->opacity);
  return *this;
}

auto form::owner(const control& value) -> form& {
  if (data_->owner && data_->owner->handle() == value.handle()) return *this;
  data_->owner = &value;
  post_recreate_handle();
  return *this;
}

auto form::owner(null_ptr) -> form& {
  if (!data_->owner) return *this;
  data_->owner = nullptr;
  post_recreate_handle();
  return *this;
}

auto form::parent(const control& parent) -> control& {
  throw_helper::throws(exception_case::invalid_operation, "Top-level control cannot be added to a control.");
}

auto form::show_icon() const noexcept -> bool {
  return data_->show_icon;
}

auto form::show_icon(bool value) -> form& {
  if (data_->show_icon == value) return *this;
  data_->show_icon = value;
  post_recreate_handle();
  return *this;
}

auto form::show_in_taskbar() const noexcept -> bool {
  return data_->show_in_taskbar;
}

auto form::show_in_taskbar(bool value) -> form& {
  if (data_->show_in_taskbar == value) return *this;
  data_->show_in_taskbar = value;
  post_recreate_handle();
  return *this;
}

auto form::start_position() const noexcept -> form_start_position {
  return data_->start_position;
}

auto form::start_position(form_start_position start_position) -> form& {
  data_->start_position = start_position;
  return *this;
}

auto form::status_bar() const noexcept -> std::optional<status_bar_ref> {
  return data_->status_bar;
}

auto form::status_bar(const forms::status_bar& value) -> form& {
  if (data_->status_bar.has_value() && &data_->status_bar.value().get() == &value) return *this;
  data_->status_bar = const_cast<forms::status_bar&>(value);
  data_->status_bar.value().get().system_status_bar(true);
  return *this;
}

auto form::status_bar(null_ptr) -> form& {
  if (!data_->status_bar.has_value()) return *this;
  data_->status_bar.value().get().system_status_bar(false);
  data_->status_bar.reset();
  return *this;
}

auto form::tool_bar() const noexcept -> std::optional<tool_bar_ref> {
  return data_->tool_bar;
}

auto form::tool_bar(const forms::tool_bar& value) -> form& {
  if (data_->tool_bar.has_value() && &data_->tool_bar.value().get() == &value) return *this;
  if (data_->tool_bar.has_value()) data_->tool_bar.value().get().system_tool_bar(false);
  data_->tool_bar = const_cast<forms::tool_bar&>(value);
  data_->tool_bar.value().get().system_tool_bar(true);
  return *this;
}

auto form::tool_bar(null_ptr) -> form& {
  if (!data_->tool_bar.has_value()) return *this;
  data_->tool_bar.value().get().system_tool_bar(false);
  data_->tool_bar.reset();
  return *this;
}

auto form::top_level() const noexcept -> bool {
  return get_state(state::top_level);
}

auto form::top_level(bool top_level) -> form& {
  if (!get_state(state::top_level) == top_level) return *this;
  set_state(state::top_level, top_level);
  return *this;
}

auto form::top_most() const noexcept -> bool {
  return data_->top_most;
}

auto form::top_most(bool value) -> form& {
  if (data_->top_most == value) return *this;
  data_->top_most = value;
  post_recreate_handle();
  return *this;
}

auto form::visible(bool visible) -> control& {
  auto current_window_state = std::optional<forms::form_window_state> {};
  if (!data_->previous_screen) {
    current_window_state = data_->window_state;
    data_->previous_screen = xtd::new_sptr<screen>(screen::from_control(*this));
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

auto form::window_state() const noexcept -> form_window_state {
  return data_->window_state;
}

auto form::window_state(form_window_state value) -> form& {
  if (data_->window_state != value) {
    data_->window_state = value;
    internal_set_window_state();
  }
  return *this;
}

auto form::activate() -> void {
  if (is_handle_created()) native::form::activate(handle());
}

auto form::bring_to_front() -> void {
  activate();
  control::focus();
}

auto form::center_to_screen() -> void {
  if (!data_->previous_screen) start_position(form_start_position::center_screen);
  else {
    screen screen = screen::from_control(*this);
    left((screen.working_area().width - width()) / 2);
    top((screen.working_area().height - height()) / 2);
  }
}

auto form::close() -> void {
  if (is_handle_created() && data_->previous_screen) native::form::close(handle());
}

auto form::create() -> form {
  return form {};
}

auto form::create(const xtd::string& text) -> form {
  auto result = form {};
  result.text(text);
  return result;
}

auto form::create(const xtd::string& text, const xtd::drawing::point& location) -> form {
  auto result = form {};
  result.text(text);
  result.start_position(form_start_position::manual);
  result.location(location);
  return result;
}

auto form::create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size) -> form {
  auto result = form {};
  result.text(text);
  result.start_position(form_start_position::manual);
  result.location(location);
  result.size(size);
  return result;
}

auto form::create(const xtd::string& text, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> form {
  auto result = form {};
  result.text(text);
  result.start_position(form_start_position::manual);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

auto form::create(const xtd::string& text, const xtd::drawing::size& size) -> form {
  auto result = form {};
  result.text(text);
  result.size(size);
  return result;
}

auto form::create(const xtd::string& text, const xtd::drawing::size& size, const xtd::string& name) -> form {
  auto result = form {};
  result.text(text);
  result.size(size);
  result.name(name);
  return result;
}

auto form::create(const xtd::string& text, form_start_position start_position) -> form {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  return result;
}

auto form::create(const xtd::string& text, form_start_position start_position, const xtd::drawing::point& location) -> form {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  result.location(location);
  return result;
}

auto form::create(const xtd::string& text, form_start_position start_position, const xtd::drawing::point& location, const xtd::drawing::size& size) -> form {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  result.location(location);
  result.size(size);
  return result;
}

auto form::create(const xtd::string& text, form_start_position start_position, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> form {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

auto form::create(const xtd::string& text, form_start_position start_position, const xtd::drawing::size& size) -> form {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  result.size(size);
  return result;
}

auto form::create(const xtd::string& text, form_start_position start_position, const xtd::drawing::size& size, const xtd::string& name) -> form {
  auto result = form {};
  result.text(text);
  result.start_position(start_position);
  result.size(size);
  result.name(name);
  return result;
}

auto form::pre_process_message(const xtd::forms::message& message) -> bool {
  if (message.msg == WM_KEYUP) {
    auto key_event_args = forms::key_event_args {static_cast<keys>(message.wparam)};
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

auto form::show_dialog() -> xtd::forms::dialog_result {
  data_->closed = false;
  set_state(state::modal, true);
  data_->previous_screen = xtd::new_sptr<screen>(screen::from_control(*this));
  recreate_handle();
  data_->dialog_result = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  forms::dialog_result result = is_handle_created() ? static_cast<forms::dialog_result>(native::form::show_dialog(handle())) : dialog_result::cancel;
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

auto form::show_dialog(const iwin32_window& owner) -> xtd::forms::dialog_result {
  data_->closed = false;
  data_->parent_before_show_dialog = parent().has_value() ? parent().value().get().handle() : 0;
  set_state(state::modal, true);
  if (owner.handle() != handle()) set_parent(owner.handle());
  data_->previous_screen = xtd::new_sptr<screen>(screen::from_control(*this));
  recreate_handle();
  data_->dialog_result = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  return is_handle_created() ? static_cast<forms::dialog_result>(native::form::show_dialog(handle())) : dialog_result::cancel;
}

namespace {
  class show_sheet_params_saver {
  public:
    show_sheet_params_saver(form* form) : form_ {form} {
      if (!form_) return;
      text_ = form_->text();
      control_box_ = form_->control_box();
      start_position_ = form_->start_position();
      location_ = form_->location();
      form_->start_position(form_start_position::center_parent).control_box(false).text("");
    }
    ~show_sheet_params_saver() {
      if (!form_) return;
      form_->start_position(start_position_).control_box(control_box_).text(text_).location(location_);
    }
  private:
    form* form_ = nullptr;
    string text_;
    bool control_box_ = false;
    form_start_position start_position_ = form_start_position::manual;
    point location_;
  };
}

auto form::show_sheet(const iwin32_window& owner) -> void {
  auto params_saver = show_sheet_params_saver {environment::os_version().is_macos_platform() ? nullptr : this};
  data_->closed = false;
  data_->parent_before_show_dialog = parent().has_value() ? parent().value().get().handle() : 0;
  set_state(state::modal, true);
  if (owner.handle() != handle()) set_parent(owner.handle());
  data_->previous_screen = xtd::new_sptr<screen>(screen::from_control(*this));
  recreate_handle();
  data_->dialog_result = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  if (is_handle_created()) native::form::show_sheet(handle());
}

auto form::show_sheet_dialog(const iwin32_window& owner) -> xtd::forms::dialog_result {
  auto params_saver = show_sheet_params_saver {this};
  data_->closed = false;
  data_->parent_before_show_dialog = parent().has_value() ? parent().value().get().handle() : 0;
  set_state(state::modal, true);
  if (owner.handle() != handle()) set_parent(owner.handle());
  data_->previous_screen = xtd::new_sptr<screen>(screen::from_control(*this));
  recreate_handle();
  data_->dialog_result = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  return is_handle_created() ? static_cast<forms::dialog_result>(native::form::show_sheet_dialog(handle())) : dialog_result::cancel;
}

auto form::create_params() const noexcept -> xtd::forms::create_params {
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

auto form::default_size() const noexcept -> xtd::drawing::size {
  return {300, 300};
}

auto form::on_activated(const event_args& e) -> void {
  if (!can_raise_events()) return;
  auto safe_activated = activated;
  if (safe_activated.is_empty()) return;
  safe_activated(*this, e);
}

auto form::on_deactivate(const event_args& e) -> void {
  if (!can_raise_events()) return;
  auto safe_deactivate = deactivate;
  if (safe_deactivate.is_empty()) return;
  safe_deactivate(*this, e);
}

auto form::on_handle_created(const event_args& e) -> void {
  control::top_level_controls_.add(self_);
  container_control::on_handle_created(e);
  if (data_->show_icon && data_->icon != xtd::drawing::icon::empty) native::form::icon(handle(), data_->icon);
  if (data_->accept_button.has_value()) data_->accept_button.value().get().notify_default(true);
  if (data_->opacity != 1.0) native::form::opacity(handle(), data_->opacity);
  if (!region().is_empty() && !region().is_infinite()) native::form::set_region(handle(), region().handle());
  
  if (data_->menu.has_value()) create_system_menu();
}

auto form::on_handle_destroyed(const event_args& e) -> void {
  control::top_level_controls_.remove(self_);
  container_control::on_handle_destroyed(e);
  destroy_system_menu();
}

auto form::on_form_closed(const form_closed_event_args& e) -> void {
  static auto closing = false;
  if (closing) return;
  closing = true;
  if (can_raise_events()) {
    auto safe_form_closed = form_closed;
    if (!safe_form_closed.is_empty()) safe_form_closed(*this, e);
  }
  closing = false;
}

auto form::on_form_closing(form_closing_event_args& e) -> void {
  if (!can_raise_events()) return;
  auto safe_form_closing = form_closing;
  if (safe_form_closing.is_empty()) return;
  safe_form_closing(*this, e);
}

auto form::on_layout(const event_args& e) -> void {
  scrollable_control::on_layout(e);
  if (is_handle_created() && auto_scroll()) native::form::virtual_size(handle(), display_rectangle().size());
}

auto form::on_location_changed(const event_args& e) -> void {
  if (handle() && top() < screen::get_working_area(handle()).top()) top(screen::get_working_area(handle()).top());
  container_control::on_location_changed(e);
}

auto form::on_paint(paint_event_args& e) -> void {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (control_appearance() == forms::control_appearance::standard) form_renderer::draw_form(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt);
  container_control::on_paint(e);
}

auto form::on_region_changed(const event_args& e) -> void {
  native::form::set_region(handle(), region().handle());
  container_control::on_region_changed(e);
}

auto form::on_resize(const event_args& e) -> void {
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

auto form::wnd_proc(message& message) -> void {
  switch (message.msg) {
    case WM_ACTIVATE: wm_activate(message); break;
    case WM_CLOSE: wm_close(message); break;
    case WM_MENUCOMMAND: if (data_->menu.has_value()) data_->menu.value().get().wm_click(message); break;
    case WM_SYSCOLORCHANGE: wm_syscolor_change(message); break;
    case WM_RECREATE: wm_recreate(message); break;
    default: container_control::wnd_proc(message); break;
  }
}

auto form::closed_() const noexcept -> bool {
  return data_->closed;
}

auto form::internal_set_window_state() -> void {
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

auto form::create_system_menu() -> void {
  if (!data_->menu.has_value()) return;
  
  // Workaround : Get client size because afer changing tool bar to system, the client size does not correct.
  auto prev_client_size = client_size();
  
  native::form::menu(handle(), data_->menu.value().get().handle());
  
  // Workaround : Force the client size with the previously saved client size.
  client_size(prev_client_size);
}

auto form::destroy_system_menu() -> void {
  if (!data_->menu) return;
  
  // Workaround : Get client size because afer changing tool bar to system, the client size does not correct.
  auto prev_client_size = client_size();
  
  native::form::menu(handle(), 0);
  
  // Workaround : Force the client size with the previously saved client size.
  client_size(prev_client_size);
}

auto form::fill_in_create_params_border_styles(xtd::forms::create_params& create_params) const -> void {
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

auto form::fill_in_create_params_border_icons(xtd::forms::create_params& create_params) const -> void {
  if (data_->form_border_style == xtd::forms::form_border_style::none)
    create_params.class_style(create_params.class_style() | CS_NOCLOSE);
  else {
    if (!xtd::string::is_empty(text())) create_params.style(create_params.style() | WS_CAPTION);
      
    if (data_->control_box) create_params.style(create_params.style() | WS_SYSMENU | WS_CAPTION);
    else create_params.style(create_params.style() & ~WS_SYSMENU);
      
    if (!data_->close_box) create_params.class_style(create_params.class_style() | CS_NOCLOSE);
    else create_params.class_style(create_params.class_style() & ~CS_NOCLOSE);
      
    if (data_->maximize_box) create_params.style(create_params.style() | WS_MAXIMIZEBOX);
    else create_params.style(create_params.style() & ~WS_MAXIMIZEBOX);
      
    if (data_->minimize_box) create_params.style(create_params.style() | WS_MINIMIZEBOX);
    else create_params.style(create_params.style() & ~WS_MINIMIZEBOX);
      
    if (data_->help_button && !data_->maximize_box && !data_->minimize_box && data_->control_box) create_params.ex_style(create_params.ex_style() | WS_EX_CONTEXTHELP);
    else create_params.ex_style(create_params.ex_style() & ~WS_EX_CONTEXTHELP);
  }
}

auto form::fill_in_create_params_start_position(xtd::forms::create_params& create_params) const -> void {
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
        create_params.location({(data_->previous_screen->working_area().width - width()) / 2, (data_->previous_screen->working_area().height - height()) / 2});
        create_params.size(size());
        break;
      case form_start_position::windows_default_location:
        create_params.location({default_location, default_location});
        create_params.size(size());
        break;
      case form_start_position::windows_default_bounds:
        create_params.location({default_location, default_location});
        create_params.size({data_->previous_screen->working_area().width / 4 * 3, data_->previous_screen->working_area().height / 4 * 3});
        break;
      case form_start_position::center_parent:
        if (parent().has_value()) create_params.location({parent().value().get().left() + (parent().value().get().width() - width()) / 2, parent().value().get().top() + (parent().value().get().height() - height()) / 2});
        else create_params.location({default_location, default_location});
        create_params.size(size());
        break;
    }
    
    if (data_->start_position == form_start_position::windows_default_location || data_->start_position == form_start_position::windows_default_bounds || (data_->start_position == form_start_position::center_parent && parent().has_value()))
      default_location = default_location < 200 ? default_location + 20 : 40;
  }
}

auto form::fill_in_create_params_window_state(xtd::forms::create_params& create_params) const -> void {
  switch (data_->window_state) {
    case form_window_state::maximized: create_params.style(create_params.style() | WS_MAXIMIZE); break;
    case form_window_state::minimized: create_params.style(create_params.style() | WS_MINIMIZE); break;
    default: break;
  }
}

auto form::wm_activate(message& message) -> void {
  if (message.lparam == WA_INACTIVE && active_form_.has_value() && &active_form_.value().get() == this) {
    active_form_.reset();
    on_deactivate(event_args::empty);
  } else {
    active_form_ = *this;
    on_activated(event_args::empty);
  }
}

auto form::wm_close(message& message) -> void {
  if (data_->closed) return;
  auto event_args = form_closing_event_args {};
  on_form_closing(event_args);
  message.result = event_args.cancel();
  if (event_args.cancel() != true) {
    control::top_level_controls_.remove(self_);
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

auto form::wm_recreate(message& message) -> void {
  auto current_location = location();
  recreate_handle();
  location(current_location);
}

auto form::wm_syscolor_change(message& message) -> void {
  def_wnd_proc(message);
  if (&application::open_forms()[0].get() == this) style_sheets::style_sheet::on_system_colors_changed(event_args::empty);
  on_system_colors_changed(event_args::empty);
}
