#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");
  
  label label1;
  label1.location({10, 50});
  label1.parent(form_main);
  label1.text("value = ");
  
  up_down_button up_down_button1;
  up_down_button1.location({10, 10});
  up_down_button1.parent(form_main);
  up_down_button1.value_changed +=[&] {
    label1.text(strings::format("value = {}", up_down_button1.value()));
  };
  up_down_button1.wrapped(true);
  up_down_button1.minimum(10);
  up_down_button1.maximum(20);
  up_down_button1.value(15);

  application::run(form_main);
}
