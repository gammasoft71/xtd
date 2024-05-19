#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/message_dialog>

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
      label_dialog_result.text("");
      dialog.show_sheet(*this);
    };
    
    label_dialog_result.location({10, 45});
    label_dialog_result.width(200);

    dialog.text("Message");
    dialog.message("Hello, World!");
    dialog.buttons(xtd::forms::message_dialog_buttons::ok_cancel);
    dialog.icon(xtd::forms::message_dialog_icon::warning);
    dialog.dialog_closed += [&](object & sender, const dialog_closed_event_args & e) {
      label_dialog_result.text(ustring::format("dialog_result = {}", e.dialog_result()));
    };
  }
  
private:
  button button_show_message;
  label label_dialog_result;
  message_dialog dialog;
};

auto main() -> int {
  application::run(form1 {});
}
