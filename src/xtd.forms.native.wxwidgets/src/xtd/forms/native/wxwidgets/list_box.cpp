#include <limits>
#include <stdexcept>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/list_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_list_box.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void list_box::begin_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void list_box::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->Delete(static_cast<int32_t>(index));
}

void list_box::end_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void list_box::insert_item(intptr_t control, size_t index, const ustring& value) {
  if (control == 0) return;
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->Insert(convert_string::to_wstring(value), static_cast<int32_t>(index));
}

size_t list_box::selected_index(intptr_t control) {
  if (control == 0) return std::numeric_limits<size_t>::max();
  if (static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->HasMultipleSelection()) {
    vector<size_t> indices = selected_indices(control);
    if (indices.empty()) return std::numeric_limits<size_t>::max();
    return indices[0];
  }
  return static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void list_box::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  return static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(static_cast<int32_t>(index));
}

vector<size_t> list_box::selected_indices(intptr_t control) {
  if (control == 0) return {};
  vector<size_t> indices;
  wxArrayInt wx_indices;
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelections(wx_indices);
  for (int index : wx_indices)
    indices.push_back(index);
  return indices;
}

void list_box::update_item(intptr_t control, size_t index, const ustring& value) {
  if (control == 0) return;
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetString(static_cast<int32_t>(index), convert_string::to_wstring(value));
}
