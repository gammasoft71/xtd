#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Radio button example");
      this->controls().push_back_range({this->radio_button1, this->radio_button2, this->radio_button3, this->radio_button4, this->radio_button5, this->label1});
      
      this->radio_button1.auto_check(false);
      this->radio_button1.checked(true);
      this->radio_button1.location({30, 30});
      this->radio_button1.text("Radio 1");
      this->radio_button1.click += [&](const control& sender, const event_args& e) {
        // Uncomments next line to check / uncheck radio button 1 (auto_check is false...)
        this->radio_button1.checked(!this->radio_button1.checked());
      };
      
      this->radio_button2.location({30, 60});
      this->radio_button2.text("Radio 2");
      
      this->radio_button3.checked_changed += [&](const control& sender, const event_args& e) {
        this->label1.text(strings::format("Radio 3 checked = {}", this->radio_button3.checked()));
      };
      this->radio_button3.checked(true);
      this->radio_button3.location({30, 90});
      this->radio_button3.text("Radio 3");
      
      this->radio_button4.appearance(appearance::button);
      this->radio_button4.location({30, 120});
      this->radio_button4.text("Radio 4");
      
      this->radio_button5.auto_check(false);
      this->radio_button5.appearance(appearance::button);
      this->radio_button5.location({30, 150});
      this->radio_button5.text("Radio 5");
      this->radio_button5.click += [&](const control& sender, const event_args& e) {
        // Uncomments next line to check / uncheck radio button 1 (auto_check is false...)
        this->radio_button5.checked(!this->radio_button5.checked());
      };
      
      this->label1.auto_size(true);
      this->label1.location({30, 180});
      this->label1.text(strings::format("Radio 3 checked = {}", this->radio_button3.checked()));
    }
    
  private:
    radio_button radio_button1;
    radio_button radio_button2;
    radio_button radio_button3;
    radio_button radio_button4;
    radio_button radio_button5;
    label label1;
  };
}

int main() {
  application::run(examples::form1());
}
