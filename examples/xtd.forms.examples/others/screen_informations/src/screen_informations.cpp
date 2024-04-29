#include <xtd/drawing/colors>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/screen>
#include <xtd/forms/text_box>

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
    screen_informations_text_box.append_text(ustring::format("Number of screens: {}{}", screen::all_screens().size(), environment::new_line()));
    screen_informations_text_box.append_text(ustring::format("Standard pixels per inch: {}{}", screen::get_standard_pixels_per_inch(), environment::new_line()));
    auto index = 0;
    for (auto screen : screen::all_screens()) {
      screen_informations_text_box.append_text(environment::new_line());
      screen_informations_text_box.append_text(ustring::format("Screen: {}\n", ++index, environment::new_line()));
      screen_informations_text_box.append_text(ustring::format("   Device name: {}{}", screen.device_name(), environment::new_line()));
      screen_informations_text_box.append_text(ustring::format("   Bounds: {}{}", screen.bounds(), environment::new_line()));
      screen_informations_text_box.append_text(ustring::format("   High resolution: {}{}", screen.high_resolution(), environment::new_line()));
      screen_informations_text_box.append_text(ustring::format("   working area: {}{}", screen.working_area(), environment::new_line()));
      screen_informations_text_box.append_text(ustring::format("   Primary: {}{}", screen.primary(), environment::new_line()));
      screen_informations_text_box.append_text(ustring::format("   Bits per pixels (Depth): {}{}", screen.bits_per_pixel(), environment::new_line()));
      screen_informations_text_box.append_text(ustring::format("   Pixels per Inch (PPI): {}{}", screen.pixels_per_inch(), environment::new_line()));
      screen_informations_text_box.append_text(ustring::format("   Scale factor: {}{}", screen.scale_factor()));
    }
  }
  
private:
  text_box screen_informations_text_box;
};

auto main()->int {
  xtd::forms::application::run(main_form());
}
