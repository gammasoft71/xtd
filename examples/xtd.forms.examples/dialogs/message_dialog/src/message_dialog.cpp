#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    controls().push_back_range({button_show_message, label_dialog_result});
    location({400, 200});
    start_position(form_start_position::manual);
    text("Message dialog exemple");
    
    button_show_message.location({10, 10});
    button_show_message.text("Message...");
    button_show_message.width(100);
    button_show_message.click += delegate_ {
      auto dialog = message_dialog {};
      dialog.buttons(message_dialog_buttons::ok_cancel);
      dialog.icon(message_dialog_icon::warning);
      dialog.message("Hello, World!");
      dialog.text("Message");
      label_dialog_result.text(string::format("dialog_result = {}", dialog.show_sheet_dialog(*this)));
    };
    
    label_dialog_result.location({10, 55});
    label_dialog_result.width(200);
  }
  
private:
  button button_show_message;
  label label_dialog_result;
};

auto main() -> int {
  application::run(form1 {});
}
