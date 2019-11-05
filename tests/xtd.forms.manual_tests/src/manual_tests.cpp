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
  label1.text("value = 50");

  numeric_up_down numeric_up_down1;
  numeric_up_down1.location({80, 50});
  numeric_up_down1.value(50);
  numeric_up_down1.parent(form_main);
  numeric_up_down1.value_changed +=[&] {
    label1.text(strings::format("value = {}", numeric_up_down1.value()));
  };
  
  numeric_up_down numeric_up_down2;
  numeric_up_down2.location({80, 100});
  numeric_up_down2.decimal_place(2);
  numeric_up_down2.increment(.01);
  numeric_up_down2.minimum(10.0);
  numeric_up_down2.maximum(11.0);
  numeric_up_down2.parent(form_main);
  
  application::run(form_main);
}
