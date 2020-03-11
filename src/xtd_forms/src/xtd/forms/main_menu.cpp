#include <xtd/forms/native/main_menu.h>
#include "../../../include/xtd/forms/menu_item.h"
#include "../../../include/xtd/forms/main_menu.h"

using namespace xtd;
using namespace xtd::forms;

main_menu::main_menu() {
  data_->handle_ = create_menu_handle();
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
}

main_menu::~main_menu() {
  if (data_.use_count() == 1) destroy_menu_handle(data_->handle_);
}

intptr_t main_menu::create_menu_handle() {
  return native::main_menu::create();
}

void main_menu::destroy_menu_handle(intptr_t handle) {
  return native::main_menu::destroy(handle);
}
