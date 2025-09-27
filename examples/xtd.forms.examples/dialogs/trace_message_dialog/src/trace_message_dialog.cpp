#define TRACE // Force to trace even if example is builded with -DNTRACE.
#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    button_show_debug_message.location({10, 10});
    button_show_debug_message.parent(*this);
    button_show_debug_message.text("Error...");
    button_show_debug_message.auto_size(true);
    button_show_debug_message.click += delegate_ {
      auto dialog = trace_message_dialog {};
      dialog.message("An unknown process error occured.");
      dialog.show_sheet_dialog(*this);
    };
  }
  
private:
  button button_show_debug_message;
};

auto main() -> int {
  auto tf = trace_form {};
  application::run(form1 {});
}
