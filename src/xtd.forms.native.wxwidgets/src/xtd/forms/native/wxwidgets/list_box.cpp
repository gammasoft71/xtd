#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_list_box.h"
#include <xtd/forms/native/application>
#include <xtd/forms/native/list_box>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_colors>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <limits>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void list_box::begin_update(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void list_box::delete_item(intptr control, size_t index) {
  if (!control || !wxTheApp) throw argument_exception {};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->Delete(static_cast<int32>(index));
}

void list_box::end_update(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void list_box::insert_item(intptr control, size_t index, const string& value) {
  if (!control || !wxTheApp) throw argument_exception {};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->Insert(convert_string::to_wstring(value), static_cast<int32>(index));
}

size_t list_box::selected_index(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0;
  }
  if (static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->HasMultipleSelection()) {
    std::vector<size_t> indices = selected_indices(control);
    if (indices.empty()) return std::numeric_limits<size_t>::max();
    return indices[0];
  }
  return static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void list_box::selected_index(intptr control, size_t index) {
  if (!control || !wxTheApp) throw argument_exception {};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  return static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(static_cast<int32>(index));
}

std::vector<size_t> list_box::selected_indices(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  std::vector<size_t> indices;
  wxArrayInt wx_indices;
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelections(wx_indices);
  std::for_each(wx_indices.begin(), wx_indices.end(), [&](int32 index) {indices.push_back(index);});
  return indices;
}

void list_box::update_item(intptr control, size_t index, const string& value) {
  if (!control || !wxTheApp) throw argument_exception {};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetString(static_cast<int32>(index), convert_string::to_wstring(value));
}
