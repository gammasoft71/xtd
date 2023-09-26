#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/context_menu>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/menu.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr context_menu::create() {
  return reinterpret_cast<intptr>(new wxMenu());
}

void context_menu::destroy(intptr context_menu) {
  delete reinterpret_cast<wxMenu*>(context_menu);
}

void context_menu::insert_item(intptr context_menu, size_t pos, intptr menu_item) {
  if (context_menu == 0) throw argument_exception {csf_};
  if (menu_item == 0) throw argument_exception {csf_};
  reinterpret_cast<wxMenu*>(context_menu)->Insert(pos, reinterpret_cast<wxMenuItem*>(menu_item));
}

void context_menu::insert_menu(intptr context_menu, size_t pos, intptr menu_item, const ustring& text) {
  if (context_menu == 0) throw argument_exception {csf_};
  if (menu_item == 0) throw argument_exception {csf_};
  reinterpret_cast<wxMenu*>(context_menu)->Insert(pos, wxID_ANY, convert_string::to_wstring(text), reinterpret_cast<wxMenu*>(menu_item));
}

intptr context_menu::native_handle(intptr context_menu) {
  if (context_menu == 0) throw argument_exception {csf_};
  return context_menu;
}

void context_menu::remove_item(intptr context_menu, size_t pos) {
  if (context_menu == 0) throw argument_exception {csf_};
  reinterpret_cast<wxMenu*>(context_menu)->Remove(reinterpret_cast<wxMenu*>(context_menu)->FindItemByPosition(pos));
}

void context_menu::text(intptr context_menu, const xtd::ustring& text) {
  if (context_menu == 0) throw argument_exception {csf_};
  reinterpret_cast<wxMenu*>(context_menu)->SetTitle(text);
}
