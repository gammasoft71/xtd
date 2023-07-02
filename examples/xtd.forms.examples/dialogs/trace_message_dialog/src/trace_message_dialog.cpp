#define TRACE
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    button_show_debug_message.location({10, 10});
    button_show_debug_message.parent(*this);
    button_show_debug_message.text("Error...");
    button_show_debug_message.auto_size(true);
    button_show_debug_message.click += [&] {
      auto dialog = trace_message_dialog {};
      dialog.message("An unknown process error occured.");
      dialog.show_sheet_dialog(*this);
    };
  }
  
private:
  button button_show_debug_message;
};

auto main()->int {
  trace_form trace_form;
  application::run(form1 {});
}
