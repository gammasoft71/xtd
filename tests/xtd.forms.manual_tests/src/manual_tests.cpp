#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::diagnostics;

using key = int;

class form1 : public form {
public:
  form1() {
    this->name("form1");
    this->text("form1");
    this->location({100, 100});

    this->key_down += [&](const control& sender, key_event_args& e) {
      debug::write_line(strings::format("key_down [key_code={}, key_data={}, key_value={}]", e.key_code(), e.key_data(), e.key_value()));
    };

    this->key_press += [&](const control& sender, key_press_event_args& e) {
      debug::write_line(strings::format("key_press [key_char={}]", e.key_char()));
    };

    this->key_up += [&](const control& sender, key_event_args& e) {
      debug::write_line(strings::format("key_up [key_code={}, key_data={}, key_value={}]", e.key_code(), e.key_data(), e.key_value()));
    };
  }
};

// The main entry point for the application.
int main() {
  application::run(form1());
}
