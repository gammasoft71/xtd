#include <xtd/forms/native/tab_control.hpp>
#include <xtd/forms/native/tab_page.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include "../../../include/xtd/forms/tab_control.hpp"
#include "../../../include/xtd/forms/tab_page.hpp"

using namespace xtd;
using namespace xtd::forms;

tab_page::tab_page() {
}

forms::create_params tab_page::create_params() const {
  forms::create_params create_params = this->panel::create_params();
  
  create_params.class_name("tabpage");
  
  return create_params;
}

void tab_page::on_handle_created(const event_args &e) {
  this->panel::on_handle_created(e);
  if (this->parent().has_value() && dynamic_cast<tab_control*>(&this->parent().value().get()) != nullptr)
    native::tab_control::add_item(this->parent_, this->handle_, this->text_);
}

void tab_page::on_handle_destroyed(const event_args &e) {
  /*
  if (this->parent().has_value() && dynamic_cast<tab_control*>(&this->parent().value().get()) != nullptr) {
    for (size_t index = 0; index < this->parent().value().get().controls().size(); index++) {
      if (this->parent().value().get().controls()[index].get().handle() == this->handle_) {
        native::tab_control::delete_item(this->parent_, index);
        break;
      }
    }
    this->panel::on_handle_destroyed(e);
  }
   */
}
