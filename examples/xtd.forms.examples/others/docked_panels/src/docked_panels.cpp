#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  auto form_main = control::create<form>("Docked panels example");
  form_main->client_size({300, 300});
    
  auto panel1 = control::create<panel>(*form_main, point {10, 10}, size {100, 100}, color::light_green);
  panel1->border_style(border_style::fixed_single);
  panel1->dock(dock_style::fill);
    
  auto panel2 = control::create<panel>(*form_main, point {10, 10}, size {100, 100}, color::light_yellow);
  panel2->border_style(border_style::fixed_single);
  panel2->dock(dock_style::right);
  
  auto panel3 = control::create<panel>(*form_main, point {10, 10}, size {100, 100}, color::light_blue);
  panel3->border_style(border_style::fixed_single);
  panel3->dock(dock_style::top);
  
  auto panel4 = control::create<panel>(*form_main, point {10, 10}, size {100, 100}, color::light_pink);
  panel4->border_style(border_style::fixed_single);
  panel4->dock(dock_style::left);
  
  auto panel5 = control::create<panel>(*form_main, point {10, 10}, size {100, 100}, color::light_salmon);
  panel5->border_style(border_style::fixed_single);
  panel5->dock(dock_style::bottom);

  application::run(*form_main);
}
