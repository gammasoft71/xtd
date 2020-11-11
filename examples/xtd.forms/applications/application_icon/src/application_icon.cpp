#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Application icon example");
  xtd::forms::application::run(*main_form);
}
