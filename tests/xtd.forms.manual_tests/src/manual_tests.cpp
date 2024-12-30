#include <xtd/xtd>

auto main()->int {
  auto form1 = form::create("form1");
  auto button1 = button::create(form1, "Click me", {10, 10});
  button1.click += [&] {message_box::show(form1, "Hello !");};
  application::run(form1);
}
