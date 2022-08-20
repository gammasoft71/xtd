#include "../../../include/xtd/forms/list_control.h"

using namespace xtd;
using namespace xtd::forms;

list_control::list_control() {
  //back_color_ = default_back_color();
  //fore_color_ = default_fore_color();
}

drawing::color list_control::default_back_color() const {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color list_control::default_fore_color() const {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}
