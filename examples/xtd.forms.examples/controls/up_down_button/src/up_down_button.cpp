#include <xtd/xtd>

namespace up_down_button_example {
  class form1 : public form {
  public:
    form1() {
      text("Up down button example");
      
      up_down_button1.parent(*this);
      up_down_button1.location({10, 10});
      up_down_button1.value_changed += delegate_ {
        label1.text(string::format("value = {}", up_down_button1.value()));
      };
      up_down_button1.minimum(10);
      up_down_button1.maximum(20);
      up_down_button1.value(15);
      up_down_button1.wrapped(true);
      
      label1.parent(*this);
      label1.location({10, 50});
    }
    
  private:
    up_down_button up_down_button1;
    label label1;
  };
}

auto main() -> int {
  application::run(up_down_button_example::form1 {});
}
