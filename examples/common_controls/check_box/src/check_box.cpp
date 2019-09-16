#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Check box example");
      this->controls().push_back_range({this->check_box1, this->check_box2, this->check_box3, this->check_box4, this->check_box5});

      this->check_box1.auto_check(false);
      this->check_box1.click += [&](const control& sender, const event_args& e) {
        //this->check_box1.checked(!this->check_box1.checked());
        //this->check_box1.text(strings::format("{}", this->check_box1.check_state()));
      };
      this->check_box1.location({30, 30});
      this->check_box1.text(strings::format("{}", this->check_box1.check_state()));

      this->check_box2.check_state_changed += [&](const control& sender, const event_args& e) {
        this->check_box2.text(strings::format("{}", this->check_box2.check_state()));
      };
      this->check_box2.checked(true);
      this->check_box2.location({30, 60});

      this->check_box3.check_state_changed += [&](const control& sender, const event_args& e) {
        this->check_box3.text(strings::format("{}", this->check_box3.check_state()));
      };
      this->check_box3.check_state(forms::check_state::indeterminate);
      this->check_box3.three_state(true);
      this->check_box3.location({30, 90});

      this->check_box4.appearance(forms::appearance::button);
      this->check_box4.auto_check(false);
      this->check_box4.click += [&](const control& sender, const event_args& e) {
        //this->check_box4.checked(!this->check_box4.checked());
        //this->check_box4.text(strings::format("{}", this->check_box4.check_state()));
      };
      this->check_box4.location({30, 120});
      this->check_box4.text(strings::format("{}", this->check_box4.check_state()));

      this->check_box5.appearance(forms::appearance::button);
      this->check_box5.check_state_changed += [&](const control& sender, const event_args& e) {
        this->check_box5.text(strings::format("{}", this->check_box5.check_state()));
      };
      this->check_box5.checked(true);
      this->check_box5.location({30, 150});
    }
    
  private:
    check_box check_box1;
    check_box check_box2;
    check_box check_box3;
    check_box check_box4;
    check_box check_box5;
  };
}

int main() {
  application::enable_visual_styles();
  application::run(examples::form1());
}
