#include <xtd/xtd>

namespace tutorial {
  class simple : public xtd::forms::form {
  public:
    simple() {
      text("Simple");
      start_position(xtd::forms::form_start_position::center_screen);
    }
    
    static auto main() {
      xtd::forms::application::run(simple());
    }
  };
}

startup_(tutorial::simple::main);
