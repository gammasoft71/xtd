#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  button button;
  button.text("Click me");
  button.location({10, 10});
  button.width(90);
  button.click += [](const control& sender, const event_args& e) {
    message_box::show("Hello, World!");
  };

  form form;
  form.text("Hello World Form");
  form.controls().push_back(button);

  application::run(form);
}
