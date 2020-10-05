#define TRACE 1
#include <xtd/xtd.forms>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Key events example");
    
    key_down += [&](control& sender, key_event_args& e) {
      xtd::diagnostics::trace::write_line("key_down={{key_code={}, key_data=[{}], value=0x{:X4}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers());
    };

    key_press += [&](control& sender, key_press_event_args& e) {
      xtd::diagnostics::trace::write_line("key_press={{key_char={}}}", e.key_char() == 0 ? "[none]" : xtd::strings::format("'{}'", e.key_char()));
    };

    key_up += [&](control& sender, key_event_args& e) {
      xtd::diagnostics::trace::write_line("key_up={{key_code={}, key_data=[{}], value=0x{:X4}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers());
      if (e.modifiers() == keys::none) xtd::diagnostics::trace::write_line();
    };
  }
  
private:
  trace_form trace_form_;
};

int main() {
  application::run(form1());
}
