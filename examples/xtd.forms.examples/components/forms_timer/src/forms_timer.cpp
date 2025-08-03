#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace timer_example {
  class form1 : public form {
  public:
    form1() {
      label1.parent(*this);
      label1.text("0.0");
      label1.font(drawing::font("Arial", 48, font_style::italic));
      label1.location({10, 10});
      label1.auto_size(true);
      label1.fore_color(color::dodger_blue);
      
      button1.parent(*this);
      button1.text("Start");
      button1.location({10, 90});
      button1.click += delegate_(object & sender, const event_args & e) {
        timer1.enabled(!timer1.enabled());
        button1.text(timer1.enabled() ? "Stop" : "Start");
      };
      
      timer1.interval(100_ms);
      timer1.tick += delegate_(object & sender, const event_args & e) {
        label1.text(string::format("{:F1}", ++counter / 10.0));
      };
      
      text("Timer example");
      client_size({230, 130});
    }
    
  private:
    timer timer1;
    label label1;
    button button1;
    int counter = 0;
  };
}

auto main() -> int {
  application::run(timer_example::form1 {});
}
