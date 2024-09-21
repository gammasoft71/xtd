#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

auto main()->int {
  auto form1 = form::create("form1");
  auto button1 = button::create(form1, "Click me", {10, 10});
  application::run(form1);
}
