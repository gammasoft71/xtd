#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  form form;
  form.text("Test forms").controls().push_back(button().parent(form).location({30, 30}).text("Click me"));
  form.controls()[0].get().click += [] {message_box::show("Hello, World!");};
  application::run(form);
}
