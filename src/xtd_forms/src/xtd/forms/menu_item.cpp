#include <xtd/forms/native/menu.h>
#include <xtd/forms/native/menu_item.h>
#include "../../../include/xtd/forms/menu_item.h"

using namespace xtd;
using namespace xtd::forms;

menu_item::menu_item() : menu(menu::menu_item_collection {}) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text) : menu(menu::menu_item_collection {}), text_(text) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const std::initializer_list<menu_item>& items) : menu(items), text_(text) {
  data_->handle_ = create_menu_handle();
}

menu_item::menu_item(const std::string& text, const std::vector<menu_item>& items) : menu(items), text_(text) {
  data_->handle_ = create_menu_handle();
}

intptr_t menu_item::create_menu_handle() {
  if (is_parent()) {
    std::vector<intptr_t> menu_items;
    for (auto item : data_->menu_items_)
      menu_items.push_back(item.handle());
    return native::menu::create(text_, menu_items);
  }
  return native::menu_item::create(text_);
}

void menu_item::destroy_menu_handle(intptr_t handle) {
  if (is_parent()) return native::menu::destroy(handle);
  return native::menu_item::destroy(handle);
}
