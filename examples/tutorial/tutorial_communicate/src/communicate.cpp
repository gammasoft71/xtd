#include <xtd/xtd.forms>

namespace tutorial {
  class communicate : public xtd::forms::form {
  public:
    simple() {
      text("communicate");
      start_position(xtd::forms::form_start_position::center_screen);
    }

    static void main() {
      xtd::forms::application::run(communicate());
    }
  };
}

startup_(tutorial::communicate);
