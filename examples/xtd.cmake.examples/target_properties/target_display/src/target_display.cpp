#include <xtd/xtd>

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Application display");
  application::run(*main_form);
}
