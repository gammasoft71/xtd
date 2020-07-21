#include <xtd/xtd.forms>

namespace tutorial {
  class form_icon : public xtd::forms::form {
  public:
    form_icon() {
      text("Icon");
      start_position(xtd::forms::form_start_position::center_screen);
    }

    static void main() {
      xtd::forms::application::run(form_icon());
    }
  };
}

startup_(tutorial::form_icon);
