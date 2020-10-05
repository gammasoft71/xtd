#define TRACE 1
#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Key events example");
    
    key_down += [&](control& sender, key_event_args& e) {
      trace::write_line(strings::format("key_down={{key_code={}, key_data=[{}], value={}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()));
    };

    key_press += [&](control& sender, key_press_event_args& e) {
      trace::write_line(strings::format("key_press={{key_char={}}}", e.key_char() == 0 ? "[None]" : strings::format("{}", e.key_char())));
    };

    key_up += [&](control& sender, key_event_args& e) {
      trace::write_line(strings::format("key_up={{key_code={}, key_data=[{}], value={}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()));
      if (e.modifiers() == keys::none) trace::write_line();
    };
  }
  
private:
  trace_form trace_form_;
};

int main() {
  application::run(form1());
}
