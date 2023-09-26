#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/menu_item>
#include <xtd/forms/native/menu_item_kind>
#include <xtd/forms/native/virtual_keys>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/menuitem.h>
#include <map>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  #if defined(__WXOSX__)
  static bool is_about_item(const xtd::ustring& text) {
    wxString itemText = text;
    itemText.Replace("&", "");
    itemText.Replace(".", "");
    itemText.LowerCase();
    wxString aboutText = "&About..."_t;
    aboutText.Replace("&", "");
    aboutText.Replace(".", "");
    aboutText.LowerCase();
    return itemText == aboutText || itemText == "about";
  }
  
  static bool is_quit_item(const xtd::ustring& text) {
    wxString itemText = text;
    itemText.Replace("&", "");
    itemText.Replace(".", "");
    itemText.LowerCase();
    wxString exitText = "E&xit"_t;
    exitText.Replace("&", "");
    exitText.Replace(".", "");
    exitText.LowerCase();
    return itemText == exitText || itemText == "exit" || itemText == "quit";
  }
  
  static bool is_preferences_item(const xtd::ustring& text) {
    wxString itemText = text;
    itemText.Replace("&", "");
    itemText.Replace(".", "");
    itemText.LowerCase();
    wxString preferenceText = "E&xit"_t;
    preferenceText.Replace("&", "");
    preferenceText.Replace(".", "");
    preferenceText.LowerCase();
    return itemText == preferenceText || itemText == "preferences" || itemText == "options";
  }
  #endif
  
  static xtd::ustring make_item_text(const xtd::ustring& text, size_t shortcut) {
    using namespace std::literals;
    #if defined(__WXOSX__)
    if (is_about_item(text)) return "";
    if (is_quit_item(text)) return "";
    if (is_preferences_item(text)) return "";
    #endif
    if (shortcut == VK_NONE) return text;
    auto key = ""s;
    if ((shortcut & VK_COMMAND_MODIFIER) == VK_COMMAND_MODIFIER) key += (key.empty() ? ""s : "+"s) + "Ctrl"s;
    if ((shortcut & VK_CONTROL_MODIFIER) == VK_CONTROL_MODIFIER) key += (key.empty() ? ""s : "+"s) + "RawCtrl"s;
    if ((shortcut & VK_ALT_MODIFIER) == VK_ALT_MODIFIER) key += (key.empty() ? ""s : "+"s) + "Alt"s;
    if ((shortcut & VK_SHIFT_MODIFIER) == VK_SHIFT_MODIFIER) key += (key.empty() ? ""s : "+"s) + "Shift"s;
    
    shortcut &= ~(VK_COMMAND_MODIFIER | VK_CONTROL_MODIFIER | VK_ALT_MODIFIER | VK_SHIFT_MODIFIER);
    
    if (shortcut >= VK_A && shortcut <= VK_Z) key += (key.empty() ? ""s : "+"s) + static_cast<char>(shortcut);
    else if (shortcut >= VK_0 && shortcut <= VK_9) key += (key.empty() ? ""s : "+"s) + static_cast<char>(shortcut);
    else if (shortcut == VK_BACK) key += (key.empty() ? ""s : "+"s) + "Back"s;
    else if (shortcut == VK_TAB) key += (key.empty() ? ""s : "+"s) + "Tab"s;
    else if (shortcut == VK_CLEAR) key += (key.empty() ? ""s : "+"s) + "Clear"s;
    else if (shortcut == VK_RETURN) key += (key.empty() ? ""s : "+"s) + "Return"s;
    else if (shortcut == VK_ESCAPE) key += (key.empty() ? ""s : "+"s) + "Escape"s;
    else if (shortcut == VK_SPACE) key += (key.empty() ? ""s : "+"s) + "Space"s;
    else if (shortcut == VK_PRIOR) key += (key.empty() ? ""s : "+"s) + "Prior"s;
    else if (shortcut == VK_NEXT) key += (key.empty() ? ""s : "+"s) + "Next"s;
    else if (shortcut == VK_END) key += (key.empty() ? ""s : "+"s) + "End"s;
    else if (shortcut == VK_HOME) key += (key.empty() ? ""s : "+"s) + "Home"s;
    else if (shortcut == VK_LEFT) key += (key.empty() ? ""s : "+"s) + "Left"s;
    else if (shortcut == VK_UP) key += (key.empty() ? ""s : "+"s) + "Up"s;
    else if (shortcut == VK_RIGHT) key += (key.empty() ? ""s : "+"s) + "Right"s;
    else if (shortcut == VK_DOWN) key += (key.empty() ? ""s : "+"s) + "Down"s;
    else if (shortcut == VK_SELECT) key += (key.empty() ? ""s : "+"s) + "Select"s;
    else if (shortcut == VK_PRINT) key += (key.empty() ? ""s : "+"s) + "Print"s;
    else if (shortcut == VK_EXECUTE) key += (key.empty() ? ""s : "+"s) + "Execute"s;
    else if (shortcut == VK_SNAPSHOT) key += (key.empty() ? ""s : "+"s) + "Snapshot"s;
    else if (shortcut == VK_INSERT) key += (key.empty() ? ""s : "+"s) + "Insert"s;
    else if (shortcut == VK_DELETE) key += (key.empty() ? ""s : "+"s) + "Delete"s;
    else if (shortcut == VK_HELP) key += (key.empty() ? ""s : "+"s) + "Help"s;
    else if (shortcut == VK_F1) key += (key.empty() ? ""s : "+"s) + "F1"s;
    else if (shortcut == VK_F2) key += (key.empty() ? ""s : "+"s) + "F2"s;
    else if (shortcut == VK_F3) key += (key.empty() ? ""s : "+"s) + "F3"s;
    else if (shortcut == VK_F4) key += (key.empty() ? ""s : "+"s) + "F4"s;
    else if (shortcut == VK_F5) key += (key.empty() ? ""s : "+"s) + "F5"s;
    else if (shortcut == VK_F6) key += (key.empty() ? ""s : "+"s) + "F6"s;
    else if (shortcut == VK_F7) key += (key.empty() ? ""s : "+"s) + "F7"s;
    else if (shortcut == VK_F8) key += (key.empty() ? ""s : "+"s) + "F8"s;
    else if (shortcut == VK_F9) key += (key.empty() ? ""s : "+"s) + "F9"s;
    else if (shortcut == VK_F10) key += (key.empty() ? ""s : "+"s) + "F10"s;
    else if (shortcut == VK_F11) key += (key.empty() ? ""s : "+"s) + "F11"s;
    else if (shortcut == VK_F12) key += (key.empty() ? ""s : "+"s) + "F12"s;
    else if (shortcut == VK_F13) key += (key.empty() ? ""s : "+"s) + "F13"s;
    else if (shortcut == VK_F14) key += (key.empty() ? ""s : "+"s) + "F14"s;
    else if (shortcut == VK_F15) key += (key.empty() ? ""s : "+"s) + "F15"s;
    else if (shortcut == VK_F16) key += (key.empty() ? ""s : "+"s) + "F16"s;
    else if (shortcut == VK_F17) key += (key.empty() ? ""s : "+"s) + "F17"s;
    else if (shortcut == VK_F18) key += (key.empty() ? ""s : "+"s) + "F18"s;
    else if (shortcut == VK_F19) key += (key.empty() ? ""s : "+"s) + "F19"s;
    else if (shortcut == VK_F20) key += (key.empty() ? ""s : "+"s) + "F20"s;
    else if (shortcut == VK_F21) key += (key.empty() ? ""s : "+"s) + "F21"s;
    else if (shortcut == VK_F22) key += (key.empty() ? ""s : "+"s) + "F22"s;
    else if (shortcut == VK_F23) key += (key.empty() ? ""s : "+"s) + "F23"s;
    else if (shortcut == VK_F24) key += (key.empty() ? ""s : "+"s) + "F24"s;
    return text + "\t" + key;
  }
  
  static wxWindowID make_window_id(const xtd::ustring& text) {
    #if defined(__WXOSX__)
    if (is_about_item(text)) return wxID_ABOUT;
    if (is_quit_item(text)) return wxID_EXIT;
    if (is_preferences_item(text)) return wxID_PREFERENCES;
    #endif
    return wxID_ANY;
  }
}

void menu_item::checked(intptr menu_item, bool checked) {
  reinterpret_cast<wxMenuItem*>(menu_item)->Check(checked);
}

intptr menu_item::create(intptr menu, const ustring& text, const xtd::drawing::image& image, int32 kind, size_t shortcut) {
  static map<int32, wxItemKind> kinds = {{MI_NORMAL, wxITEM_NORMAL}, {MI_CHECK, wxITEM_CHECK}, {MI_RADIO, wxITEM_RADIO}, {MI_DROPDOWN, wxITEM_DROPDOWN}, {MI_SEPARATOR, wxITEM_SEPARATOR}};
  auto wx_menu_item = new wxMenuItem(menu == 0 ? nullptr : reinterpret_cast<wxMenu*>(menu), make_window_id(text), convert_string::to_wstring(make_item_text(text, shortcut)), wxEmptyString, kinds[kind]);
  if (image.handle() != 0) wx_menu_item->SetBitmap(wxBitmap(*reinterpret_cast<wxImage*>(image.handle())));
  return reinterpret_cast<intptr>(wx_menu_item);
}

void menu_item::destroy(intptr menu_item) {
  if (!wxTheApp) return;
  if (menu_item == 0) throw argument_exception {csf_};
  delete reinterpret_cast<wxMenuItem*>(menu_item);
}

void menu_item::enabled(intptr menu_item, bool enabled) {
  reinterpret_cast<wxMenuItem*>(menu_item)->Enable(enabled);
}

intptr menu_item::menu_id(intptr menu_item) {
  if (menu_item == 0) throw argument_exception {csf_};
  return static_cast<intptr>(reinterpret_cast<wxMenuItem*>(menu_item)->GetId());
}

void menu_item::text(intptr menu_item, const xtd::ustring& text, size_t shortcut) {
  if (menu_item == 0) throw argument_exception {csf_};
  reinterpret_cast<wxMenuItem*>(menu_item)->SetItemLabel(convert_string::to_wstring(make_item_text(text, shortcut)));
}
