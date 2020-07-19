#include <random>
#include <stdexcept>
#include <xtd/xtd.diagnostics>
#include <xtd/forms/native/class_styles.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/form.h>
#include <xtd/forms/native/window_styles.h>
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/screen.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

std::optional<std::reference_wrapper<form>> form::active_form_;

form::form() {
  this->auto_size_mode_ = forms::auto_size_mode::grow_only;
  this->back_color_ = this->default_back_color();
  this->cursor_ = this->default_cursor();
  this->fore_color_ = this->default_fore_color();
  this->font_ = this->default_font();
  this->size_ = this->default_size();
  this->set_state(state::visible, false);
  this->set_state(state::top_level, true);
  this->create_control();
}

form& form::accept_button(const ibutton_control& accept_button) {
  if (!this->accept_button_.has_value() || &this->accept_button_.value().get() != &accept_button) {
    this->accept_button_ = const_cast<ibutton_control&>(accept_button);
  }
  return *this;
}

form& form::accept_button(nullptr_t) {
  this->accept_button_.reset();
  return *this;
}

form& form::cancel_button(const ibutton_control& cancel_button) {
  if (!this->cancel_button_.has_value() || &this->cancel_button_.value().get() != &cancel_button) {
    this->cancel_button_ = const_cast<ibutton_control&>(cancel_button);
  }
  return *this;
}

form& form::cancel_button(nullptr_t) {
  this->cancel_button_.reset();
  return *this;
}

form& form::auto_size_mode(forms::auto_size_mode value) {
  this->set_auto_size_mode(value);
  return *this;
}

form& form::close_box(bool value) {
  if (this->close_box_ != value) {
    this->close_box_ = value;
    this->recreate_handle();
  }
  return *this;
}

form& form::control_box(bool value) {
  if (this->control_box_ != value) {
    this->control_box_ = value;
    this->recreate_handle();
  }
  return *this;
}

form& form::dialog_result(forms::dialog_result value) {
  if (this->dialog_result_ != value)
    this->dialog_result_ = value;
  return *this;
}

form& form::form_border_style(forms::form_border_style value) {
  if (this->form_border_style_ != value) {
    this->form_border_style_ = value;
    this->recreate_handle();
  }
  return *this;
}

form& form::help_button(bool value) {
  if (this->help_button_ != value) {
    this->help_button_ = value;
    this->recreate_handle();
  }
  return *this;
}

form& form::maximize_box(bool value) {
  if (this->maximize_box_ != value) {
    this->maximize_box_ = value;
    this->recreate_handle();
  }
  return *this;
}

form& form::menu(const forms::main_menu& value) {
  if (!menu_.has_value() || &menu_.value() != &value) {
    menu_ = value;
    native::form::menu(handle(), menu_.value().handle());
  }
  return *this;
}

form& form::menu(nullptr_t) {
  if (menu_.has_value()) {
    menu_.reset();
    native::form::menu(handle(), 0);
  }
  return *this;
}

form& form::minimize_box(bool value) {
  if (this->minimize_box_ != value) {
    this->minimize_box_ = value;
    this->recreate_handle();
  }
  return *this;
}

control& form::parent(const control& parent) {
  throw std::invalid_argument("Top-level control cannot be added to a control.");
  return *this;
}

form& form::start_position(form_start_position start_position) {
  if (this->start_position_ != start_position)
    this->start_position_ = start_position;
  return *this;
}

form& form::top_level(bool top_level) {
  if (!this->get_state(state::top_level) != top_level) {
    this->set_state(state::top_level, top_level);
  }
  return *this;
}

control& form::visible(bool visible) {
  std::optional<forms::form_window_state> current_window_state;
  if (!this->previous_screeen_) {
    current_window_state = this->window_state_;
    this->previous_screeen_ = std::make_shared<screen>(screen::from_control(*this));
    this->recreate_handle();
  }
  this->container_control::visible(visible);
  if (active_form().has_value() && active_form().value().get().handle() == this->handle() && this->active_control_.has_value())
    this->active_control_.value().get().focus();

  if (current_window_state.has_value())
    this->window_state(current_window_state.value());
  this->internal_set_window_state();
  return *this;
}

form& form::window_state(form_window_state value) {
  if (this->window_state_ == form_window_state::full_screen && value != form_window_state::normal) return *this;
  if (this->window_state_ != form_window_state::normal && value == form_window_state::full_screen) return *this;
  if (this->window_state_ != value) {
    this->window_state_ = value;
    this->internal_set_window_state();
  }
  return *this;
}

void form::activate() {
  native::form::activate(this->handle());
}

void form::center_to_screen() {
  screen screen = screen::from_control(*this);
  left((screen.working_area().width() - width()) / 2);
  top((screen.working_area().height() - height()) / 2);
}

void form::close() {
  native::form::close(this->handle());
}

forms::dialog_result form::show_dialog() {
  return show_dialog(application::open_forms()[0].get());
}

forms::dialog_result form::show_dialog(const iwin32_window& owner) {
  intptr_t current_parent = this->parent_;
  this->set_state(state::modal, true);
  if (owner.handle() != this->handle()) this->parent_ = owner.handle();
  this->show();
  forms::dialog_result result = this->dialog_result_ = forms::dialog_result::none;
  application::raise_enter_thread_modal(event_args::empty);
  result = static_cast<forms::dialog_result>(native::form::show_dialog(this->handle()));
  application::raise_leave_thread_modal(event_args::empty);
  this->set_state(state::modal, false);
  this->parent_ = current_parent;
  this->hide();
  return result;
}

forms::create_params form::create_params() const {
  forms::create_params create_params = this->container_control::create_params();
  static int32_t default_location = 0;
  if (default_location == 0) {
    std::random_device rand;
    default_location = std::uniform_int_distribution<int32_t> {4, 20}(rand) * 10;
  }

  create_params.class_name("form");
  
  create_params.style(create_params.style() | WS_CLIPCHILDREN);
  
  switch (this->form_border_style_) {
    case forms::form_border_style::none: break;
    case forms::form_border_style::fixed_single: create_params.style(create_params.style() | WS_BORDER); break;
    case forms::form_border_style::sizable: create_params.style(create_params.style() | WS_BORDER | WS_THICKFRAME); break;
    case forms::form_border_style::fixed_3d: create_params.style(create_params.style() | WS_BORDER); create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE); break;
    case forms::form_border_style::fixed_dialog: create_params.style(create_params.style() | WS_BORDER); create_params.ex_style(create_params.ex_style() | WS_EX_DLGMODALFRAME); break;
    case forms::form_border_style::fixed_tool_window: create_params.style(create_params.style() | WS_BORDER); create_params.ex_style(create_params.ex_style() | WS_EX_TOOLWINDOW); break;
    case forms::form_border_style::sizable_tool_window: create_params.style(create_params.style() | WS_BORDER | WS_THICKFRAME); create_params.ex_style(create_params.ex_style() | WS_EX_TOOLWINDOW); break;
    default: break;
  }

  switch (this->window_state_) {
    case form_window_state::maximized: create_params.style(create_params.style() | WS_MAXIMIZE); break;
    case form_window_state::minimized: create_params.style(create_params.style() | WS_MINIMIZE); break;
    default: break;
  }

  if (this->form_border_style_ != form_border_style::none) create_params.style(create_params.style() | WS_CAPTION);

  if (this->control_box_) create_params.style(create_params.style() | WS_SYSMENU);
  if (this->maximize_box_) create_params.style(create_params.style() | WS_MAXIMIZEBOX);
  if (this->minimize_box_) create_params.style(create_params.style() | WS_MINIMIZEBOX);
  if (this->help_button_ && !this->maximize_box_ && !this->minimize_box_) create_params.ex_style(create_params.ex_style() | WS_EX_CONTEXTHELP);

  if (!this->close_box_) create_params.class_style(create_params.class_style() | CS_NOCLOSE);

  if (this->show_in_taskbar_) create_params.ex_style(create_params.ex_style() | WS_EX_APPWINDOW);

  if (!this->show_icon_ && (this->form_border_style_ == forms::form_border_style::sizable || this->form_border_style_ == forms::form_border_style::fixed_3d || this->form_border_style_ == forms::form_border_style::fixed_single)) create_params.ex_style(create_params.ex_style() | WS_EX_DLGMODALFRAME);
  
  if (this->get_state(state::modal)) create_params.ex_style(create_params.ex_style() | WS_EX_MODALWINDOW);
  
  if (this->previous_screeen_) {
    switch (this->start_position_) {
      case form_start_position::manual:
        create_params.location(this->location());
        create_params.size(this->size());
        if (application::open_forms().size() == 1) default_location = 40;
        break;
      case form_start_position::center_screen:
        create_params.location({(this->previous_screeen_->working_area().width() - this->width()) / 2, (this->previous_screeen_->working_area().height() - this->height()) / 2});
        create_params.size(this->size());
        break;
      case form_start_position::windows_default_location:
        create_params.location({default_location, default_location});
        create_params.size(this->size());
        break;
      case form_start_position::windows_default_bounds:
        create_params.location({default_location, default_location});
        create_params.size({this->previous_screeen_->working_area().width() / 4 * 3, this->previous_screeen_->working_area().height() / 4 * 3});
        break;
      case form_start_position::center_parent:
        if (this->parent_ != 0)
          create_params.location({this->parent().value().get().left() + (this->parent().value().get().width() - this->width()) / 2, this->parent().value().get().top() + (this->parent().value().get().height() - this->height()) / 2});
        else
          create_params.location({default_location, default_location});
        create_params.size(this->size());
        break;
    }
    
    if (this->start_position_ == form_start_position::windows_default_location || this->start_position_ == form_start_position::windows_default_bounds || (this->start_position_ == form_start_position::center_parent && !this->parent_)) {
      default_location = default_location < 200 ? default_location + 20 : 40;
    }
  }

  return create_params;
}

void form::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_ACTIVATE: this->wm_activate(message); break;
    case WM_KEYUP: this->wm_key_up(message); break;
    case WM_CLOSE: this->wm_close(message); break;
    case WM_MENUCOMMAND: if (menu_.has_value()) menu_.value().wm_click(message); break;
    default: this->container_control::wnd_proc(message); break;
  }
}

void form::wm_activate(message &message) {
  if (message.lparam() == WA_INACTIVE && active_form_.has_value() && &active_form_.value().get() == this) {
    active_form_.reset();
    this->on_deactivate(event_args::empty);
  } else {
    active_form_ = *this;
    this->on_activated(event_args::empty);
  }
}

void form::wm_close(message &message) {
  form_closing_event_args event_args;
  this->on_form_closing(event_args);
  if (event_args.cancel() != true) {
    if (!this->get_state(state::modal)) {
      this->def_wnd_proc(message);
      this->destroy_control();
    } else {
      if (this->dialog_result_ == forms::dialog_result::none) this->dialog_result_ = forms::dialog_result::cancel;
      native::form::end_dialog(this->handle(), static_cast<int32_t>(this->dialog_result_));
    }
    form_closed_event_args close_event_args;
    on_form_closed(close_event_args);
  }
}

void form::wm_key_up(message& message) {
  container_control::wnd_proc(message);
  key_event_args key_event_args(static_cast<keys>(message.wparam()));
  if (key_event_args.key_data() == keys::enter && accept_button_.has_value()) {
    accept_button_.value().get().perform_click();
    cdebug << "accept_button::perform_click" << endl;
  }
  if (key_event_args.key_data() == keys::escape && cancel_button_.has_value()) {
    cancel_button_.value().get().perform_click();
    cdebug << "cancel_button::perform_click" << endl;
  }
}

void form::on_handle_created(const event_args &e) {
  this->container_control::on_handle_created(e);
  if (menu_.has_value()) native::form::menu(handle(), menu_.value().handle());
  if (this->accept_button_.has_value()) native::form::default_control(this->handle(), dynamic_cast<control&>(this->accept_button_.value().get()).handle());
  if (menu_.has_value()) native::form::menu(handle(), menu_.value().handle());
}

void form::on_handle_destroyed(const event_args &e) {
  this->container_control::on_handle_destroyed(e);
  native::form::menu(handle(), 0);
}

void form::on_layout(const event_args& e) {
  this->scrollable_control::on_layout(e);
  if (auto_scroll_) native::form::virtual_size(this->handle(), display_rectangle().size());
}

void form::on_resize(const event_args& e) {
  if (native::form::minimize(this->handle()))
    this->window_state_ = forms::form_window_state::minimized;
  else if (native::form::maximize(this->handle()))
    this->window_state_ = forms::form_window_state::maximized;
  else if (this->window_state_ != form_window_state::full_screen)
    this->window_state_ = forms::form_window_state::normal;
  this->container_control::on_resize(e);
}

void form::internal_set_window_state() {
  if (!this->previous_screeen_)
    this->recreate_handle();
  else {
    switch (this->window_state_) {
      case form_window_state::normal: native::form::restore(this->handle()); break;
      case form_window_state::maximized: native::form::maximize(this->handle(), true); break;
      case form_window_state::minimized: native::form::minimize(this->handle(), true); break;
      case form_window_state::full_screen: native::form::full_screen(this->handle(), true); break;
      default: break;
    }
  }
}
