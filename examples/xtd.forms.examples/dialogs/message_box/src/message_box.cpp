#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/message_box>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    controls().push_back_range({button_show_message, label_dialog_result});
    location({400, 200});
    start_position(form_start_position::manual);
    text("Message box exemple");
    
    button_show_message.location({10, 10});
    button_show_message.text("Message...");
    button_show_message.width(100);
    button_show_message.click += [&] {
      auto result = message_box::show(*this, "Hello, World!", "Message", message_box_buttons::ok_cancel, message_box_icon::warning);
      label_dialog_result.text(ustring::format("dialog_result = {}", result));
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
