#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Check box example");

      this->check_box1.parent(*this);
      this->check_box1.auto_check(false);
      this->check_box1.location({30, 30});
      this->check_box1.text("Unchecked");

      this->check_box2.parent(*this);
      this->check_box2.checked(true);
      this->check_box2.location({30, 60});
      this->check_box2.text("Checked");

      this->check_box3.parent(*this);
      this->check_box3.check_state_changed += [&](const control& sender, const event_args& e) {
        this->label1.text(strings::format("check_box 3 state = {}", this->check_box3.check_state()));
      };
      this->check_box3.check_state(forms::check_state::indeterminate);
      this->check_box3.three_state(true);
      this->check_box3.location({30, 90});
      this->check_box3.text("Indeterminate");
      
      this->label1.parent(*this);
      this->label1.auto_size(true);
      this->label1.location({30, 150});
    }
    
  private:
    check_box check_box1;
    check_box check_box2;
    check_box check_box3;
    label label1;
  };
}

int main() {
  application::enable_visual_styles();
  application::run(examples::form1());
}
