#include <xtd/drawing/native/system_colors.h>
#include <wx/settings.h>

#include <cstdint>
#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/textctrl.h>

bool __xtd_enable_dark_mode__ = false;

using namespace xtd::drawing::native;

namespace {
  uint32_t to_argb(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) {
    return (alpha << 24) + (red << 16) + (green << 8) + blue;
  }

  uint32_t to_argb(const wxColour color) {
    return ::to_argb(color.Alpha(), color.Red(), color.Green(), color.Blue());
  }
}

uint32_t system_colors::to_argb(intptr_t color){
#if defined(__WXOSX__)
  return ::to_argb(wxColour(reinterpret_cast<WX_NSColor>(color)));
#else
  return static_cast<uint32_t>(color);
#endif
}

intptr_t system_colors::active_border() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 154, 154, 154);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER));
#endif
}

intptr_t system_colors::active_caption() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 154, 154, 154);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION));
#endif
}

intptr_t system_colors::active_caption_text() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_CAPTIONTEXT).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 255, 255, 255);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_CAPTIONTEXT));
#endif
}

intptr_t system_colors::app_workspace() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 38, 38, 38);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE));
#endif
}

intptr_t system_colors::button_face() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 38, 38, 38);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
#endif
}

intptr_t system_colors::button_highlight() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 74, 74, 74);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
#endif
}

intptr_t system_colors::button_shadow() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 35, 35, 35);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
#endif
}

intptr_t system_colors::control() {
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
#  if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).OSXGetNSColor());
#  else
#    if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 38, 38, 38);
#    endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
#  endif
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 38, 38, 38);
#  endif
  if (!wxTheApp) throw std::invalid_argument("Application::initialize() must be call before");
  wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
  wxButton* button = new wxButton(frame, wxID_ANY, "");
  wxColour colour = button->GetBackgroundColour();
  intptr_t default_color = ::to_argb(colour);
  delete button;
  delete frame;
  return default_color;
#endif
}

intptr_t system_colors::control_dark() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 35, 35, 35);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
#endif
}

intptr_t system_colors::control_dark_dark() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 35, 35, 35);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW));
#endif
}

intptr_t system_colors::control_light() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 74, 74, 74);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT));
#endif
}

intptr_t system_colors::control_light_light() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 74, 74, 74);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
#endif
}

intptr_t system_colors::control_text() {
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
#  if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT).OSXGetNSColor());
#  else
#    if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 255, 255, 255);
#    endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT));
#  endif
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 255, 255, 255);
#  endif
  if (!wxTheApp) throw std::invalid_argument("Application::initialize() must be call before");
  wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
  wxButton* button = new wxButton(frame, wxID_ANY, "");
  wxColour colour = button->GetForegroundColour();
  intptr_t default_color = ::to_argb(colour);
  delete button;
  delete frame;
  return default_color;
#endif
}

intptr_t system_colors::desktop() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP));
#endif
}

intptr_t system_colors::gradient_active_caption() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 154, 154, 154);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION));
#endif
}

intptr_t system_colors::gradient_inactive_caption() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 154, 154, 184);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION));
#endif
}

intptr_t system_colors::gray_text() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 107, 107, 107);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT));
#endif
}

intptr_t system_colors::highlight() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT));
#endif
}

intptr_t system_colors::highlight_text() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT));
#endif
}

intptr_t system_colors::hot_track() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT));
#endif
}

intptr_t system_colors::inactive_border() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 154, 154, 184);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER));
#endif
}

intptr_t system_colors::inactive_caption() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 154, 154, 184);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION));
#endif
}

intptr_t system_colors::inactive_caption_text() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 107, 107, 107);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
#endif
}

intptr_t system_colors::info() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK));
#endif
}

intptr_t system_colors::info_text() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT));
#endif
}

intptr_t system_colors::menu() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 0, 0, 0);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU));
#endif
}

intptr_t system_colors::menu_bar() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 0, 0, 0);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR));
#endif
}

intptr_t system_colors::menu_highlight() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT));
#endif
}

intptr_t system_colors::menu_text() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 255, 255, 255);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT));
#endif
}

intptr_t system_colors::scroll_bar() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 38, 38, 38);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR));
#endif
}

intptr_t system_colors::window() {
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
#  if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW).OSXGetNSColor());
#  else
#    if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 38, 38, 38);
#    endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
#  endif
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 38, 38, 38);
#  endif
  if (!wxTheApp) throw std::invalid_argument("Application::initialize() must be call before");
  wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
  wxTextCtrl* text = new wxTextCtrl(frame, wxID_ANY, "");
  wxColour colour = text->GetBackgroundColour();
  intptr_t default_color = ::to_argb(colour);
  delete text;
  delete frame;
  return default_color;
#endif
}

intptr_t system_colors::window_frame() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME).OSXGetNSColor());
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 154, 154, 184);
#  endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME));
#endif
}

intptr_t system_colors::window_text() {
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
#  if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT).OSXGetNSColor());
#  else
#    if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 255, 255, 255);
#    endif
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT));
#  endif
#else
#  if defined(__WXMSW__)
  if (__xtd_enable_dark_mode__) return ::to_argb(255, 255, 255, 255);
#  endif
  if (!wxTheApp) throw std::invalid_argument("Application::initialize() must be call before");
  wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "");
  wxTextCtrl* text = new wxTextCtrl(frame, wxID_ANY, "");
  wxColour colour = text->GetForegroundColour();
  intptr_t default_color = ::to_argb(colour);
  delete text;
  delete frame;
  return default_color;
#endif
}
