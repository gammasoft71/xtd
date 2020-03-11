#include <stdexcept>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/list_box.hpp>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_list_box.hpp"

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
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->Delete(index);
}

void list_box::end_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void list_box::insert_item(intptr_t control, size_t index, const std::string& value) {
  if (control == 0) return;
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->Insert({value.c_str(), wxMBConvUTF8()}, index);
}

size_t list_box::selected_index(intptr_t control) {
  if (control == 0) return -1;
  if (static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->HasMultipleSelection()) {
    vector<size_t> indices = selected_indices(control);
    if (indices.empty()) return -1;
    return indices[0];
  }
  return static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void list_box::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  return static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(index);
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

void list_box::update_item(intptr_t control, size_t index, const std::string& value) {
  if (control == 0) return;
  static_cast<wxListBox*>(reinterpret_cast<control_handler*>(control)->control())->SetString(index, {value.c_str(), wxMBConvUTF8()});
}
