#include "../../../include/xtd/forms/tool_bar_button.hpp"

struct xtd::forms::tool_bar_button::data {
  xtd::forms::control* control = nullptr;
  std::optional<std::reference_wrapper<xtd::forms::context_menu>> drop_down_menu;
  bool enabled = true;
  size_t image_index = xtd::forms::image_list::image_collection::npos;
  xtd::drawing::image image_key;
  xtd::string name;
  bool partial_push = false;
  bool pushed = false;
  xtd::drawing::rectangle rectangle;
  xtd::forms::tool_bar_button_style style = xtd::forms::tool_bar_button_style::push_button;
  xtd::any_object tag;
  xtd::string text;
  xtd::string tool_tip_text;
  bool visible = true;
  xtd::forms::tool_bar* parent = nullptr;
  intptr handle = 0;
};
