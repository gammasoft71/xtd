#define TRACE
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Form and Messages");
    key_down += [&](control& sender, key_event_args& e) {
      ctrace << format("key_down {{key_code={}, key_data={}, value={}, modifiers={}}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()) << endl;
    };
    key_press += [&](control& sender, key_press_event_args& e) {
      ctrace << format("key_press {{key_char={}}}", e.key_char()) << endl;
    };
    key_up += [&](control& sender, key_event_args& e) {
      ctrace << format("key_up {{key_code={}, key_data={}, value={}, modifiers={}}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()) << endl;
    };
  }
};

int main() {
  application::run(form1());
}
