#include <xtd/forms/native/about_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include <wx/aboutdlg.h>

using namespace xtd;
using namespace xtd::forms::native;

bool about_dialog::run_dialog(intptr_t hwnd, const std::string& name, const std::string& description, const std::string& version, const std::string& long_version, const std::string& copyright) {
  wxAboutDialogInfo about_info;
  about_info.SetName(name);
  about_info.SetDescription(description);
  about_info.SetVersion(version, long_version);
  about_info.SetCopyright(copyright);
  wxAboutBox(about_info, hwnd ? reinterpret_cast<control_handler*>(hwnd)->control() : nullptr);
  return true;
}
