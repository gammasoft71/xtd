#include <xtd/xtd>

using namespace xtd::forms;

class main_form : public form {
public:
  main_form() {
    text("Hello world (message_box)");

    button1.location({10, 10});
    button1.parent(*this);
    button1.text("&Click me");
    button1.click += [] {
      message_box::show("Hello, World!");
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(main_form());
}
