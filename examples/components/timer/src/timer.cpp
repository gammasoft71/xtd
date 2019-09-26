#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->label.parent(*this);
      this->label.text("0.0");
      this->label.font(drawing::font("Arial", 48, font_style::italic));
      this->label.location({10, 10});
      this->label.auto_size(true);
      this->label.fore_color(color::dodger_blue);

      this->button.parent(*this);
      this->button.text("Start");
      this->button.location({10, 90});
      this->button.click += [&](const control& sender, const event_args& e) {
        this->timer.enabled(!this->timer.enabled());
        this->button.text(this->timer.enabled() ? "Stop": "Start");
      };

      this->timer.interval(100);
      this->timer.tick += [&](const forms::timer& sender, const event_args& e) {
        this->label.text(strings::format("{:F1}", ++this->counter / 10.0));
      };

      this->text("Timer example");
      this->client_size({230, 130});
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
