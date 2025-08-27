#include <xtd/xtd>

namespace control_example {
  class form1 : public form {
  public:
    form1() {
      text("Control example");
      
      control1.parent(*this);
      control1.cursor(cursors::hand());
      control1.back_color(colors::spring_green());
      control1.location({50, 50});
      control1.size({100, 50});
      control1.click += delegate_ {
        control1.back_color(control1.back_color() == colors::spring_green() ? colors::orange_red() : colors::spring_green());
      };
    }
    
  private:
    control control1;
  };
}

auto main() -> int {
  application::run(control_example::form1 {});
}
