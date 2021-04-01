#define DEBUG // Force debug mode even if example is builded in release.
#include <xtd/xtd>

using namespace xtd::diagnostics;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Debug form example");

    write_debug_button.auto_repeat(true);
    write_debug_button.auto_size(true);
    write_debug_button.location({10, 10});
    write_debug_button.parent(*this);
    write_debug_button.text("Write line...");
    write_debug_button.click += [&] {
      static int counter = 0;
      debug::write_line("Write line {}...", ++counter);
    };
  }
  
private:
  button write_debug_button;
};

int main() {
  debug_form debug_form;
  application::run(form1());
}
