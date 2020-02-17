#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Gui application");
  auto information_label = control::create<label>(*main_form, "This console application was generate by \nxtd cmake helpers.\nSee CMakeLists.txt file.\n", {10, 10});
  information_label->auto_size(true);
  application::run(*main_form);
}
