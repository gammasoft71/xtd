#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class main_form : public form {
public:
  main_form() {
    back_color(colors::dark_blue());
    client_size({450, 300});
    fore_color(colors::yellow());
    text("Screen informations example");

    screen_informations_text_box.dock(dock_style::fill);
    screen_informations_text_box.multiline(true);
    screen_informations_text_box.parent(*this);
    screen_informations_text_box.read_only(true);
    screen_informations_text_box.word_wrap(false);
    screen_informations_text_box.append_text(ustring::format("Number of screens: {}\n", screen::all_screens().size()));
    screen_informations_text_box.append_text(ustring::format("Standard pixels per inch: {}\n", screen::get_standard_pixels_per_inch()));
    auto index = 1;
    for (auto screen : screen::all_screens()) {
      screen_informations_text_box.append_text("\n");
      screen_informations_text_box.append_text(ustring::format("Screen: {}\n", index));
      screen_informations_text_box.append_text(ustring::format("   Device name: {}\n", screen.device_name()));
      screen_informations_text_box.append_text(ustring::format("   Bounds: {}\n", screen.bounds()));
      screen_informations_text_box.append_text(ustring::format("   High resolution: {}\n", screen.high_resolution()));
      screen_informations_text_box.append_text(ustring::format("   working area: {}\n", screen.working_area()));
      screen_informations_text_box.append_text(ustring::format("   Primary: {}\n", screen.primary()));
      screen_informations_text_box.append_text(ustring::format("   Bits per pixels (Depth): {}\n", screen.bits_per_pixel()));
      screen_informations_text_box.append_text(ustring::format("   Pixels per Inch (PPI): {}\n", screen.pixels_per_inch()));
      screen_informations_text_box.append_text(ustring::format("   Scale factor: {}\n", screen.scale_factor()));
      ++index;
    }
  }
  
private:
  text_box screen_informations_text_box;
};

auto main()->int {
  xtd::forms::application::run(main_form());
}
