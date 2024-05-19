#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/input_box>
#include <xtd/forms/label>

using namespace xtd::forms;

namespace input_box_example {
  class form1 : public form {
  public:
    form1() {
      text("Input box example");
      controls().push_back_range({button1, label1});
      
      button1.location({10, 10});
      button1.text("Text...");
      button1.click += [&] {
        auto value = label1.text();
        if (input_box::show(value, *this, "Message text", "Caption text") == dialog_result::ok)
          label1.text(value);
      };
      
      label1.location({10, 50});
      label1.auto_size(true);
      label1.text("Default value");
    }
    
  private:
    button button1;
    label label1;
  };
}

auto main() -> int {
  application::run(input_box_example::form1 {});
}
