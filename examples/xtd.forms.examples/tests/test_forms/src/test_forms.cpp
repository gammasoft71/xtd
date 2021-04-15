#include <xtd/xtd>

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
      e.graphics().draw_image(system_images::from_name("gammasoft", drawing::size {2048, 2048}), e.clip_rectangle());
      /*
      e.graphics().clear(colors::light_blue());
      e.graphics().draw_rectangle(pens::black(), 10, 10, 20, 20);
      e.graphics().draw_rectangle(pens::white(), 12, 12, 16, 16);

      e.graphics().draw_rectangle(pens::black(), 40, 10, 20, 20);
      e.graphics().draw_ellipse(pens::white(), 42, 12, 16, 16);

      e.graphics().fill_rectangle(brushes::black(), 10, 40, 20, 20);
      e.graphics().fill_rectangle(brushes::white(), 12, 42, 16, 16);

      e.graphics().fill_rectangle(brushes::black(), 40, 40, 20, 20);
      e.graphics().fill_ellipse(brushes::white(), 42, 42, 16, 16);
       */
    };
  }

  static void main() {
    xtd::forms::application::run(form_main());
  }
private:
  panel panel_;
};

startup_(form_main);
