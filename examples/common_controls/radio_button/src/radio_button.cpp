#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Radio button example");

      this->radio_button1.parent(*this);
      this->radio_button1.checked(true);
      this->radio_button1.location({30, 30});
      this->radio_button1.text("Radio 1");

      this->radio_button2.parent(*this);
      this->radio_button2.location({30, 60});
      this->radio_button2.text("Radio 2");

      this->radio_button3.parent(*this);
      this->radio_button3.checked_changed += [&](const control& sender, const event_args& e) {
        this->label1.text(strings::format("Radio 3 checked = {}", this->radio_button3.checked()));
      };
      this->radio_button3.location({30, 90});
      this->radio_button3.text("Radio 3");
      
      this->label1.parent(*this);
      this->label1.auto_size(true);
      this->label1.location({30, 150});
    }
    
  private:
    radio_button radio_button1;
    radio_button radio_button2;
    radio_button radio_button3;
    label label1;
  };
}

int main() {
  application::enable_visual_styles();
  application::run(examples::form1());
}
