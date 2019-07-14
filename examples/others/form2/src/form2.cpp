#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  auto form1 = control::create<form>("form1");
  application::run(*form1);
}
