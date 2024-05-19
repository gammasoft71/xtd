#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/text_box>

using namespace xtd::forms;

namespace text_box_password_example {
  class form1 : public form {
  public:
    form1() {
      text("Text box password example");
      *this << text_box1 << label1;
      active_control(text_box1);
      
      text_box1.location({10, 10});
      text_box1.use_system_password_char(true);
      text_box1.text_changed += [&] {
        label1.text(text_box1.text());
      };
      text_box1.text("123456");
      
      label1.location({10, 50});
      label1.auto_size(true);
    }
    
  private:
    text_box text_box1;
    label label1;
  };
}

auto main() -> int {
  application::run(text_box_password_example::form1 {});
}
