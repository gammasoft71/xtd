#include <xtd/drawing/system_colors.h>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/panel>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Forms manual test").client_size({300, 300});
    panel1.back_color(xtd::drawing::system_colors::window());
    panel1.anchor(anchor_styles::all);
  }
  
  panel panel1 = panel::create(*this, {25, 25}  , {250, 250});
};

auto main()->int {
  application::run(form1 {});
}
