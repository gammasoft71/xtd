#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("My first application");
      client_size({300, 300});

      paint += [&](control& sender, paint_event_args& e) {
        e.graphics().draw_string("Hello World!", {font(), 32, font_style::bold | font_style::italic}, xtd::drawing::solid_brush(color::blue), e.clip_rectangle(), xtd::drawing::string_format().alignment(xtd::drawing::string_alignment::center).line_alignment(xtd::drawing::string_alignment::center));
      };
    }
  };
}

int main() {
  application::run(examples::form1());
}
