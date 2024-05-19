#include <xtd/drawing/drawing_2d/hatch_brush>
#include <xtd/drawing/color_translator>
#include <xtd/forms/application>
#include <xtd/forms/color_picker>
#include <xtd/forms/control_paint>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/panel>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

namespace color_picker_example {
  class form1 : public form {
  public:
    form1() {
      text("Color picker example");
      
      color_picker.parent(*this);
      color_picker.alpha_color(true);
      color_picker.location({10, 10});
      color_picker.color_picker_changed += [&](object& sender, const color_picker_event_args& e) {
        test_zone.invalidate();
        color_label.text(color_translator::to_html(e.color()));
      };
      color_picker.color(color::red);

      test_zone.parent(*this);
      test_zone.location({10, 50});
      test_zone.border_style(border_style::fixed_3d);
      test_zone.double_buffered(true);
      test_zone.paint += [&](object& sender, paint_event_args& e) {
        e.graphics().fill_rectangle(hatch_brush {hatch_style::wide_checker_board, color::from_argb(0x66, 0x66, 0x66), color::from_argb(0x99, 0x99, 0x99)}, e.clip_rectangle());
        e.graphics().fill_rectangle(solid_brush {color_picker.color()}, e.clip_rectangle());
        control_paint::draw_border(test_zone, e.graphics(), test_zone.border_style(), test_zone.border_sides(), application::style_sheet().system_colors().control_text(), e.clip_rectangle());
      };
      
      color_label.parent(*this);
      color_label.auto_size(true);
      color_label.location({10, 160});
    }
    
  private:
    forms::color_picker color_picker;
    panel test_zone;
    label color_label;
  };
}

auto main() -> int {
  application::run(color_picker_example::form1 {});
}
