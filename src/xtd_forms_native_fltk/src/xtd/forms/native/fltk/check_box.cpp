#include <xtd/forms/native/check_box.hpp>
#include "fl_check_box.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  int to_check_box_state(int value) {
    switch (value) {
      case BST_UNCHECKED: return FL_CHECK_BOX_UNCHECKED;
      case BST_CHECKED: return FL_CHECK_BOX_CHECKED;
      case BST_INDETERMINATE: return FL_CHECK_BOX_INDETERMINATE;
      default: return FL_CHECK_BOX_UNCHECKED;
    }
  }
  
  int from_check_box_state(int value) {
    switch (value) {
      case FL_CHECK_BOX_UNCHECKED: return BST_UNCHECKED;
      case FL_CHECK_BOX_CHECKED: return BST_CHECKED;
      case FL_CHECK_BOX_INDETERMINATE: return BST_INDETERMINATE;
      default: return BST_UNCHECKED;
    }
  }
}

int check_box::check_state(intptr_t control) {
  if (control == 0) return false;
  return from_check_box_state(static_cast<Fl_Check_Box*>(reinterpret_cast<control_handler*>(control)->control())->state());
}

void check_box::check_state(intptr_t control, int state) {
  if (control == 0) return;
  static_cast<Fl_Check_Box*>(reinterpret_cast<control_handler*>(control)->control())->state(to_check_box_state(state));
}
