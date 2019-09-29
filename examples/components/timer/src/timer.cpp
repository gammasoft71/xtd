#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      label.parent(*this);
      label.text("0.0");
      label.font(drawing::font("Arial", 48, font_style::italic));
      label.location({10, 10});
      label.auto_size(true);
      label.fore_color(color::dodger_blue);

      button.parent(*this);
      button.text("Start");
      button.location({10, 90});
      button.click += [this](const control& sender, const event_args& e) {
        timer.enabled(!timer.enabled());
        button.text(timer.enabled() ? "Stop": "Start");
      };

      timer.interval(100);
      timer.tick += [this](const forms::timer& sender, const event_args& e) {
        label.text(strings::format("{:F1}", ++counter / 10.0));
      };

      text("Timer example");
      client_size({230, 130});
    }
    
  private:
    forms::timer timer;
    forms::label label;
    forms::button button;
    int counter = 0;
  };
}

int main() {
  application::run(examples::form1());
}
