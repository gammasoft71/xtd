#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/toggle_button>

using namespace xtd;
using namespace xtd::forms;

namespace toggle_button_example {
  class form1 : public form {
  public:
    form1() {
      text("Toggle button example");
      controls().push_back_range({toggle_button1, toggle_button2, toggle_button3});
      
      toggle_button1.auto_check(false);
      toggle_button1.click += [&] {
        //toggle_button1.checked(!toggle_button1.checked());
        toggle_button1.text(ustring::format("{}", toggle_button1.check_state()));
      };
      toggle_button1.location({30, 30});
      toggle_button1.text(ustring::format("{}", toggle_button1.check_state()));
      toggle_button1.width(120);
      
      toggle_button2.check_state_changed += [&] {
        toggle_button2.text(ustring::format("{}", toggle_button2.check_state()));
      };
      toggle_button2.checked(true);
      toggle_button2.location({30, 80});
      toggle_button2.width(120);
      
      toggle_button3.check_state_changed += [&] {
        toggle_button3.text(ustring::format("{}", toggle_button3.check_state()));
      };
      toggle_button3.check_state(forms::check_state::indeterminate);
      toggle_button3.three_state(true);
      toggle_button3.location({30, 130});
      toggle_button3.width(120);
    }
    
  private:
    toggle_button toggle_button1;
    toggle_button toggle_button2;
    toggle_button toggle_button3;
  };
}

auto main() -> int {
  application::enable_visual_styles();
  application::run(toggle_button_example::form1 {});
}
