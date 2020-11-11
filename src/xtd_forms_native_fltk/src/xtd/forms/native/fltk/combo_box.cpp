#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/combo_box.hpp>
#include "fl_combo_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void combo_box::begin_update(intptr_t control) {
  if (control == 0) return;
}

void combo_box::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  if (dynamic_cast<Fl_Choice*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<Fl_Choice*>(reinterpret_cast<control_handler*>(control)->control())->remove(index);
  else
    static_cast<Fl_Input_Choice*>(reinterpret_cast<control_handler*>(control)->control())->remove(index);
}

void combo_box::end_update(intptr_t control) {
  if (control == 0) return;
}

void combo_box::insert_item(intptr_t control, size_t index, const ustring& value) {
  if (control == 0) return;
  if (dynamic_cast<Fl_Choice*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<Fl_Choice*>(reinterpret_cast<control_handler*>(control)->control())->add(value.c_str());
  else
    static_cast<Fl_Input_Choice*>(reinterpret_cast<control_handler*>(control)->control())->add(value.c_str());
}

size_t combo_box::selected_index(intptr_t control) {
  if (control == 0) return -1;
  if (dynamic_cast<Fl_Choice*>(reinterpret_cast<control_handler*>(control)->control()))
    return static_cast<Fl_Choice*>(reinterpret_cast<control_handler*>(control)->control())->value();
  return static_cast<Fl_Input_Choice*>(reinterpret_cast<control_handler*>(control)->control())->input()->position();
}

void combo_box::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  if (dynamic_cast<Fl_Choice*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<Fl_Choice*>(reinterpret_cast<control_handler*>(control)->control())->value(index);
  else
    static_cast<Fl_Input_Choice*>(reinterpret_cast<control_handler*>(control)->control())->input()->position(index);
}
