#include "../resources/gammasoft_16x16.xpm"
#include "../resources/gammasoft_64x64.xpm"
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Bitmap button example");
    controls().push_back_range({button1, button2, label1, label2});
    
    button1.location({50, 50});
    button1.image(image::from_data(gammasoft_16x16_xpm));
    button1.image_align(content_alignment::middle_center);
    button1.click += [&] {
      label1.text(ustring::format("Button 1 clicked {} times", ++button1_clicked));
    };

    button2.auto_repeat(true);
    button2.location({50, 100});
    button2.size({200, 75});
    button2.image(image::from_data(gammasoft_64x64_xpm));
    button2.image_align(content_alignment::middle_center);
    button2.click += [&] {
      label2.text(ustring::format("Button 2 clicked {} times", ++button2_clicked));
    };

    label1.parent(*this);
    label1.text("Button 1 clicked 0 times");
    label1.location({50, 200});
    label1.width(200);
    
    label2.parent(*this);
    label2.text("Button 2 clicked 0 times");
    label2.location({50, 230});
    label2.width(200);
  }
  
private:
  button button1;
  button button2;
  label label1;
  label label2;
  int button1_clicked = 0;
  int button2_clicked = 0;
};

auto main()->int {
  //application::system_controls(true);
  application::run(form1 {});
}
