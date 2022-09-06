#include <random>
#include <stdexcept>
#include <xtd/as.h>
#include <xtd/invalid_operation_exception.h>
#include <xtd/is.h>
#include <xtd/literals.h>
#include <xtd/random.h>
#include <xtd/diagnostics/debug.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/system_icons.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/class_styles.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/form.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/form_renderer.h"
#include "../../../include/xtd/forms/screen.h"
#include "../../../include/xtd/forms/style_sheets/style_sheet.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

std::optional<std::reference_wrapper<form>> form::active_form_;

form::form() {
  set_auto_size_mode(forms::auto_size_mode::grow_only);
  icon_ = system_icons::xtd_forms_logo();
  set_state(state::visible, false);
  set_state(state::top_level, true);
  
  if (!application::style_sheet().is_system_style_sheet()) {
    back_color(default_back_color());
    fore_color(default_fore_color());
  }
  create_control();
}

form& form::accept_button(const ibutton_control& accept_button) {
  if (!accept_button_.has_value() || &accept_button_.value().get() != &accept_button) {
    if (accept_button_.has_value()) accept_button_.value().get().notify_default(false);
    accept_button_ = const_cast<ibutton_control&>(accept_button);
    accept_button_.value().get().notify_default(true);
  }
  return *this;
}

form& form::accept_button(std::nullptr_t) {
  if (accept_button_.has_value()) accept_button_.value().get().notify_default(false);
  accept_button_.reset();
  return *this;
}

form& form::cancel_button(const ibutton_control& cancel_button) {
  if (!cancel_button_.has_value() || &cancel_button_.value().get() != &cancel_button)
    cancel_button_ = const_cast<ibutton_control&>(cancel_button);
  return *this;
}

form& form::cancel_button(std::nullptr_t) {
  cancel_button_.reset();
  return *this;
}

form& form::auto_size_mode(forms::auto_size_mode value) {
  set_auto_size_mode(value);
  return *this;
}

form& form::close_box(bool value) {
  if (close_box_ != value) {
    close_box_ = value;
    post_recreate_handle();
  }
  return *this;
}

form& form::control_box(bool value) {
  if (control_box_ != value) {
    control_box_ = value;
    post_recreate_handle();
  }
  return *this;
}

form& form::dialog_result(forms::dialog_result value) {
  dialog_result_ = value;
  return *this;
}

form& form::form_border_style(forms::form_border_style value) {
  if (form_border_style_ != value) {
    form_border_style_ = value;
    post_recreate_handle();
  }
  return *this;
}

form& form::help_button(bool value) {
  if (help_button_ != value) {
    help_button_ = value;
    post_recreate_handle();
  }
  return *this;
}

form& form::icon(const xtd::drawing::icon& value) {
  if (icon_ != value) {
    icon_ = value != drawing::icon::empty ? value : system_icons::xtd_forms_logo();
    if (is_handle_created() && show_icon_) native::form::icon(handle(), icon_);
  }
  return *this;
}

form& form::maximize_box(bool value) {
  if (maximize_box_ != value) {
    maximize_box_ = value;
    post_recreate_handle();
  }
  return *this;
}

form& form::menu(const forms::main_menu& value) {
  if (!menu_.has_value() || &menu_.value().get() != &value) {
    menu_ = const_cast<forms::main_menu&>(value);
    if (is_handle_created()) create_system_menu();
  }
  return *this;
}

form& form::menu(std::nullptr_t) {
  if (menu_.has_value()) {
    if (is_handle_created()) destroy_system_menu();
    menu_.reset();
  }
  return *this;
}

form& form::minimize_box(bool value) {
  if (minimize_box_ != value) {
    minimize_box_ = value;
    post_recreate_handle();
  }
  return *this;
}

std::optional<control_ref> form::owner() const {
  return owner_ ? std::optional<control_ref>(control_ref(const_cast<control&>(*owner_))) : std::optional<control_ref>();
}

form& form::owner(const control& value) {
  if (!owner_ || owner_->handle() != value.handle()) {
    owner_ = &value;
    post_recreate_handle();
  }
  return *this;
}

form& form::owner(std::nullptr_t) {
  if (owner_) {
    owner_ = nullptr;
    post_recreate_handle();
  }
  return *this;
}

control& form::parent(const control& parent) {
  throw invalid_operation_exception("Top-level control cannot be added to a control."_t, current_stack_frame_);
}

form& form::show_icon(bool value) {
  if (show_icon_ != value) {
    show_icon_ = value;
    post_recreate_handle();
  }
  
  return *this;
}

form& form::show_in_taskbar(bool value) {
  if (show_in_taskbar_ != value) {
    show_in_taskbar_ = value;
    post_recreate_handle();
  }
  
  return *this;
}

form& form::start_position(form_start_position start_position) {
  start_position_ = start_position;
  return *this;
}

form& form::top_level(bool top_level) {
  if (!get_state(state::top_level) != top_level)
    set_state(state::top_level, top_level);
  return *this;
}

form& form::status_bar(const forms::status_bar& value) {
  if (!status_bar_.has_value() || &status_bar_.value().get() != &value) {
    status_bar_ = const_cast<forms::status_bar&>(value);
    status_bar_.value().get().is_system_status_bar(true);
  }
  return *this;
}

form& form::status_bar(std::nullptr_t) {
  if (status_bar_.has_value()) {
    status_bar_.value().get().is_system_status_bar(false);
    status_bar_.reset();
  }
  return *this;
}

form& form::tool_bar(const forms::tool_bar& value) {
  if (!tool_bar_.has_value() || &tool_bar_.value().get() != &value) {
    tool_bar_ = const_cast<forms::tool_bar&>(value);
    tool_bar_.value().get().is_system_tool_bar(true);
  }
  return *this;
}

form& form::tool_bar(std::nullptr_t) {
  if (tool_bar_.has_value()) {
    tool_bar_.value().get().is_system_tool_bar(false);
    tool_bar_.reset();
  }
  return *this;
}

form& form::top_most(bool value) {
  if (top_most_ != value) {
    top_most_ = value;
    post_recreate_handle();
  }
  return *this;
}

form& form::opacity(double opacity) {
  if (opacity_ != opacity) {
    opacity_ = opacity;
    if (is_handle_created()) native::form::opacity(handle(), opacity_);
  }
  return *this;
}

control& form::visible(bool visible) {
  std::optional<forms::form_window_state> current_window_state;
  if (!previous_screen_) {
    current_window_state = window_state_;
    previous_screen_ = std::make_shared<screen>(screen::from_control(*this));
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
    closed_ = false;
    if (accept_button_.has_value()) accept_button_.value().get().notify_default(true);
  }
  return *this;
}

form& form::window_state(form_window_state value) {
  if (window_state_ != value) {
    window_state_ = value;
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
  if (is_handle_created() && previous_screen_) native::form::close(handle());
}

bool form::pre_process_message(xtd::forms::message& message) {
  if (message.msg() == WM_KEYUP) {
    key_event_args key_event_args(static_cast<keys>(message.wparam()));
    if (key_event_args.key_data() == keys::enter && accept_button_.has_value()) {
      accept_button_.value().get().perform_click();
      return true;
    } else if (key_event_args.key_data() == keys::escape && cancel_button_.has_value()) {
      cancel_button_.value().get().perform_click();
      return true;
    }
  }
  
  return container_control::pre_process_message(message);
}

forms::dialog_result form::show_dialog() {
  closed_ = false;
  set_state(state::modal, true);
  previous_screen_ = std::make_shared<screen>(screen::from_control(*this));
  recreate_handle();
  dialog_result_ = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  forms::dialog_result result = is_handle_created() ? static_cast<forms::dialog_result>(native::form::show_dialog(handle())) : dialog_result::cancel;
  application::raise_leave_thread_modal(event_args::empty);
  return result;
}

forms::dialog_result form::show_dialog(const iwin32_window& owner) {
  closed_ = false;
  parent_before_show_dialog_ = parent().has_value() ? parent().value().get().handle() : 0;
  set_state(state::modal, true);
  if (owner.handle() != handle()) set_parent(owner.handle());
  previous_screen_ = std::make_shared<screen>(screen::from_control(*this));
  recreate_handle();
  dialog_result_ = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  return is_handle_created() ? static_cast<forms::dialog_result>(native::form::show_dialog(handle())) : dialog_result::cancel;
}

void form::show_sheet(const iwin32_window& owner) {
  closed_ = false;
  parent_before_show_dialog_ = parent().has_value() ? parent().value().get().handle() : 0;
  set_state(state::modal, true);
  if (owner.handle() != handle()) set_parent(owner.handle());
  previous_screen_ = std::make_shared<screen>(screen::from_control(*this));
  recreate_handle();
  dialog_result_ = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  if (is_handle_created()) native::form::show_sheet(handle());
}

forms::dialog_result form::show_sheet_dialog(const iwin32_window& owner) {
  closed_ = false;
  parent_before_show_dialog_ = parent().has_value() ? parent().value().get().handle() : 0;
  set_state(state::modal, true);
  if (owner.handle() != handle()) set_parent(owner.handle());
  previous_screen_ = std::make_shared<screen>(screen::from_control(*this));
  recreate_handle();
  dialog_result_ = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  return is_handle_created() ? static_cast<forms::dialog_result>(native::form::show_sheet_dialog(handle())) : dialog_result::cancel;
}

forms::create_params form::create_params() const {
  forms::create_params cp = container_control::create_params();
  cp.style(cp.style() & ~WS_CHILD);
  
  cp.class_name("form");
  
  cp.style(cp.style() | WS_CLIPCHILDREN);
  
  if (get_state(state::modal)) cp.ex_style(cp.ex_style() | WS_EX_MODALWINDOW);
  
  if (owner_ != nullptr) cp.parent(owner_->handle());
  
  if (top_most_) cp.ex_style(cp.ex_style() | WS_EX_TOPMOST);
  
  if (!enabled())
    // Forms that are parent of a modal dialog must keep their WS_DISABLED style (VSWhidbey 449309)
    cp.style(cp.style() | WS_DISABLED);
  else if (top_level())
    // It doesn't seem to make sense to allow a top-level form to be disabled
    //
    cp.style(cp.style() & ~WS_DISABLED);
    
  if (top_level() && opacity() != 0)
    cp.ex_style(cp.ex_style() | WS_EX_LAYERED);
    
  fill_in_create_params_border_styles(cp);
  fill_in_create_params_window_state(cp);
  fill_in_create_params_border_icons(cp);
  
  if (show_in_taskbar_)
    cp.ex_style(cp.ex_style() | WS_EX_APPWINDOW);
    
  xtd::forms::form_border_style border_style = form_border_style();
  if (!show_icon_ && (border_style == xtd::forms::form_border_style::sizable || border_style == xtd::forms::form_border_style::fixed_3d || border_style == xtd::forms::form_border_style::fixed_single))
    cp.ex_style(cp.ex_style() | WS_EX_DLGMODALFRAME);
    
  if (top_level())
    fill_in_create_params_start_position(cp);
    
  /*
  if (right_to_left == xtd::forms::right_to_left::yes && right_to_left_layout() == true) {
    cp.ex_style(cp.ex_style() | WS_EX_LAYOUTRTL | WS_EX_NOINHERITLAYOUT);
    cp.ex_style(cp.ex_style() & ~(WS_EX_RTLREADING | WS_EX_RIGHT | WS_EX_LEFTSCROLLBAR));
  }*/
  
  //diagnostics::debug::write_line("create_params = {}, style = {}, ex_style = {}", cp, __windows_style_to_string__(cp.style()), __windows_extended_style_to_string__(cp.ex_style()));
  
  return cp;
}

void form::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_ACTIVATE: wm_activate(message); break;
    case WM_CLOSE: wm_close(message); break;
    case WM_MENUCOMMAND: if (menu_.has_value()) menu_.value().get().wm_click(message); break;
    case WM_SYSCOLORCHANGE: wm_syscolor_change(message); break;
    case WM_RECREATE: wm_recreate(message); break;
    default: container_control::wnd_proc(message); break;
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
  if (closed_) return;
  form_closing_event_args event_args;
  on_form_closing(event_args);
  message.result(event_args.cancel() == true);
  if (event_args.cancel() != true) {
    closed_ = true;
    if (!get_state(state::modal))
      hide();
    else {
      if (dialog_result_ == forms::dialog_result::none) dialog_result_ = forms::dialog_result::cancel;
      native::form::end_dialog(handle(), static_cast<int32_t>(dialog_result_));
      set_parent(parent_before_show_dialog_);
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

void form::on_handle_created(const event_args& e) {
  container_control::on_handle_created(e);
  if (show_icon_ && icon_ != drawing::icon::empty) native::form::icon(handle(), icon_);
  if (accept_button_.has_value()) accept_button_.value().get().notify_default(true);
  if (opacity_ != 1.0) native::form::opacity(handle(), opacity_);
  if (!region().is_empty() && !region().is_infinite()) native::form::set_region(handle(), region().handle());
  
  if (menu_.has_value()) create_system_menu();
}

void form::on_handle_destroyed(const event_args& e) {
  container_control::on_handle_destroyed(e);
  destroy_system_menu();
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
      window_state_ = forms::form_window_state::minimized;
    else if (native::form::maximize(handle()))
      window_state_ = forms::form_window_state::maximized;
    else if (native::form::full_screen(handle()))
      window_state_ = forms::form_window_state::full_screen;
    else
      window_state_ = forms::form_window_state::normal;
  }
  container_control::on_resize(e);
}

void form::on_system_colors_changed(const event_args& e) {
  if (can_raise_events()) system_colors_changed(*this, e);
}

void form::internal_set_window_state() {
  if (!previous_screen_)
    post_recreate_handle();
  else if (is_handle_created()) {
    switch (window_state_) {
      case form_window_state::normal: native::form::restore(handle()); break;
      case form_window_state::maximized: native::form::maximize(handle(), true); break;
      case form_window_state::minimized: native::form::minimize(handle(), true); break;
      case form_window_state::full_screen: native::form::full_screen(handle(), true); break;
      default: break;
    }
  }
}

void form::create_system_menu() {
  if (!menu_.has_value()) return;
  
  // Workaround : Get client size because afer changing tool bar to system, the client size does not correct.
  auto prev_client_size = client_size();
  
  native::form::menu(handle(), menu_.value().get().handle());
  
  // Workaround : Force the client size with the previously saved client size.
  client_size(prev_client_size);
}

void form::destroy_system_menu() {
  if (!menu_) return;
  
  // Workaround : Get client size because afer changing tool bar to system, the client size does not correct.
  auto prev_client_size = client_size();
  
  native::form::menu(handle(), 0);
  
  // Workaround : Force the client size with the previously saved client size.
  client_size(prev_client_size);
}

void form::fill_in_create_params_border_styles(xtd::forms::create_params& cp) const {
  switch (form_border_style_) {
    case xtd::forms::form_border_style::none: break;
    case xtd::forms::form_border_style::fixed_single: cp.style(cp.style() | WS_BORDER); break;
    case xtd::forms::form_border_style::sizable: cp.style(cp.style() | WS_BORDER | WS_THICKFRAME); break;
    case xtd::forms::form_border_style::fixed_3d:
      cp.style(cp.style() | WS_BORDER);
      cp.ex_style(cp.ex_style() | WS_EX_CLIENTEDGE);
      break;
    case xtd::forms::form_border_style::fixed_dialog:
      cp.style(cp.style() | WS_BORDER);
      cp.ex_style(cp.ex_style() | WS_EX_DLGMODALFRAME);
      break;
    case xtd::forms::form_border_style::fixed_tool_window:
      cp.style(cp.style() | WS_BORDER);
      cp.ex_style(cp.ex_style() | WS_EX_TOOLWINDOW);
      break;
    case xtd::forms::form_border_style::sizable_tool_window:
      cp.style(cp.style() | WS_BORDER | WS_THICKFRAME);
      cp.ex_style(cp.ex_style() | WS_EX_TOOLWINDOW);
      break;
  }
}

void form::fill_in_create_params_border_icons(xtd::forms::create_params& cp) const {
  if (form_border_style_ == xtd::forms::form_border_style::none)
    cp.class_style(cp.class_style() | CS_NOCLOSE);
  else {
    if (!text().empty())
      cp.style(cp.style() | WS_CAPTION);
      
    if (control_box_)
      cp.style(cp.style() | WS_SYSMENU | WS_CAPTION);
    else
      cp.style(cp.style() & ~WS_SYSMENU);
      
    if (!close_box_)
      cp.class_style(cp.class_style() | CS_NOCLOSE);
    else
      cp.class_style(cp.class_style() & ~CS_NOCLOSE);
      
    if (maximize_box_)
      cp.style(cp.style() | WS_MAXIMIZEBOX);
    else
      cp.style(cp.style() & ~WS_MAXIMIZEBOX);
      
    if (minimize_box_)
      cp.style(cp.style() | WS_MINIMIZEBOX);
    else
      cp.style(cp.style() & ~WS_MINIMIZEBOX);
      
    if (help_button_ && !maximize_box_ && !minimize_box_ && control_box_)
      cp.ex_style(cp.ex_style() | WS_EX_CONTEXTHELP);
    else
      cp.ex_style(cp.ex_style() & ~WS_EX_CONTEXTHELP);
  }
}

void form::fill_in_create_params_start_position(xtd::forms::create_params& cp) const {
  static int32_t default_location = 0;
  if (default_location == 0)
    default_location = xtd::random().next(4, 20) * 10;
    
  if (previous_screen_) {
    switch (start_position_) {
      case form_start_position::manual:
        cp.location(location());
        cp.size(size());
        break;
      case form_start_position::center_screen:
        cp.location({(previous_screen_->working_area().width() - width()) / 2, (previous_screen_->working_area().height() - height()) / 2});
        cp.size(size());
        break;
      case form_start_position::windows_default_location:
        cp.location({default_location, default_location});
        cp.size(size());
        break;
      case form_start_position::windows_default_bounds:
        cp.location({default_location, default_location});
        cp.size({previous_screen_->working_area().width() / 4 * 3, previous_screen_->working_area().height() / 4 * 3});
        break;
      case form_start_position::center_parent:
        if (parent().has_value())
          cp.location({parent().value().get().left() + (parent().value().get().width() - width()) / 2, parent().value().get().top() + (parent().value().get().height() - height()) / 2});
        else
          cp.location({default_location, default_location});
        cp.size(size());
        break;
    }
    
    if (start_position_ == form_start_position::windows_default_location || start_position_ == form_start_position::windows_default_bounds || (start_position_ == form_start_position::center_parent && parent().has_value()))
      default_location = default_location < 200 ? default_location + 20 : 40;
  }
}

void form::fill_in_create_params_window_state(xtd::forms::create_params& cp) const {
  switch (window_state_) {
    case form_window_state::maximized: cp.style(cp.style() | WS_MAXIMIZE); break;
    case form_window_state::minimized: cp.style(cp.style() | WS_MINIMIZE); break;
    default: break;
  }
}
