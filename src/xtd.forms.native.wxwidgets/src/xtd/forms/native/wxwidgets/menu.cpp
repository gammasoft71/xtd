#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/menu>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/app.h>
#include <wx/menu.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;
using namespace xtd::helpers;

intptr menu::create() {
  return reinterpret_cast<intptr>(new wxMenu());
}

void menu::destroy(intptr menu) {
  if (!wxTheApp) return;
  if (menu == 0) throw_helper::throws(exception_case::argument);
  delete reinterpret_cast<wxMenu*>(menu);
}

void menu::insert_item(intptr menu, size_t pos, intptr menu_item) {
  if (menu == 0) throw_helper::throws(exception_case::argument);
  if (menu_item == 0) throw_helper::throws(exception_case::argument);
  reinterpret_cast<wxMenu*>(menu)->Insert(pos, reinterpret_cast<wxMenuItem*>(menu_item));
}

void menu::insert_menu(intptr menu, size_t pos, intptr menu_item, const string& text) {
  if (menu == 0) throw_helper::throws(exception_case::argument);
  if (menu_item == 0) throw_helper::throws(exception_case::argument);
  reinterpret_cast<wxMenu*>(menu)->Insert(pos, wxID_ANY, convert_string::to_wstring(text), reinterpret_cast<wxMenu*>(menu_item));
}

intptr menu::native_handle(intptr menu) {
  if (menu == 0) throw_helper::throws(exception_case::argument);
  return menu;
}

void menu::remove_item(intptr menu, size_t pos) {
  if (menu == 0) throw_helper::throws(exception_case::argument);
  reinterpret_cast<wxMenu*>(menu)->Remove(reinterpret_cast<wxMenu*>(menu)->FindItemByPosition(pos));
}

void menu::text(intptr menu, const xtd::string& text) {
  if (menu == 0) throw_helper::throws(exception_case::argument);
  auto wx_menu = reinterpret_cast<wxMenu*>(menu);
  if (wx_menu->GetMenuBar()) wx_menu->GetMenuBar()->SetMenuLabel(wx_menu->GetMenuBar()->FindMenu(wx_menu->GetTitle()), text.chars());
  else wx_menu->SetTitle(text.chars());
}
