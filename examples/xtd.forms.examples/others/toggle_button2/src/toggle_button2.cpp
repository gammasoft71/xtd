#include <xtd/drawing/pens>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/toggle_button>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({280, 180});
    controls().push_back_range({button_red, button_green, button_blue, panel_color});
    text("Toggle button example");
    
    button_red.location({20, 20});
    button_red.image(image_from_color(color::red));
    button_red.image_align(content_alignment::middle_left);
    button_red.text("Red");
    button_red.three_state(true);
    button_red.check_state_changed += event_handler(*this, &form1::update_color);
    
    button_green.location({20, 70});
    button_green.image(image_from_color(color::lime));
    button_green.image_align(content_alignment::middle_left);
    button_green.text("Green");
    button_green.three_state(true);
    button_green.check_state_changed += event_handler(*this, &form1::update_color);
    
    button_blue.location({20, 120});
    button_blue.image(image_from_color(color::blue));
    button_blue.image_align(content_alignment::middle_left);
    button_blue.text("Blue");
    button_blue.three_state(true);
    button_blue.check_state_changed += event_handler(*this, &form1::update_color);
    
    panel_color.border_style(forms::border_style::fixed_3d);
    panel_color.location({150, 20});
    panel_color.size({110, 110});
    
    update_color(*this, event_args::empty);
  }
  
private:
  void update_color(object& sender, const event_args& e) {
    static auto color_levels = std::map<check_state, unsigned char> {{check_state::unchecked, 0_u8}, {check_state::checked, 255_u8}, {check_state::indeterminate, 128_u8}};
    panel_color.back_color(color::from_argb(color_levels[button_red.check_state()], color_levels[button_green.check_state()], color_levels[button_blue.check_state()]));
  }
  
  image image_from_color(const color& color) {
    auto colored_bitmap = bitmap {16, 16};
    auto g = graphics::from_image(colored_bitmap);
    g.fill_ellipse(solid_brush(color), 0, 0, colored_bitmap.width(), colored_bitmap.height());
    g.draw_ellipse(pens::black(), 0, 0, colored_bitmap.width() - 1, colored_bitmap.height() - 1);
    return colored_bitmap;
  }
  
  toggle_button button_red;
  toggle_button button_green;
  toggle_button button_blue;
  panel panel_color;
};

auto main() -> int {
  application::run(form1 {});
}
