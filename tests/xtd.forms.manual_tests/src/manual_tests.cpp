#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");
    
  panel panel_main;
  panel_main.parent(form_main);
  panel_main.auto_scroll(true);
  panel_main.dock(dock_style::fill);

  int panel_count = (int)known_color::yellow_green - (int)known_color::alice_blue;
  known_color panel_color = (known_color)((int)known_color::alice_blue + panel_count - 1);
  std::vector<panel> panels(panel_count);
  for (panel& panel : panels) {
    panel.parent(panel_main);
    panel.back_color(color::from_known_color(panel_color));
    panel.height(30);
    panel.dock(dock_style::top);
    panel_color = (known_color)((int)panel_color - 1);
  }

  application::run(form_main);
}
