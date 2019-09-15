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
  this->make_control(*this);
  this->control::data_->auto_size_mode_ = forms::auto_size_mode::grow_only;
  this->control::data_->back_color_ = this->default_back_color();
  this->control::data_->fore_color_ = this->default_fore_color();
  this->control::data_->font_ = this->default_font();
  this->control::data_->size_ = this->default_size();
  this->control::data_->visible_ = false;
  this->create_control();
}

form& form::operator=(const form& value) {
  this->control::operator=(value);
  this->form_closed = value.form_closed;
  this->form_closing = value.form_closing;
  this->data_ = value.data_;
  return *this;
}

form& form::auto_size_mode(forms::auto_size_mode value) {
  this->set_auto_size_mode(value);
  return *this;
}

form& form::dialog_result(forms::dialog_result dialog_result) {
  if (this->data_->dialog_result_ != dialog_result)
    this->data_->dialog_result_ = dialog_result;
  return *this;
}

control& form::parent(const control& parent) {
  throw std::invalid_argument("Top-level control cannot be added to a control.");
  return *this;
}

void form::close() {
  native::form::close(this->control::data_->handle_);
}

forms::dialog_result form::show_dialog() {
  return show_dialog(application::open_forms()[0].get());
}

forms::dialog_result form::show_dialog(const iwin32_window& owner) {
  intptr_t parent_old = this->control::data_->parent_;
  this->data_->modal_ = true;
  this->control::data_->parent_ = owner.handle();
  this->recreate_handle();
  native::control::enabled(owner.handle(), false);
  forms::dialog_result result = this->data_->dialog_result_;
  if (application::message_loop())
    result = static_cast<forms::dialog_result>(native::form::show_dialog(this->control::data_->handle_));
  else
    application::run(*this);
  this->data_->modal_ = false;
  this->control::data_->parent_ = parent_old;
  this->recreate_handle();
  native::control::enabled(owner.handle(), true);
  return result;
}

forms::create_params form::create_params() const {
  forms::create_params create_params = this->control::create_params();

  create_params.class_name("form");
  create_params.style(WS_OVERLAPPEDWINDOW);
  if (this->data_->modal_) create_params.ex_style(create_params.ex_style() | WS_EX_MODALWINDOW);
  
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
    if (this->data_->modal_) {
      if (this->data_->dialog_result_ == forms::dialog_result::none)
        this->data_->dialog_result_ = forms::dialog_result::cancel;
      native::form::end_dialog(this->control::data_->handle_, static_cast<int32_t>(this->data_->dialog_result_));
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
