#include <xtd/forms/native/tab_control.hpp>
#include "wx_tab_control.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void tab_control::add_item(intptr_t control, intptr_t page, const ustring& text) {
  if (control == 0 || page == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->AddPage(reinterpret_cast<control_handler*>(page)->control(), text);
}

void tab_control::instert_item(intptr_t control, size_t index, intptr_t page, const ustring& text) {
  if (control == 0 || page == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->InsertPage(index, reinterpret_cast<control_handler*>(page)->control(), text);
}

void tab_control::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->DeletePage(index);
}

size_t tab_control::selected_index(intptr_t control) {
  if (control == 0) return -1;
  return static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void tab_control::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(index);
}
