#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Input dialog multiline example");
      controls().push_back_range({button1, label1});

      button1.location({10, 10});
      button1.auto_size(true);
      button1.text("Lines...");
      button1.click += [&] {
        input_dialog input_dialog;
        input_dialog.text("Enter lines");
        input_dialog.multiline(true);
        input_dialog.value("line 1\nline 2");
        input_dialog.dialog_style(xtd::forms::dialog_style::system);
        if (input_dialog.show_dialog() == dialog_result::ok)
          label1.text(input_dialog.value());
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
