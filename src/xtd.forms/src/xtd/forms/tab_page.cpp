#include "../../../include/xtd/forms/tab_control.hpp"
#include "../../../include/xtd/forms/tab_page.hpp"
#include "tab_control_data.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/tab_control>
#include <xtd/forms/native/tab_page>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/as>
#include <xtd/is>

using namespace xtd;
using namespace xtd::forms;

struct tab_page::data {
  size_t image_index = image_list::npos;
};

tab_page::tab_page() : data_(xtd::new_sptr<data>()) {
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
  if (!is<tab_control>(parent)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument, string::format("tab_page cannot be added to a '{}'.  tab_page can only be added to tab_control", parent.get_type().full_name()).c_str());
  as<tab_control>(const_cast<control&>(parent)).tab_pages().push_back(*this);
  return *this;
}

control& tab_page::parent(std::nullptr_t) {
  if (!parent()) return *this;
  auto it = find(as<tab_control>(parent().value().get()).tab_pages().begin(), as<tab_control>(parent().value().get()).tab_pages().end(), *this);
  if (it != as<tab_control>(parent().value().get()).tab_pages().end()) as<tab_control>(const_cast<control&>(parent().value().get())).tab_pages().erase(it);
  return *this;
}

control& tab_page::text(const string& text) {
  if (control::text() == text) return *this;
  if (is_handle_created() && parent().has_value()) native::tab_page::text(handle(), text);
  set_text(text);
  return *this;
}

tab_page tab_page::create() {
  return tab_page {};
}

tab_page tab_page::create(const drawing::point& location) {
  auto result = tab_page {};
  result.location(location);
  return result;
}

tab_page tab_page::create(const drawing::point& location, const drawing::size& size) {
  auto result = tab_page {};
  result.location(location);
  result.size(size);
  return result;
}

tab_page tab_page::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = tab_page {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

tab_page tab_page::create(const xtd::string& text) {
  auto result = tab_page {};
  result.text(text);
  return result;
}

tab_page tab_page::create(const xtd::string& text, const drawing::point& location) {
  auto result = tab_page {};
  result.text(text);
  result.location(location);
  return result;
}

tab_page tab_page::create(const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = tab_page {};
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

tab_page tab_page::create(const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = tab_page {};
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

tab_page tab_page::create(const control& parent) {
  auto result = tab_page {};
  result.parent(parent);
  return result;
}

tab_page tab_page::create(const control& parent, const drawing::point& location) {
  auto result = tab_page {};
  result.parent(parent);
  result.location(location);
  return result;
}

tab_page tab_page::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = tab_page {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

tab_page tab_page::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = tab_page {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

tab_page tab_page::create(const control& parent, const xtd::string& text) {
  auto result = tab_page {};
  result.parent(parent);
  result.text(text);
  return result;
}

tab_page tab_page::create(const control& parent, const xtd::string& text, const drawing::point& location) {
  auto result = tab_page {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  return result;
}

tab_page tab_page::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = tab_page {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

tab_page tab_page::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = tab_page {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

void tab_page::destroy_handle() {
  if (parent().has_value()) native::tab_control::delete_page(parent().value().get().handle(), handle());
  panel::destroy_handle();
}

xtd::uptr<xtd::object> tab_page::clone() const {
  auto result = xtd::new_uptr<tab_page>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()));
  return result;
}

void tab_page::on_handle_created(const event_args& e) {
  panel::on_handle_created(e);
  native::tab_control::insert_page(parent().value().get().handle(), parent().value().get().get_child_index(handle()), handle());
  native::tab_page::text(handle(), text());
  native::tab_page::image_index(handle(), data_->image_index);
  if (parent().value().get().get_child_index(handle()) == static_cast<tab_control&>(parent().value().get()).data_->selected_index)
    native::tab_control::selected_index(parent().value().get().handle(), static_cast<tab_control&>(parent().value().get()).data_->selected_index);
}
