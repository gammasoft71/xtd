#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("form1");
    location({300, 200});
    size({640, 480});
    form_closing += [](const control& sender, form_closing_event_args& e) {
      e.cancel(message_box::show("Are you sure you want exit?", "Close Form", message_box_buttons::yes_no, message_box_icon::question) == dialog_result::no);
    };
    
    button.parent(*this);
    button.text("Close");
    button.location({10, 10});
    button.click += [this](const control& sender, const event_args& e) {
      close();
    };
  }
private:
  forms::button button;
};

int main() {
  application::run(form1());
}
