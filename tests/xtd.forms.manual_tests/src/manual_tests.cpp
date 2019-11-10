#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");
  
  button button1;
  button1.parent(form_main);
  button1.location({10, 10});
  button1.text("click");
  button1.click += [] {
    message_box::show("Message", "Caption", message_box_buttons::yes_no_cancel);
  };

  application::run(form_main);
}
