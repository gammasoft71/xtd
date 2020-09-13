#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Toggle button example");
      controls().push_back_range({toggle_button1, toggle_button2, toggle_button3});

      toggle_button1.auto_check(false);
      toggle_button1.click += [&] {
        //toggle_button1.checked(!toggle_button1.checked());
        toggle_button1.text(strings::format("{}", toggle_button1.check_state()));
      };
      toggle_button1.location({30, 30});
      toggle_button1.text(strings::format("{}", toggle_button1.check_state()));

      toggle_button2.check_state_changed += [&] {
        toggle_button2.text(strings::format("{}", toggle_button2.check_state()));
      };
      toggle_button2.checked(true);
      toggle_button2.location({30, 60});

      toggle_button3.auto_size(true);
      toggle_button3.check_state_changed += [&] {
        toggle_button3.text(strings::format("{}", toggle_button3.check_state()));
      };
      toggle_button3.check_state(forms::check_state::indeterminate);
      toggle_button3.three_state(true);
      toggle_button3.location({30, 90});
    }
    
  private:
    toggle_button toggle_button1;
    toggle_button toggle_button2;
    toggle_button toggle_button3;
  };
}

int main() {
  application::enable_visual_styles();
  application::run(examples::form1());
}
