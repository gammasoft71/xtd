#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/panel>

using namespace xtd::drawing;
using namespace xtd::forms;

auto main() -> int {
  auto form_main = form::create("Docked panels example");
  form_main.client_size({300, 300});
  
  auto panel1 = panel::create(form_main, point {10, 10}, size {100, 100});
  panel1.back_color(color::light_green);
  panel1.border_style(border_style::fixed_single);
  panel1.dock(dock_style::fill);
  
  auto panel2 = panel::create(form_main, point {10, 10}, size {100, 100});
  panel2.back_color(color::light_yellow);
  panel2.border_style(border_style::fixed_single);
  panel2.dock(dock_style::right);
  
  auto panel3 = panel::create(form_main, point {10, 10}, size {100, 100});
  panel3.back_color(color::light_blue);
  panel3.border_style(border_style::fixed_single);
  panel3.dock(dock_style::top);
  
  auto panel4 = panel::create(form_main, point {10, 10}, size {100, 100});
  panel4.back_color(color::light_pink);
  panel4.border_style(border_style::fixed_single);
  panel4.dock(dock_style::left);
  
  auto panel5 = panel::create(form_main, point {10, 10}, size {100, 100});
  panel5.back_color(color::light_salmon);
  panel5.border_style(border_style::fixed_single);
  panel5.dock(dock_style::bottom);
  
  application::run(form_main);
}
