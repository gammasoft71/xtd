#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/input_dialog>
#include <xtd/forms/label>

using namespace xtd::forms;

namespace input_dialog_example {
  class form1 : public form {
  public:
    form1() {
      text("Input dialog example");
      controls().push_back_range({button1, label1});
      
      button1.location({10, 10});
      button1.text("Text...");
      button1.click += [&] {
        auto dialog = input_dialog {};
        dialog.text("Caption text");
        dialog.message("Message text");
        dialog.value(label1.text());
        if (dialog.show_sheet_dialog(*this) == dialog_result::ok)
          label1.text(dialog.value());
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
  application::run(input_dialog_example::form1 {});
}
