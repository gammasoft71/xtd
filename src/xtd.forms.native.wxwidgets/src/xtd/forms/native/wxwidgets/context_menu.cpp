#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/context_menu.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/menu.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t context_menu::create() {
  return reinterpret_cast<intptr_t>(new wxMenu());
}

void context_menu::destroy(intptr_t context_menu) {
  if (!context_menu) return;
  delete reinterpret_cast<wxMenu*>(context_menu);
}

void context_menu::insert_item(intptr_t context_menu, size_t pos, intptr_t menu_item) {
  if (context_menu == 0) throw argument_exception(csf_);
  if (menu_item == 0) throw argument_exception(csf_);
  reinterpret_cast<wxMenu*>(context_menu)->Insert(pos, reinterpret_cast<wxMenuItem*>(menu_item));
}

void context_menu::insert_menu(intptr_t context_menu, size_t pos, intptr_t menu_item, const ustring& text) {
  if (context_menu == 0) throw argument_exception(csf_);
  if (menu_item == 0) throw argument_exception(csf_);
  reinterpret_cast<wxMenu*>(context_menu)->Insert(pos, wxID_ANY, convert_string::to_wstring(text), reinterpret_cast<wxMenu*>(menu_item));
}

intptr_t context_menu::native_handle(intptr_t context_menu) {
  if (context_menu == 0) throw argument_exception(csf_);
  return context_menu;
}

void context_menu::remove_item(intptr_t context_menu, size_t pos) {
  if (context_menu == 0) throw argument_exception(csf_);
  reinterpret_cast<wxMenu*>(context_menu)->Remove(reinterpret_cast<wxMenu*>(context_menu)->FindItemByPosition(pos));
}

void context_menu::text(intptr_t context_menu, const xtd::ustring& text) {
  if (context_menu == 0) throw argument_exception(csf_);
  reinterpret_cast<wxMenu*>(context_menu)->SetTitle(text);
}
