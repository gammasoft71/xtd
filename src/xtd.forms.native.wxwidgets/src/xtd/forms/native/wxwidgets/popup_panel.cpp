#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/popup_panel.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_popup_panel.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/convert_string.h>
#include <wx/popupwin.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void popup_panel::visible(intptr_t control, bool visible) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  if (!visible) static_cast<wxPopupTransientWindow*>(reinterpret_cast<control_handler*>(control)->control())->Dismiss();
  else {
    static_cast<wxPopupTransientWindow*>(reinterpret_cast<control_handler*>(control)->control())->Raise();
    static_cast<wxPopupTransientWindow*>(reinterpret_cast<control_handler*>(control)->control())->Popup();
  }
}

void popup_panel::virtual_size(intptr_t control, const drawing::size& size) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->main_control()->SetVirtualSize(wxSize(size.width(), size.height()));
  if (dynamic_cast<wxPopupPanel*>(reinterpret_cast<control_handler*>(control)->main_control())) static_cast<wxPopupPanel*>(reinterpret_cast<control_handler*>(control)->main_control())->SetScrollRate(10, 10);
}
