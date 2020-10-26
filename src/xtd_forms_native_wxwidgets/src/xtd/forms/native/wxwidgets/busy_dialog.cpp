#include <xtd/drawing/bitmap.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/busy_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include <wx/busyinfo.h>
#include <wx/iconbndl.h>

using namespace xtd;
using namespace xtd::forms::native;

intptr_t busy_dialog::create(intptr_t hwnd, const xtd::drawing::icon& icon, const std::string& text, const std::string& description, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_color, double transparency) {
  return reinterpret_cast<intptr_t>(new wxBusyInfo(wxBusyInfoFlags().Parent(hwnd ? reinterpret_cast<control_handler*>(hwnd)->control() : nullptr).Icon(icon.handle() ? reinterpret_cast<wxIconBundle*>(icon.handle())->GetIcon() : wxNullIcon).Title(text).Label(description).Background(wxColour(back_color.r(), back_color.g(), back_color.b(), back_color.a())).Foreground(wxColour(fore_color.r(), fore_color.g(), fore_color.b(), fore_color.a())).Transparency(255.0 * transparency)));
}

void busy_dialog::destroy(intptr_t dialog) {
  delete reinterpret_cast<wxBusyInfo*>(dialog);
}
