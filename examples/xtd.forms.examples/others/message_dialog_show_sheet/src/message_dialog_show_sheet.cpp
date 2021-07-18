#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    controls().push_back_range({button_show_message, label_dialog_result});
    location({400, 200});
    start_position(form_start_position::manual);
    text("Message dialog (show sheet) exemple");

    button_show_message.location({10, 10});
    button_show_message.text("Message...");
    button_show_message.width(100);
    button_show_message.click += [&] {
      std::shared_ptr<message_dialog> dialog = std::make_shared<message_dialog>();
      dialog->text("Message");
      dialog->message("Hello, World!");
      dialog->buttons(xtd::forms::message_dialog_buttons::ok_cancel);
      dialog->icon(xtd::forms::message_dialog_icon::warning);
      dialog->dialog_closed += [this, dialog](component& sender, const dialog_closed_event_args& e) {
        label_dialog_result.text(strings::format("dialog_result = {}", e.dialog_result()));
      };
      dialog->show_sheet(*this);
    };
    
    label_dialog_result.location({10, 45});
    label_dialog_result.width(200);
    
  }
  
private:
  button button_show_message;
  label label_dialog_result;
};

int main() {
  application::run(form1());
}
