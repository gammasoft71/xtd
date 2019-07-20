#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::diagnostics;

class numeric_text_box : public text_box {
public:
  numeric_text_box() {
    this->key_down += [&](const control& sender, key_event_args& e) {
      debug::write_line(strings::format("key_down [key_code={}, key_data={}, key_value={}, modifiers={}]", e.key_code(), e.key_data(), e.key_value(), e.modifiers()));
    };
    
    this->key_press += [&](const control& sender, key_press_event_args& e) {
      debug::write_line(strings::format("key_press [key_char={}]", e.key_char()));
      e.handled((!std::iscntrl(e.key_char()) && !std::isdigit(e.key_char()) && e.key_char() != '.') || (e.key_char() == '.' && this->text().find('.') != std::string::npos));
    };
    
    this->key_up += [&](const control& sender, key_event_args& e) {
      debug::write_line(strings::format("key_up [key_code={}, key_data={}, key_value={}, modifiers={}]", e.key_code(), e.key_data(), e.key_value(), e.modifiers()));
    };
    
    this->text_changed += [&](const control& sender, const event_args& e) {
      debug::write_line(strings::format("text_changed [text={}]", this->text()));
    };
  }
};

class form1 : public form {
public:
  form1() {
    this->name("form1");
    this->text("form1");
    
    this->text_box1.parent(*this);
    this->text_box1.name("text_box1");
    this->text_box1.text("0");
    this->text_box1.location({10, 10});
  }
  
private:
  numeric_text_box text_box1;
};

// The main entry point for the application.
int main() {
  keys k = keys::control + keys::alt + keys::del;
  cdebug << "keys=" << k << std::endl;
  application::run(form1());
}
