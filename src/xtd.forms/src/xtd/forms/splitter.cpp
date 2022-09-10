#include "../../../include/xtd/forms/splitter.h"

using namespace xtd;
using namespace xtd::forms;

splitter::splitter() {
  dock(xtd::forms::dock_style::left);
  set_style(control_styles::selectable, false);
}

forms::cursor splitter::default_cursor() const {
  return dock() == dock_style::left || dock() == dock_style::right ? xtd::forms::cursors::vsplit() : xtd::forms::cursors::hsplit();
}

drawing::size splitter::default_size() const {
  return {3, 3};
}
