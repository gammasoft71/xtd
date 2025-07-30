#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Busy box example");
    
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Do something...");
    button1.click += [] {
      busy_box::show("Please wait while do something...", "Application busy");
      for (auto count = 0; count < 500; ++count) {
        application::do_events();
        thread::sleep(10);
      }
      busy_box::hide();
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  xtd::forms::application::run(form1 {});
}
