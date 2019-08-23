#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  message_box::show("Invalid argument exception: Bad index value!", "Error", message_box_buttons::ok, message_box_icon::exclamation);

  form form;
  form.text("Test forms");
  
  button button;
  button.parent(form).location({30, 30}).text("Click me").click += [] {
    message_box::show("Hello, World!");
  };
  
  application::run(form);
}
