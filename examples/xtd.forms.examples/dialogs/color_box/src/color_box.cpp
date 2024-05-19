#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/color_box>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Color box example");
    controls().push_back(button1);
    
    button1.location({10, 10});
    button1.text("Color...");
    button1.click += [&] {
      auto color = back_color();
      if (color_box::show(color, *this) == forms::dialog_result::ok)
        back_color(color);
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  application::run(form1 {});
}
