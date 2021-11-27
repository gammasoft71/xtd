#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/main_menu.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/menu.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

#if defined(__APPLE__)
namespace {
  static bool is_help_item(const xtd::ustring& text) {
    wxString itemText = text;
    itemText.Replace(L"&", L"");
    itemText.Replace(L".", L"");
    itemText.LowerCase();
    return itemText == L"help";
  }
  
  static bool is_view_item(const xtd::ustring& text) {
    wxString itemText = text;
    itemText.Replace(L"&", L"");
    itemText.Replace(L".", L"");
    itemText.LowerCase();
    return itemText == L"view";
  }
  
  static bool is_window_item(const xtd::ustring& text) {
    wxString itemText = text;
    itemText.Replace(L"&", L"");
    itemText.Replace(L".", L"");
    itemText.LowerCase();
    return itemText == L"window";
  }
}
#endif

intptr_t main_menu::create() {
  return reinterpret_cast<intptr_t>(new wxMenuBar);
}

void main_menu::destroy(intptr_t main_menu) {
  if (!wxTheApp) return;
  if (main_menu == 0) throw argument_exception(csf_);
  reinterpret_cast<wxMenuBar*>(main_menu)->Destroy();
}

void main_menu::insert_item(intptr_t main_menu, size_t pos, intptr_t menu_item, const ustring& text) {
  if (main_menu == 0) throw argument_exception(csf_);
  if (menu_item == 0) throw argument_exception(csf_);

  auto wx_main_menu = reinterpret_cast<wxMenuBar*>(main_menu);
  
#if defined(__APPLE__)
  if (is_window_item(convert_string::to_wstring(text))) {
    bool has_view_menu = false;
    for (size_t index = 0; index < wx_main_menu->GetMenuCount(); ++index)
      if (is_view_item(convert_string::to_wstring(text))) has_view_menu = true;
    if (!has_view_menu) wx_main_menu->Insert(pos++, new wxMenu, L"&View"_t);
  }
  
  if (is_help_item(convert_string::to_wstring(text))) {
    bool has_view_menu = false, has_window_menu = false;
    for (size_t index = 0; index < wx_main_menu->GetMenuCount(); ++index) {
      if (is_view_item(convert_string::to_wstring(text))) has_view_menu = true;
      if (is_window_item(convert_string::to_wstring(text))) has_window_menu = true;
    }
    if (!has_view_menu) wx_main_menu->Insert(pos++, new wxMenu, L"&View"_t);
    if (!has_window_menu) wx_main_menu->Insert(pos++, new wxMenu, L"&Window"_t);
  }
#endif
  
  wx_main_menu->Insert(pos, reinterpret_cast<wxMenu*>(menu_item), convert_string::to_wstring(text));
}

void main_menu::remove_item(intptr_t main_menu, size_t pos) {
  if (main_menu == 0) throw argument_exception(csf_);
  reinterpret_cast<wxMenuBar*>(main_menu)->Remove(pos);
}
