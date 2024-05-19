#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace hello_world_paint_example {
  class main_form : public form {
  public:
    main_form() {
      text("Hello world (paint)");
      client_size({300, 300});
      
      paint += [&](object& sender, paint_event_args& e) {
        e.graphics().clear(color::light_blue);
        e.graphics().draw_string("Hello, World!", {system_fonts::default_font(), 32, font_style::bold | font_style::italic}, solid_brush {color_converter::dark(color::light_blue)}, rectangle::offset(e.clip_rectangle(), {2, 2}), string_format().alignment(string_alignment::center).line_alignment(string_alignment::center));
        e.graphics().draw_string("Hello, World!", {system_fonts::default_font(), 32, font_style::bold | font_style::italic}, brushes::dark_blue(), rectangle::inflate(e.clip_rectangle(), {-2, -2}), string_format().alignment(string_alignment::center).line_alignment(string_alignment::center));
      };
    }
  };
}

auto main() -> int {
  application::run(hello_world_paint_example::main_form());
}
