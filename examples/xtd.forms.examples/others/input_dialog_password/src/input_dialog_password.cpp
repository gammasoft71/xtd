#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/input_dialog>
#include <xtd/forms/label>

using namespace xtd;
using namespace xtd::forms;

namespace input_dialog_password_example {
  class form1 : public form {
  public:
    form1() {
      text("Input dialog password example");
      controls().push_back_range({button1, label1});
      
      button1.location({10, 10});
      button1.auto_size(true);
      button1.text("Password...");
      button1.click += delegate_ {
        input_dialog input_dialog;
        input_dialog.text("User password");
        input_dialog.message("user: admin");
        input_dialog.use_system_password_char(true);
        input_dialog.value(label1.text());
        if (input_dialog.show_sheet_dialog(*this) == dialog_result::ok)
          label1.text(input_dialog.value());
      };
      
      label1.location({10, 50});
      label1.auto_size(true);
      label1.text("sysad47@74dasys");
    }
    
  private:
    button button1;
    label label1;
  };
}

auto main() -> int {
  application::run(input_dialog_password_example::form1 {});
}
