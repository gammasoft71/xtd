#include <xtd/xtd.forms>

int main() {
  auto form1 = xtd::forms::control::create<xtd::forms::form>("form1");
  xtd::forms::application::run(*form1);
}
