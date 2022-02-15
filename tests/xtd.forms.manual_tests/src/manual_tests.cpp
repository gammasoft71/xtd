#include <xtd/xtd.forms.h>
#include <xtd/forms/style_sheets/style_sheet.h>
#include <xtd/forms/button_renderer.h>
#include <xtd/forms/text_renderer.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;

class form1 : public form {
public:
  form1();
  
private:
};

form1::form1() {
  text("form1 - system");
  client_size({800, 450});
  
  paint += [&](object& sender, paint_event_args& e) {
    /*
    rectangle rect1(20, 20, 60, 80);
    rectangle rect2(50, 30, 60, 80);
    drawing::region region(rect1);
    region.make_xor(rect2);
    e.graphics().fill_region(brushes::dodger_blue(), region);
     */
    
    graphics_path path;
    path.add_ellipse(20, 20, 60, 80);
    //e.graphics().fill_path(brushes::dodger_blue(), path);
    drawing::region region(path);
    rectangle rect2(50, 30, 60, 80);
    region.exclude(rect2);
    e.graphics().fill_region(brushes::dodger_blue(), region);
  };
}

int main() {
  application::run(form1());
}

