#include <xtd/forms/progress_dialog_flags.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/progress_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/progdlg.h>
#include <wx/timer.h>

using namespace xtd;
using namespace xtd::forms::native;

namespace {
#if defined(__WXMSW__)
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
#endif

  class wx_progress_dialog : public wxProgressDialog {
  public:
    wx_progress_dialog(const std::string& title, const std::string& message, int32_t maximum = 100, wxWindow* parent = nullptr, int32_t style = wxPD_APP_MODAL | wxPD_AUTO_HIDE) : wxProgressDialog(title, message, maximum, parent, style) {
      timer_marquee.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
        if (event.GetTimer().GetId() == timer_marquee.GetId())
          Pulse();
      });
    }
    
    void minimum(int32_t minimum) {
      minumum_ = minimum;
      if (maximum_ - minumum_> 0) SetRange(maximum_ - minumum_);
    }

    void maximum(int32_t maximum) {
      maximum_ = maximum;
      if (maximum_ - minumum_ > 0) SetRange(maximum_ - minumum_);
    }

    void value(int32_t value) {
      value_ = value;
      if (value_ - minumum_ > 0) Update(value_ - minumum_);
    }

    void marquee(bool marquee, size_t animation_speed) {
      animation_speed_ = animation_speed;
      if (marquee) timer_marquee.Start(static_cast<int32_t>(animation_speed));
      else timer_marquee.Stop();
    }
    
    void message(const std::string& message) {
      if (!timer_marquee.IsRunning()) Update(value_, message);
      else {
        timer_marquee.Stop();
        Pulse(message);
        timer_marquee.Start(animation_speed_);
      }
    }
    
  private:
    size_t animation_speed_ = 0;
    int32_t maximum_ = 0;
    int32_t minumum_ = 0;
    wxTimer timer_marquee;
    int32_t value_ = 0;
  };

  int32_t options_to_wx_style(size_t options) {
    int32_t wx_style = wxPD_AUTO_HIDE;

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

bool progress_dialog::cancelled(intptr_t dialog) {
  if (dialog == 0) return false;
  return reinterpret_cast<wx_progress_dialog*>(dialog)->WasCancelled();
}

intptr_t progress_dialog::create(intptr_t hwnd, const std::string& text, const std::string& message, const std::vector<std::string>& informations, size_t animation_speed, int32_t minimum, int32_t maximum, int32_t value, size_t options) {
#if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
#endif
  auto dialog = new wx_progress_dialog(text, message.empty() ? " " : message, 0, hwnd ? reinterpret_cast<control_handler*>(hwnd)->control() : nullptr, options_to_wx_style(options));
  dialog->Hide();
  dialog->marquee((options & PROGDLG_MARQUEEPROGRESS) == PROGDLG_MARQUEEPROGRESS, animation_speed);
  dialog->minimum(minimum);
  dialog->maximum(maximum);
  dialog->value(value);
  return reinterpret_cast<intptr_t>(dialog);
}

void progress_dialog::destroy(intptr_t dialog) {
  delete reinterpret_cast<wx_progress_dialog*>(dialog);
}

void progress_dialog::informations(intptr_t dialog, const std::vector<std::string>& informations) {
  // doesn't exists on wxWidgets
}

void progress_dialog::marquee(intptr_t dialog, bool marquee, size_t animation_speed) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->marquee(marquee, animation_speed);
}

void progress_dialog::maximum(intptr_t dialog, int32_t maximum) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->maximum(maximum);
}

void progress_dialog::message(intptr_t dialog, const std::string& message) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->message(message);
}

void progress_dialog::minimum(intptr_t dialog, int32_t minimum) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->minimum(minimum);
}

void progress_dialog::resume(intptr_t dialog) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->Resume();
}

void progress_dialog::show(intptr_t dialog) {
  reinterpret_cast<wx_progress_dialog*>(dialog)->Show();
}

void progress_dialog::show_sheet(intptr_t dialog) {
  reinterpret_cast<wx_progress_dialog*>(dialog)->ShowWindowModal();
}

bool progress_dialog::skipped(intptr_t dialog) {
  if (dialog == 0) return false;
  return reinterpret_cast<wx_progress_dialog*>(dialog)->WasSkipped();
}

void progress_dialog::value(intptr_t dialog, int32_t value) {
  if (dialog == 0) return;
  reinterpret_cast<wx_progress_dialog*>(dialog)->value(value);
}
