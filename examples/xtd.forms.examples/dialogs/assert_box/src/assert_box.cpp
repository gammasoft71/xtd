#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Assert box example");
    controls().add(button1);
    
    button1.location({10, 10});
    button1.auto_size(true);
    button1.text("assert...");
    button1.click += delegate_ {
      switch(assert_box::show(*this, "Index must be > 0", diagnostics::stack_frame::current())) {
        case forms::dialog_result::abort: application::exit(); break;
        case forms::dialog_result::retry: diagnostics::debugger::debug_break(); break;
        default: break;
      }
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  application::run(form1 {});
}
