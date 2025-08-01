#include <wx/progdlg.h>
#include <wx/timer.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.hpp"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.hpp"
#include <xtd/forms/native/progress_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_colors>
#include <xtd/forms/progress_dialog_flags>
#include <xtd/as>
#include <xtd/convert_string>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  #if defined(__WXMSW__)
  auto handle_hook = HHOOK {};
  LRESULT CALLBACK callbackProc(INT ncode, WPARAM wparam, LPARAM lparam) {
    if (ncode == HCBT_ACTIVATE) {
      allow_dark_mode_for_window(static_cast<intptr>(wparam));
      refresh_title_bar_theme_color(static_cast<intptr>(wparam));
      UnhookWindowsHookEx(handle_hook);
    } else
      CallNextHookEx(handle_hook, ncode, wparam, lparam);
    return 0;
  }
  #endif
  
  class wx_progress_dialog : public wxProgressDialog {
  public:
    wx_progress_dialog(const string& title, const string& message, int32 maximum = 100, wxWindow* parent = nullptr, int32 style = wxPD_APP_MODAL | wxPD_AUTO_HIDE) : wxProgressDialog(convert_string::to_wstring(title).c_str(), convert_string::to_wstring(message).c_str(), maximum, parent, style) {
      if (environment::os_version().is_macos()) SetBackgroundColour(wxColour(system_colors::control().r(), system_colors::control().g(), system_colors::control().b(), system_colors::control().a()));
      timer_marquee.Bind(wxEVT_TIMER, [&](wxTimerEvent & event) {
        if (event.GetTimer().GetId() == timer_marquee.GetId())
          Pulse();
      });
    }
    
    void minimum(int32 minimum) {
      minimum_ = minimum;
      if (maximum_ - minimum_ > 0) SetRange(maximum_ - minimum_);
    }
    
    void maximum(int32 maximum) {
      maximum_ = maximum;
      if (maximum_ - minimum_ > 0) SetRange(maximum_ - minimum_);
    }
    
    void value(int32 value) {
      value_ = value;
      if (value_ - minimum_ > 0) Update(value_ - minimum_);
    }
    
    void marquee(bool marquee, size_t animation_speed) {
      animation_speed_ = animation_speed;
      if (marquee) timer_marquee.Start(static_cast<int32>(animation_speed));
      else timer_marquee.Stop();
    }
    
    void message(const string& message) {
      if (!timer_marquee.IsRunning()) Update(value_, convert_string::to_wstring(message).c_str());
      else {
        timer_marquee.Stop();
        Pulse(convert_string::to_wstring(message).c_str());
        timer_marquee.Start(as<int32>(animation_speed_));
      }
    }
    
  private:
    size_t animation_speed_ = 0;
    int32 maximum_ = 0;
    int32 minimum_ = 0;
    wxTimer timer_marquee;
    int32 value_ = 0;
  };
  
  int32 options_to_wx_style(size_t options) {
    int32 wx_style = wxPD_AUTO_HIDE;
    
    if ((options & PROGDLG_MODAL) == PROGDLG_MODAL) wx_style |= wxPD_APP_MODAL;
    if ((options & PROGDLG_AUTOTIME) == PROGDLG_AUTOTIME) wx_style |= wxPD_REMAINING_TIME;
    //if ((options & PROGDLG_NOTIME) == PROGDLG_NOTIME) wx_style |= wxPD__NOTIME; : doesn't exists on wxWidgets
    //if ((options & PROGDLG_NOMINIMIZE) == PROGDLG_NOMINIMIZE) wx_style |= wxPD_NOMINIMIZE; :doesn't exists on wxWidgets
    //if ((options & PROGDLG_NOPROGRESSBAR) == PROGDLG_NOPROGRESSBAR) wx_style |= wxPD_NOPROGRESSBAR; : doesn't exists on wxWidgets
    //if ((options & PROGDLG_MARQUEEPROGRESS) == PROGDLG_MARQUEEPROGRESS) wx_style |= wxPD_MARQUEEPROGRESS; : doesn't exists on wxWidgets
    if ((options & PROGDLG_NOCANCEL) != PROGDLG_NOCANCEL) wx_style |= wxPD_CAN_ABORT;
    if ((options & PROGDLG_NOSKIP) != PROGDLG_NOSKIP) wx_style |= wxPD_CAN_SKIP;
    if ((options & PROGDLG_SMOOTH) == PROGDLG_SMOOTH) wx_style |= wxPD_SMOOTH;
    //if ((options & PROGDLG_SMOOTH_REVERSE) == PROGDLG_SMOOTH_REVERSE) wx_style |= wxPD_SMOOTH_REVERSE; : doesn't exists on wxWidgets
    if ((options & PROGDLG_ELAPSEDTIME) == PROGDLG_ELAPSEDTIME) wx_style |= wxPD_ELAPSED_TIME;
    if ((options & PROGDLG_ESTIMATEDTIME) == PROGDLG_ESTIMATEDTIME) wx_style |= wxPD_ESTIMATED_TIME;
    
    return wx_style;
  }
}

bool progress_dialog::cancelled(intptr dialog) {
  if (dialog == 0) return false;
  return reinterpret_cast<wx_progress_dialog*>(dialog)->WasCancelled();
}

intptr progress_dialog::create(intptr hwnd, const string& text, const string& message, const array<string>& informations, size_t animation_speed, int32 minimum, int32 maximum, int32 value, size_t options) {
  #if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
  #endif
  auto dialog = new wx_progress_dialog(text, message.empty() ? " " : message, 0, hwnd ? reinterpret_cast<control_handler*>(hwnd)->control() : nullptr, options_to_wx_style(options));
  dialog->Hide();
  dialog->marquee((options & PROGDLG_MARQUEEPROGRESS) == PROGDLG_MARQUEEPROGRESS, animation_speed);
  dialog->minimum(minimum);
  dialog->maximum(maximum);
  dialog->value(value);
  return reinterpret_cast<intptr>(dialog);
}

void progress_dialog::destroy(intptr dialog) {
  delete reinterpret_cast<wx_progress_dialog*>(dialog);
}

void progress_dialog::informations(intptr dialog, const array<string>& informations) {
  // doesn't exists on wxWidgets
}

void progress_dialog::marquee(intptr dialog, bool marquee, size_t animation_speed) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->marquee(marquee, animation_speed);
}

void progress_dialog::maximum(intptr dialog, int32 maximum) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->maximum(maximum);
}

void progress_dialog::message(intptr dialog, const string& message) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->message(message);
}

void progress_dialog::minimum(intptr dialog, int32 minimum) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->minimum(minimum);
}

void progress_dialog::resume(intptr dialog) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->Resume();
}

void progress_dialog::show(intptr dialog) {
  reinterpret_cast<wx_progress_dialog*>(dialog)->Show();
}

void progress_dialog::show_sheet(intptr dialog) {
  reinterpret_cast<wx_progress_dialog*>(dialog)->ShowWindowModal();
}

bool progress_dialog::skipped(intptr dialog) {
  if (dialog == 0) return false;
  return reinterpret_cast<wx_progress_dialog*>(dialog)->WasSkipped();
}

void progress_dialog::value(intptr dialog, int32 value) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->value(value);
}
