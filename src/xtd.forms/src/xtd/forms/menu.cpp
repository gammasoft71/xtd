#include "../../../include/xtd/forms/context_menu"
#include "../../../include/xtd/forms/main_menu"
#include "../../../include/xtd/forms/menu"
#include "../../../include/xtd/forms/menu_item"
#include "menu_data.h"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/menu>
#include <xtd/forms/native/menu_item>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/as>
#include <xtd/is>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

map<intptr, reference_wrapper<menu>> menu::handles_;

menu::menu() : data_(make_shared<data>()) {
  //data_->mdi_list_item = make_unique<menu_item>();
  data_->menu_items.item_added += {*this, &menu::on_item_added};
  data_->menu_items.item_removed += {*this, &menu::on_item_removed};
}

menu::menu(const menu_item_collection& items) : data_(make_shared<data>()) {
  //data_->mdi_list_item = make_unique<menu_item>();
  data_->menu_items.item_added += {*this, &menu::on_item_added};
  data_->menu_items.item_removed += {*this, &menu::on_item_removed};
  data_->menu_items.push_back_range(items);
}

menu::menu(const initializer_list<menu_item_ref>& items) : data_(make_shared<data>()) {
  //data_->mdi_list_item = make_unique<menu_item>();
  data_->menu_items.item_added += {*this, &menu::on_item_added};
  data_->menu_items.item_removed += {*this, &menu::on_item_removed};
  data_->menu_items.push_back_range(items);
}

menu::menu(const vector<menu_item_ref>& items) : data_(make_shared<data>()) {
  //data_->mdi_list_item = make_unique<menu_item>();
  data_->menu_items.item_added += {*this, &menu::on_item_added};
  data_->menu_items.item_removed += {*this, &menu::on_item_removed};
  data_->menu_items.push_back_range(items);
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
  return data_->menu_items.size() != 0;
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

menu& menu::menu_items(const initializer_list<reference_wrapper<menu_item>>& value) {
  data_->menu_items.clear();
  for (const auto& item : value)
    data_->menu_items.push_back(item);
  return *this;
}

menu& menu::menu_items(const vector<reference_wrapper<menu_item>>& value) {
  data_->menu_items.clear();
  for (const auto& item : value)
    data_->menu_items.push_back(item);
  return *this;
}

const xtd::ustring& menu::name() const noexcept {
  return data_->name;
}

menu& menu::name(const xtd::ustring& value) {
  data_->name = value;
  return *this;
}

std::any menu::tag() const noexcept {
  return data_->tag;
}

menu& menu::tag(std::any value) {
  data_->tag = value;
  return *this;
}

bool menu::equals(const menu& value) const noexcept {
  return data_ == value.data_;
}

optional<reference_wrapper<context_menu>> menu::get_context_menu() const noexcept {
  auto item = const_cast<menu*>(this);
  while (item) {
    if (dynamic_cast<context_menu*>(item)) return static_cast<context_menu&>(*item);
    if (item->data_->parent.has_value())item = &item->data_->parent.value().get();
    else item = nullptr;
  }
  return {};
}

optional<reference_wrapper<main_menu>> menu::get_main_menu() const noexcept {
  auto item = const_cast<menu*>(this);
  while (item) {
    if (dynamic_cast<main_menu*>(item)) return static_cast<main_menu&>(*item);
    if (item->data_->parent.has_value())item = &item->data_->parent.value().get();
    else item = nullptr;
  }
  return {};
}

ustring menu::to_string() const noexcept {
  return ustring::format("{}, items.size: {}", get_type().full_name(), data_->menu_items.size());
}

void menu::clone_menu(const menu& menu_src) {
  data_->mdi_list_item = menu_src.data_->mdi_list_item;
  data_->menu_items = menu_src.data_->menu_items;
  data_->name = menu_src.data_->name;
  data_->tag = menu_src.data_->tag;
}

void menu::merge_menu(const menu& menu_src) {
  if (data_.get() == menu_src.data_.get()) throw argument_exception("It was attempted to merge the menu with itself"_t, csf_);
  data_->menu_items.push_back_range(menu_src.data_->menu_items);
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

