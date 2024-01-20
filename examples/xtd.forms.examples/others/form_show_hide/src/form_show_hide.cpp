#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/check_box>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({320, 325});
    controls().push_back_range({close_button, show_button, hide_button, cancel_close_check_box});
    text("Form shaw and hide example");
    
    close_button.location({10, 10});
    close_button.size({100, 40});
    close_button.text("Close");
    close_button.click += [&] {
      form2.close();
    };
    
    show_button.location({10, 60});
    show_button.size({100, 40});
    show_button.text("Show");
    show_button.click += [&] {
      form2.show();
    };
    
    hide_button.location({10, 110});
    hide_button.size({100, 40});
    hide_button.text("Hide");
    hide_button.click += [&] {
      form2.hide();
    };
    
    cancel_close_check_box.location({10, 160});
    cancel_close_check_box.size({100, 40});
    cancel_close_check_box.text("cancel close");
    
    form2.text("Close count = 0");
    form2.form_closing += [&](object& seander, form_closing_event_args& e) {
      e.cancel(cancel_close_check_box.checked());
    };
    form2.form_closed += [&] {
      static auto close_count = 0;
      form2.text(ustring::format("Close count = {}", ++close_count));
    };
  }
  
private:
  button close_button;
  button show_button;
  button hide_button;
  check_box cancel_close_check_box;
  form form2;
};

auto main()->int {
  application::run(form1 {});
}
