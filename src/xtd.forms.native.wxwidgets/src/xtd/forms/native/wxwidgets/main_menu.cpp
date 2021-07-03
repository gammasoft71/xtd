#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_menu.h"
#include <xtd/forms/native/main_menu.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/menu.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

std::map<wxWindowID, wx_menu_item*> wx_menu_bar::ids_;

intptr_t main_menu::create(const std::vector<intptr_t>& menu_items) {
  std::vector<wx_menu_item*> wx_menu_items;
  for (auto item : menu_items)
    wx_menu_items.push_back(reinterpret_cast<wx_menu_item*>(item));
  return reinterpret_cast<intptr_t>(new wx_menu_bar(wx_menu_items));
}

void main_menu::destroy(intptr_t main_menu) {
  if (!main_menu) return;
  if (wxTheApp) reinterpret_cast<wx_menu_bar*>(main_menu)->Destroy();
}
