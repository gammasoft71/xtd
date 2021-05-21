#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_menu.h"
#include <xtd/forms/native/menu_item.h>
#include <xtd/forms/native/menu_item_kind.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <map>
#include <wx/menuitem.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t menu_item::create(const std::string& text, const xtd::drawing::image& image, int32_t kind, bool checked, size_t shortcut) {
  //return reinterpret_cast<intptr_t>(new wxMenuItem());
  static map<int32_t, wx_menu_item_kind> kinds = {{MI_NORMAL, wx_menu_item_kind::normal}, {MI_CHECK, wx_menu_item_kind::check}, {MI_RADIO, wx_menu_item_kind::radio}, {MI_DROPDOWN, wx_menu_item_kind::drop_down}, {MI_SEPARATOR, wx_menu_item_kind::separator}};
  return reinterpret_cast<intptr_t>(new wx_menu_item(text, image.handle(), kinds[kind], checked, shortcut));
}

void menu_item::destroy(intptr_t menu_item) {
  if (!menu_item) return;
  //delete reinterpret_cast<wxMenuItem*>(menu_item);
  delete reinterpret_cast<wx_menu_item*>(menu_item);
}

int32_t menu_item::menu_id(intptr_t menu_item) {
  //return reinterpret_cast<wx_menu_item*>(menu_item)->;
  return 0;
}
