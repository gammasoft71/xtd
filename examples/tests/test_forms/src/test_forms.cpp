#include <xtd/xtd.forms>

int main() {
  auto main_form = xtd::forms::control::create<xtd::forms::form>("Test forms");
  auto picture = xtd::forms::control::create<xtd::forms::picture_box>(*main_form);
  picture->image(xtd::forms::theme_images::current_theme().from_name("xtd-forms", xtd::drawing::size(1024, 1024)));
  picture->size_mode(xtd::forms::picture_box_size_mode::zoom);
  picture->dock(xtd::forms::dock_style::fill);
  xtd::forms::application::run(*main_form);
}
