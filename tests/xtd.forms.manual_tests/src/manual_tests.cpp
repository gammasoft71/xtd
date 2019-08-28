#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form;
  form.text("Manual tests");

  form.paint += [&](const control& sender, paint_event_args& e) {
    e.graphics().draw_string(strings::format("{}", system_fonts::default_font), system_fonts::default_font, solid_brush(system_colors::control_text), 10, 10);
 };
  
  application::run(form);
}
