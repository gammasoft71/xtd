#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Input box example");
      controls().push_back_range({button1, label1});

      button1.location({10, 10});
      button1.text("Text...");
      button1.click += [&] {
        input_box input_box;
        input_box.caption("Caption text");
        input_box.text("Message text");
        input_box.value(label1.text());
        if (input_box.show_dialog() == dialog_result::ok)
          label1.text(input_box.value());
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

int main() {
  application::run(examples::form1());
}
