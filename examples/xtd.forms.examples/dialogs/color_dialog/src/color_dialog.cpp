#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Color dialog example");
    
    button1.click += [&] {
      auto dialog = color_dialog {};
      dialog.color(selected_color);
      dialog.custom_colors(custom_colors);
      if (dialog.show_dialog(*this) == forms::dialog_result::ok) {
        selected_color = dialog.color();
        color_label.text(color_translator::to_html(selected_color));
        test_zone.invalidate();
      }
      custom_colors = dialog.custom_colors();
    };

    test_zone.border_style(border_style::inset).double_buffered(true);
    test_zone.paint += [&](object& sender, paint_event_args& e) {
      e.graphics().fill_rectangle(drawing_2d::hatch_brush {drawing_2d::hatch_style::wide_checker_board, color::from_argb(0x66, 0x66, 0x66), color::from_argb(0x99, 0x99, 0x99)}, e.clip_rectangle());
      e.graphics().fill_rectangle(solid_brush {selected_color}, e.clip_rectangle());
      control_paint::draw_border(test_zone, e.graphics(), test_zone.border_style(), test_zone.border_sides(), application::style_sheet().system_colors().control_text(), rectangle::add(e.clip_rectangle(), -1, -1));
    };
    
    color_label.auto_size(true);
  }
  
private:
  color selected_color = system_colors::control();
  color_dialog::colors custom_colors = {color::red, color::green, color::blue, color::yellow, system_colors::control()};
  button button1 = button::create(*this, "Color...", {10, 10});
  panel test_zone = panel::create(*this, {10, 50});
  label color_label = label::create(*this, color_translator::to_html(selected_color), {10, 160});
};

auto main() -> int {
  application::run(form1 {});
}
