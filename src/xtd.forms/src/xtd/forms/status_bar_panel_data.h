#include "../../../include/xtd/forms/status_bar_panel.h"

struct xtd::forms::status_bar_panel::data {
  xtd::forms::horizontal_alignment alignment = xtd::forms::horizontal_alignment::left;
  xtd::forms::status_bar_panel_auto_size auto_size = xtd::forms::status_bar_panel_auto_size::none;
  bool init_mode = false;
  xtd::forms::status_bar_panel_border_style border_style = xtd::forms::status_bar_panel_border_style::sunken;
  xtd::forms::control* control = nullptr;
  intptr handle = 0;
  xtd::drawing::image image;
  int32 min_width = 10;
  xtd::ustring name;
  xtd::forms::status_bar* parent = nullptr;
  xtd::forms::status_bar_panel_style style = xtd::forms::status_bar_panel_style::text;
  std::any tag;
  xtd::ustring text;
  xtd::ustring tool_tip_text;
  int32 width = 100;
};

