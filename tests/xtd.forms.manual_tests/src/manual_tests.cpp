#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  auto form_main = control::create<form>("Form main");
  form_main->client_size({300, 300});
  //form_main->suspend_layout();
  
  auto main_panel = control::create<panel>(*form_main);
  main_panel->dock(dock_style::fill);
  
  auto panel1 = control::create<panel>(*main_panel, "panel1", {10, 10}, {100, 100});
  panel1->back_color(drawing::color::light_green);
  panel1->border_style(forms::border_style::fixed_single);
  panel1->dock(dock_style::fill);
    
  auto panel2 = control::create<panel>(*main_panel, "panel2", {10, 10}, {100, 100});
  panel2->back_color(drawing::color::light_yellow);
  panel2->border_style(forms::border_style::fixed_single);
  panel2->dock(dock_style::right);
  
  auto panel3 = control::create<panel>(*main_panel, "panel3", {10, 10}, {100, 100});
  panel3->back_color(drawing::color::light_blue);
  panel3->border_style(forms::border_style::fixed_single);
  panel3->dock(dock_style::top);
  
  auto panel4 = control::create<panel>(*main_panel, "panel4", {10, 10}, {100, 100});
  panel4->back_color(drawing::color::light_pink);
  panel4->border_style(forms::border_style::fixed_single);
  panel4->dock(dock_style::left);
  
  auto panel5 = control::create<panel>(*main_panel, "panel4", {10, 10}, {100, 100});
  panel5->back_color(drawing::color::light_salmon);
  panel5->border_style(forms::border_style::fixed_single);
  panel5->dock(dock_style::bottom);

  //form_main->resume_layout();
  application::run(*form_main);
}
