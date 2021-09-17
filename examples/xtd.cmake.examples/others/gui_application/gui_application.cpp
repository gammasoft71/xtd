#include <xtd/xtd>

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Gui application");
  auto information_label = control::create<label>(*main_form, "\nThis GUI application was generate by \nxtd cmake helpers.\n\nSee CMakeLists.txt file.", {10, 10});
  information_label->text_align(content_alignment::top_center).dock(dock_style::fill);
  application::run(*main_form);
}
