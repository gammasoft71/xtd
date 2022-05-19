#include <xtd/argument_exception.h>
#include <xtd/diagnostics/stopwatch.h>
#include <xtd/cdebug.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/tool_bar.h>
// Workaround : When wxWidgets destroy the tool bar tool with a control, it destroy the control. But with xtd, the control is managed by xtd and it can be destroyed.
#if !defined (WIN32)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-macro"
#endif
#define protected public
#define private public
// end Workaround
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tool_bar.h"
// Workaround : When wxWidgets destroy the tool bar tool with a control, it destroy the control. But with xtd, the control is managed by xtd and it can be destroyed.
#undef protected
#undef private
#if !defined (WIN32)
#pragma clang diagnostic pop
#endif
// end Workaround
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms::native;

intptr_t tool_bar::add_tool_bar_button(intptr_t tool_bar, const xtd::ustring& text, const xtd::drawing::image& image, bool enabled, bool visible) {
  if (!tool_bar || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddTool(wxID_ANY, convert_string::to_wstring(text), *reinterpret_cast<wxImage*>(image.handle()));
  tool_bar_item->Enable(enabled && visible);
  return static_cast<intptr_t>(tool_bar_item->GetId());
}

intptr_t tool_bar::add_tool_bar_toggle_button(intptr_t tool_bar, const xtd::ustring& text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible) {
  if (!tool_bar || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddTool(wxID_ANY, convert_string::to_wstring(text), *reinterpret_cast<wxImage*>(image.handle()), wxEmptyString, wxITEM_CHECK);
  tool_bar_item->Toggle(pushed);
  tool_bar_item->Enable(enabled && visible);
  return static_cast<intptr_t>(tool_bar_item->GetId());
}

intptr_t tool_bar::add_tool_bar_separator(intptr_t tool_bar) {
  if (!tool_bar || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddSeparator();
  return static_cast<intptr_t>(tool_bar_item->GetId());
}

intptr_t tool_bar::add_tool_bar_stretchable_separator(intptr_t tool_bar) {
  if (!tool_bar || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddStretchableSpace();
  return static_cast<intptr_t>(tool_bar_item->GetId());
}

intptr_t tool_bar::add_tool_bar_control(intptr_t tool_bar, intptr_t control, const xtd::ustring& text) {
  if (!tool_bar || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  if (control && !dynamic_cast<wxControl*>(reinterpret_cast<control_handler*>(control)->control())) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Must be a control", __FILE__, __LINE__, __func__);
    return 0;
  }
  
  auto tool_bar_item = static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->AddControl(control ? static_cast<wxControl*>(reinterpret_cast<control_handler*>(control)->control()) : new wxControl(reinterpret_cast<control_handler*>(tool_bar)->control(), wxID_ANY), convert_string::to_wstring(text));
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
    // Workaround : When wxWidgets destroy the tool bar tool with a control, it destroy the control. But with xtd, the control is managed by xtd and it can be destroyed.
    // To prevent destroy control change the tool bar tool style to wxTOOL_STYLE_BUTTON...
    if (static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->GetToolBar() != nullptr)
      for (size_t index = 0; index < static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->GetToolBar()->GetToolsCount(); ++index)
        static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->GetToolBar()->GetToolByPos(index)->m_toolStyle = wxTOOL_STYLE_BUTTON;
    /// end Workaround
    static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetToolBar(nullptr);
    return true;
  }

  if (static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->GetToolBar() == nullptr) {
    static_cast<wxFrame*>(reinterpret_cast<control_handler*>(control)->control())->SetToolBar(static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control()));
    dynamic_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->Realize();
  }
  return true;
}

void tool_bar::update_tool_bar_item(intptr_t tool_bar, intptr_t handle, const xtd::ustring& text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible) {
  if (!tool_bar || !handle || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(tool_bar)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(tool_bar)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }

  auto tool_bar_item = dynamic_cast<wxToolBar*>(reinterpret_cast<control_handler*>(tool_bar)->control())->FindById(static_cast<int>(handle));
  if (!tool_bar_item) throw argument_exception(csf_);

  tool_bar_item->SetLabel(convert_string::to_wstring(text));
  tool_bar_item->SetNormalBitmap(*reinterpret_cast<wxImage*>(image.handle()));
  tool_bar_item->SetToggle(pushed);
  tool_bar_item->Enable(enabled && visible);
}
