#include <stdexcept>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/panel.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_panel.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void panel::virtual_size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;

  reinterpret_cast<control_handler*>(control)->control()->SetVirtualSize(wxSize(size.width(), size.height()));
  if (dynamic_cast<wxScrolled<wxPanel>*>(reinterpret_cast<control_handler*>(control)->control())) static_cast<wxScrolled<wxPanel>*>(reinterpret_cast<control_handler*>(control)->control())->SetScrollRate(10, 10);
}
