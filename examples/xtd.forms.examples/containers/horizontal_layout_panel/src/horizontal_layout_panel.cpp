#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form_main : public form {
public:
  form_main() {
    text("Horizontal layout panel example");

    layout_panel.parent(*this);
    layout_panel.controls().push_back_range({light_pink_panel, light_green_panel, light_blue_panel, light_yellow_panel});
    layout_panel.control_layout_style(light_pink_panel, {30, size_type::absolute, true});
    layout_panel.control_layout_style(light_green_panel, {.70f, size_type::percent, true});
    layout_panel.control_layout_style(light_blue_panel, {.15f, size_type::percent, true});
    layout_panel.control_layout_style(light_yellow_panel, {size_type::auto_size, true});
    layout_panel.dock(dock_style::fill);
    layout_panel.padding(forms::padding(5));

    light_pink_panel.back_color(colors::light_pink());
    light_green_panel.back_color(colors::light_green());
    light_blue_panel.back_color(colors::light_blue());
    light_yellow_panel.back_color(colors::light_yellow());
  }
  
  static void main() {
    xtd::forms::application::run(form_main());
  }
  
private:
  horizontal_layout_panel layout_panel;
  panel light_pink_panel;
  panel light_green_panel;
  panel light_blue_panel;
  panel light_yellow_panel;
};

startup_(form_main);
