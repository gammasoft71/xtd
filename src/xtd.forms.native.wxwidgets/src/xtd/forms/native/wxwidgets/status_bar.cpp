#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_status_bar.h"
#include <xtd/forms/native/status_bar>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/diagnostics/stopwatch>
#include <xtd/argument_exception>
#include <xtd/cdebug>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  int32 to_wx_style(int32 style) {
    switch (style) {
      case 3: return wxSB_SUNKEN;
      case 2: return wxSB_RAISED;
      case 1:
      default: return wxSB_NORMAL;
    }
  }
}

intptr status_bar::add_status_bar_panel(intptr status_bar, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, int32 alignment, int32 auto_size, int32 border_style, int32 min_width, int32 width) {
  if (!status_bar || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(status_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(status_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.push_back(to_wx_style(border_style));
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts.push_back(convert_string::to_wstring(text));
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.push_back(auto_size == 3 ? -1 : width);
  
  int32 count = static_cast<int32>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetFieldsCount(count);
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusStyles(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.data());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusText(reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts[static_cast<int32>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size())], count - 1);
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusWidths(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.data());
  return static_cast<intptr>(count - 1);
}

intptr status_bar::add_status_bar_control(intptr status_bar, intptr control, const xtd::ustring& text) {
  if (!status_bar || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(status_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(status_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  if (control && !dynamic_cast<wxControl*>(reinterpret_cast<control_handler*>(control)->control())) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(status_bar)->control() == 0, "Must be a control", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.push_back(wxSB_NORMAL);
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts.push_back(wxEmptyString);
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.push_back(0);
  
  int32 count = static_cast<int32>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetFieldsCount(count);
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusStyles(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.data());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusText(reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts[static_cast<int32>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size())], count - 1);
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusWidths(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.data());
  return static_cast<intptr>(count - 1);
}

bool status_bar::set_system_status_bar(intptr control, intptr status_bar) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (status_bar != 0 && !dynamic_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())) throw argument_exception("dialog can't have tool bar"_t, csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }
  
  if (status_bar == 0) {
    static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetStatusBar(nullptr);
    return true;
  }
  
  if (static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->GetStatusBar() == nullptr)
    static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetStatusBar(static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control()));
  return true;
}

bool status_bar::sizing_grip() {
  return !environment::os_version().is_macos();
}

xtd::ustring status_bar::sizing_grip_cursor_name() {
  if (environment::os_version().is_linux()) return "pan_se";
  return "size_nwse";
}

void status_bar::update_status_bar_item(intptr status_bar, intptr handle, int32 border_style, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool visible, int32 width, bool stretchable) {
  if (!status_bar || !handle || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(status_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(status_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  if (static_cast<size_t>(handle) > reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size() - 1) throw argument_exception {csf_};
  
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.push_back(to_wx_style(border_style));
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts.push_back(convert_string::to_wstring(text));
  reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.push_back(stretchable ? -1 : width);
  
  int32 count = static_cast<int32>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetFieldsCount(count);
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusStyles(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.data());
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusText(reinterpret_cast<wx_status_bar*>(status_bar)->panel_texts[static_cast<int32>(reinterpret_cast<wx_status_bar*>(status_bar)->panel_styles.size())], static_cast<int32>(handle));
  static_cast<wxStatusBar*>(reinterpret_cast<control_handler*>(status_bar)->control())->SetStatusWidths(count, reinterpret_cast<wx_status_bar*>(status_bar)->panel_widths.data());
}
