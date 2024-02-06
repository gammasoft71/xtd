#include "../resources/gammasoft_16x16.xpm"
#include "../resources/gammasoft_32x32.xpm"
#include "../resources/gammasoft_64x64.xpm"
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Bitmap button with text example");
    controls().push_back_range({button1, button2, button3, button4});
    
    button1.location({40, 40});
    button1.width(100);
    button1.text("Gammasoft");
    
    button2.location({40, 80});
    button2.width(120);
    button2.image(image::from_data(gammasoft_16x16_xpm));
    button2.image_align(content_alignment::middle_left);
    button2.text("Gammasoft");
    
    button3.location({40, 120});
    button3.size({140, 40});
    button3.image(image::from_data(gammasoft_32x32_xpm));
    button3.image_align(content_alignment::middle_left);
    button3.text("Gammasoft");
    
    button4.location({40, 175});
    button4.size({70, 70});
    button4.image(image::from_data(gammasoft_64x64_xpm));
  }
  
private:
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main()->int {
  application::run(form1 {});
}
