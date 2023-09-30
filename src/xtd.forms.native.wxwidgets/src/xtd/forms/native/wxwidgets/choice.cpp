#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_choice.h"
#include <xtd/forms/native/application>
#include <xtd/forms/native/choice>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_colors>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <limits>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void choice::begin_update(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void choice::delete_item(intptr control, size_t index) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->Delete(static_cast<int32>(index));
}

void choice::end_update(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void choice::insert_item(intptr control, size_t index, const ustring& value) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->Insert(xtd::convert_string::to_wstring(value), static_cast<int32>(index));
}

size_t choice::selected_index(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  return static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void choice::selected_index(intptr control, size_t index) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  return static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(static_cast<int32>(index));
}

void choice::update_item(intptr control, size_t index, const ustring& value) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->SetString(static_cast<int32>(index), xtd::convert_string::to_wstring(value));
}
