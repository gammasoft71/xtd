#include <xtd/argument_exception.h>
#include <xtd/diagnostics/stopwatch.h>
#include <xtd/cdebug.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/tool_bar.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tool_bar.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tool_bar.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms::native;

intptr_t tool_bar::add_tool_bar_button(intptr_t control, const xtd::ustring& text, intptr_t image, bool enabled) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(control)->control())->AddTool(wxID_ANY, convert_string::to_wstring(text), *reinterpret_cast<wxImage*>(image));
  tool_bar_item->Enable(enabled);
  return static_cast<intptr_t>(tool_bar_item->GetId());
}

intptr_t tool_bar::add_tool_bar_toggle_button(intptr_t control, const xtd::ustring& text, intptr_t image, bool pushed, bool enabled) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(control)->control())->AddTool(wxID_ANY, convert_string::to_wstring(text), *reinterpret_cast<wxImage*>(image), wxEmptyString, wxITEM_CHECK);
  tool_bar_item->Toggle(pushed);
  tool_bar_item->Enable(enabled);
  return static_cast<intptr_t>(tool_bar_item->GetId());
}

intptr_t tool_bar::add_tool_bar_separator(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(control)->control())->AddSeparator();
  return static_cast<intptr_t>(tool_bar_item->GetId());
}

intptr_t tool_bar::add_tool_bar_stretchable_separator(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(control)->control())->AddStretchableSpace();
  return static_cast<intptr_t>(tool_bar_item->GetId());
}

bool tool_bar::set_system_tool_bar(intptr_t control, intptr_t tool_bar) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (tool_bar != 0 && !dynamic_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())) throw argument_exception("dialog can't have tool bar"_t, current_stack_frame_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }

  if (tool_bar == 0) {
    static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetToolBar(nullptr);
  return true;
  }

  if (static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->GetToolBar() == nullptr)
    static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetToolBar(tool_bar != 0 ? static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control()) : nullptr);
  if (tool_bar) dynamic_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->Realize();
  return true;
}
