#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/menu.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/menu.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t menu::create(const ustring& text) {
  auto wx_menu = new wxMenu();
  wx_menu->SetTitle(convert_string::to_wstring(text));
  
  return reinterpret_cast<intptr_t>(wx_menu);
}

void menu::destroy(intptr_t menu) {
  if (!wxTheApp) return;
  if (menu == 0) throw argument_exception(csf_);
  delete reinterpret_cast<wxMenu*>(menu);
}

void menu::insert_item(intptr_t menu, size_t pos,  intptr_t menu_item) {
  if (menu == 0) throw argument_exception(csf_);
  if (menu_item == 0) throw argument_exception(csf_);
  reinterpret_cast<wxMenu*>(menu)->Insert(pos, reinterpret_cast<wxMenuItem*>(menu_item));
}

void menu::insert_menu(intptr_t menu, size_t pos,  intptr_t menu_item) {
  if (menu == 0) throw argument_exception(csf_);
  if (menu_item == 0) throw argument_exception(csf_);
  reinterpret_cast<wxMenu*>(menu)->Insert(pos, wxID_ANY, reinterpret_cast<wxMenu*>(menu_item)->GetTitle(), reinterpret_cast<wxMenu*>(menu_item));
}

intptr_t menu::native_handle(intptr_t menu) {
  if (menu == 0) throw argument_exception(csf_);
  return menu;
}
