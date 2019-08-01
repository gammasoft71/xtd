#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("form1");
    this->location({300, 200});
    this->size({640, 480});
    this->form_closing += [](const control& sender, form_closing_event_args& e) {
      e.cancel(message_box::show("Are you sure you want exit?", "Close Form", message_box_buttons::yes_no, message_box_icon::question) == dialog_result::no);
    };
    
    this->button.parent(*this);
    this->button.text("Close");
    this->button.location({10, 10});
    this->button.click += [&](const control& sender, const event_args& e) {
      this->close();
    };
  }
private:
  button button;
};

int main() {
  application::run(form1());
}
