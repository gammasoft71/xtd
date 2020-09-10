#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Check box example");
      controls().push_back_range({check_box1, check_box2, check_box3, check_box4, check_box5});

      check_box1.auto_check(false);
      check_box1.click += [&] {
        //check_box1.checked(!check_box1.checked());
        check_box1.text(strings::format("{}", check_box1.check_state()));
      };
      check_box1.location({30, 30});
      check_box1.text(strings::format("{}", check_box1.check_state()));

      check_box2.check_state_changed += [&] {
        check_box2.text(strings::format("{}", check_box2.check_state()));
      };
      check_box2.checked(true);
      check_box2.location({30, 60});

      check_box3.auto_size(true);
      check_box3.check_state_changed += [&] {
        check_box3.text(strings::format("{}", check_box3.check_state()));
      };
      check_box3.check_state(forms::check_state::indeterminate);
      check_box3.three_state(true);
      check_box3.location({30, 90});

      check_box4.appearance(forms::appearance::button);
      check_box4.text_align(content_alignment::middle_center);
      check_box4.check_state_changed += [&] {
        check_box4.text(strings::format("{}", check_box4.check_state()));
      };
      check_box4.checked(true);
      check_box4.location({30, 120});

      check_box5.appearance(forms::appearance::button);
      check_box5.text_align(content_alignment::middle_center);
      check_box5.auto_check(false);
      check_box5.click += [&] {
        //check_box5.checked(!check_box5.checked());
        check_box5.text(strings::format("{}", check_box5.check_state()));
      };
      check_box5.location({30, 150});
      check_box5.text(strings::format("{}", check_box5.check_state()));
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
