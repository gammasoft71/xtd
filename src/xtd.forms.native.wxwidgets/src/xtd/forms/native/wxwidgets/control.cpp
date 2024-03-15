#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/hdc_wrapper>
#include <xtd/drawing/native/system_colors>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#define __XTD_FORMS_NATIVE_LIBRARY__
#if defined(__WXMSW__)
#include <winsock2.h>
#include <Windows.h>
#include <windowsx.h>
#include <Commctrl.h>
#undef max
#undef min
#endif
#include <xtd/forms/native/application>
#include <xtd/forms/native/control>
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_check_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_choice.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_combo_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_command_link_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_checked_list_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_collapsible_panel.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_color_picker.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_combo_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_control.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_date_time_picker.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_domain_up_down.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_font_picker.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_form.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_group_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_label.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_light_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_list_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_loading_indicator.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_month_calendar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_numeric_up_down.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_panel.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_picture_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_popup_panel.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_progress_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_radio_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_scroll_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_status_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_switch_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_control.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_page.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_text_box.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_toggle_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tool_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_track_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_up_down_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_user_control.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_colors>
#include <xtd/drawing/system_fonts>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <xtd/environment>
#include <wx/dcbuffer.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcscreen.h>
#include <wx/font.h>
#include <wx/frame.h>
#include <map>

wxDEFINE_EVENT(wxEVT_ENTER_SIZEMOVE, wxCommandEvent);
wxDEFINE_EVENT(wxEVT_EXIT_SIZEMOVE, wxCommandEvent);
wxDEFINE_EVENT(wxEVT_RECREATE, wxCommandEvent);

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

extern drawing_native_export_ bool __enable_system_font_size__ ;
extern std::vector<control_handler*> __control_handler_to_delete_items__;

namespace {
  void RefreshRect(wxWindow* wnd, const drawing::rectangle& rect, bool invalidate_children) {
    wnd->RefreshRect(wxRect(rect.left(), rect.top(), rect.width(), rect.height()));
    if (!invalidate_children) return;
    
    for (auto child : wnd->GetChildren())
      RefreshRect(child, xtd::drawing::rectangle::make_intersect(rect, {child->GetRect().x, child->GetRect().y, child->GetRect().width, child->GetRect().height}), invalidate_children);
  }
  
  intptr init_dark_mode_control(intptr control) {
    allow_dark_mode_for_window(reinterpret_cast<intptr>(reinterpret_cast<xtd::forms::native::control_handler*>(control)->control()->GetHandle()));
    return control;
  }
  
  intptr init_dark_mode_form(intptr control) {
    allow_dark_mode_for_window(reinterpret_cast<intptr>(reinterpret_cast<xtd::forms::native::control_handler*>(control)->control()->GetHandle()));
    refresh_title_bar_theme_color(reinterpret_cast<intptr>(reinterpret_cast<xtd::forms::native::control_handler*>(control)->control()->GetHandle()));
    return control;
  }
}

extern int32 __mainloop_runnning__;

void control::back_color(intptr control, const color& color) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  #if !defined(__WXMSW__)
  if (dynamic_cast<wx_user_panel*>(reinterpret_cast<control_handler*>(control)->control())) return;
  if (dynamic_cast<wx_user_window*>(reinterpret_cast<control_handler*>(control)->control())) return;
  #endif
  
  reinterpret_cast<control_handler*>(control)->SetBackgroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
}

void control::context_menu(intptr control, intptr context_menu, const xtd::drawing::point& pos) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->PopupMenu(context_menu ? reinterpret_cast<wxMenu*>(context_menu) : nullptr, wxPoint(pos.x(), pos.y()));
}

intptr control::user_context_menu(intptr control, intptr context_menu, const xtd::drawing::point& pos) {
  if (!control || !context_menu || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return static_cast<intptr>(-1);
  }
  return static_cast<intptr>(reinterpret_cast<control_handler*>(control)->control()->GetPopupMenuSelectionFromUser(*reinterpret_cast<wxMenu*>(context_menu), pos.x(), pos.y()));
}

intptr control::create(const forms::native::create_params& create_params) {
  application::initialize(); // Must be first
  if (create_params.class_name == "button") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_button(create_params)));
  if (create_params.class_name == "checkbox") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_check_box(create_params)));
  if (create_params.class_name == "checkedlistbox") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_checked_list_box(create_params)));
  if (create_params.class_name == "choice") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_choice(create_params)));
  if (create_params.class_name == "collapsiblepanel") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_collapsible_panel(create_params)));
  if (create_params.class_name == "colorpicker") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_color_picker(create_params)));
  if (create_params.class_name == "combobox") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_combo_box(create_params)));
  if (create_params.class_name == "commandlinkbutton") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_command_link_button(create_params)));
  if (create_params.class_name == "datetimepicker") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_date_time_picker(create_params)));
  if (create_params.class_name == "domainupdown") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_domain_up_down(create_params)));
  if (create_params.class_name == "fontpicker") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_font_picker(create_params)));
  if (create_params.class_name == "form") return init_dark_mode_form(reinterpret_cast<intptr>(new wx_form(create_params)));
  if (create_params.class_name == "groupbox") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_group_box(create_params)));
  if (create_params.class_name == "label") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_label(create_params)));
  if (create_params.class_name == "lightbutton") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_light_button(create_params)));
  if (create_params.class_name == "listbox") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_list_box(create_params)));
  if (create_params.class_name == "loadingindicator") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_loading_indicator(create_params)));
  if (create_params.class_name == "monthcalendar") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_month_calendar(create_params)));
  if (create_params.class_name == "numericupdown") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_numeric_up_down(create_params)));
  if (create_params.class_name == "panel") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_panel(create_params)));
  if (create_params.class_name == "picturebox") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_picture_box(create_params)));
  if (create_params.class_name == "popuppanel") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_popup_panel(create_params)));
  if (create_params.class_name == "progressbar") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_progress_bar(create_params)));
  if (create_params.class_name == "radiobutton") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_radio_button(create_params)));
  if (create_params.class_name == "scrollbar") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_scroll_bar(create_params)));
  if (create_params.class_name == "statusbar") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_status_bar(create_params)));
  if (create_params.class_name == "switchbutton") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_switch_button(create_params)));
  if (create_params.class_name == "tabcontrol") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_tab_control(create_params)));
  if (create_params.class_name == "tabpage") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_tab_page(create_params)));
  if (create_params.class_name == "textbox") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_text_box(create_params)));
  if (create_params.class_name == "togglebutton") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_toggle_button(create_params)));
  if (create_params.class_name == "toolbar") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_tool_bar(create_params)));
  if (create_params.class_name == "trackbar") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_track_bar(create_params)));
  if (create_params.class_name == "updownbutton") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_up_down_button(create_params)));
  if (create_params.class_name == "usercontrol") return init_dark_mode_control(reinterpret_cast<intptr>(new wx_user_control(create_params)));
  return init_dark_mode_control(reinterpret_cast<intptr>(new wx_control(create_params)));
}

intptr control::create_paint_graphics(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  #if defined(__WXGTK__)
  hdc_wrapper->create<wxClientDC>(reinterpret_cast<control_handler*>(control)->main_control());
  #else
  hdc_wrapper->create<wxPaintDC>(reinterpret_cast<control_handler*>(control)->main_control());
  #endif
  return reinterpret_cast<intptr>(hdc_wrapper);
}

intptr control::create_double_buffered_paint_graphics(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  //wxColour back_color = reinterpret_cast<control_handler*>(control)->main_control()->GetBackgroundColour();
  reinterpret_cast<control_handler*>(control)->main_control()->SetBackgroundStyle(wxBackgroundStyle::wxBG_STYLE_PAINT);
  //reinterpret_cast<control_handler*>(control)->graphic_control()->SetBackgroundColour(back_color);
  #if defined(__WXGTK__)
  hdc_wrapper->create_buffered_hdc(std::make_unique<wxClientDC>(reinterpret_cast<control_handler*>(control)->main_control()));
  #else
  hdc_wrapper->create<wxAutoBufferedPaintDC>(reinterpret_cast<control_handler*>(control)->main_control());
  #endif
  return reinterpret_cast<intptr>(hdc_wrapper);
}

intptr control::create_graphics(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  hdc_wrapper->create<wxClientDC>(reinterpret_cast<control_handler*>(control)->main_control());
  return reinterpret_cast<intptr>(hdc_wrapper);
}

intptr control::def_wnd_proc(intptr control, intptr hwnd, uint32 msg, intptr wparam, intptr lparam, intptr presult, intptr handle) {
  if (!control || !handle) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return static_cast<intptr>(-1);
  }
  
  // Workaround to remove Ctrl-Alt-middle click that shows information about wx version
  wxMouseEvent* mouse_event = dynamic_cast<wxMouseEvent*>(reinterpret_cast<wxEvent*>(handle));
  if (mouse_event && mouse_event->GetEventType() == wxEVT_MIDDLE_DOWN && mouse_event->ControlDown() && mouse_event->AltDown()) return 0;

  return reinterpret_cast<control_handler*>(control)->call_def_wnd_proc(hwnd, msg, wparam, lparam, presult, handle);
}

xtd::drawing::size control::default_size(const xtd::ustring& class_name) {
  static auto is_gnome = environment::os_version().desktop_environment() == "gnome";
  static auto is_macos = environment::os_version().desktop_environment() == "macos";
  
  if (class_name == "button") return {75, __enable_system_font_size__ ? 34 : 25};
  if (class_name == "checkbox") return {104, 25};
  if (class_name == "checkedlistbox") return {120, 90};
  if (class_name == "choice") return {130, __enable_system_font_size__ ? 34 : 25};
  if (class_name == "collapsiblepanel") return {0, 0};
  if (class_name == "colorpicker") return {104, __enable_system_font_size__ ? 34 : 25};
  if (class_name == "combobox") return {130, __enable_system_font_size__ ? 34 : is_macos ? 21 : 23};
  if (class_name == "commandlinkbutton") return {200, 60};
  if (class_name == "datetimepicker") return {140, is_gnome ? 34 :  25};
  if (class_name == "domainupdown") return {150, is_gnome ? 34 : 23};
  if (class_name == "fontpicker") return {104, __enable_system_font_size__ ? 34 : 25};
  if (class_name == "form") return {300, 300};
  if (class_name == "groupbox") return {200, 100};
  if (class_name == "label") return {100, 23};
  if (class_name == "lightbutton") return {75, __enable_system_font_size__ ? 34 : 25};
  if (class_name == "listbox") return {120, 96};
  if (class_name == "loadingindicator") return {32, 32};
  if (class_name == "monthcalendar") return {240, 162};
  if (class_name == "numericupdown") return {120, is_gnome ? 34 : 23};
  if (class_name == "panel") return {200, 100};
  if (class_name == "picturebox") return {100, 50};
  if (class_name == "popuppanel") return {100, 150};
  if (class_name == "progressbar") return {100, 23};
  if (class_name == "radiobutton") return {104, 25};
  if (class_name == "scrollbar") return {17, 17};
  if (class_name == "statusbar") return {100, 23};
  if (class_name == "switchbutton") return {50, 25};
  if (class_name == "tabcontrol") return {200, 100};
  if (class_name == "tabpage") return {200, 100};
  if (class_name == "textbox") return {100, __enable_system_font_size__ ? 34 : 23};
  if (class_name == "togglebutton") return {104, __enable_system_font_size__ ? 34 : 25};
  if (class_name == "toolbar") return {100, 23};
  if (class_name == "trackbar") return {104, 45};
  if (class_name == "updownbutton") return {is_gnome ? 71 : 18, 34};
  if (class_name == "usercontrol") return {150, 150};
  return {0, 0};
}

void control::destroy(intptr control) {
  if (!control) throw argument_exception {csf_};
  if (reinterpret_cast<control_handler*>(control)->control() == 0 || !wxTheApp) return;
  reinterpret_cast<control_handler*>(control)->control()->Unlink();
  reinterpret_cast<control_handler*>(control)->control()->DeletePendingEvents();
  reinterpret_cast<control_handler*>(control)->Destroy();
  // Do not delete control_handler here because wxwidgets defers the deletion of wxWindow in the idle event so the deletion of handler_control will also be done in the idle event.
  __control_handler_to_delete_items__.push_back(reinterpret_cast<class control_handler*>(control));
}

drawing::rectangle control::client_rectangle(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxRect rect = reinterpret_cast<control_handler*>(control)->GetClientRect();
  return {{rect.GetX(), rect.GetY()}, client_size(control)};
}

drawing::size control::client_size(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxSize size = reinterpret_cast<control_handler*>(control)->GetClientSize();
  return {size.GetWidth(), size.GetHeight()};
}

void control::client_size(intptr control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetClientSize(size.width(), size.height());
}

void control::cursor(intptr control, intptr cursor) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetCursor(cursor ? *reinterpret_cast<wxCursor*>(cursor) : wxNullCursor);
}

bool control::enabled(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }
  return reinterpret_cast<control_handler*>(control)->control()->IsEnabled();
}

void control::enabled(intptr control, bool enabled) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Enable(enabled);
}

void control ::focus(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetFocus();
}

void control::fore_color(intptr control, const color& color) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetForegroundColour(wxColour(color.r(), color.g(), color.b(), color.a()));
}

void control::font(intptr control, const drawing::font& font) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetFont(*reinterpret_cast<wxFont*>(font.handle()));
}

intptr control::native_handle(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  return reinterpret_cast<intptr>(reinterpret_cast<control_handler*>(control)->control()->GetHandle());
}

void control::invoke_in_control_thread(intptr control, delegate<void(std::vector<std::any>)> invoker, const std::vector<std::any>& args, std::shared_ptr<xtd::threading::manual_reset_event> invoked, std::shared_ptr<bool> completed) {
  if (!control || !wxTheApp || !wxTheApp->IsMainLoopRunning() || !reinterpret_cast<control_handler*>(control)->control()->GetEvtHandlerEnabled()) return;
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->CallAfter([ = ] {
    invoker(args);
    *completed = true;
    invoked->set();
  });
}

point control::location(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxPoint location = reinterpret_cast<control_handler*>(control)->GetPosition();
  return {location.x, location.y};
}

void control::location(intptr control, const point& location) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetPosition({location.x(), location.y()});
}

void control::maximum_client_size(intptr control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetMaxClientSize({size.width() != 0 ? size.width() : -1, size.height() != 0 ? size.height() : -1});
}

void control::maximum_size(intptr control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetMaxSize({size.width() != 0 ? size.width() : -1, size.height() != 0 ? size.height() : -1});
}

void control::minimum_client_size(intptr control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetMinClientSize({size.width(), size.height()});
}

void control::minimum_size(intptr control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetMinSize({size.width(), size.height()});
}

drawing::point control::point_to_screen(intptr control, const drawing::point& p) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxPoint result = reinterpret_cast<control_handler*>(control)->control()->ClientToScreen(wxPoint(p.x(), p.y()));
  return {result.x, result.y};
}

drawing::point control::point_to_client(intptr control, const drawing::point& p) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxPoint result = reinterpret_cast<control_handler*>(control)->control()->ScreenToClient(wxPoint(p.x(), p.y()));
  return {result.x, result.y};
}

drawing::size control::size(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  wxSize size = reinterpret_cast<control_handler*>(control)->GetSize();
  return {size.GetWidth(), size.GetHeight()};
}

void control::size(intptr control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetSize(size.width(), size.height());
}

ustring control::text(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return "";
  }
  return xtd::convert_string::to_string(reinterpret_cast<control_handler*>(control)->control()->GetLabel().c_str().AsWChar());
}

void control::text(intptr control, const ustring& text) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->SetLabel(convert_string::to_wstring(text));
}

intptr control::toolkit_handle(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  return reinterpret_cast<intptr>(reinterpret_cast<control_handler*>(control)->control());
}

bool control::visible(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }
  return reinterpret_cast<control_handler*>(control)->control()->IsShown();
}

void control::visible(intptr control, bool visible) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->Show(visible);
}

void control::invalidate(intptr control, const drawing::rectangle& rect, bool invalidate_children) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  RefreshRect(reinterpret_cast<control_handler*>(control)->main_control(), rect, invalidate_children);
}

void control::invalidate(intptr control, const drawing::region& region, bool invalidate_children) {
  invalidate(control, rectangle::round(region.get_bounds()), invalidate_children);
}

void control::register_wnd_proc(intptr control, const delegate<intptr(intptr, int32, intptr, intptr, intptr)>& wnd_proc) {
  if (!control) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->wnd_proc = wnd_proc;
}

void control::resume_layout(intptr control) {
  if (!control) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  if (reinterpret_cast<control_handler*>(control)->LayoutSuspendedCount() == 0) return;
  if (reinterpret_cast<control_handler*>(control)->LayoutSuspendedCount() == 1) reinterpret_cast<control_handler*>(control)->control()->Thaw();
  reinterpret_cast<control_handler*>(control)->DecrementLayoutSuspended();
}

void control::right_to_left(intptr control, int32 value) {
  if (!control) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  switch (value) {
    case 0: reinterpret_cast<control_handler*>(control)->control()->SetLayoutDirection(wxLayoutDirection::wxLayout_LeftToRight); break;
    case 1: reinterpret_cast<control_handler*>(control)->control()->SetLayoutDirection(wxLayoutDirection::wxLayout_RightToLeft); break;
    case 2: reinterpret_cast<control_handler*>(control)->control()->SetLayoutDirection(wxLayoutDirection::wxLayout_LeftToRight); break;
    default: reinterpret_cast<control_handler*>(control)->control()->SetLayoutDirection(wxLayoutDirection::wxLayout_LeftToRight); break;
  }
}

intptr control::send_message(intptr control, intptr hwnd, int32 msg, intptr wparam, intptr lparam) {
  if (!control) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return static_cast<intptr>(-1);
  }
  return reinterpret_cast<control_handler*>(control)->send_message(hwnd, msg, wparam, lparam, 0);
}

void control::suspend_layout(intptr control) {
  if (!control) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  if (reinterpret_cast<control_handler*>(control)->LayoutSuspendedCount() == 0) reinterpret_cast<control_handler*>(control)->control()->Freeze();
  reinterpret_cast<control_handler*>(control)->IncrementLayoutSuspended();
}

void control::unregister_wnd_proc(intptr control) {
  if (!control) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->wnd_proc = nullptr;
}

void control::update(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->main_control()->Update();
}
