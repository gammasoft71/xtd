#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace tutorial {
  class simple : public form {
  public:
    simple() {
      text("Simple");
      start_position(form_start_position::center_screen);
    }

    static void main() {
      xtd::forms::application::run(simple());
    }
  };
}

startup_(tutorial::simple);
