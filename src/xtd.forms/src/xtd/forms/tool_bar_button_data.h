#include "../../../include/xtd/forms/tool_bar_button.h"

struct xtd::forms::tool_bar_button::data {
  xtd::forms::control* control = nullptr;
  std::optional<std::reference_wrapper<xtd::forms::context_menu>> drop_down_menu;
  bool enabled = true;
  size_t image_index = xtd::forms::image_list::image_collection::npos;
  xtd::drawing::image image_key;
  xtd::ustring name;
  bool partial_push = false;
  bool pushed = false;
  xtd::drawing::rectangle rectangle;
  xtd::forms::tool_bar_button_style style = xtd::forms::tool_bar_button_style::push_button;
  std::any tag;
  xtd::ustring text;
  xtd::ustring tool_tip_text;
  bool visible = true;
  xtd::forms::tool_bar* parent = nullptr;
  intptr handle = 0;
};
