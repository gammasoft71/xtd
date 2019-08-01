#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  form form;
  form.text("Hello World Form");
  
  button button;
  button.parent(form);
  button.text("Click me");
  button.location({10, 10});
  button.width(90);
  button.click += [](const control& sender, const event_args& e) {
    message_box::show("Hello, World!");
  };

  application::run(form);
}
