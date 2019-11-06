#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");
  
  label label1;
  label1.location({10, 40});
  label1.parent(form_main);
  label1.text("value = ");
  
  button button1;
  button1.parent(form_main);
  button1.location({10, 100});
  button1.text("Reset");

  domain_up_down domain_up_down1;
  domain_up_down1.location({10, 10});
  domain_up_down1.parent(form_main);
  domain_up_down1.items().push_back_range({"item 1", "item2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"});
  domain_up_down1.text_changed +=[&] {
    label1.text(strings::format("value = {}", domain_up_down1.selected_item()));
  };
  //domain_up_down1.text("item 6");
  domain_up_down1.selected_index(1);

  button1.click += [&] {
    domain_up_down1.selected_index(-1);
  };


  application::run(form_main);
}
