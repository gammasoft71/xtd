#define TRACE
#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Key events example");
    
    control1.dock(dock_style::fill);
    control1.parent(*this);
    
    control1.key_down += delegate_(object & sender, key_event_args & e) {
      ctrace << string::format("key_down={{key_code={}, key_data=[{}], value=0x{:X4}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()) << environment::new_line;
    };
    
    control1.key_press += delegate_(object & sender, key_press_event_args & e) {
      ctrace << string::format("key_press={{key_char={}}}", e.key_char() == 0 ? "[none]" : string::format("'{}'", e.key_char())) << environment::new_line;
    };
    
    control1.key_up += delegate_(object & sender, key_event_args & e) {
      ctrace << string::format("key_up={{key_code={}, key_data=[{}], value=0x{:X4}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()) << environment::new_line;
      if (e.modifiers() == keys::none) ctrace << environment::new_line;
    };
  }
  
private:
  control control1;
};

auto main() -> int {
  trace_form trace_form;
  application::run(form1 {});
}
