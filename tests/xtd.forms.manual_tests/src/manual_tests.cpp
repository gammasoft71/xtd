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
    //this->enabled(false);

    this->key_down += [&](const control& sender, key_event_args& e) {
      debug::write_line(strings::format("key_down [key_code={}, key_data={}, key_value={}]", e.key_code(), e.key_data(), e.key_value()));
    };

    this->key_press += [&](const control& sender, key_press_event_args& e) {
      debug::write_line(strings::format("key_press [key_char={}]", static_cast<char>(e.key_char())));
    };

    this->key_up += [&](const control& sender, key_event_args& e) {
      debug::write_line(strings::format("key_up [key_code={}, key_data={}, key_value={}]", e.key_code(), e.key_data(), e.key_value()));
    };
  }

  /*
protected:
  void wnd_proc(xtd::forms::message& message) override {
    this->form::wnd_proc(message);

    switch (message.msg()) {
    case WM_CHAR: debug::write_line(xtd::strings::format("WM_CHAR [char={}, repeat={}]", static_cast<char>(message.wparam()), message.lparam())); break;
    case WM_KEYDOWN: debug::write_line(xtd::strings::format("WM_KEYDOWN [key={}, repeat={}]", static_cast<key>(message.wparam()), message.lparam())); break;
    case WM_KEYUP: debug::write_line(xtd::strings::format("WM_KEYUP [key={}, repeat={}]", static_cast<key>(message.wparam()), message.lparam())); break;
    }
  }
  */
};

// The main entry point for the application.
int main() {
  application::run(form1());
}
