#include <xtd/xtd.forms>
#include "Gammasoft-32x32.xpm"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Bitmap button example");

    bitmap_button1.parent(*this);
    bitmap_button1.location({50, 50});
    bitmap_button1.size({40, 40});
    bitmap_button1.image(image::from_data(gammasoft_32x32));
    
    bitmap_button2.parent(*this);
    bitmap_button2.location({100, 50});
    bitmap_button2.size({140, 40});
    bitmap_button2.image(image::from_data(gammasoft_32x32));
    bitmap_button2.image_align(content_alignment::middle_left);
    bitmap_button2.text("Gammasoft");
  }
  
private:
  button bitmap_button1;
  button bitmap_button2;
};

int main() {
  application::run(form1());
}
