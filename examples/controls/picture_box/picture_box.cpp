#include <xtd/xtd.forms>
#include "logo.xpm"

using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Picture box example");
      client_size({300, 300});

      picture_box1.parent(*this);
      picture_box1.border_style(border_style::fixed_3d);
      picture_box1.location({20, 20});
      picture_box1.size({260, 260});
      picture_box1.image(bitmap(logo_xpm));
      picture_box1.size_mode(picture_box_size_mode::zoom);
      picture_box1.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
    }
    
  private:
    picture_box picture_box1;
  };
}

int main() {
  application::run(examples::form1());
}
