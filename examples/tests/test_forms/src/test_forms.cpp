#include <xtd/xtd.forms>

int main() {
  xtd::forms::theme_color::current_theme_color(xtd::forms::theme_color("frozen", xtd::forms::theme_style::light, {[](xtd::forms::known_themed_color color)->xtd::drawing::color {
    switch (color) {
      case xtd::forms::known_themed_color::accent: return xtd::drawing::color::white;
      case xtd::forms::known_themed_color::accent_text: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::active_border: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::active_caption: return xtd::drawing::color::alice_blue;
      case xtd::forms::known_themed_color::active_caption_text: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::app_workspace: return xtd::drawing::color::alice_blue;
      case xtd::forms::known_themed_color::button_face: return xtd::drawing::color::white;
      case xtd::forms::known_themed_color::button_highlight: return xtd::drawing::color::white;
      case xtd::forms::known_themed_color::button_shadow: return xtd::drawing::color::light_gray;
      case xtd::forms::known_themed_color::control: return xtd::drawing::color::alice_blue;
      case xtd::forms::known_themed_color::control_dark: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::control_dark_dark: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::control_light: return xtd::drawing::color::white;
      case xtd::forms::known_themed_color::control_light_light: return xtd::drawing::color::white;
      case xtd::forms::known_themed_color::control_text: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::desktop: return xtd::drawing::color::alice_blue;
      case xtd::forms::known_themed_color::gradient_active_caption: return xtd::drawing::color::alice_blue;
      case xtd::forms::known_themed_color::gradient_inactive_caption: return xtd::drawing::color::alice_blue;
      case xtd::forms::known_themed_color::gray_text: return xtd::drawing::color::gray;
      case xtd::forms::known_themed_color::highlight: return  xtd::drawing::system_colors::highlight();
      case xtd::forms::known_themed_color::highlight_text: return  xtd::drawing::system_colors::highlight_text();
      case xtd::forms::known_themed_color::hot_track: return  xtd::drawing::system_colors::hot_track();
      case xtd::forms::known_themed_color::inactive_border: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::inactive_caption: return xtd::drawing::color::alice_blue;
      case xtd::forms::known_themed_color::inactive_caption_text: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::info: return  xtd::drawing::system_colors::info();
      case xtd::forms::known_themed_color::info_text: return  xtd::drawing::system_colors::info_text();
      case xtd::forms::known_themed_color::menu: return xtd::drawing::color::alice_blue;;
      case xtd::forms::known_themed_color::menu_text: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::menu_bar: return xtd::drawing::color::alice_blue;;
      case xtd::forms::known_themed_color::menu_highlight: return  xtd::drawing::system_colors::menu_highlight();
      case xtd::forms::known_themed_color::scroll_bar: return xtd::drawing::color::alice_blue;
      case xtd::forms::known_themed_color::text_box: return xtd::drawing::color::white;
      case xtd::forms::known_themed_color::text_box_text: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::window: return xtd::drawing::color::white;
      case xtd::forms::known_themed_color::window_frame: return xtd::drawing::color::dark_gray;
      case xtd::forms::known_themed_color::window_text: return xtd::drawing::color::dark_gray;
      default: throw std::invalid_argument("unknown know_color");
    }
  }}));

  auto main_form = xtd::forms::control::create<xtd::forms::form>("Test Gui", xtd::drawing::point(-1, -1), xtd::drawing::size(400, 300));
  auto label = xtd::forms::control::create<xtd::forms::label>(*main_form, "This example showhow to use theme_color.\nSet current theme color to \"Frozen\" theme color.", xtd::drawing::point(10, 10));
  label->auto_size(true);
  auto button = xtd::forms::control::create<xtd::forms::button>(*main_form, "Click me", xtd::drawing::point(10, 50));
  auto text_box = xtd::forms::control::create<xtd::forms::text_box>(*main_form, "Text box line", xtd::drawing::point(10, 80));
  auto list_box = xtd::forms::control::create<xtd::forms::list_box>(*main_form, xtd::drawing::point(150, 50));
  list_box->items().push_back_range({"Apple", "Banana", "Orange", "Peer"});
  list_box->selection_mode(xtd::forms::selection_mode::multi_extended);
  xtd::forms::application::run(*main_form);
}
