#include <xtd/forms/native/tab_control.hpp>
#include "fl_tab_control.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void tab_control::add_item(intptr_t control, intptr_t page, const ustring& text) {
  if (control == 0 || page == 0) return;
  reinterpret_cast<control_handler*>(page)->control()->parent(static_cast<Fl_Group*>(reinterpret_cast<control_handler*>(control)->control()));
}

void tab_control::insert_item(intptr_t control, size_t index, intptr_t page, const ustring& text) {
  if (control == 0 || page == 0) return;
  reinterpret_cast<control_handler*>(page)->control()->parent(static_cast<Fl_Group*>(reinterpret_cast<control_handler*>(control)->control()));
}

void tab_control::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<Fl_Tabs*>(reinterpret_cast<control_handler*>(control)->control())->child(index)->parent(nullptr);
}

size_t tab_control::selected_index(intptr_t control) {
  if (control == 0) return -1;
  Fl_Widget* selected_item = static_cast<Fl_Tabs*>(reinterpret_cast<control_handler*>(control)->control())->value();
  for (int index = 0; index < static_cast<Fl_Tabs*>(reinterpret_cast<control_handler*>(control)->control())->children(); index++)
    if (static_cast<Fl_Tabs*>(reinterpret_cast<control_handler*>(control)->control())->child(index) == selected_item)
      return index;
  return -1;
}

void tab_control::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<Fl_Tabs*>(reinterpret_cast<control_handler*>(control)->control())->push(static_cast<Fl_Tabs*>(reinterpret_cast<control_handler*>(control)->control())->child(index));
}
