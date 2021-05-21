#include <stdexcept>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/collapsible_panel.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_collapsible_panel.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

bool collapsible_panel::expanded(intptr_t control) {
  if (control == 0) return false;
  return !static_cast<wxScrolled<wxCollapsiblePane>*>(reinterpret_cast<control_handler*>(control)->control())->IsCollapsed();
}

void collapsible_panel::expanded(intptr_t control, bool expand) {
  if (control == 0) return;
  static_cast<wxScrolled<wxCollapsiblePane>*>(reinterpret_cast<control_handler*>(control)->control())->Collapse(!expand);
}
