#define DEBUG // Force debug mode even if example is builded in release.
#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    button_show_debug_message.location({10, 10});
    button_show_debug_message.parent(*this);
    button_show_debug_message.text("Error...");
    button_show_debug_message.auto_size(true);
    button_show_debug_message.click += delegate_ {
      auto dialog = debug_message_dialog {};
      dialog.message("An unknown process error occured.");
      dialog.show_sheet_dialog(*this);
    };
  }
  
private:
  button button_show_debug_message;
};

auto main() -> int {
  auto df = debug_form {};
  application::run(form1 {});
}
