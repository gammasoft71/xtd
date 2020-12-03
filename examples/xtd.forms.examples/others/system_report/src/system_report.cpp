#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class main_form : public form {
public:
  main_form() {
    text("System reports example");
    start_position(form_start_position::center_screen);
    size({500, 700});
    reports.dock(dock_style::fill);
    reports.font({drawing::font_family::generic_monospace(), reports.font().size()});
    reports.multiline(true);
    reports.parent(*this);
    reports.read_only(true);
    reports.text(system_report::to_string());
  }
  
private:
  text_box reports;
};

auto main()->int {
  xtd::forms::application::run(main_form());
}
