#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms;

class form_main : public form {
public:
  form_main() {
    client_size({300, 300});

    panel_.parent(*this);
    panel_.dock(dock_style::fill);
    panel_.paint += [&](control& sender, paint_event_args& e) {
      e.graphics().draw_rectangle(pen(color::black, 1), 10, 10, 20, 20);
      e.graphics().draw_rectangle(pen(color::black, 1), 12, 12, 16, 16);

      e.graphics().fill_rectangle(solid_brush(color::black), 10, 40, 20, 20);
      e.graphics().fill_rectangle(solid_brush(color::white), 12, 42, 16, 16);
    };
  }

  static void main() {
    xtd::forms::application::run(form_main());
  }

  panel panel_;
};

startup_(form_main);