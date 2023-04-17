#include <xtd/xtd>
#include "../properties/resources.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace form_background_image2 {
  class form1 : public form {
  public:
    form1() {
      double_buffered(true);
      background_image(properties::resources::background());
      client_size({600, 450});
      text("form with background image example 2");
      
      image_layout_choice.parent(*this);
      for (auto [value, name] : enum_object<>::get_entries<xtd::forms::image_layout>())
        image_layout_choice.items().push_back({name, value});
      image_layout_choice.location({10, 10});
      image_layout_choice.selected_index_changed += [&] {
        background_image_layout(as<xtd::forms::image_layout>(image_layout_choice.selected_item().tag()));
      };
      image_layout_choice.selected_index(0);
    }
    
  private:
    choice image_layout_choice;
  };
}

auto main()->int {
  application::run(::form_background_image2::form1 {});
}
