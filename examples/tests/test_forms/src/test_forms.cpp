#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  auto form_main = control::create<form>("Test Gui");
  application::run(*form_main);
}
