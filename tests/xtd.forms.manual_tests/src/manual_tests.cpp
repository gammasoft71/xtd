#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");
  //form_main.show();

  tab_control tab_control1;
  tab_control1.parent(form_main);
  tab_control1.dock(dock_style::fill);
  
  tab_page tab_page1;
  tab_page1.text("Pink");
  tab_page1.back_color(drawing::color::light_pink);
  tab_page1.parent(tab_control1);
  
  tab_page tab_page2;
  tab_page2.parent(tab_control1);
  tab_page2.text("Green");
  tab_page2.back_color(drawing::color::light_green);

  application::run(form_main);
}
