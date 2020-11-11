#define TRACE
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Key events example");
    
    key_down += [&](control& sender, key_event_args& e) {
      ctrace << format("key_down={{key_code={}, key_data=[{}], value=0x{:X4}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()) << endl;
    };
    
    key_press += [&](control& sender, key_press_event_args& e) {
      ctrace << format("key_press={{key_char={}}}", e.key_char() == 0 ? "[none]" : xtd::strings::format("'{}'", e.key_char())) << endl;
    };
    
    key_up += [&](control& sender, key_event_args& e) {
      ctrace << format("key_up={{key_code={}, key_data=[{}], value=0x{:X4}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()) << endl;
      if (e.modifiers() == keys::none) ctrace << endl;
    };
  }
};

int main() {
  trace_form trace;
  application::run(form1());
}
