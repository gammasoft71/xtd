#include <xtd/xtd.forms>
#include "../resources/gammasoft_16x16.xpm"
#include "../resources/gammasoft_32x32.xpm"
#include "../resources/gammasoft_64x64.xpm"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Bitmap button example");
    controls().push_back_range({button1, button2, button3, button4});
    
    button1.location({50, 50});
    button1.width(100);
    button1.text("Gammasoft");

    button2.location({50, 80});
    button2.width(120);
    button2.image(image::from_data(gammasoft_16x16_xpm));
    button2.image_align(content_alignment::middle_left);
    button2.text("Gammasoft");
    
    button3.location({50, 110});
    button3.size({140, 40});
    button3.image(image::from_data(gammasoft_32x32_xpm));
    button3.image_align(content_alignment::middle_left);
    button3.text("Gammasoft");
    
    button4.location({50, 155});
    button4.size({70, 70});
    button4.image(image::from_data(gammasoft_64x64_xpm));
  }
  
private:
  button button1;
  button button2;
  button button3;
  button button4;
};

int main() {
  application::enable_button_images();
  application::run(form1());
}
