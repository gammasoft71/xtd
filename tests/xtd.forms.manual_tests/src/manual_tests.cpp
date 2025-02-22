#include <xtd/xtd>

namespace xtd::tests {
  class form1 : public form {
  public:
    static auto main() {
      application::system_controls(true);
      application::run(form1 {});
    }
    
    form1() {
      text("form1");
      button1.click += [&] {message_box::show(*this, "Hello, World! !");};
    }
    
  private:
    button button1 = button::create(*this, "button1", {10, 10});
  };
}

startup_(tests::form1::main);
