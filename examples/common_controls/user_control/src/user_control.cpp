#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("User control example");

      this->user_control1.parent(*this);
      this->user_control1.cursor(cursors::hand());
      this->user_control1.back_color(color::light_blue);
      this->user_control1.location({50, 50});
      this->user_control1.double_click += [&](const control& sender, const event_args& e) {
        this->user_control1.back_color(this->user_control1.back_color() == color::light_blue ? color::light_pink : color::light_blue);
      };
    }
    
  private:
    user_control user_control1;
  };
}

int main() {
  application::run(examples::form1());
}
