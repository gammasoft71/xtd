#define TRACE
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/trace_form>
#include <xtd/ctrace>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Key events example");
    
    control1.dock(dock_style::fill);
    control1.parent(*this);
    
    control1.key_down += [&](object & sender, key_event_args & e) {
      ctrace << ustring::format("key_down={{key_code={}, key_data=[{}], value=0x{:X4}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()) << endl;
    };
    
    control1.key_press += [&](object & sender, key_press_event_args & e) {
      ctrace << ustring::format("key_press={{key_char={}}}", e.key_char() == 0 ? "[none]" : ustring::format("'{}'", e.key_char())) << endl;
    };
    
    control1.key_up += [&](object & sender, key_event_args & e) {
      ctrace << ustring::format("key_up={{key_code={}, key_data=[{}], value=0x{:X4}, modifiers=[{}]}}", e.key_code(), e.key_data(), e.key_value(), e.modifiers()) << endl;
      if (e.modifiers() == keys::none) ctrace << endl;
    };
  }
  
private:
  control control1;
};

auto main() -> int {
  trace_form trace_form;
  application::run(form1 {});
}
