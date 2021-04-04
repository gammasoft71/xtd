#define DEBUG // Force debug mode even if example is builded in release.
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Enable debug example");
    name("form1");

    button1.auto_repeat(true);
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("click-me");
    button1.name("button1");

    text_box1.location({10, 50});
    text_box1.parent(*this);
    text_box1.text("Text box");
    text_box1.name("text_box1");
  }
  
private:
  button button1;
  text_box text_box1;
};

int main() {
  debug_form debug_form;
  enable_debug::trace_switch().level(xtd::diagnostics::trace_level::verbose);
  enable_debug::set(enable_debug::key_events|enable_debug::mouse_events, true);
  application::run(form1());
}
