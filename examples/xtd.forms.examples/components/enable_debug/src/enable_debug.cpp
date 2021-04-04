#define DEBUG // Force debug mode even if example is builded in release.
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Enable debug example");

    button1.auto_repeat(true);
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("click-me");
  }
  
private:
  button button1;
};

int main() {
  debug_form debug_form;
  enable_debug::trace_switch().level(xtd::diagnostics::trace_level::verbose);
  enable_debug::set(enable_debug::all, true);
  application::run(form1());
}
