#include <xtd/forms/native/tab_control.h>
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/tab_page.h>
#include <xtd/forms/native/window_styles.h>
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/tab_page.h"

using namespace xtd;
using namespace xtd::forms;

tab_page::tab_page() {
}

forms::create_params tab_page::create_params() const {
  forms::create_params create_params = this->panel::create_params();
  
  create_params.class_name("tabpage");
  
  return create_params;
}

scrollable_control& tab_page::auto_scroll(bool auto_scroll) {
  if (this->auto_scroll_ != auto_scroll) {
    panel::auto_scroll(auto_scroll);
    if (parent().has_value()) static_cast<tab_control&>(parent().value().get()).recreate_handle();
  }
  return *this;
}

control& tab_page::text(const std::string& text) {
  if (this->text_ != text) {
    if (this->parent().has_value()) {
      for (size_t index = 0; index < this->parent().value().get().controls().size(); index++) {
        if (this->parent().value().get().controls()[index].get().handle() == handle()) {
          native::tab_control::page_text(parent_, index, text);
        }
      }
    }
  }
  return control::text(text);
}

void tab_page::destroy_handle() {
  if (this->parent().has_value()) native::tab_control::delete_item(this->parent().value().get().handle(), handle());
  panel::destroy_handle();
}
