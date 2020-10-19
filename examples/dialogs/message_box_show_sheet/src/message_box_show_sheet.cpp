#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    controls().push_back_range({button_show_message, label_dialog_result});
    location({400, 200});
    start_position(form_start_position::manual);
    text("Message box (show sheet) exemple");

    button_show_message.location({10, 10});
    button_show_message.text("Message box");
    button_show_message.width(100);
    button_show_message.click += [&] {
      message_box::show_sheet(*this, "Hello, World!", "Message", message_box_buttons::ok_cancel, message_box_icon::asterisk);
    };
    
    label_dialog_result.location({10, 45});
    label_dialog_result.width(200);
    
    message_box::message_box_closed += [&](const message_box_closed_event_args& e) {
      label_dialog_result.text(strings::format("dialog_result = {}", e.dialog_result()));
    };
  }
  
private:
  button button_show_message;
  label label_dialog_result;
};

int main() {
  application::run(form1());
}
