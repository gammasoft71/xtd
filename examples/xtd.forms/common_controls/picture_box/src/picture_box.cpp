#include <xtd/xtd.forms>
#include "../properties/resources.h"

using namespace xtd::drawing;
using namespace xtd::forms;

namespace picture_box {
  class form1 : public form {
  public:
    form1() {
      text("Picture box example");
      client_size({300, 345});

      choice1.parent(*this);
      choice1.location({20, 20});
      choice1.width(260);
      choice1.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right);
      choice1.items().push_back_range({{"normal", picture_box_size_mode::normal}, {"stretch_image", picture_box_size_mode::stretch_image}, {"auto_size", picture_box_size_mode::auto_size}, {"center_image", picture_box_size_mode::center_image}, {"zoom", picture_box_size_mode::zoom}});
      choice1.selected_index(0);
      choice1.selected_value_changed += [&] {
        picture_box1.size_mode(std::any_cast<picture_box_size_mode>(choice1.selected_item().tag()));
      };

      picture_box1.parent(*this);
      picture_box1.border_style(border_style::fixed_single);
      picture_box1.location({20, 65});
      picture_box1.size({260, 260});
      picture_box1.image(properties::resources::logo());
      picture_box1.size_mode(std::any_cast<picture_box_size_mode>(choice1.selected_item().tag()));
      picture_box1.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
    }
    
  private:
    choice choice1;
    xtd::forms::picture_box picture_box1;
  };
}

int main() {
  application::run(::picture_box::form1());
}
