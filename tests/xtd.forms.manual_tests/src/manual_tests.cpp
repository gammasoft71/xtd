#include <xtd/xtd>

auto main() -> int {
  auto form1 = form::create("form1");
  auto button1 = button::create(form1, "button1", {10, 10});
  button1.click += [&] {message_box::show(form1, "Hello, World! !");};
  application::run(form1);
}
