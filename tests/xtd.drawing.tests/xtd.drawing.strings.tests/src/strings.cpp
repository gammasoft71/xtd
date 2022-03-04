#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

class strings_form : public form {
public:
  static void main() {
    application::run(strings_form());
  }
  
  strings_form() {
    text("Strings tests");
    padding(5);
    client_size({1000, 800});

    tab_control.parent(*this);
    tab_control.dock(dock_style::fill);
    
    tab_page_color.parent(tab_control);
    tab_page_color.text("Color");
    tab_page_color.paint += {*this, &strings_form::draw_strings_with_color};
    
    tab_page_linear_gradient.parent(tab_control);
    tab_page_linear_gradient.text("Linear gradient");
    tab_page_linear_gradient.paint += {*this, &strings_form::draw_strings_with_linear_gradient};
    
    tab_page_multilines.parent(tab_control);
    tab_page_multilines.text("Multiline");
    tab_page_multilines.paint += {*this, &strings_form::draw_strings_multilines};
    
    tab_page_hot_key_prefix.parent(tab_control);
    tab_page_hot_key_prefix.text("Prefix");
    tab_page_hot_key_prefix.paint += {*this, &strings_form::draw_strings_hot_key_prefix};
  }
  
private:
  forms::tab_control tab_control;
  forms::tab_page tab_page_color;
  forms::tab_page tab_page_linear_gradient;
  forms::tab_page tab_page_multilines;
  forms::tab_page tab_page_hot_key_prefix;

  const ustring regular_str = u8"Regular text - 普通文本";
  const ustring italic_str = u8"Italic text - 斜体文字";
  const ustring bold_str = u8"Bold text - 黑体字";
  
  const xtd::drawing::font regular_font = xtd::drawing::font(system_fonts::default_font(), 32, font_style::regular);
  const xtd::drawing::font italic_font = xtd::drawing::font(system_fonts::default_font(), 32, font_style::italic);
  const xtd::drawing::font bold_font = xtd::drawing::font(system_fonts::default_font(), 32, font_style::bold);

  void draw_grid(const rectangle& rect, drawing::graphics& graphics, const drawing::size& grid_size = drawing::size(5, 5)) {
    auto color1 = back_color().is_dark() ? color::light(back_color()) : color::dark(back_color());
    auto color2 = fore_color().is_dark() ? color::light(fore_color()) : color::dark(fore_color());
    for (auto x = rect.left(); x < rect.right(); x += grid_size.width())
      graphics.draw_line(pen(color1, 1), point(x, rect.top()), point(x, rect.bottom()));
    for (auto y = rect.top(); y < rect.bottom(); y += grid_size.height())
      graphics.draw_line(pen(color1, 1), point(rect.left(), y), point(rect.right(), y));
    for (auto x = rect.left(); x < rect.right(); x += grid_size.width() * 10)
      graphics.draw_line(pen(color2, 1), point(x, rect.top()), point(x, rect.bottom()));
    for (auto y = rect.top(); y < rect.bottom(); y += grid_size.height() * 10)
      graphics.draw_line(pen(color2, 1), point(rect.left(), y), point(rect.right(), y));
  }
  
  void draw_strings_with_color(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_string(regular_str, regular_font, solid_brush(color::red), point(50, 50));
    e.graphics().draw_string(italic_str, italic_font, solid_brush(color::green), point(50, 100));
    e.graphics().draw_string(bold_str, bold_font, solid_brush(color::blue), point(50, 150));

    e.graphics().draw_rotated_string(regular_str, regular_font, solid_brush(color::red), point(100, 250), 90);
    e.graphics().draw_rotated_string(italic_str, italic_font, solid_brush(color::green), point(150, 250), 90);
    e.graphics().draw_rotated_string(bold_str, bold_font, solid_brush(color::blue), point(200, 250), 90);

    e.graphics().draw_rotated_string(regular_str, regular_font, solid_brush(color::red), point(300, 250), 45);
    e.graphics().draw_rotated_string(italic_str, italic_font, solid_brush(color::green), point(350, 250), 45);
    e.graphics().draw_rotated_string(bold_str, bold_font, solid_brush(color::blue), point(400, 250), 45);
  }
  
  void draw_strings_with_linear_gradient(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());

    e.graphics().draw_string(regular_str, regular_font, linear_gradient_brush(point_f(50, 50), point_f(e.graphics().measure_string(regular_str, regular_font)), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}), point(50, 50));
    e.graphics().draw_string(italic_str, italic_font, linear_gradient_brush(point_f(50, 50), point_f(e.graphics().measure_string(italic_str, italic_font)), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}), point(50, 100));
    e.graphics().draw_string(bold_str, bold_font, linear_gradient_brush(point_f(50, 50), point_f(e.graphics().measure_string(bold_str, bold_font)), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}), point(50, 150));

    auto text_size = e.graphics().measure_string(regular_str, regular_font);
    e.graphics().draw_rotated_string(regular_str, regular_font, linear_gradient_brush(rectangle_f(point_f(100, 250), size_f(text_size.height(), text_size.width())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 90.0f), point(100, 250), 90);
    text_size = e.graphics().measure_string(italic_str, italic_font);
    e.graphics().draw_rotated_string(italic_str, italic_font, linear_gradient_brush(rectangle_f(point_f(150, 250), size_f(text_size.height(), text_size.width())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 90.0f), point(150, 250), 90);
    text_size = e.graphics().measure_string(bold_str, bold_font);
    e.graphics().draw_rotated_string(bold_str, bold_font, linear_gradient_brush(rectangle_f(point_f(200, 250), size_f(text_size.height(), text_size.width())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 90.0f), point(200, 250), 90);

    text_size = size_f(300.0f, 300.0f);
    e.graphics().draw_rotated_string(regular_str, regular_font, linear_gradient_brush(rectangle_f(point_f(300, 250), size_f(text_size.width(), text_size.height())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 45.0f), point(300, 250), 45);
    text_size = size_f(260.0f, 260.0f);
    e.graphics().draw_rotated_string(italic_str, italic_font, linear_gradient_brush(rectangle_f(point_f(350, 250), size_f(text_size.width(), text_size.height())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 45.0f), point(350, 250), 45);
    text_size = size_f(240.0f, 240.0f);
    e.graphics().draw_rotated_string(bold_str, bold_font, linear_gradient_brush(rectangle_f(point_f(400, 250), size_f(text_size.width(), text_size.height())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 45.0f), point(400, 250), 45);
  }
  
  void draw_strings_hot_key_prefix(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_string("&No hotkey prefix", regular_font, solid_brush(color::red), point(50, 50), string_format().hotkey_prefix(xtd::drawing::hotkey_prefix::none));
    e.graphics().draw_string("&Show hotkey prefix", regular_font, solid_brush(color::red), point(50, 100), string_format().hotkey_prefix(xtd::drawing::hotkey_prefix::show));
    e.graphics().draw_string("&Hide hotkey prefix", regular_font, solid_brush(color::red), point(50, 150), string_format().hotkey_prefix(xtd::drawing::hotkey_prefix::hide));
  }
  
  void draw_strings_multilines(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    const xtd::drawing::font font = xtd::drawing::font(system_fonts::default_font(), 16, font_style::regular);
    e.graphics().draw_string("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nSed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec,\nultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a,\nsemper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie,\nenim est eleifend mi, non fermentum diam nisl sit amet erat.", font, solid_brush(system_colors::highlight_text()), point(50, 50));
    e.graphics().draw_string("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nSed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec,\nultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a,\nsemper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie,\nenim est eleifend mi, non fermentum diam nisl sit amet erat.", font, solid_brush(system_colors::highlight_text()), point(50, 250), string_format().alignment(xtd::drawing::string_alignment::center));
    e.graphics().draw_string("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nSed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec,\nultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a,\nsemper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie,\nenim est eleifend mi, non fermentum diam nisl sit amet erat.", font, solid_brush(system_colors::highlight_text()), point(50, 450), string_format().alignment(xtd::drawing::string_alignment::far));
  }
};

startup_(strings_form);

