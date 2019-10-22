#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/checked_list_box.hpp>
#include "fl_checked_list_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void checked_list_box::begin_update(intptr_t control) {
  if (control == 0) return;
}

void checked_list_box::check_state(intptr_t control, size_t index, int check_state) {
  if (control == 0) return;
  static_cast<Fl_Check_Browser*>(reinterpret_cast<control_handler*>(control)->control())->checked(index, check_state != 0);
}

int checked_list_box::check_state(intptr_t control, size_t index) {
  if (control == 0) return false;
  return static_cast<Fl_Check_Browser*>(reinterpret_cast<control_handler*>(control)->control())->checked(index);
}

void checked_list_box::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<Fl_Check_Browser*>(reinterpret_cast<control_handler*>(control)->control())->remove(index);
}

void checked_list_box::end_update(intptr_t control) {
  if (control == 0) return;
}

void checked_list_box::insert_item(intptr_t control, size_t index, const ustring& value, bool checked) {
  if (control == 0) return;
  static_cast<Fl_Check_Browser*>(reinterpret_cast<control_handler*>(control)->control())->add(value.c_str(), checked);
  if (reinterpret_cast<fl_checked_list_box*>(control)->sorted())
    static_cast<Fl_Check_Browser*>(reinterpret_cast<control_handler*>(control)->control())->sort();
}

size_t checked_list_box::selected_index(intptr_t control) {
  if (control == 0) return -1;
  return -1;
}

void checked_list_box::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
}

vector<size_t> checked_list_box::selected_indices(intptr_t control) {
  if (control == 0) return {};
  return {};
    
}
