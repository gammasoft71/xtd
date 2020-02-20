#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Test Gui");
  auto picture = control::create<picture_box>(*main_form);
  picture->size_mode(picture_box_size_mode::zoom).dock(dock_style::fill);
  picture->image(properties::resources::xtd_console());
  application::run(*main_form);
}
