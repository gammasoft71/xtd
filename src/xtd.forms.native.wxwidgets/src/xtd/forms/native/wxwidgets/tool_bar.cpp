#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tool_bar"
#include <xtd/forms/native/tool_bar>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/diagnostics/stopwatch>
#include <xtd/argument_exception>
#include <xtd/cdebug>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr tool_bar::add_tool_bar_button(intptr tool_bar, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool enabled, bool visible) {
  if (!tool_bar || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddTool(wxID_ANY, convert_string::to_wstring(text), *reinterpret_cast<wxImage*>(image.handle()));
  tool_bar_item->Enable(enabled && visible);
  tool_bar_item->SetShortHelp(convert_string::to_wstring(tool_tip_text));
  return static_cast<intptr>(tool_bar_item->GetId());
}

intptr tool_bar::add_tool_bar_drop_down_button(intptr tool_bar, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool enabled, bool visible, intptr drop_down_menu) {
  if (!tool_bar || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddTool(wxID_ANY, convert_string::to_wstring(text), *reinterpret_cast<wxImage*>(image.handle()), wxEmptyString, wxITEM_DROPDOWN);
  tool_bar_item->Enable(enabled && visible);
  tool_bar_item->SetDropdownMenu(reinterpret_cast<wxMenu*>(drop_down_menu));
  tool_bar_item->SetShortHelp(convert_string::to_wstring(tool_tip_text));
  return static_cast<intptr>(tool_bar_item->GetId());
}

intptr tool_bar::add_tool_bar_toggle_button(intptr tool_bar, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible) {
  if (!tool_bar || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddTool(wxID_ANY, convert_string::to_wstring(text), *reinterpret_cast<wxImage*>(image.handle()), wxEmptyString, wxITEM_CHECK);
  tool_bar_item->Enable(enabled && visible);
  tool_bar_item->SetShortHelp(convert_string::to_wstring(tool_tip_text));
  tool_bar_item->Toggle(pushed);
  return static_cast<intptr>(tool_bar_item->GetId());
}

intptr tool_bar::add_tool_bar_separator(intptr tool_bar) {
  if (!tool_bar || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddSeparator();
  return static_cast<intptr>(tool_bar_item->GetId());
}

intptr tool_bar::add_tool_bar_stretchable_separator(intptr tool_bar) {
  if (!tool_bar || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddStretchableSpace();
  return static_cast<intptr>(tool_bar_item->GetId());
}

intptr tool_bar::add_tool_bar_control(intptr tool_bar, intptr control, const xtd::ustring& text, const xtd::ustring& tool_tip_text) {
  if (!tool_bar || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  if (control && !dynamic_cast<wxControl*>(reinterpret_cast<control_handler*>(control)->control())) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Must be a control", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddControl(control ? static_cast<wxControl*>(reinterpret_cast<control_handler*>(control)->control()) : new wxControl(reinterpret_cast<control_handler*>(tool_bar)->control(), wxID_ANY), convert_string::to_wstring(text));
  tool_bar_item->SetShortHelp(convert_string::to_wstring(tool_tip_text));
  return static_cast<intptr>(tool_bar_item->GetId());
}

bool tool_bar::set_system_tool_bar(intptr control, intptr tool_bar) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (tool_bar != 0 && !dynamic_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())) throw argument_exception("dialog can't have tool bar"_t, csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }
  
  if (tool_bar == 0) {
    static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetToolBar(nullptr);
    return true;
  }
  
  if (static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->GetToolBar() == nullptr) {
    static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetToolBar(static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control()));
    dynamic_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->Realize();
  }
  return true;
}

void tool_bar::update_tool_bar_item(intptr tool_bar, intptr handle, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible) {
  if (!tool_bar || !handle || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  auto tool_bar_item = dynamic_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->FindById(static_cast<int32>(handle));
  if (!tool_bar_item) throw argument_exception {csf_};
  
  tool_bar_item->SetLabel(convert_string::to_wstring(text));
  tool_bar_item->SetNormalBitmap(*reinterpret_cast<wxImage*>(image.handle()));
  tool_bar_item->SetShortHelp(convert_string::to_wstring(tool_tip_text));
  tool_bar_item->SetToggle(pushed);
  tool_bar_item->Enable(enabled && visible);
}

rectangle tool_bar::tool_bar_item_rectangle(intptr tool_bar, intptr handle) {
  if (!tool_bar || !handle || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  
  auto tool_bar_item = dynamic_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->FindById(static_cast<int32>(handle));
  if (!tool_bar_item) throw argument_exception {csf_};
  return {};
}
