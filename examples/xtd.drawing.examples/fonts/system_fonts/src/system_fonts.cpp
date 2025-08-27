#include <xtd/xtd>

auto main() -> int {
  console::write_line("caption_font       : {}", drawing::system_fonts::caption_font());
  console::write_line("default_font       : {}", drawing::system_fonts::default_font());
  console::write_line("dialog_font        : {}", drawing::system_fonts::dialog_font());
  console::write_line("icon_title_font    : {}", drawing::system_fonts::icon_title_font());
  console::write_line("menu_font          : {}", drawing::system_fonts::menu_font());
  console::write_line("message_box_font   : {}", drawing::system_fonts::message_box_font());
  console::write_line("small_caption_font : {}", drawing::system_fonts::small_caption_font());
  console::write_line("status_font        : {}", drawing::system_fonts::status_font());
}

// This code can produce the following output :
//
// caption_font       : [font: name=.AppleSystemUIFont, size=9, units=3, gdi_char_set=0, gdi_vertical_font=false]
// default_font       : [font: name=.AppleSystemUIFont, size=9, units=3, gdi_char_set=0, gdi_vertical_font=false]
// dialog_font        : [font: name=.AppleSystemUIFont, size=9, units=3, gdi_char_set=0, gdi_vertical_font=false]
// icon_title_font    : [font: name=.AppleSystemUIFont, size=9, units=3, gdi_char_set=0, gdi_vertical_font=false]
// menu_font          : [font: name=.AppleSystemUIFont, size=9, units=3, gdi_char_set=0, gdi_vertical_font=false]
// message_box_font   : [font: name=.AppleSystemUIFont, size=9, units=3, gdi_char_set=0, gdi_vertical_font=false]
// small_caption_font : [font: name=.AppleSystemUIFont, size=9, units=3, gdi_char_set=0, gdi_vertical_font=false]
// status_font        : [font: name=.AppleSystemUIFont, size=9, units=3, gdi_char_set=0, gdi_vertical_font=false]
