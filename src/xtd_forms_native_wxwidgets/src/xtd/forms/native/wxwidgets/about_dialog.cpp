#include <xtd/forms/native/about_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include <wx/aboutdlg.h>

using namespace xtd;
using namespace xtd::forms::native;

#if defined(__WXMSW__)
namespace {
  HHOOK handle_hook;
  LRESULT CALLBACK callbackProc(INT ncode, WPARAM wparam, LPARAM lparam) {
    if (ncode == HCBT_ACTIVATE) {
      allow_dark_mode_for_window(static_cast<intptr_t>(wparam));
      refresh_title_bar_theme_color(static_cast<intptr_t>(wparam));
      UnhookWindowsHookEx(handle_hook);
    }
    else
      CallNextHookEx(handle_hook, ncode, wparam, lparam);
    return 0;
  }
}
#endif

void about_dialog::show(intptr_t hwnd, const xtd::drawing::icon& icon, const std::string& name, const std::string& description, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const std::vector<std::string>& creators, const std::vector<std::string>& designers, const std::vector<std::string>& doc_writers, const std::vector<std::string>& translators, const std::string& license) {
  wxAboutDialogInfo about_info;
  about_info.SetName(name);
  about_info.SetDescription(description);
  about_info.SetVersion(version, long_version);
  about_info.SetCopyright(xtd::strings::replace(copyright, u8"\u00A9", u8"(c)"));
  if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") {
    about_info.SetIcon(*reinterpret_cast<wxIcon*>(icon.handle()));
    about_info.SetWebSite(website, website_label);
    for (auto creator : creators)
      about_info.AddDeveloper(creator);
    for (auto doc_writer : doc_writers)
      about_info.AddDocWriter(doc_writer);
    for (auto translator : translators)
      about_info.AddTranslator(translator);
    for (auto designer : designers)
      about_info.AddArtist(designer);
    about_info.SetLicense(license);

  }
#if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
#endif
  wxAboutBox(about_info, hwnd ? reinterpret_cast<control_handler*>(hwnd)->control() : nullptr);
}
