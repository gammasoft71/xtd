#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form_main : public form {
public:
  form_main() {
    text("Vertical layout panel example");

    layout_panel.parent(*this);
    layout_panel.dock(dock_style::fill);
    layout_panel.padding(forms::padding(5));
    
    red_panel.parent(layout_panel);
    red_panel.back_color(colors::red());
    
    green_panel.parent(layout_panel);
    green_panel.back_color(colors::green());
    
    blue_panel.parent(layout_panel);
    blue_panel.back_color(colors::blue());
    
    yellow_panel.parent(layout_panel);
    yellow_panel.back_color(colors::yellow());
  }
  
  static void main() {
    xtd::forms::application::run(form_main());
  }
  
private:
  vertical_layout_panel layout_panel;
  panel red_panel;
  panel green_panel;
  panel blue_panel;
  panel yellow_panel;
};

startup_(form_main);
