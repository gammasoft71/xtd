#include "../resources/gammasoft_32x32.xpm"
#include "../resources/gammasoft_64x64.xpm"
#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Flat button example");
    controls().add_range({button1, button2, button3, button4});
    
    button1.location({40, 40});
    button1.flat_style(xtd::forms::flat_style::flat);
    button1.text("button1");
    
    button2.location({40, 80});
    button2.back_color(color::green);
    button2.flat_appearance(flat_button_appearance().border_color(color::light_green)
      .border_size(2)
      .mouse_over_back_color(color::light_green)
      .mouse_down_back_color(color::dark_green));
    button2.flat_style(xtd::forms::flat_style::flat);
    button2.text("button2");
    
    button3.location({40, 120});
    button3.flat_style(xtd::forms::flat_style::flat);
    button3.size({140, 40});
    button3.image(image::from_xpm_data(gammasoft_32x32_xpm));
    button3.image_align(content_alignment::middle_left);
    button3.text("Gammasoft");
    
    button4.location({40, 175});
    button4.flat_appearance(flat_button_appearance().border_size(0));
    button4.flat_style(xtd::forms::flat_style::flat);
    button4.size({70, 70});
    button4.image(image::from_xpm_data(gammasoft_64x64_xpm));
  }
  
private:
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1 {});
}
