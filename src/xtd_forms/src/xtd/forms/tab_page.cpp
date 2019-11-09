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

control& tab_page::text(const ustring& text) {
  if (this->text_ != text) {
    this->text_ = text;
    if (this->parent().has_value())
    static_cast<tab_control&>(this->parent().value().get()).recreate_handle();
  }
  return *this;
}

void tab_page::create_handle() {
  panel::create_handle();
  native::tab_control::add_item(this->parent().value().get().handle(), this->handle_, this->text_);
}

void tab_page::destroy_handle() {
  native::tab_control::delete_item(this->parent().value().get().handle(), this->handle_);
  panel::destroy_handle();
}
