#include <xtd/forms/native/tab_control.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_control.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void tab_control::add_item(intptr_t control, intptr_t page, const std::string& text) {
  if (control == 0 || page == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->AddPage(reinterpret_cast<control_handler*>(page)->control(), {text.c_str(), wxMBConvUTF8()});
}

void tab_control::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->RemovePage(index);
}

void tab_control::delete_item(intptr_t control, intptr_t page) {
  if (control == 0 || page == 0) return;
  size_t index = static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->FindPage(reinterpret_cast<control_handler*>(page)->control());
  if (index != -1) delete_item(control, index);
}

void tab_control::image_list(intptr_t control, intptr_t image_list) {
  if (control == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->SetImageList(reinterpret_cast<wxImageList*>(image_list));
}

void tab_control::insert_item(intptr_t control, size_t index, intptr_t page) {
  if (control == 0 || page == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->InsertPage(index, reinterpret_cast<control_handler*>(page)->control(), wxEmptyString);
}

void tab_control::page_image_index(intptr_t control, size_t index, size_t image_index) {
  if (control == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->SetPageImage(static_cast<int32_t>(index), static_cast<int32_t>(image_index));
}

void tab_control::page_text(intptr_t control, size_t index, const std::string& text) {
  if (control == 0) return;
  static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->SetPageText(static_cast<int32_t>(index), {text.c_str(), wxMBConvUTF8()});
}

size_t tab_control::selected_index(intptr_t control) {
  if (control == 0) return -1;
  return static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void tab_control::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  if (index != -1) static_cast<wxNotebookBase*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(index);
}

void tab_control::update_item(intptr_t control, size_t index, intptr_t page) {
  if (control == 0 || page == 0) return;
  delete_item(control, index);
  insert_item(control, index, page);
}
