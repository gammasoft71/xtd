#include <xtd/xtd>

class main_form : public form {
public:
  main_form() {
    text("Hello world (message_box)");
    
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("&Click me");
    button1.click += delegate_ {
      message_box::show("Hello, World!");
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  application::run(main_form {});
}
