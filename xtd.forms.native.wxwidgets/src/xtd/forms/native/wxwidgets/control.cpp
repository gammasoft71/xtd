#include <map>
#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/drawing/system_fonts.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/control.hpp>
#include "hdc_wrapper.hpp"
#include "wx_button.hpp"
#include "wx_check_box.hpp"
#include "wx_combo_box.hpp"
#include "wx_checked_list_box.hpp"
#include "wx_combo_box.hpp"
#include "wx_control.hpp"
#include "wx_form.hpp"
#include "wx_group_box.hpp"
#include "wx_label.hpp"
#include "wx_list_box.hpp"
#include "wx_panel.hpp"
#include "wx_progress_bar.hpp"
#include "wx_radio_button.hpp"
#include "wx_text_box.hpp"
#include "wx_track_bar.hpp"
#include "wx_user_control.hpp"
#include <wx/dcbuffer.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcscreen.h>
#include <wx/font.h>
#include <wx/settings.h>

namespace {
#if defined (__WXGTK__)
  static bool is_window_manager_ready = false;

  bool wait_window_manager() {
    if (wxTopLevelWindows.size() == 0) return false;
    static int value = wxSystemSettings::GetMetric(wxSYS_CAPTION_Y, wxTopLevelWindows[0]);
    while (value == -1) {
      value = wxSystemSettings::GetMetric(wxSYS_BORDER_Y, wxTopLevelWindows[0]);
      wxYield();
    }
    is_window_manager_ready = true;
    return true;
  }

  wxSize GetFrameDecorationsize(wxFrame& frame) {
    wxSize size;

    if (frame.GetMenuBar() != nullptr)
      size.SetHeight(size.GetHeight() + wxSystemSettings::GetMetric(wxSYS_MENU_Y, &frame));

    return size;
  }

  wxSize GetDecorationsize(wxTopLevelWindow& topLevelWindow) {
    wxSize size;

    if (topLevelWindow.HasFlag(wxRESIZE_BORDER)) {
      size.SetHeight(size.GetHeight() + wxSystemSettings::GetMetric(wxSYS_BORDER_Y, &topLevelWindow) * 2);
      size.SetWidth(size.GetWidth() + wxSystemSettings::GetMetric(wxSYS_BORDER_X, &topLevelWindow) * 2);
    }

    if (topLevelWindow.HasFlag(wxCAPTION))
      size.SetHeight(size.GetHeight() + wxSystemSettings::GetMetric(wxSYS_CAPTION_Y, &topLevelWindow));

    if (topLevelWindow.HasFlag(wxALWAYS_SHOW_SB)) {
      size.SetHeight(size.GetHeight() + wxSystemSettings::GetMetric(wxSYS_HSCROLL_Y, &topLevelWindow));
      size.SetWidth(size.GetWidth() + wxSystemSettings::GetMetric(wxSYS_VSCROLL_X, &topLevelWindow));
    }

    if (dynamic_cast<wxFrame*>(&topLevelWindow) != nullptr)
      size += GetFrameDecorationsize(static_cast<wxFrame&>(topLevelWindow));

    return size;
  }

  wxSize GetClientSize(wxTopLevelWindow& topLevelWindow) {
    return topLevelWindow.GetSize() - GetDecorationsize(topLevelWindow);
  }

  void SetClientSize(wxTopLevelWindow& topLevelWindow, const wxSize& size) {
    topLevelWindow.SetSize(size + GetDecorationsize(topLevelWindow));
  }
#else
  static bool is_window_manager_ready = true;

  bool wait_window_manager() {
    return true;
  }

  wxSize GetClientSize(wxTopLevelWindow& topLevelWindow) {
    return topLevelWindow.GetClientSize();
  }

  void SetClientSize(wxTopLevelWindow& topLevelWindow, const wxSize& size) {
    topLevelWindow.SetClientSize(size);
  }
#endif
}

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

extern int32_t __mainloop_runnning__;

color control::back_color(intptr_t control) {
  if (control == 0) return color::empty;
  wxColour colour = reinterpret_cast<control_handler*>(control)->control()->GetBackgroundColour();
#if defined (__WXOSX__)
  return color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#endif
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void control::back_color(intptr_t control, const color& color) {
  if (control == 0) return;
#if defined (__WXOSX__)
  if (color.handle())
    reinterpret_cast<control_handler*>(control)->control()->SetBackgroundColour(wxColour(reinterpret_cast<WX_NSColor>(color.handle())));
  else
    reinterpret_cast<control_handler*>(control)->control()->SetBackgroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#else
  reinterpret_cast<control_handler*>(control)->control()->SetBackgroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#endif
}

void control::begin_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

intptr_t control::create(const forms::create_params& create_params) {
  application::initialize(); // Must be first
  if (create_params.class_name() == "button") return reinterpret_cast<intptr_t>(new wx_button(create_params));
  if (create_params.class_name() == "checkbox") return reinterpret_cast<intptr_t>(new wx_check_box(create_params));
  if (create_params.class_name() == "checkedlistbox") return reinterpret_cast<intptr_t>(new wx_checked_list_box(create_params));
  if (create_params.class_name() == "combobox") return reinterpret_cast<intptr_t>(new wx_combo_box(create_params));
  if (create_params.class_name() == "form") return reinterpret_cast<intptr_t>(new wx_form(create_params));
  if (create_params.class_name() == "groupbox") return reinterpret_cast<intptr_t>(new wx_group_box(create_params));
  if (create_params.class_name() == "label") return reinterpret_cast<intptr_t>(new wx_label(create_params));
  if (create_params.class_name() == "listbox") return reinterpret_cast<intptr_t>(new wx_list_box(create_params));
  if (create_params.class_name() == "panel") return reinterpret_cast<intptr_t>(new wx_panel(create_params));
  if (create_params.class_name() == "progressbar") return reinterpret_cast<intptr_t>(new wx_progress_bar(create_params));
  if (create_params.class_name() == "radiobutton") return reinterpret_cast<intptr_t>(new wx_radio_button(create_params));
  if (create_params.class_name() == "textbox") return reinterpret_cast<intptr_t>(new wx_text_box(create_params));
  if (create_params.class_name() == "trackbar") return reinterpret_cast<intptr_t>(new wx_track_bar(create_params));
  if (create_params.class_name() == "usercontrol") return reinterpret_cast<intptr_t>(new wx_user_control(create_params));
  return reinterpret_cast<intptr_t>(new wx_control(create_params));
}

intptr_t control::create_paint_graphics(intptr_t control) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper();
  if (control == 0) hdc_wrapper->create<wxScreenDC>();
  else  hdc_wrapper->create<wxPaintDC>(reinterpret_cast<control_handler*>(control)->control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::create_double_buffered_paint_graphics(intptr_t control) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper();
  wxColour back_color = reinterpret_cast<control_handler*>(control)->control()->GetBackgroundColour();
  reinterpret_cast<control_handler*>(control)->control()->SetBackgroundStyle(wxBackgroundStyle::wxBG_STYLE_PAINT);
  reinterpret_cast<control_handler*>(control)->control()->SetBackgroundColour(back_color);
  if (control == 0) hdc_wrapper->create<wxScreenDC>();
  else  hdc_wrapper->create<wxAutoBufferedPaintDC>(reinterpret_cast<control_handler*>(control)->control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::create_graphics(intptr_t control) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper();
  if (control == 0) hdc_wrapper->create<wxScreenDC>();
  else  hdc_wrapper->create<wxClientDC>(reinterpret_cast<control_handler*>(control)->control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::def_wnd_proc(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t presult, intptr_t handle) {
  if (!control || handle == 0) return 0;
  return reinterpret_cast<control_handler*>(control)->call_def_wnd_proc(hwnd, msg, wparam, lparam, presult, handle);
}

font control::default_font() {
  return system_fonts::default_font();
}

void control::destroy(intptr_t control) {
  if (control == 0) return;
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return;
  if (wxTheApp) reinterpret_cast<control_handler*>(control)->destroy();
  delete reinterpret_cast<class control_handler*>(control);
}

void control::init() {
  application::initialize(); // Must be first
}

drawing::rectangle control::client_rectangle(intptr_t control) {
  if (control == 0) return {};
  wxRect rect = reinterpret_cast<control_handler*>(control)->control()->GetClientRect();
  return {{rect.GetX(), rect.GetY()}, client_size(control)};
}

drawing::size control::client_size(intptr_t control) {
  if (control == 0) return {};

  wxSize size;
  if (is_window_manager_ready && dynamic_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control()))
    size = GetClientSize(*static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control()));
  else
    size = reinterpret_cast<control_handler*>(control)->control()->GetClientSize();
  return {size.GetWidth(), size.GetHeight()};
}

void control::client_size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;

  if (is_window_manager_ready && dynamic_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control()))
    SetClientSize(*static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control()), {size.width(), size.height()});
  else
    reinterpret_cast<control_handler*>(control)->control()->SetClientSize(size.width(), size.height());
}

void control::cursor(intptr_t control, intptr_t cursor) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetCursor(*reinterpret_cast<wxCursor*>(cursor));
}

bool control::enabled(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsEnabled();
}

void control::enabled(intptr_t control, bool enabled) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Enable(enabled);
}

void control::end_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

color control::fore_color(intptr_t control) {
  if (control == 0) return color::empty;
  wxColour colour = reinterpret_cast<control_handler*>(control)->control()->GetForegroundColour();
#if defined (__WXOSX__)
  return color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#endif
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void control::fore_color(intptr_t control, const color& color) {
  if (control == 0) return;
#if defined (__WXOSX__)
  if (color.handle())
    reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(reinterpret_cast<WX_NSColor>(color.handle())));
  else
    reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#else
  reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#endif
}

drawing::font control::font(intptr_t control) {
  return drawing::font::from_hfont(reinterpret_cast<intptr_t>(new wxFont(reinterpret_cast<control_handler*>(control)->control()->GetFont())));
}

void control::font(intptr_t control, const drawing::font& font) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetFont(*reinterpret_cast<wxFont*>(font.handle()));
}

point control::location(intptr_t control) {
  if (control == 0) return {};
  wxPoint location = reinterpret_cast<control_handler*>(control)->control()->GetPosition();
  return {location.x, location.y};
}

void control::location(intptr_t control, const point& location) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetPosition({location.x(), location.y()});
}

drawing::size control::size(intptr_t control) {
  if (control == 0) return {};
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetSize();
  return {size.GetWidth(), size.GetHeight()};
}

void control::size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->SetSize(size.width(), size.height());
}

string control::text(intptr_t control) {
  if (control == 0) return {};
  return reinterpret_cast<control_handler*>(control)->control()->GetLabel().ToStdString();
}

void control::text(intptr_t control, const string& text) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetLabel(text);
}

bool control::visible(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsShown();
}

void control::visible(intptr_t control, bool visible) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Show(visible);

  if (!is_window_manager_ready && visible == true && dynamic_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control()))
    wait_window_manager();
}

void control::refresh(intptr_t control) {
  if (control == 0) return;

  if (!reinterpret_cast<control_handler*>(control)->control()->IsBeingDeleted())
    reinterpret_cast<control_handler*>(control)->control()->Refresh();
}


void control::register_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->wnd_proc += wnd_proc;
}

void control::unregister_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->wnd_proc -= wnd_proc;
}

intptr_t control::send_message(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {
  if (hwnd == 0) return -1;
  return reinterpret_cast<control_handler*>(control)->send_message(hwnd, msg, wparam, lparam, 0);
}
