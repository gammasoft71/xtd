#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/panel>

using namespace xtd::drawing;
using namespace xtd::forms;

namespace auto_scroll_example {
  class form1 : public form {
  public:
    form1() {
      auto_scroll(true);
      controls().push_back_range({panel5, panel4, panel3, panel2, panel1});
      size({400, 250});
      text("Auto scroll example");
      
      panel1.border_style(border_style::fixed_single).back_color(color::light_green).dock(dock_style::top);
      panel2.border_style(border_style::fixed_single).back_color(color::light_pink).dock(dock_style::top);
      panel3.border_style(border_style::fixed_single).back_color(color::light_blue).dock(dock_style::top);
      panel4.border_style(border_style::fixed_single).back_color(color::light_yellow).dock(dock_style::top);
      panel5.border_style(border_style::fixed_single).back_color(color::light_salmon).dock(dock_style::top);
    }
    
  private:
    panel panel1;
    panel panel2;
    panel panel3;
    panel panel4;
    panel panel5;
  };
}

auto main()->int {
  application::run(auto_scroll_example::form1 {});
}
