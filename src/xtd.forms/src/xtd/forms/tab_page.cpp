#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/tab_control.h>
#include <xtd/forms/native/tab_page.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/as.h>
#include <xtd/is.h>
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/tab_page.h"
#include "tab_control_data.h"

using namespace xtd;
using namespace xtd::forms;

struct tab_page::data {
  size_t image_index = image_list::npos;
};

tab_page::tab_page() : data_(std::make_shared<data>()) {
}

forms::create_params tab_page::create_params() const noexcept {
  auto create_params = panel::create_params();
  create_params.class_name("tabpage");
  return create_params;
}

scrollable_control& tab_page::auto_scroll(bool value) {
  if (auto_scroll() == value) return *this;
  panel::auto_scroll(value);
  if (parent().has_value()) static_cast<tab_control&>(parent().value().get()).post_recreate_handle();
  return *this;
}

size_t tab_page::image_index() const noexcept {
  return data_->image_index;
}

tab_page& tab_page::image_index(size_t value) {
  if (data_->image_index == value) return *this;
  data_->image_index = value;
  if (is_handle_created() && parent().has_value()) native::tab_page::image_index(handle(), data_->image_index);
  return *this;
}

control& tab_page::parent(const control& parent) {
  if (!is<tab_control>(parent)) throw argument_exception(ustring::format("tab_page cannot be added to a '{}'.  tab_page can only be added to tab_control"), parent.get_type().full_name());
  as<tab_control>(const_cast<control&>(parent)).tab_pages().push_back(*this);
  return *this;
}

control& tab_page::text(const ustring& text) {
  if (control::text() == text) return *this;
  if (is_handle_created() && parent().has_value()) native::tab_page::text(handle(), text);
  set_text(text);
  return *this;
}

tab_page tab_page::create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = tab_page {};
  result.text(text);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
}

tab_page tab_page::create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto result = tab_page {};
  result.parent(parent);
  result.text(text);
  if (location != drawing::point {-1, -1}) result.location(location);
  if (size != drawing::size {-1, -1}) result.size(size);
  result.name(name);
  return result;
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
