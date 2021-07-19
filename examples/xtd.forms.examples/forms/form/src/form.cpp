#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("form1");
    location({300, 200});
    size({640, 480});

    button_close.parent(*this);
    button_close.text("Close");
    button_close.auto_size(true);
    button_close.location({10, 10});
    button_close.click += event_handler(*this, &form::close);
    
    button_exit.parent(*this);
    button_exit.text("Exit");
    button_exit.auto_size(true);
    button_exit.location({100, 10});
    button_exit.click += overload_<>(&application::exit);
    
    button_exit_thread.parent(*this);
    button_exit_thread.text("Exit thread");
    button_exit_thread.auto_size(true);
    button_exit_thread.location({190, 10});
    button_exit_thread.click += &application::exit_thread;
  }

protected:
  void on_form_closing(form_closing_event_args& e) override {
    e.cancel(message_box::show(*this, "Are you sure you want exit?", "Close Form", message_box_buttons::yes_no, message_box_icon::question) == dialog_result::no);
  };

private:
  forms::button button_close;
  forms::button button_exit;
  forms::button button_exit_thread;
};

int main() {
  application::run(form1());
}
