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
    graphics_path path;
    
    path.add_rectangle(rectangle(10, 10, 200, 100));
    e.graphics().fill_path(brushes::dodger_blue(), path);
  };
}

int main() {
  application::run(form1());
}

