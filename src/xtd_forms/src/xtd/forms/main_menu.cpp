#include <xtd/forms/native/main_menu.h>
#include <xtd/diagnostics/cdebug.h>
#include "../../../include/xtd/forms/menu_item.h"
#include "../../../include/xtd/forms/main_menu.h"

using namespace xtd;
using namespace xtd::forms;

main_menu::main_menu() {
  data_->menu_items_.item_added += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_ = *this;
    item.get().data_->parent_ = *this;
    item.get().create_menu();
  };

  data_->menu_items_.item_updated += [&](size_t, std::reference_wrapper<menu_item> item) {
    
  };

  data_->menu_items_.item_erased += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_.reset();
    item.get().destroy_menu();
  };

  data_->handle_ = create_menu_handle();
}

main_menu::main_menu(const std::initializer_list<menu_item>& menu_items) {
  data_->menu_items_.item_added += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_ = *this;
    item.get().data_->parent_ = *this;
    item.get().create_menu();
  };
  
  data_->menu_items_.item_updated += [&](size_t, std::reference_wrapper<menu_item> item) {
    
  };
  
  data_->menu_items_.item_erased += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_.reset();
    item.get().destroy_menu();
  };
  
  data_->menu_items_.push_back_range(menu_items);
  
  data_->handle_ = create_menu_handle();
}

main_menu::main_menu(const std::vector<menu_item>& menu_items) {
  data_->menu_items_.item_added += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_ = *this;
    item.get().data_->parent_ = *this;
    item.get().create_menu();
  };
  
  data_->menu_items_.item_updated += [&](size_t, std::reference_wrapper<menu_item> item) {
    
  };
  
  data_->menu_items_.item_erased += [&](size_t, std::reference_wrapper<menu_item> item) {
    item.get().data_->parent_.reset();
    item.get().destroy_menu();
  };
  
  data_->menu_items_.push_back_range(menu_items);
  
  data_->handle_ = create_menu_handle();
}


main_menu::~main_menu() {
  if (data_.use_count() == 1) destroy_menu_handle(data_->handle_);
}

intptr_t main_menu::create_menu_handle() {
  std::vector<intptr_t> menu_items;
  for(auto menu_item : data_->menu_items_)
    menu_items.push_back(menu_item.data_->handle_);
  auto handle = native::main_menu::create(menu_items);
  add_handles(data_->menu_items_);
  return handle;
}

void main_menu::destroy_menu_handle(intptr_t handle) {
  remove_handles(data_->menu_items_);
  return native::main_menu::destroy(handle);
}

void main_menu::wm_click(message& message) {
  for (auto item : handles_) {
    cdebug << format("handle = 0x{:X}, menu = {}", item.first, item.second) << std::endl;
  }
  auto menu = static_cast<menu_item*>(handles_[message.lparam()]);
  cdebug << format("Menu click : wparam = {}, lparam = 0x{:X}, menu = {}", message.wparam(), message.lparam(), menu ? menu->text() : "(null)") << std::endl;
}
