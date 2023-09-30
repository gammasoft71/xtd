#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_collapsible_panel.h"
#include <xtd/forms/native/collapsible_panel>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

bool collapsible_panel::expanded(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return false;
  }
  return !static_cast<wxScrolled<wxCollapsiblePane>*>(reinterpret_cast<control_handler*>(control)->control())->IsCollapsed();
}

void collapsible_panel::expanded(intptr control, bool expand) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxScrolled<wxCollapsiblePane>*>(reinterpret_cast<control_handler*>(control)->control())->Collapse(!expand);
}
