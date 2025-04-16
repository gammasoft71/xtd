#include "../../../include/xtd/drawing/system_pens.hpp"

using namespace xtd;
using namespace xtd::drawing;

pen system_pens::accent() {
  return pen {color::from_known_color(known_color::accent), 1};
}

pen system_pens::accent_text() {
  return pen {color::from_known_color(known_color::accent_text), 1};
}

pen system_pens::active_border() {
  return pen {color::from_known_color(known_color::active_border), 1};
}

pen system_pens::active_caption() {
  return pen {color::from_known_color(known_color::active_caption), 1};
}

pen system_pens::active_caption_text() {
  return pen {color::from_known_color(known_color::active_caption_text), 1};
}

pen system_pens::active_text() {
  return pen {color::from_known_color(known_color::active_text), 1};
}

pen system_pens::app_workspace() {
  return pen {color::from_known_color(known_color::app_workspace), 1};
}

pen system_pens::button_face() {
  return pen {color::from_known_color(known_color::button_face), 1};
}

pen system_pens::button_highlight() {
  return pen {color::from_known_color(known_color::button_highlight), 1};
}

pen system_pens::button_shadow() {
  return pen {color::from_known_color(known_color::button_shadow), 1};
}

pen system_pens::control() {
  return pen {color::from_known_color(known_color::control), 1};
}

pen system_pens::control_dark() {
  return pen {color::from_known_color(known_color::control_dark), 1};
}

pen system_pens::control_dark_dark() {
  return pen {color::from_known_color(known_color::control_dark_dark), 1};
}

pen system_pens::control_light() {
  return pen {color::from_known_color(known_color::control_light), 1};
}

pen system_pens::control_light_light() {
  return pen {color::from_known_color(known_color::control_light_light), 1};
}

pen system_pens::control_text() {
  return pen {color::from_known_color(known_color::control_text), 1};
}

pen system_pens::desktop() {
  return pen {color::from_known_color(known_color::desktop), 1};
}

pen system_pens::gradient_active_caption() {
  return pen {color::from_known_color(known_color::gradient_active_caption), 1};
}

pen system_pens::gradient_inactive_caption() {
  return pen {color::from_known_color(known_color::gradient_inactive_caption), 1};
}

pen system_pens::gray_text() {
  return pen {color::from_known_color(known_color::gray_text), 1};
}

pen system_pens::highlight() {
  return pen {color::from_known_color(known_color::highlight), 1};
}

pen system_pens::highlight_text() {
  return pen {color::from_known_color(known_color::highlight_text), 1};
}

pen system_pens::hot_track() {
  return pen {color::from_known_color(known_color::hot_track), 1};
}

pen system_pens::inactive_border() {
  return pen {color::from_known_color(known_color::inactive_border), 1};
}

pen system_pens::inactive_caption() {
  return pen {color::from_known_color(known_color::inactive_caption), 1};
}

pen system_pens::inactive_caption_text() {
  return pen {color::from_known_color(known_color::inactive_caption_text), 1};
}

pen system_pens::info() {
  return pen {color::from_known_color(known_color::info), 1};
}

pen system_pens::info_text() {
  return pen {color::from_known_color(known_color::info_text), 1};
}

pen system_pens::link_text() {
  return pen {color::from_known_color(known_color::link_text), 1};
}

pen system_pens::menu() {
  return pen {color::from_known_color(known_color::menu), 1};
}

pen system_pens::menu_bar() {
  return pen {color::from_known_color(known_color::menu_bar), 1};
}

pen system_pens::menu_highlight() {
  return pen {color::from_known_color(known_color::menu_highlight), 1};
}

pen system_pens::menu_text() {
  return pen {color::from_known_color(known_color::menu_text), 1};
}

pen system_pens::scroll_bar() {
  return pen {color::from_known_color(known_color::scroll_bar), 1};
}

pen system_pens::text_box() {
  return pen {color::from_known_color(known_color::text_box), 1};
}

pen system_pens::text_box_text() {
  return pen {color::from_known_color(known_color::text_box_text), 1};
}

pen system_pens::visited_text() {
  return pen {color::from_known_color(known_color::visited_text), 1};
}

pen system_pens::window() {
  return pen {color::from_known_color(known_color::window), 1};
}

pen system_pens::window_frame() {
  return pen {color::from_known_color(known_color::window_frame), 1};
}

pen system_pens::window_text() {
  return pen {color::from_known_color(known_color::window_text), 1};
}

const array<pen>& system_pens::get_pens() {
  static array system_pens {system_pens::accent(), system_pens::accent_text(), system_pens::active_border(), system_pens::active_caption(), system_pens::active_caption_text(), system_pens::active_text(), system_pens::app_workspace(), system_pens::button_face(), system_pens::button_highlight(), system_pens::button_shadow(), system_pens::control(), system_pens::control_dark(), system_pens::control_dark_dark(), system_pens::control_light(), system_pens::control_light_light(), system_pens::control_text(), system_pens::desktop(), system_pens::gradient_active_caption(), system_pens::gradient_inactive_caption(), system_pens::gray_text(), system_pens::highlight(), system_pens::highlight_text(), system_pens::hot_track(), system_pens::inactive_border(), system_pens::inactive_caption(), system_pens::inactive_caption_text(), system_pens::info(), system_pens::info_text(), system_pens::link_text(), system_pens::menu(), system_pens::menu_bar(), system_pens::menu_highlight(), system_pens::menu_text(), system_pens::scroll_bar(), system_pens::text_box(), system_pens::text_box_text(), system_pens::visited_text(), system_pens::window(), system_pens::window_frame(), system_pens::window_text(),};
  return system_pens;
}
