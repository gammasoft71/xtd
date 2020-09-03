#include <xtd/xtd.forms>

int main() {
  auto main_form = xtd::forms::control::create<xtd::forms::form>("Test forms");
  /*
  auto picture = xtd::forms::control::create<xtd::forms::picture_box>(*main_form);
  picture->image(xtd::forms::theme_images::current_theme().from_name("xtd-forms", xtd::drawing::size(1024, 1024)));
  picture->size_mode(xtd::forms::picture_box_size_mode::zoom);
  picture->dock(xtd::forms::dock_style::fill);
   */
  
  auto button = xtd::forms::control::create<xtd::forms::button>(*main_form, "Message", xtd::drawing::point(10, 10));
  button->click += [&] {
    xtd::cdebug << "begin message..." << std::endl;
    auto dialog = xtd::forms::control::create<xtd::forms::form>("Dialog", {}, {200, 100}).release();
    dialog->start_position(xtd::forms::form_start_position::center_screen);
    dialog->show();
    xtd::cdebug << "end message..." << std::endl;
  };
  
  xtd::forms::application::run(*main_form);
}
