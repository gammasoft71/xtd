#include <limits>
#include <stdexcept>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/checked_list_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_checked_list_box.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void checked_list_box::begin_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void checked_list_box::check_state(intptr_t control, size_t index, int32_t check_state) {
  if (control == 0) return;
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Check(static_cast<int32_t>(index), check_state != 0);
}

int32_t checked_list_box::check_state(intptr_t control, size_t index) {
  if (control == 0) return false;
  return static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->IsChecked(static_cast<int32_t>(index));
}

void checked_list_box::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Delete(static_cast<int32_t>(index));
}

void checked_list_box::end_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void checked_list_box::insert_item(intptr_t control, size_t index, const std::string& value, int32_t check_state) {
  if (control == 0) return;
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Insert(wxString(xtd::convert_string::to_wstring(value)), static_cast<int32_t>(index));
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Check(static_cast<int32_t>(index), check_state != 0);
#if defined(__WXMSW__)
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetItem(index)->SetTextColour(static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetForegroundColour());
#endif
}

size_t checked_list_box::selected_index(intptr_t control) {
  if (control == 0) return std::numeric_limits<size_t>::max();
  if (static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->HasMultipleSelection()) {
    vector<size_t> indices = selected_indices(control);
    if (indices.empty()) return std::numeric_limits<size_t>::max();
    return indices[0];
  }
  return static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void checked_list_box::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  return static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(static_cast<int32_t>(index));
}

vector<size_t> checked_list_box::selected_indices(intptr_t control) {
  if (control == 0) return {};
  vector<size_t> indices;
  wxArrayInt wx_indices;
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelections(wx_indices);
  for (int index : wx_indices)
    indices.push_back(index);
  return indices;
    
}

void checked_list_box::update_item(intptr_t control, size_t index, const std::string& value, int32_t check_state) {
  if (control == 0) return;
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetString(static_cast<int32_t>(index), wxString(xtd::convert_string::to_wstring(value)));
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Check(static_cast<int32_t>(index), check_state != 0);
}
