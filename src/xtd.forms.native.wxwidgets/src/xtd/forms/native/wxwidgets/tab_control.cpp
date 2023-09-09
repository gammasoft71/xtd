#include <limits>
#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/tab_control.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_control.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void tab_control::delete_page(intptr control, intptr page) {
  if (!wxTheApp) return;
  if (!control || !page) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  auto ctrl = static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control());
  if (ctrl != nullptr) {
    int32 index = ctrl->FindPage(reinterpret_cast<control_handler*>(page)->control());
    if (index != wxNOT_FOUND)
      static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->RemovePage(index);
  }
}

void tab_control::image_list(intptr control, intptr image_list) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->SetImageList(reinterpret_cast<wxImageList*>(image_list));
}

void tab_control::insert_page(intptr control, size_t index, intptr page) {
  if (!control || !page || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->InsertPage(index, reinterpret_cast<control_handler*>(page)->control(), wxEmptyString);
}

size_t tab_control::selected_index(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  return static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void tab_control::selected_index(intptr control, size_t index) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  if (index != std::numeric_limits<size_t>::max()) static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(index);
}
