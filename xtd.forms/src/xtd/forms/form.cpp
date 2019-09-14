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
  this->data_->is_dialog_shown_ = true;
  this->show();
  if (this->control::data_->parent_) this->control::data_->parent_ = owner.handle();
  if (application::message_loop())
    return static_cast<forms::dialog_result>(native::form::show_dialog(this->control::data_->handle_, owner.handle()));
  application::run(*this);
  this->data_->is_dialog_shown_ = false;
  return this->data_->dialog_result_;
}

forms::create_params form::create_params() const {
  forms::create_params create_params = this->control::create_params();
  
  create_params.class_name("form");
  create_params.style(WS_OVERLAPPEDWINDOW);
  
  return create_params;
}

void form::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_CLOSE: this->wm_close(message); break;
    default: this->control::wnd_proc(message); break;
  }
}

void form::wm_close(message &message) {
  this->def_wnd_proc(message);
  this->data_->dialog_result_ = forms::dialog_result::cancel;
  form_closing_event_args event_args;
  this->on_form_closing(event_args);
  if (event_args.cancel() != true) {
    if (this->data_->is_dialog_shown_) {
      native::form::end_dialog(this->control::data_->handle_, static_cast<int32_t>(this->data_->dialog_result_));
      this->data_->is_dialog_shown_ = false;
    }
    this->destroy_handle();
  }
}

drawing::size form::measure_control() const {
  drawing::rectangle bounds;
  for (auto item : this->controls())
    bounds = drawing::rectangle::make_union(bounds, item.get().bounds());
  return drawing::size(bounds.location() + bounds.size());
}
