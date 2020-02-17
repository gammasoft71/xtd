#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Application icon");
  application::run(*main_form);
}
