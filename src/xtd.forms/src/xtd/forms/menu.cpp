#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/menu.h>
#include <xtd/forms/native/menu_item.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/as.h>
#include <xtd/argument_exception.h>
#include <xtd/is.h>
#include "../../../include/xtd/forms/menu.h"
#include "../../../include/xtd/forms/context_menu.h"
#include "../../../include/xtd/forms/main_menu.h"
#include "../../../include/xtd/forms/menu_item.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

map<intptr_t, reference_wrapper<menu>> menu::handles_;

menu::menu() : data_(make_shared<data>()) {
  //data_->mdi_list_item_ = make_unique<menu_item>();
  data_->menu_items_.item_added += {*this, &menu::on_item_added};
  data_->menu_items_.item_removed += {*this, &menu::on_item_removed};
}

menu::menu(const menu_item_collection& items) : data_(make_shared<data>()) {
  //data_->mdi_list_item_ = make_unique<menu_item>();
  data_->menu_items_.item_added += {*this, &menu::on_item_added};
  data_->menu_items_.item_removed += {*this, &menu::on_item_removed};
  data_->menu_items_.push_back_range(items);
}

menu::menu(const initializer_list<menu_item_ref>& items) : data_(make_shared<data>()) {
  //data_->mdi_list_item_ = make_unique<menu_item>();
  data_->menu_items_.item_added += {*this, &menu::on_item_added};
  data_->menu_items_.item_removed += {*this, &menu::on_item_removed};
  data_->menu_items_.push_back_range(items);
}

menu::menu(const vector<menu_item_ref>& items) : data_(make_shared<data>()) {
  //data_->mdi_list_item_ = make_unique<menu_item>();
  data_->menu_items_.item_added += {*this, &menu::on_item_added};
  data_->menu_items_.item_removed += {*this, &menu::on_item_removed};
  data_->menu_items_.push_back_range(items);
}

menu::~menu() {
  data_->menu_items_.item_added -= {*this, &menu::on_item_added};
  data_->menu_items_.item_removed -= {*this, &menu::on_item_removed};
  destroy_menu();
}

intptr_t menu::handle() const noexcept {
  return data_->handle_;
}

bool menu::is_parent() const noexcept {
  return data_->menu_items_.size() != 0;
}

const menu_item& menu::mdi_list_item() const noexcept {
  return *data_->mdi_list_item_;
}

const menu::menu_item_collection& menu::menu_items() const noexcept {
  return data_->menu_items_;
}

menu::menu_item_collection& menu::menu_items() noexcept {
  return data_->menu_items_;
}

menu& menu::menu_items(const menu_item_collection& value) {
  if (&data_->menu_items_ != &value) {
    data_->menu_items_.clear();
    data_->menu_items_ = value;
  }
  return *this;
}

menu& menu::menu_items(const initializer_list<reference_wrapper<menu_item>>& value) {
  data_->menu_items_.clear();
  for (const auto& item : value)
    data_->menu_items_.push_back(item);
  return *this;
}

menu& menu::menu_items(const vector<reference_wrapper<menu_item>>& value) {
  data_->menu_items_.clear();
  for (const auto& item : value)
    data_->menu_items_.push_back(item);
  return *this;
}

const xtd::ustring& menu::name() const noexcept {
  return data_->name_;
}

menu& menu::name(const xtd::ustring& value) {
  data_->name_ = value;
  return *this;
}

std::any menu::tag() const noexcept {
  return data_->tag_;
}

menu& menu::tag(std::any value) {
  data_->tag_ = value;
  return *this;
}

bool menu::equals(const menu& value) const noexcept {
  return data_ == value.data_;
}

bool menu::equals(const object& obj) const noexcept {
  return is<menu>(obj) && equals(as<menu>(obj));
}

optional<reference_wrapper<context_menu>> menu::get_context_menu() const noexcept {
  menu* item = const_cast<menu*>(this);
  while (item)
    if (dynamic_cast<context_menu*>(item)) return static_cast<context_menu&>(*item);
  return {};
}

optional<reference_wrapper<main_menu>> menu::get_main_menu() const noexcept {
  menu* item = const_cast<menu*>(this);
  while (item)
    if (dynamic_cast<main_menu*>(item)) return static_cast<main_menu&>(*item);
  return {};
}

ustring menu::to_string() const noexcept {
  return ustring::format("{}, items.size: {}", ustring::full_class_name(*this), data_->menu_items_.size());
}

void menu::clone_menu(const menu& menu_src) {
  *data_->mdi_list_item_ = *menu_src.data_->mdi_list_item_;
  data_->menu_items_ = menu_src.data_->menu_items_;
  data_->name_ = menu_src.data_->name_;
  data_->tag_ = menu_src.data_->tag_;
}

void menu::merge_menu(const menu& menu_src) {
  if (data_.get() == menu_src.data_.get()) throw argument_exception("It was attempted to merge the menu with itself"_t, current_stack_frame_);
  data_->menu_items_.push_back_range(menu_src.data_->menu_items_);
}

void menu::destroy_menu_handle(intptr_t handle) {
}

void menu::on_item_added(size_t pos, menu_item_ref item) {
}

void menu::on_item_removed(size_t pos, menu_item_ref item) {
}

void menu::create_menu() {
  if (!data_->handle_)
    data_->handle_ = create_menu_handle();
}

void menu::destroy_menu() {
  if (data_->handle_)
    destroy_menu_handle(data_->handle_);
}

void menu::recreate_menu() {
  destroy_menu();
  create_menu();
}

