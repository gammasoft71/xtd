#include <stdexcept>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/checked_list_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_checked_list_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void checked_list_box::begin_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void checked_list_box::check_state(intptr_t control, size_t index, int check_state) {
  if (control == 0) return;
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Check(static_cast<int32_t>(index), check_state != 0);
}

int checked_list_box::check_state(intptr_t control, size_t index) {
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

void checked_list_box::insert_item(intptr_t control, size_t index, const std::string& value, bool checked) {
  if (control == 0) return;
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Insert({value.c_str(), wxMBConvUTF8()}, static_cast<int32_t>(index));
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Check(static_cast<int32_t>(index), checked);
#if defined(__WXMSW__)
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetItem(index)->SetTextColour(static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetForegroundColour());
#endif
}

size_t checked_list_box::selected_index(intptr_t control) {
  if (control == 0) return -1;
  if (static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->HasMultipleSelection()) {
    vector<size_t> indices = selected_indices(control);
    if (indices.empty()) return -1;
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

void checked_list_box::update_item(intptr_t control, size_t index, const std::string& value, bool checked) {
  if (control == 0) return;
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetString(static_cast<int32_t>(index), {value.c_str(), wxMBConvUTF8()});
  static_cast<wxCheckListBox*>(reinterpret_cast<control_handler*>(control)->control())->Check(static_cast<int32_t>(index), checked);
}
