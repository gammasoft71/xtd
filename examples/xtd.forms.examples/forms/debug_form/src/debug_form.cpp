#define DEBUG // Force debug mode even if example is builded in release.
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Debug form example");

    button1.auto_repeat(true);
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Write line...");
    button1.click += [&] {
      static int counter = 0;
      xtd::diagnostics::debug::write_line("Write line {}...", ++counter);
    };
  }
  
private:
  button button1;
};

int main() {
  debug_form debug_form;
  debug_form.back_color(xtd::drawing::color::black);
  debug_form.fore_color(xtd::drawing::color::lime);
  
  application::run(form1());
}
