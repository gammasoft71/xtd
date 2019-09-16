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
  /// @todo Read default_location and next_location from registry...
  static std::random_device rand;
  static int32_t default_location = std::uniform_int_distribution<int32_t> {2, 18}(rand) * 10; // 20;
  static bool next_location = true; // Strangely, on Windows the first location is used 2 times; this boolean simumate it.
  //static microsoft::win32::registry_key key = microsoft::win32::registry::current_user().create_sub_key("Software").create_sub_key("Gammasoft71").create_sub_key("xtd").create_sub_key(environment::version().to_string()).create_sub_key("forms");
  //static int32_t default_location = static_cast<int32_t>(key.get_value("DefaultFormLocation", 20));
  //static bool next_location = static_cast<int32_t>(key.get_value("NextFormLocation", 1))); // Strangely, on Windows the first location is used 2 times; this boolean simumate it.
}

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

form& form::start_position(form_start_position start_position) {
  if (this->start_position_ != start_position)
    this->start_position_ = start_position;
  return *this;
}

control& form::visible(bool visible) {
  if (!this->previous_screeen_) {
    this->client_size_ = {-1, -1};
    this->previous_screeen_ = std::make_shared<screen>(screen::from_control(*this));
    this->recreate_handle();
  }
  this->container_control::visible(visible);
  return *this;
}

void form::close() {
  native::form::close(this->handle_);
}

forms::dialog_result form::show_dialog() {
  return show_dialog(application::open_forms()[0].get());
}

forms::dialog_result form::show_dialog(const iwin32_window& owner) {
  intptr_t current_parent = this->parent_;
  this->modal_ = true;
  this->parent_ = owner.handle();
  this->recreate_handle();
  this->show();
  forms::dialog_result result = this->dialog_result_ = forms::dialog_result::none;
  if (application::message_loop())
    result = static_cast<forms::dialog_result>(native::form::show_dialog(this->handle_));
  else
    application::run(*this);
  this->modal_ = false;
  this->parent_ = current_parent;
  this->hide();
  this->recreate_handle();
  return result;
}

forms::create_params form::create_params() const {
  forms::create_params create_params = this->container_control::create_params();

  create_params.class_name("form");
  create_params.style(WS_OVERLAPPEDWINDOW);
  if (this->modal_) create_params.ex_style(create_params.ex_style() | WS_EX_MODALWINDOW);
  if (this->previous_screeen_) {
    switch (this->start_position_) {
      case form_start_position::manual:
        create_params.location(this->location());
        create_params.size(this->size());
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
          create_params.location({this->parent().left() + (this->parent().width() - this->width()) / 2, this->parent().top() + (this->parent().height() - this->height()) / 2});
        else
          create_params.location({default_location, default_location});
        create_params.size(this->size());
        break;
    }
    
    if (this->start_position_ == form_start_position::windows_default_location || this->start_position_ == form_start_position::windows_default_bounds || (this->start_position_ == form_start_position::center_parent && !this->parent_)) {
      next_location = !(next_location == true && default_location == 20);
      if (next_location) default_location = default_location < 180 ? default_location + 20 : 20;
    }
  }

  return create_params;
}

void form::wnd_proc(message &message) {
  if (this->enabled()) {
    switch (message.msg()) {
      case WM_CLOSE: this->wm_close(message); break;
      default: this->container_control::wnd_proc(message); break;
    }
  }
}

void form::wm_close(message &message) {
  this->def_wnd_proc(message);
  form_closing_event_args event_args;
  this->on_form_closing(event_args);
  if (event_args.cancel() != true) {
    if (!this->modal_)
      this->destroy_handle();
    else {
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
