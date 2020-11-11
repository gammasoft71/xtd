#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  button button;
  button.text("&Click me");
  button.location({10, 10});
  button.click += [] {
    message_box::show("Hello, World!");
  };

  form form;
  form.text("Hello world (message_box)");
  form.controls().push_back(button);

  application::run(form);
}
