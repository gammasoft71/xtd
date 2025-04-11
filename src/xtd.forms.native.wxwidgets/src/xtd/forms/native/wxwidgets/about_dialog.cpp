#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.hpp"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.hpp"
#include <xtd/forms/native/about_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/bitmap>
#include <xtd/convert_string>
#include <xtd/literals>
#include <wx/aboutdlg.h>

using namespace xtd;
using namespace xtd::forms::native;

#if defined(__WXMSW__)
namespace {
  auto handle_hook = HHOOK{};
  LRESULT CALLBACK callbackProc(INT ncode, WPARAM wparam, LPARAM lparam) {
    if (ncode == HCBT_ACTIVATE) {
      allow_dark_mode_for_window(static_cast<intptr>(wparam));
      refresh_title_bar_theme_color(static_cast<intptr>(wparam));
      UnhookWindowsHookEx(handle_hook);
    } else
      CallNextHookEx(handle_hook, ncode, wparam, lparam);
    return 0;
  }
}
#endif

void about_dialog::show(intptr hwnd, const xtd::drawing::icon& icon, const string& name, const string& description, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const array<string>& creators, const array<string>& designers, const array<string>& doc_writers, const array<string>& translators, const string& license) {
  wxAboutDialogInfo about_info;
  about_info.SetName(convert_string::to_wstring(name));
  about_info.SetDescription(convert_string::to_wstring(description));
  if (!long_version.empty() || !version.empty()) about_info.SetVersion(version.empty() ? convert_string::to_wstring(long_version) : convert_string::to_wstring(version), convert_string::to_wstring(long_version));
  about_info.SetCopyright(convert_string::to_wstring(string(copyright).replace(u8"\u00A9"_s, u8"(c)"_s)));
  #if defined(__WXGTK__)
  about_info.SetIcon(reinterpret_cast<wxIconBundle*>(icon.handle())->GetIcon());
  about_info.SetWebSite(convert_string::to_wstring(website), convert_string::to_wstring(website_label));
  for (auto creator : creators)
    about_info.AddDeveloper(convert_string::to_wstring(creator));
  for (auto doc_writer : doc_writers)
    about_info.AddDocWriter(convert_string::to_wstring(doc_writer));
  for (auto translator : translators)
    about_info.AddTranslator(convert_string::to_wstring(translator));
  for (auto designer : designers)
    about_info.AddArtist(convert_string::to_wstring(designer));
  about_info.SetLicense(convert_string::to_wstring(license));
  #endif
  
  #if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
  #endif
  wxAboutBox(about_info, hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control());
}
