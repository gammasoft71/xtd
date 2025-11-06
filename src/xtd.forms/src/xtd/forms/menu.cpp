#include "../../../include/xtd/forms/context_menu.hpp"
#include "../../../include/xtd/forms/main_menu.hpp"
#include "../../../include/xtd/forms/menu.hpp"
#include "../../../include/xtd/forms/menu_item.hpp"
#include "menu_data.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/menu>
#include <xtd/forms/native/menu_item>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/as>
#include <xtd/is>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

std::map<intptr, xtd::ref<menu>> menu::handles_;

menu::menu() : data_(xtd::new_sptr<data>()) {
  //data_->mdi_list_item = xtd::new_uptr<menu_item>();
  data_->menu_items.item_added += {*this, &menu::on_item_added};
  data_->menu_items.item_removed += {*this, &menu::on_item_removed};
}

menu::menu(const menu_item_collection& items) : data_(xtd::new_sptr<data>()) {
  //data_->mdi_list_item = xtd::new_uptr<menu_item>();
  data_->menu_items.item_added += {*this, &menu::on_item_added};
  data_->menu_items.item_removed += {*this, &menu::on_item_removed};
  data_->menu_items.add_range(items);
}

menu::menu(const std::initializer_list<menu_item_ref>& items) : data_(xtd::new_sptr<data>()) {
  //data_->mdi_list_item = xtd::new_uptr<menu_item>();
  data_->menu_items.item_added += {*this, &menu::on_item_added};
  data_->menu_items.item_removed += {*this, &menu::on_item_removed};
  data_->menu_items.add_range(items);
}

menu::menu(const std::vector<menu_item_ref>& items) : data_(xtd::new_sptr<data>()) {
  //data_->mdi_list_item = xtd::new_uptr<menu_item>();
  data_->menu_items.item_added += {*this, &menu::on_item_added};
  data_->menu_items.item_removed += {*this, &menu::on_item_removed};
  data_->menu_items.add_range(items);
}

menu::menu(menu&& rhs) : component(std::move(rhs)), data_ {std::move(rhs.data_)} {
  data_->menu_items.item_added -= {rhs, &menu::on_item_added};
  data_->menu_items.item_removed -= {rhs, &menu::on_item_removed};
  data_->menu_items.item_added += {*this, &menu::on_item_added};
  data_->menu_items.item_removed += {*this, &menu::on_item_removed};
}

menu::~menu() {
  data_->menu_items.item_added -= {*this, &menu::on_item_added};
  data_->menu_items.item_removed -= {*this, &menu::on_item_removed};
  destroy_menu();
}

intptr menu::handle() const noexcept {
  return data_->handle;
}

bool menu::is_parent() const noexcept {
  return data_->menu_items.count() != 0;
}

const menu_item& menu::mdi_list_item() const noexcept {
  return *data_->mdi_list_item;
}

const menu::menu_item_collection& menu::menu_items() const noexcept {
  return data_->menu_items;
}

menu::menu_item_collection& menu::menu_items() noexcept {
  return data_->menu_items;
}

menu& menu::menu_items(const menu_item_collection& value) {
  if (&data_->menu_items != &value) {
    data_->menu_items.clear();
    data_->menu_items = value;
  }
  return *this;
}

menu& menu::menu_items(const std::initializer_list<menu_item_ref>& value) {
  data_->menu_items.clear();
  for (const auto& item : value)
    data_->menu_items.add(item);
  return *this;
}

menu& menu::menu_items(const std::vector<menu_item_ref>& value) {
  data_->menu_items.clear();
  for (const auto& item : value)
    data_->menu_items.add(item);
  return *this;
}

const xtd::string& menu::name() const noexcept {
  return data_->name;
}

menu& menu::name(const xtd::string& value) {
  data_->name = value;
  return *this;
}

const any_object& menu::tag() const noexcept {
  return data_->tag;
}

menu& menu::tag(const any_object& value) {
  data_->tag = value;
  return *this;
}

bool menu::equals(const object& obj) const noexcept {
  return is<menu>(obj) && equals(static_cast<const menu&>(obj));
}

bool menu::equals(const menu& other) const noexcept {
  return data_ == other.data_;
}

xtd::size menu::get_hash_code() const noexcept {
  return hash_code::combine(data_);
}

std::optional<xtd::ref<context_menu>> menu::get_context_menu() const noexcept {
  auto item = const_cast<menu*>(this);
  while (item) {
    if (dynamic_cast<context_menu*>(item)) return static_cast<context_menu&>(*item);
    if (item->data_->parent.has_value())item = &item->data_->parent.value().get();
    else item = nullptr;
  }
  return std::nullopt;
}

std::optional<xtd::ref<main_menu>> menu::get_main_menu() const noexcept {
  auto item = const_cast<menu*>(this);
  while (item) {
    if (dynamic_cast<main_menu*>(item)) return static_cast<main_menu&>(*item);
    if (item->data_->parent.has_value())item = &item->data_->parent.value().get();
    else item = nullptr;
  }
  return std::nullopt;
}

string menu::to_string() const noexcept {
  return string::format("{}, items.size: {}", get_type().full_name(), data_->menu_items.count());
}

void menu::clone_menu(const menu& menu_src) {
  data_->mdi_list_item = menu_src.data_->mdi_list_item;
  data_->menu_items = menu_src.data_->menu_items;
  data_->name = menu_src.data_->name;
  data_->tag = menu_src.data_->tag;
}

void menu::merge_menu(const menu& menu_src) {
  if (data_.get() == menu_src.data_.get()) throw_helper::throws(exception_case::argument, "It was attempted to merge the menu with itself");
  data_->menu_items.add_range(menu_src.data_->menu_items);
}

void menu::destroy_menu_handle(intptr handle) {
}

void menu::on_item_added(size_t pos, menu_item_ref item) {
}

void menu::on_item_removed(size_t pos, menu_item_ref item) {
}

void menu::create_menu() {
  if (!data_->handle)
    data_->handle = create_menu_handle();
}

void menu::destroy_menu() {
  if (data_->handle)
    destroy_menu_handle(data_->handle);
}

void menu::recreate_menu() {
  destroy_menu();
  create_menu();
}

