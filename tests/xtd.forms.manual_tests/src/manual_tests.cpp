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
    e.graphics().fill_rectangle(brushes::yellow(), rectangle(10, 10, 200, 100));
    e.graphics().page_unit(xtd::drawing::graphics_unit::millimeter);
    e.graphics().fill_rectangle(brushes::lime(), rectangle(2000, 2000, 10000, 5000));
  };
}

int main() {
  application::run(form1());
}

