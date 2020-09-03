#include <codecvt>
#include <map>
#include <stdexcept>
#include <xtd/environment.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/system_fonts.h>
#include <xtd/drawing/native/hdc_wrapper.h>
#include <xtd/drawing/native/system_colors.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/control.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_check_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_choice.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_combo_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_command_link_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_checked_list_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_color_picker.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_combo_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_control.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_date_time_picker.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_domain_up_down.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_font_picker.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_form.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_group_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_label.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_list_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_numeric_up_down.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_panel.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_picture_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_progress_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_radio_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_control.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_page.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_text_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_track_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_up_down_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_user_control.h"
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
      for (auto window : wxTopLevelWindows)
        if ((value = wxSystemSettings::GetMetric(wxSYS_BORDER_Y, window)) != -1) break;
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

  intptr_t set_control_extra_options(intptr_t control) {
    allow_dark_mode_for_window(reinterpret_cast<intptr_t>(reinterpret_cast<xtd::forms::native::control_handler*>(control)->control()->GetHandle()));
    return control;
  }

  intptr_t set_form_extra_options(intptr_t control) {
    allow_dark_mode_for_window(reinterpret_cast<intptr_t>(reinterpret_cast<xtd::forms::native::control_handler*>(control)->control()->GetHandle()));
    refresh_title_bar_theme_color(reinterpret_cast<intptr_t>(reinterpret_cast<xtd::forms::native::control_handler*>(control)->control()->GetHandle()));
    return control;
  }
}

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

extern int32_t __mainloop_runnning__;

void control::back_color(intptr_t control, const color& color) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->graphic_control()->SetBackgroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
}

intptr_t control::create(const forms::create_params& create_params) {
  application::initialize(); // Must be first
  if (create_params.class_name() == "button") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_button(create_params)));
  if (create_params.class_name() == "checkbox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_check_box(create_params)));
  if (create_params.class_name() == "checkedlistbox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_checked_list_box(create_params)));
  if (create_params.class_name() == "choice") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_choice(create_params)));
  if (create_params.class_name() == "colorpicker") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_color_picker(create_params)));
  if (create_params.class_name() == "combobox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_combo_box(create_params)));
  if (create_params.class_name() == "commandlinkbutton") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_command_link_button(create_params)));
  if (create_params.class_name() == "datetimepicker") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_date_time_picker(create_params)));
  if (create_params.class_name() == "domainupdown") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_domain_up_down(create_params)));
  if (create_params.class_name() == "fontpicker") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_font_picker(create_params)));
  if (create_params.class_name() == "form") return set_form_extra_options(reinterpret_cast<intptr_t>(new wx_form(create_params)));
  if (create_params.class_name() == "groupbox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_group_box(create_params)));
  if (create_params.class_name() == "label") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_label(create_params)));
  if (create_params.class_name() == "listbox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_list_box(create_params)));
  if (create_params.class_name() == "numericupdown") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_numeric_up_down(create_params)));
  if (create_params.class_name() == "panel") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_panel(create_params)));
  if (create_params.class_name() == "picturebox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_picture_box(create_params)));
  if (create_params.class_name() == "progressbar") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_progress_bar(create_params)));
  if (create_params.class_name() == "radiobutton") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_radio_button(create_params)));
  if (create_params.class_name() == "tabcontrol") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_tab_control(create_params)));
  if (create_params.class_name() == "tabpage") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_tab_page(create_params)));
  if (create_params.class_name() == "textbox") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_text_box(create_params)));
  if (create_params.class_name() == "trackbar") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_track_bar(create_params)));
  if (create_params.class_name() == "updownbutton") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_up_down_button(create_params)));
  if (create_params.class_name() == "usercontrol") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_user_control(create_params)));
  return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_control(create_params)));
}

intptr_t control::create_paint_graphics(intptr_t control) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  if (control == 0) hdc_wrapper->create<wxScreenDC>();
  else if (reinterpret_cast<control_handler*>(control)->graphic_control() != reinterpret_cast<control_handler*>(control)->control()) hdc_wrapper->create<wxClientDC>(reinterpret_cast<control_handler*>(control)->graphic_control());
  else hdc_wrapper->create<wxPaintDC>(reinterpret_cast<control_handler*>(control)->graphic_control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::create_double_buffered_paint_graphics(intptr_t control) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  //wxColour back_color = reinterpret_cast<control_handler*>(control)->graphic_control()->GetBackgroundColour();
  reinterpret_cast<control_handler*>(control)->graphic_control()->SetBackgroundStyle(wxBackgroundStyle::wxBG_STYLE_PAINT);
  //reinterpret_cast<control_handler*>(control)->graphic_control()->SetBackgroundColour(back_color);
  if (control == 0) hdc_wrapper->create<wxScreenDC>();
  else  hdc_wrapper->create<wxAutoBufferedPaintDC>(reinterpret_cast<control_handler*>(control)->graphic_control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::create_graphics(intptr_t control) {
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  if (control == 0) hdc_wrapper->create<wxScreenDC>();
  else  hdc_wrapper->create<wxClientDC>(reinterpret_cast<control_handler*>(control)->graphic_control());
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

intptr_t control::def_wnd_proc(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t presult, intptr_t handle) {
  if (!control || handle == 0) return 0;
  return reinterpret_cast<control_handler*>(control)->call_def_wnd_proc(hwnd, msg, wparam, lparam, presult, handle);
}

void control::destroy(intptr_t control) {
  if (control == 0 || !wxTheApp) return;
  /// @todo Fix destroy_handle on recreate with old parent and remove the following line
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return;
  if (reinterpret_cast<control_handler*>(control)->control()->GetParent() && dynamic_cast<wxNotebook*>(reinterpret_cast<control_handler*>(control)->control()->GetParent())) {
    int index = static_cast<wxNotebook*>(reinterpret_cast<control_handler*>(control)->control()->GetParent())->FindPage(reinterpret_cast<control_handler*>(control)->control());
    if (index >= 0) static_cast<wxNotebook*>(reinterpret_cast<control_handler*>(control)->control()->GetParent())->RemovePage(index);
  }
  /// end todo
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
    size = reinterpret_cast<control_handler*>(control)->GetClientSize();
  
  return {size.GetWidth(), size.GetHeight()};
}

void control::client_size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  
  if (is_window_manager_ready && dynamic_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control())) {
    int width = size.width();
#if defined(__APPLE__)
    if (width < 75) width = 75;
#endif
    SetClientSize(*static_cast<wxTopLevelWindow*>(reinterpret_cast<control_handler*>(control)->control()), {width, size.height()});
  }else
    reinterpret_cast<control_handler*>(control)->SetClientSize(size.width(), size.height());
}

void control::cursor(intptr_t control, intptr_t cursor) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->SetCursor(cursor ? *reinterpret_cast<wxCursor*>(cursor) : wxNullCursor);
}

bool control::enabled(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->IsEnabled();
}

void control::enabled(intptr_t control, bool enabled) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Enable(enabled);
}

void control ::focus(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetFocus();
}

void control::fore_color(intptr_t control, const color& color) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
}

void control::font(intptr_t control, const drawing::font& font) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetFont(*reinterpret_cast<wxFont*>(font.handle()));
}

void control::invoke_in_control_thread(intptr_t control, delegate<void(std::vector<std::any>)> invoker, const std::vector<std::any>& args, std::shared_ptr<std::shared_mutex> invoked) {
  if (control == 0 || !wxTheApp || !wxTheApp->IsMainLoopRunning() || !reinterpret_cast<control_handler*>(control)->control()->GetEvtHandlerEnabled()) {
    invoked->unlock();
  } else {
    reinterpret_cast<control_handler*>(control)->control()->CallAfter([=] {
      invoker(args);
      invoked->unlock();
    });
  }
}

point control::location(intptr_t control) {
  if (control == 0) return {};
  wxPoint location = reinterpret_cast<control_handler*>(control)->control()->GetPosition();
  return {location.x, location.y};
}

void control::location(intptr_t control, const point& location) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->SetPosition({location.x(), location.y()});
}

drawing::point control::point_to_screen(intptr_t control, const drawing::point& p) {
  if (control == 0) return p;
  wxPoint result = reinterpret_cast<control_handler*>(control)->control()->ClientToScreen(wxPoint(p.x(), p.y()));
  return {result.x, result.y};
}

drawing::point control::point_to_client(intptr_t control, const drawing::point& p) {
  if (control == 0) return p;
  wxPoint result = reinterpret_cast<control_handler*>(control)->control()->ScreenToClient(wxPoint(p.x(), p.y()));
  return {result.x, result.y};
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

std::string control::text(intptr_t control) {
  if (control == 0) return {};
  return reinterpret_cast<control_handler*>(control)->control()->GetLabel().utf8_str().data();
}

void control::text(intptr_t control, const std::string& text) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->SetLabel({text.c_str(), wxMBConvUTF8()});
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

void control::invalidate(intptr_t control, const drawing::rectangle& rect, bool erase_background) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->graphic_control()->RefreshRect(wxRect(rect.left(), rect.top(), rect.width(), rect.height()), erase_background);
}

void control::refresh(intptr_t control) {
  if (control == 0) return;
  
  reinterpret_cast<control_handler*>(control)->graphic_control()->Refresh();
}

void control::update(intptr_t control) {
  if (control == 0) return;
  
  reinterpret_cast<control_handler*>(control)->graphic_control()->Update();
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
