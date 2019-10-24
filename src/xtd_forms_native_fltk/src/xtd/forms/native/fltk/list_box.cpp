#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/list_box.hpp>
#include "fl_list_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void list_box::begin_update(intptr_t control) {
  if (control == 0) return;
}

void list_box::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<Fl_Browser*>(reinterpret_cast<control_handler*>(control)->control())->remove(index);
}

void list_box::end_update(intptr_t control) {
  if (control == 0) return;
}

void list_box::insert_item(intptr_t control, size_t index, const ustring& value) {
  if (control == 0) return;
  static_cast<Fl_Browser*>(reinterpret_cast<control_handler*>(control)->control())->insert(index + 1, value.c_str());
  if (reinterpret_cast<fl_list_box*>(control)->sorted())
    static_cast<Fl_Browser*>(reinterpret_cast<control_handler*>(control)->control())->sort();
}

size_t list_box::selected_index(intptr_t control) {
  if (control == 0) return -1;
  return static_cast<Fl_Browser*>(reinterpret_cast<control_handler*>(control)->control())->value() - 1;
}

void list_box::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<Fl_Browser*>(reinterpret_cast<control_handler*>(control)->control())->value(index + 1);
}

vector<size_t> list_box::selected_indices(intptr_t control) {
  if (control == 0) return {};
  vector<size_t> indices;
  for (int index = 1; index <= static_cast<Fl_Browser*>(reinterpret_cast<control_handler*>(control)->control())->size(); index++)
    if (static_cast<Fl_Browser*>(reinterpret_cast<control_handler*>(control)->control())->selected(index))
      indices.push_back(index - 1);
  return indices;
    
}
