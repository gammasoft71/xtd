#include <limits>
#include <stdexcept>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/choice.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_choice.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void choice::begin_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void choice::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->Delete(static_cast<int32_t>(index));
}

void choice::end_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void choice::insert_item(intptr_t control, size_t index, const ustring& value) {
  if (control == 0) return;
  static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->Insert(xtd::convert_string::to_wstring(value), static_cast<int32_t>(index));
}

size_t choice::selected_index(intptr_t control) {
  if (control == 0) return std::numeric_limits<size_t>::max();
  return static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void choice::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  return static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(static_cast<int32_t>(index));
}

void choice::update_item(intptr_t control, size_t index, const ustring& value) {
  if (control == 0) return;
  static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->SetString(static_cast<int32_t>(index), xtd::convert_string::to_wstring(value));
}
