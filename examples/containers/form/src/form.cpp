#include <xtd/xtd.forms>

using namespace std;
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

    button_close.parent(*this);
    button_close.text("Close");
    button_close.location({10, 10});
    button_close.click += {*this, &form::close};
    
    button_exit.parent(*this);
    button_exit.text("Exit");
    button_exit.location({100, 10});
    button_exit.click += overload<>::of(&application::exit);
  }
  
private:
  forms::button button_close;
  forms::button button_exit;
};

int main() {
  application::run(form1());
}
