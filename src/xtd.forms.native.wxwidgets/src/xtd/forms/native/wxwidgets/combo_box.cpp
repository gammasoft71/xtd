#include <limits>
#include <stdexcept>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/combo_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_combo_box.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void combo_box::begin_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void combo_box::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->Delete(static_cast<int32_t>(index));
}

void combo_box::end_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void combo_box::insert_item(intptr_t control, size_t index, const ustring& value) {
  if (control == 0) return;
  static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->Insert(xtd::convert_string::to_wstring(value), static_cast<int32_t>(index));
}

size_t combo_box::selected_index(intptr_t control) {
  if (control == 0) return std::numeric_limits<size_t>::max();
  return static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void combo_box::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  return static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(static_cast<int32_t>(index));
}

void combo_box::update_item(intptr_t control, size_t index, const ustring& value) {
  if (control == 0) return;
  static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->SetString(static_cast<int32_t>(index), xtd::convert_string::to_wstring(value));
}
