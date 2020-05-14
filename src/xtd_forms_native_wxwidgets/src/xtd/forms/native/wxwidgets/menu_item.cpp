#include "../../../../../include/xtd/forms/native/wxwidgets/wx_menu.h"
#include <xtd/forms/native/menu_item.h>
#include <wx/menuitem.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t menu_item::create(const std::string& text) {
  //return reinterpret_cast<intptr_t>(new wxMenuItem());
  return reinterpret_cast<intptr_t>(new wx_menu_item(text));
}


void menu_item::destroy(intptr_t menu_item) {
  if (!menu_item) return;
  //delete reinterpret_cast<wxMenuItem*>(menu_item);
  delete reinterpret_cast<wx_menu_item*>(menu_item);
}
