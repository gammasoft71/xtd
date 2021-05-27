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
    
    light_pink_panel.parent(layout_panel);
    light_pink_panel.back_color(colors::light_pink());
    
    light_green_panel.parent(layout_panel);
    light_green_panel.back_color(colors::light_green());
    
    light_blue_panel.parent(layout_panel);
    light_blue_panel.back_color(colors::light_blue());
    
    light_yellow_panel.parent(layout_panel);
    light_yellow_panel.back_color(colors::light_yellow());
  }
  
  static void main() {
    xtd::forms::application::run(form_main());
  }
  
private:
  vertical_layout_panel layout_panel;
  panel light_pink_panel;
  panel light_green_panel;
  panel light_blue_panel;
  panel light_yellow_panel;
};

startup_(form_main);
