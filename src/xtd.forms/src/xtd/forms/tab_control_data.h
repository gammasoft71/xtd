#include "../../../include/xtd/forms/tab_control.h"

struct xtd::forms::tab_control::data {
  tab_alignment alignment = tab_alignment::top;
  forms::image_list image_list;
  size_t selected_index = npos;
};
