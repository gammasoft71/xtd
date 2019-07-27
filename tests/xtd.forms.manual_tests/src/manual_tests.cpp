#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;
using namespace xtd::diagnostics;

class form1 : public form {
public:
  form1() {
    this->name("form1");
    this->text("form1");
    this->form_closing += [&](const control& sender, form_closing_event_args& e) {
      e.cancel(message_box::show(*this, "Close form ?", "form1", message_box_buttons::yes_no, message_box_icon::none) == dialog_result::no);
    };
    
    button_close.parent(*this);
    button_close.name("close");
    button_close.text("close");
    button_close.location({10, 10});
    button_close.click += [&](const control& sender, const event_args& e) {
      this->close();
    };
  }
  
private:
  button button_close;
};

// The main entry point for the application.
int main() {
  application::run(form1());
}
