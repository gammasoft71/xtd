#include <xtd/drawing/drawing_2d/hatch_brush>
#include <xtd/drawing/color_translator>
#include <xtd/drawing/system_colors>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/color_dialog>
#include <xtd/forms/control_paint>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/panel>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

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
      e.graphics().fill_rectangle(hatch_brush {hatch_style::wide_checker_board, color::from_argb(0x66, 0x66, 0x66), color::from_argb(0x99, 0x99, 0x99)}, e.clip_rectangle());
      e.graphics().fill_rectangle(solid_brush {selected_color}, e.clip_rectangle());
      control_paint::draw_border(test_zone, e.graphics(), test_zone.border_style(), test_zone.border_sides(), application::style_sheet().system_colors().control_text(), e.clip_rectangle());
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
