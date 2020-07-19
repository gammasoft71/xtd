#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Input box password example");
      controls().push_back_range({button1, label1});

      button1.location({10, 10});
      button1.auto_size(true);
      button1.text("Password...");
      button1.click += [&] {
        input_box input_box;
        input_box.caption("User password");
        input_box.use_system_password_char(true);
        input_box.value(label1.text());
        if (input_box.show_dialog() == dialog_result::ok)
          label1.text(input_box.value());
      };

      label1.location({10, 50});
      label1.auto_size(true);
    }
    
  private:
    button button1;
    label label1;
  };
}

int main() {
  application::run(examples::form1());
}
