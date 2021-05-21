#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/tab_control.h>
#include <xtd/forms/native/tab_page.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/tab_page.h"

using namespace xtd;
using namespace xtd::forms;

tab_page::tab_page() {
}

forms::create_params tab_page::create_params() const {
  forms::create_params create_params = panel::create_params();
  
  create_params.class_name("tabpage");
  
  return create_params;
}

scrollable_control& tab_page::auto_scroll(bool auto_scroll) {
  if (auto_scroll_ != auto_scroll) {
    panel::auto_scroll(auto_scroll);
    if (parent().has_value()) static_cast<tab_control&>(parent().value().get()).recreate_handle();
  }
  return *this;
}

tab_page& tab_page::image_index(int32_t value) {
  if (image_index_ != value) {
    image_index_ = value;
     if (parent().has_value()) native::tab_page::image_index(handle(), image_index_);
  }
  return *this;
}

control& tab_page::text(const std::string& text) {
  if (text_ != text) {
    if (parent().has_value())
      if (parent().has_value()) native::tab_page::text(handle(), text);
  }
  return control::text(text);
}

void tab_page::destroy_handle() {
  if (parent().has_value()) native::tab_control::delete_item(parent().value().get().handle(), parent().value().get().get_child_index(handle()));
  panel::destroy_handle();
}

void tab_page::on_handle_created(const event_args& e) {
  panel::on_handle_created(e);
  if (image_index_ != -1 && parent().has_value()) native::tab_page::image_index(handle(), image_index_);
}
