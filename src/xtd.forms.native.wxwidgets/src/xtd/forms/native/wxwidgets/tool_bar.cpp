#include <xtd/argument_exception.h>
#include <xtd/cdebug.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/tool_bar.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tool_bar.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms::native;

void tool_bar::add_tool_bar_button(intptr_t control, const xtd::ustring& text, intptr_t image) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }

  static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(control)->control())->AddTool(wxID_ANY, convert_string::to_wstring(text), *reinterpret_cast<wxImage*>(image));
}

void tool_bar::add_tool_bar_separator(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  static_cast<wxToolBar*>(reinterpret_cast<control_handler*>(control)->control())->AddSeparator();
}
