#include <random>
#include <stdexcept>
#include <xtd/xtd.diagnostics>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/form.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include <xtd/forms/window_messages.hpp>
#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/form.hpp"
#include "../../../include/xtd/forms/screen.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
/*
  static std::random_device rand;
  static int32_t default_location = std::uniform_int_distribution<int32_t> {4, 20}(rand) * 10; // 40;
 */
}

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

form& form::auto_size_mode(forms::auto_size_mode value) {
  this->set_auto_size_mode(value);
  return *this;
}

form& form::dialog_result(forms::dialog_result dialog_result) {
  if (this->dialog_result_ != dialog_result)
    this->dialog_result_ = dialog_result;
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
  if (!this->previous_screeen_) {
    this->previous_screeen_ = std::make_shared<screen>(screen::from_control(*this));
    this->recreate_handle();
  }
  this->container_control::visible(visible);
  return *this;
}

void form::activate() {
  native::form::activate(this->handle_);
}

void form::close() {
  native::form::close(this->handle_);
}

forms::dialog_result form::show_dialog() {
  return show_dialog(application::open_forms()[0].get());
}

forms::dialog_result form::show_dialog(const iwin32_window& owner) {
  intptr_t current_parent = this->parent_;
  this->set_state(state::modal, true);
  this->parent_ = owner.handle();
  this->recreate_handle();
  this->show();
  forms::dialog_result result = this->dialog_result_ = forms::dialog_result::none;
  if (application::message_loop()) {
    application::raise_enter_thread_modal(event_args::empty);
    result = static_cast<forms::dialog_result>(native::form::show_dialog(this->handle_));
    application::raise_leave_thread_modal(event_args::empty);
  } else
    application::run(*this);
  this->set_state(state::modal, false);
  this->parent_ = current_parent;
  this->hide();
  this->recreate_handle();
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
  create_params.style(WS_OVERLAPPEDWINDOW);
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
    case WM_CLOSE: this->wm_close(message); break;
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
      native::form::end_dialog(this->handle_, static_cast<int32_t>(this->dialog_result_));
    }
  }
}

drawing::size form::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : this->controls())
    bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  return drawing::size(bounds.location() + bounds.size());
}

void form::on_handle_created(const event_args &e) {
  this->container_control::on_handle_created(e);
}
