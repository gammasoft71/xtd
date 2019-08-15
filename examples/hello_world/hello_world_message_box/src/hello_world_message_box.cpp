#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  button button1;
  button1.text("Click me");
  button1.location({10, 10});
  button1.width(90);
  button1.click += [](const control& sender, const event_args& e) {
    message_box::show("Hello, World!");
  };

  form form1;
  form1.text("Hello World Form");
  form1.controls().push_back(button1);

  application::run(form1);
}
