#include <xtd/forms/native/font_dialog.h>
#include <xtd/forms/font_dialog_flags.h>
#include <wx/fontdlg.h>

using namespace xtd;
using namespace xtd::forms::native;

bool font_dialog::run_dialog(intptr_t hwnd, drawing::font& font, drawing::color& color, size_t options, size_t min_size, size_t max_size, bool show_color) {
  wxFontData font_data;
  font_data.SetColour(wxColour(color.r(), color.g(), color.b(), color.a()));
  font_data.SetInitialFont(*reinterpret_cast<wxFont*>(font.handle()));
  font_data.SetRange(min_size, max_size);
  font_data.SetShowHelp((options & CF_SHOWHELP) == CF_SHOWHELP);
  wxFontDialog dialog(reinterpret_cast<wxWindow*>(hwnd), font_data);
  if (dialog.ShowModal() != wxID_OK) return false;
  font = drawing::font(reinterpret_cast<intptr_t>(new wxFont(dialog.GetFontData().GetChosenFont())));
  wxColour colour = dialog.GetFontData().GetColour();
  color = drawing::color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
  return true;
}
