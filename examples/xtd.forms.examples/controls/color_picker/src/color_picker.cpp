#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Color picker example");
      
      test_zone.parent(*this);
      test_zone.location({10, 50});
      test_zone.back_color(color::red);
      test_zone.border_style(border_style::fixed_3d);

      color_picker.parent(*this);
      color_picker.color(test_zone.back_color());
      color_picker.location({10, 10});
      color_picker.color_changed += [&] {
        test_zone.back_color(color_picker.color());
      };
    }
    
  private:
    forms::color_picker color_picker;
    panel test_zone;
  };
}

int main() {
  application::run(examples::form1());
}
