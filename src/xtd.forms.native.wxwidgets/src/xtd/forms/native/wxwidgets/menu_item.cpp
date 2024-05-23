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
    itemText.Replace("&", ustring::empty_string);
    itemText.Replace(".", ustring::empty_string);
    itemText.LowerCase();
    wxString aboutText = "&About..."_t;
    aboutText.Replace("&", ustring::empty_string);
    aboutText.Replace(".", ustring::empty_string);
    aboutText.LowerCase();
    return itemText == aboutText || itemText == "about";
  }
#endif

  static bool is_quit_item(const xtd::ustring& text, size_t shortcut) {
    wxString itemText = text;
    itemText.Replace("&", ustring::empty_string);
    itemText.Replace(".", ustring::empty_string);
    itemText.LowerCase();
    wxString exitText = "E&xit"_t;
    exitText.Replace("&", ustring::empty_string);
    exitText.Replace(".", ustring::empty_string);
    exitText.LowerCase();
    return (itemText == exitText || itemText == "exit" || itemText == "quit") && (shortcut == (VK_COMMAND_MODIFIER | VK_Q) || shortcut == (VK_ALT_MODIFIER | VK_F4));
  }

#if defined(__WXOSX__)
  static bool is_preferences_item(const xtd::ustring& text) {
    wxString itemText = text;
    itemText.Replace("&", ustring::empty_string);
    itemText.Replace(".", ustring::empty_string);
    itemText.LowerCase();
#  ifdef __MAC_13_0
    wxString preferenceText = "&Settings..."_t;
#  else
    wxString preferenceText = "&Preferences"_t;
#  endif
    preferenceText.Replace("&", ustring::empty_string);
    preferenceText.Replace(".", ustring::empty_string);
    preferenceText.LowerCase();
    return itemText == preferenceText || itemText == "preferences" || itemText == "options" || itemText == "settings";
  }
  #endif
  
  static xtd::ustring make_item_text(const xtd::ustring& text, size_t shortcut) {
    using namespace std::literals;
#if defined(__WXOSX__)
    if (is_about_item(text)) return "";
    if (is_quit_item(text, shortcut)) return "";
#  ifdef __MAC_13_0
    if (is_preferences_item(text)) return xtd::ustring {"&Settings..."_t} + "\tCtrl+,";
#  else
    if (is_preferences_item(text)) return xtd::ustring {"&Preference"_t} + "\tCtrl+,";
#  endif
#elif defined(__WXMSW__)
      if (is_quit_item(text, shortcut)) return text + "\tAlt+F4";
#elif defined(__WXGTK__)
      if (is_quit_item(text, shortcut)) return text + "\tCtrl+Q";
#endif
    if (shortcut == VK_NONE) return text;
    auto key = ""_s;
    if ((shortcut & VK_COMMAND_MODIFIER) == VK_COMMAND_MODIFIER) key += (key.empty() ? ""_s : "+"_s) + "Ctrl"_s;
    if ((shortcut & VK_CONTROL_MODIFIER) == VK_CONTROL_MODIFIER) key += (key.empty() ? ""_s : "+"_s) + "RawCtrl"_s;
    if ((shortcut & VK_ALT_MODIFIER) == VK_ALT_MODIFIER) key += (key.empty() ? ""_s : "+"_s) + "Alt"_s;
    if ((shortcut & VK_SHIFT_MODIFIER) == VK_SHIFT_MODIFIER) key += (key.empty() ? ""_s : "+"_s) + "Shift"_s;
    
    shortcut &= ~(VK_COMMAND_MODIFIER | VK_CONTROL_MODIFIER | VK_ALT_MODIFIER | VK_SHIFT_MODIFIER);
    
    if (shortcut >= VK_A && shortcut <= VK_Z) key += (key.empty() ? ""_s : "+"_s) + static_cast<char>(shortcut);
    else if (shortcut >= VK_0 && shortcut <= VK_9) key += (key.empty() ? ""_s : "+"_s) + static_cast<char>(shortcut);
    else if (shortcut == VK_BACK) key += (key.empty() ? ""_s : "+"_s) + "Back"_s;
    else if (shortcut == VK_TAB) key += (key.empty() ? ""_s : "+"_s) + "Tab"_s;
    else if (shortcut == VK_CLEAR) key += (key.empty() ? ""_s : "+"_s) + "Clear"_s;
    else if (shortcut == VK_RETURN) key += (key.empty() ? ""_s : "+"_s) + "Return"_s;
    else if (shortcut == VK_ESCAPE) key += (key.empty() ? ""_s : "+"_s) + "Escape"_s;
    else if (shortcut == VK_SPACE) key += (key.empty() ? ""_s : "+"_s) + "Space"_s;
    else if (shortcut == VK_PRIOR) key += (key.empty() ? ""_s : "+"_s) + "Prior"_s;
    else if (shortcut == VK_NEXT) key += (key.empty() ? ""_s : "+"_s) + "Next"_s;
    else if (shortcut == VK_END) key += (key.empty() ? ""_s : "+"_s) + "End"_s;
    else if (shortcut == VK_HOME) key += (key.empty() ? ""_s : "+"_s) + "Home"_s;
    else if (shortcut == VK_LEFT) key += (key.empty() ? ""_s : "+"_s) + "Left"_s;
    else if (shortcut == VK_UP) key += (key.empty() ? ""_s : "+"_s) + "Up"_s;
    else if (shortcut == VK_RIGHT) key += (key.empty() ? ""_s : "+"_s) + "Right"_s;
    else if (shortcut == VK_DOWN) key += (key.empty() ? ""_s : "+"_s) + "Down"_s;
    else if (shortcut == VK_SELECT) key += (key.empty() ? ""_s : "+"_s) + "Select"_s;
    else if (shortcut == VK_PRINT) key += (key.empty() ? ""_s : "+"_s) + "Print"_s;
    else if (shortcut == VK_EXECUTE) key += (key.empty() ? ""_s : "+"_s) + "Execute"_s;
    else if (shortcut == VK_SNAPSHOT) key += (key.empty() ? ""_s : "+"_s) + "Snapshot"_s;
    else if (shortcut == VK_INSERT) key += (key.empty() ? ""_s : "+"_s) + "Insert"_s;
    else if (shortcut == VK_DELETE) key += (key.empty() ? ""_s : "+"_s) + "Delete"_s;
    else if (shortcut == VK_HELP) key += (key.empty() ? ""_s : "+"_s) + "Help"_s;
    else if (shortcut == VK_F1) key += (key.empty() ? ""_s : "+"_s) + "F1"_s;
    else if (shortcut == VK_F2) key += (key.empty() ? ""_s : "+"_s) + "F2"_s;
    else if (shortcut == VK_F3) key += (key.empty() ? ""_s : "+"_s) + "F3"_s;
    else if (shortcut == VK_F4) key += (key.empty() ? ""_s : "+"_s) + "F4"_s;
    else if (shortcut == VK_F5) key += (key.empty() ? ""_s : "+"_s) + "F5"_s;
    else if (shortcut == VK_F6) key += (key.empty() ? ""_s : "+"_s) + "F6"_s;
    else if (shortcut == VK_F7) key += (key.empty() ? ""_s : "+"_s) + "F7"_s;
    else if (shortcut == VK_F8) key += (key.empty() ? ""_s : "+"_s) + "F8"_s;
    else if (shortcut == VK_F9) key += (key.empty() ? ""_s : "+"_s) + "F9"_s;
    else if (shortcut == VK_F10) key += (key.empty() ? ""_s : "+"_s) + "F10"_s;
    else if (shortcut == VK_F11) key += (key.empty() ? ""_s : "+"_s) + "F11"_s;
    else if (shortcut == VK_F12) key += (key.empty() ? ""_s : "+"_s) + "F12"_s;
    else if (shortcut == VK_F13) key += (key.empty() ? ""_s : "+"_s) + "F13"_s;
    else if (shortcut == VK_F14) key += (key.empty() ? ""_s : "+"_s) + "F14"_s;
    else if (shortcut == VK_F15) key += (key.empty() ? ""_s : "+"_s) + "F15"_s;
    else if (shortcut == VK_F16) key += (key.empty() ? ""_s : "+"_s) + "F16"_s;
    else if (shortcut == VK_F17) key += (key.empty() ? ""_s : "+"_s) + "F17"_s;
    else if (shortcut == VK_F18) key += (key.empty() ? ""_s : "+"_s) + "F18"_s;
    else if (shortcut == VK_F19) key += (key.empty() ? ""_s : "+"_s) + "F19"_s;
    else if (shortcut == VK_F20) key += (key.empty() ? ""_s : "+"_s) + "F20"_s;
    else if (shortcut == VK_F21) key += (key.empty() ? ""_s : "+"_s) + "F21"_s;
    else if (shortcut == VK_F22) key += (key.empty() ? ""_s : "+"_s) + "F22"_s;
    else if (shortcut == VK_F23) key += (key.empty() ? ""_s : "+"_s) + "F23"_s;
    else if (shortcut == VK_F24) key += (key.empty() ? ""_s : "+"_s) + "F24"_s;
    return text + "\t" + key;
  }
  
  static wxWindowID make_window_id(const xtd::ustring& text, size_t shortcut) {
    #if defined(__WXOSX__)
    if (is_about_item(text)) return wxID_ABOUT;
    if (is_quit_item(text, shortcut)) return wxID_EXIT;
    if (is_preferences_item(text)) return wxID_PREFERENCES;
    #endif
    return wxID_ANY;
  }
}

void menu_item::checked(intptr menu_item, bool checked) {
  reinterpret_cast<wxMenuItem*>(menu_item)->Check(checked);
}

intptr menu_item::create(intptr menu, const ustring& text, const xtd::drawing::image& image, int32 kind, size_t shortcut) {
  static auto kinds = map<int32, wxItemKind> {{MI_NORMAL, wxITEM_NORMAL}, {MI_CHECK, wxITEM_CHECK}, {MI_RADIO, wxITEM_RADIO}, {MI_DROPDOWN, wxITEM_DROPDOWN}, {MI_SEPARATOR, wxITEM_SEPARATOR}};
  auto wx_menu_item = new wxMenuItem(menu == 0 ? nullptr : reinterpret_cast<wxMenu*>(menu), make_window_id(text, shortcut), convert_string::to_wstring(make_item_text(text, shortcut)), wxEmptyString, kinds[kind]);
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
