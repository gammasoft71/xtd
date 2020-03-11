#include <stdexcept>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/choice.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_choice.h"

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
  static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->Delete(index);
}

void choice::end_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void choice::insert_item(intptr_t control, size_t index, const std::string& value) {
  if (control == 0) return;
  static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->Insert({value.c_str(), wxMBConvUTF8()}, index);
}

size_t choice::selected_index(intptr_t control) {
  if (control == 0) return -1;
  return static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void choice::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  return static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(index);
}

void choice::update_item(intptr_t control, size_t index, const std::string& value) {
  if (control == 0) return;
  static_cast<wxChoice*>(reinterpret_cast<control_handler*>(control)->control())->SetString(index, {value.c_str(), wxMBConvUTF8()});
}
