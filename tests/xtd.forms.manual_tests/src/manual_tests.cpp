#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");

  combo_box combo_box1;
  combo_box1.location({10, 10});
  combo_box1.drop_down_style(combo_box_style::simple);
  combo_box1.height(120);
  combo_box1.items().push_back_range({"Item1", "Item2", "Item3", "Item4"});
  combo_box1.selected_index(2);
  combo_box1.parent(form_main);

  cdebug << format("height = {}", combo_box1.height()) << std::endl;
  
  application::run(form_main);
}
