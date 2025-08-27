#include <xtd/xtd>

namespace input_dialog_multiline_example {
  class form1 : public form {
  public:
    form1() {
      auto_scroll(true);
      text("Input dialog multiline example");
      controls().push_back_range({button1, label1});
      
      button1.location({10, 10});
      button1.auto_size(true);
      button1.text("Lines...");
      button1.click += delegate_ {
        input_dialog input_dialog;
        input_dialog.multiline(true);
        input_dialog.word_wrap(false);
        input_dialog.text("Enter lines");
        input_dialog.value(label1.text());
        if (input_dialog.show_dialog(*this) == dialog_result::ok)
          label1.text(input_dialog.value());
      };
      
      label1.location({10, 50});
      label1.auto_size(true);
      label1.text("line 1\nline 2");
    }
    
  private:
    button button1;
    label label1;
  };
}

auto main() -> int {
  application::run(input_dialog_multiline_example::form1 {});
}
