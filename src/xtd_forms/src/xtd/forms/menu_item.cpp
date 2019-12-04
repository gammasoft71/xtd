#include <xtd/forms/native/menu.hpp>
#include <xtd/forms/native/menu_item.hpp>
#include "../../../include/xtd/forms/menu_item.hpp"

using namespace xtd;
using namespace xtd::forms;

intptr_t menu_item::create_menu_handle() {
  if (is_parent()) return native::menu::create();
  return native::menu_item::create();
}

void menu_item::destroy_menu_handle(intptr_t handle) {
  if (is_parent()) return native::menu::destroy(handle);
  return native::menu_item::destroy(handle);
}
