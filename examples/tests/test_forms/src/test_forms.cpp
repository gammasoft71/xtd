#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  form form;
  form.text("Test forms");
  
  button button;
  button.parent(form).location({30, 30}).text("Click me").click += [] {
    message_box::show("Hello, World!");
  };
  
  application::run(form);
}
