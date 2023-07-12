#include <xtd/drawing/system_colors>
#include <xtd/forms/button>
#include <xtd/forms/color_box>
#include <xtd/forms/form>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/color_dialog>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Color dialog example");
    controls().push_back(button1);
    
    button1.location({10, 10});
    button1.text("Color...");
    button1.click += [&] {
      auto dialog = color_dialog {};
      dialog.color(back_color());
      dialog.custom_colors(custom_colors);
      if (dialog.show_dialog(*this) == forms::dialog_result::ok)
        back_color(dialog.color());
      custom_colors = dialog.custom_colors();
    };
  }
  
private:
  button button1;
  color_dialog::colors custom_colors = {color::red, color::green, color::blue, color::yellow, system_colors::control()};
};

auto main()->int {
  application::run(form1 {});
}
