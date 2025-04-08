#include "../../../include/xtd/drawing/system_brushes.hpp"

using namespace xtd;
using namespace xtd::drawing;

solid_brush system_brushes::accent() {
  return solid_brush {color::from_known_color(known_color::accent)};
}

solid_brush system_brushes::accent_text() {
  return solid_brush {color::from_known_color(known_color::accent_text)};
}

solid_brush system_brushes::active_border() {
  return solid_brush {color::from_known_color(known_color::active_border)};
}

solid_brush system_brushes::active_caption() {
  return solid_brush {color::from_known_color(known_color::active_caption)};
}

solid_brush system_brushes::active_caption_text() {
  return solid_brush {color::from_known_color(known_color::active_caption_text)};
}

solid_brush system_brushes::active_text() {
  return solid_brush {color::from_known_color(known_color::active_text)};
}

solid_brush system_brushes::app_workspace() {
  return solid_brush {color::from_known_color(known_color::app_workspace)};
}

solid_brush system_brushes::button_face() {
  return solid_brush {color::from_known_color(known_color::button_face)};
}

solid_brush system_brushes::button_highlight() {
  return solid_brush {color::from_known_color(known_color::button_highlight)};
}

solid_brush system_brushes::button_shadow() {
  return solid_brush {color::from_known_color(known_color::button_shadow)};
}

solid_brush system_brushes::control() {
  return solid_brush {color::from_known_color(known_color::control)};
}

solid_brush system_brushes::control_dark() {
  return solid_brush {color::from_known_color(known_color::control_dark)};
}

solid_brush system_brushes::control_dark_dark() {
  return solid_brush {color::from_known_color(known_color::control_dark_dark)};
}

solid_brush system_brushes::control_light() {
  return solid_brush {color::from_known_color(known_color::control_light)};
}

solid_brush system_brushes::control_light_light() {
  return solid_brush {color::from_known_color(known_color::control_light_light)};
}

solid_brush system_brushes::control_text() {
  return solid_brush {color::from_known_color(known_color::control_text)};
}

solid_brush system_brushes::desktop() {
  return solid_brush {color::from_known_color(known_color::desktop)};
}

solid_brush system_brushes::gradient_active_caption() {
  return solid_brush {color::from_known_color(known_color::gradient_active_caption)};
}

solid_brush system_brushes::gradient_inactive_caption() {
  return solid_brush {color::from_known_color(known_color::gradient_inactive_caption)};
}

solid_brush system_brushes::gray_text() {
  return solid_brush {color::from_known_color(known_color::gray_text)};
}

solid_brush system_brushes::highlight() {
  return solid_brush {color::from_known_color(known_color::highlight)};
}

solid_brush system_brushes::highlight_text() {
  return solid_brush {color::from_known_color(known_color::highlight_text)};
}

solid_brush system_brushes::hot_track() {
  return solid_brush {color::from_known_color(known_color::hot_track)};
}

solid_brush system_brushes::inactive_border() {
  return solid_brush {color::from_known_color(known_color::inactive_border)};
}

solid_brush system_brushes::inactive_caption() {
  return solid_brush {color::from_known_color(known_color::inactive_caption)};
}

solid_brush system_brushes::inactive_caption_text() {
  return solid_brush {color::from_known_color(known_color::inactive_caption_text)};
}

solid_brush system_brushes::info() {
  return solid_brush {color::from_known_color(known_color::info)};
}

solid_brush system_brushes::info_text() {
  return solid_brush {color::from_known_color(known_color::info_text)};
}

solid_brush system_brushes::link_text() {
  return solid_brush {color::from_known_color(known_color::link_text)};
}

solid_brush system_brushes::menu() {
  return solid_brush {color::from_known_color(known_color::menu)};
}

solid_brush system_brushes::menu_bar() {
  return solid_brush {color::from_known_color(known_color::menu_bar)};
}

solid_brush system_brushes::menu_highlight() {
  return solid_brush {color::from_known_color(known_color::menu_highlight)};
}

solid_brush system_brushes::menu_text() {
  return solid_brush {color::from_known_color(known_color::menu_text)};
}

solid_brush system_brushes::scroll_bar() {
  return solid_brush {color::from_known_color(known_color::scroll_bar)};
}

solid_brush system_brushes::shadow_text() {
  return solid_brush {color::from_known_color(known_color::shadow_text)};
}

solid_brush system_brushes::text_box() {
  return solid_brush {color::from_known_color(known_color::text_box)};
}

solid_brush system_brushes::text_box_text() {
  return solid_brush {color::from_known_color(known_color::text_box_text)};
}

solid_brush system_brushes::visited_text() {
  return solid_brush {color::from_known_color(known_color::visited_text)};
}

solid_brush system_brushes::window() {
  return solid_brush {color::from_known_color(known_color::window)};
}

solid_brush system_brushes::window_frame() {
  return solid_brush {color::from_known_color(known_color::window_frame)};
}

solid_brush system_brushes::window_text() {
  return solid_brush {color::from_known_color(known_color::window_text)};
}

const array<solid_brush>& system_brushes::get_brushes() {
  static auto brushes = array {system_brushes::accent(), system_brushes::accent_text(), system_brushes::active_border(), system_brushes::active_caption(), system_brushes::active_caption_text(), system_brushes::active_text(), system_brushes::app_workspace(), system_brushes::button_face(), system_brushes::button_highlight(), system_brushes::button_shadow(), system_brushes::control(), system_brushes::control_dark(), system_brushes::control_dark_dark(), system_brushes::control_light(), system_brushes::control_light_light(), system_brushes::control_text(), system_brushes::desktop(), system_brushes::gradient_active_caption(), system_brushes::gradient_inactive_caption(), system_brushes::gray_text(), system_brushes::highlight(), system_brushes::highlight_text(), system_brushes::hot_track(), system_brushes::inactive_border(), system_brushes::inactive_caption(), system_brushes::inactive_caption_text(), system_brushes::info(), system_brushes::info_text(), system_brushes::link_text(), system_brushes::menu(), system_brushes::menu_bar(), system_brushes::menu_highlight(), system_brushes::menu_text(), system_brushes::scroll_bar(), system_brushes::text_box(), system_brushes::text_box_text(), system_brushes::visited_text(), system_brushes::window(), system_brushes::window_frame(), system_brushes::window_text(),};
  return brushes;
}
