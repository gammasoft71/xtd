#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/tab_control.h>
#include <xtd/forms/native/tab_page.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/tab_page.h"
#include "tab_control_data.h"

using namespace xtd;
using namespace xtd::forms;

forms::create_params tab_page::create_params() const noexcept {
  forms::create_params create_params = panel::create_params();
  
  create_params.class_name("tabpage");
  
  return create_params;
}

scrollable_control& tab_page::auto_scroll(bool value) {
  if (auto_scroll() != value) {
    panel::auto_scroll(value);
    if (parent().has_value()) static_cast<tab_control&>(parent().value().get()).post_recreate_handle();
  }
  return *this;
}

size_t tab_page::image_index() const noexcept {
  return data_->image_index;
}

tab_page& tab_page::image_index(size_t value) {
  if (data_->image_index != value) {
    data_->image_index = value;
    if (is_handle_created() && parent().has_value()) native::tab_page::image_index(handle(), data_->image_index);
  }
  return *this;
}

control& tab_page::text(const ustring& text) {
  if (control::text() != text) {
    if (is_handle_created() && parent().has_value()) native::tab_page::text(handle(), text);
    set_text(text);
  }
  return *this;
}

void tab_page::destroy_handle() {
  if (parent().has_value()) native::tab_control::delete_page(parent().value().get().handle(), handle());
  panel::destroy_handle();
}

void tab_page::on_handle_created(const event_args& e) {
  panel::on_handle_created(e);
  native::tab_control::insert_page(parent().value().get().handle(), parent().value().get().get_child_index(handle()), handle());
  native::tab_page::text(handle(), text());
  native::tab_page::image_index(handle(), data_->image_index);
  if (parent().value().get().get_child_index(handle()) == static_cast<tab_control&>(parent().value().get()).data_->selected_index)
    native::tab_control::selected_index(parent().value().get().handle(), static_cast<tab_control&>(parent().value().get()).data_->selected_index);
}
