#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Auto scroll example");
  form_main.size({400, 250});
  form_main.auto_scroll(true);

  panel panel1;
  panel1.parent(form_main);
  panel1.back_color(color::light_salmon);
  panel1.border_style(border_style::fixed_single);
  panel1.dock(dock_style::top);
    
  panel panel2;
  panel2.parent(form_main);
  panel2.back_color(color::light_yellow);
  panel2.border_style(border_style::fixed_single);
  panel2.dock(dock_style::top);
  
  panel panel3;
  panel3.parent(form_main);
  panel3.back_color(color::light_blue);
  panel3.border_style(border_style::fixed_single);
  panel3.dock(dock_style::top);
  
  panel panel4;
  panel4.parent(form_main);
  panel4.back_color(color::light_pink);
  panel4.border_style(border_style::fixed_single);
  panel4.dock(dock_style::top);
  
  panel panel5;
  panel5.parent(form_main);
  panel5.back_color(color::light_green);
  panel5.border_style(border_style::fixed_single);
  panel5.dock(dock_style::top);

  application::run(form_main);
}
