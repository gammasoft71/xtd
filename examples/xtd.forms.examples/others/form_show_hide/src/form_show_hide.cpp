#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/check_box>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Form show and hide example").client_size({320, 325});
    
    close_button.click += [&] {form2.close();};
    show_button.click += [&] {form2.show();};
    hide_button.click += [&] {form2.hide();};
    
    form2.client_size({300, 100});
    form2.form_closing += [&](auto sender, auto& e) {e.cancel(cancel_close_check_box.checked());};
    form2.form_closed += [&] {form2.text(ustring::format("Close count = {}", ++close_count));};
  }
  
private:
  int close_count = 0;
  button close_button = button::create(*this, "Close", {10, 10}, {100, 40});
  button show_button = button::create(*this, "Show", {10, 60}, {100, 40});
  button hide_button = button::create(*this, "Hide", {10, 110}, {100, 40});
  check_box cancel_close_check_box = check_box::create(*this, "cancel close", false, check_state::unchecked, {10, 160}, {100, 40});
  form form2 = form::create("Close count = 0");
};

auto main() -> int {
  application::run(form1 {});
}
