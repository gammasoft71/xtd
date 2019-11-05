#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");
  
  label label1;
  label1.location({80, 150});
  label1.parent(form_main);
  label1.text("value = ");

  domain_up_down domain_up_down1;
  domain_up_down1.location({80, 50});
  domain_up_down1.parent(form_main);
  domain_up_down1.items().push_back_range({"item 1", "item2", "item 3", "item 4"});
  domain_up_down1.value_changed +=[&] {
    label1.text(strings::format("value = {}", domain_up_down1.text()));
  };
  domain_up_down1.text("item 6");
  //domain_up_down1.selected_index(1);
  
  application::run(form_main);
}
