#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/radio_button>

using namespace xtd;
using namespace xtd::forms;

namespace radio_button_example {
  class form1 : public form {
  public:
    form1() {
      text("Radio button example");
      controls().push_back_range({radio_button1, radio_button2, radio_button3, radio_button4, radio_button5, label1});
      
      radio_button1.auto_check(false);
      radio_button1.location({30, 30});
      radio_button1.font(drawing::font(font(), drawing::font_style::italic));
      radio_button1.text("Radio 1");
      radio_button1.click += [&] {
        // Uncomments next line to check / uncheck radio button 1 (auto_check is false...)
        //radio_button1.checked(!radio_button1.checked());
      };
      
      radio_button2.location({30, 60});
      radio_button2.text("Radio 2");
      
      radio_button3.checked_changed += [&] {
        label1.text(ustring::format("Radio 3 checked = {}", radio_button3.checked()));
      };
      radio_button3.checked(true);
      radio_button3.location({30, 90});
      radio_button3.text("Radio 3");
      
      radio_button4.appearance(appearance::button);
      radio_button4.location({30, 120});
      radio_button4.text("Radio 4");
      
      radio_button5.auto_check(false);
      radio_button5.appearance(appearance::button);
      radio_button5.font(drawing::font(font(), drawing::font_style::italic));
      radio_button5.location({30, 150});
      radio_button5.text("Radio 5");
      radio_button5.click += [&] {
        // Uncomments next line to check / uncheck radio button 5 (auto_check is false...)
        //radio_button5.checked(!radio_button5.checked());
      };
      
      label1.auto_size(true);
      label1.location({30, 180});
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

auto main() -> int {
  application::run(radio_button_example::form1 {});
}
