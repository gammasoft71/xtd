#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->controls().push_back_range({this->button_show_message, this->label_dialog_result});
    this->location({400, 200});
    this->start_position(form_start_position::manual);
    this->text("Message box exemple");

    this->button_show_message.location({10, 10});
    this->button_show_message.text("Message box");
    this->button_show_message.width(100);
    this->button_show_message.click += [&] {
      forms::dialog_result result = message_box::show("Hello, World!", "Message", message_box_buttons::ok_cancel, message_box_icon::asterisk);
      label_dialog_result.text(strings::format("DialogResult = {}", result));
    };
    
    this->label_dialog_result.location({10, 45});
    this->label_dialog_result.width(200);
  }
  
private:
  button button_show_message;
  label label_dialog_result;
};

int main() {
  application::run(form1());
}
