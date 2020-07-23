#include "../../../../../include/xtd/forms/native/wxwidgets/wx_menu.h"
#include <xtd/forms/native/menu_item.h>
#include <wx/menuitem.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t menu_item::create(const std::string& text, const xtd::drawing::image& image, int kind, bool checked, size_t shortcut) {
  //return reinterpret_cast<intptr_t>(new wxMenuItem());
  return reinterpret_cast<intptr_t>(new wx_menu_item(text, image.handle(), static_cast<wx_menu_item_kind>(kind), checked, shortcut));
}

void menu_item::destroy(intptr_t handle) {
  if (!handle) return;
  //delete reinterpret_cast<wxMenuItem*>(handle);
  delete reinterpret_cast<wx_menu_item*>(handle);
}

int menu_item::menu_id(intptr_t handle) {
  //return reinterpret_cast<wx_menu_item*>(handle)->;
  return 0;
}
