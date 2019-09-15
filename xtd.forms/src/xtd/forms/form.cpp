#include <stdexcept>
#include <xtd/xtd.diagnostics>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/form.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include <xtd/forms/window_messages.hpp>
#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/form.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

form::form() {
  this->auto_size_mode_ = forms::auto_size_mode::grow_only;
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
  this->font_ = this->default_font();
  this->size_ = this->default_size();
  this->visible_ = false;
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

void form::close() {
  native::form::close(this->handle_);
}

forms::dialog_result form::show_dialog() {
  return show_dialog(application::open_forms()[0].get());
}

forms::dialog_result form::show_dialog(const iwin32_window& owner) {
  intptr_t parent_old = this->parent_;
  this->modal_ = true;
  this->parent_ = owner.handle();
  this->recreate_handle();
  native::control::enabled(owner.handle(), false);
  forms::dialog_result result = this->dialog_result_;
  if (application::message_loop())
    result = static_cast<forms::dialog_result>(native::form::show_dialog(this->handle_));
  else
    application::run(*this);
  this->modal_ = false;
  this->parent_ = parent_old;
  this->recreate_handle();
  native::control::enabled(owner.handle(), true);
  return result;
}

forms::create_params form::create_params() const {
  forms::create_params create_params = this->control::create_params();

  create_params.class_name("form");
  create_params.style(WS_OVERLAPPEDWINDOW);
  if (this->modal_) create_params.ex_style(create_params.ex_style() | WS_EX_MODALWINDOW);
  
  return create_params;
}

void form::wnd_proc(message &message) {
  if (this->enabled()) {
    switch (message.msg()) {
      case WM_CLOSE: this->wm_close(message); break;
      default: this->control::wnd_proc(message); break;
    }
  }
}

void form::wm_close(message &message) {
  this->def_wnd_proc(message);
  form_closing_event_args event_args;
  this->on_form_closing(event_args);
  if (event_args.cancel() != true) {
    if (this->modal_) {
      if (this->dialog_result_ == forms::dialog_result::none)
        this->dialog_result_ = forms::dialog_result::cancel;
      native::form::end_dialog(this->handle_, static_cast<int32_t>(this->dialog_result_));
    } else
      this->destroy_handle();
  }
}

drawing::size form::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : this->controls())
    bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  return drawing::size(bounds.location() + bounds.size());
}

void form::on_handle_created(const event_args &e) {
  this->control::on_handle_created(e);
}
