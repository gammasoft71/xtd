#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Control example");

      this->control1.parent(*this);
      //this->control1.curosr(cursors::hand);
      this->control1.back_color(color::spring_green);
      this->control1.location({50, 50});
      this->control1.size({100, 50});
      this->control1.click += [&](const control& sender, const event_args& e) {
        this->control1.back_color(this->control1.back_color() == color::spring_green ? color::orange_red : color::spring_green);
      };
    }
    
  private:
    control control1;
  };
}

int main() {
  application::run(examples::form1());
}
