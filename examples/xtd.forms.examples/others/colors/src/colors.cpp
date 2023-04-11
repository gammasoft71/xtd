#include <xtd/xtd>
#include "color_chooser.h"
#include "color_editor.h"

using namespace xtd::forms;

namespace colors_example {
  class main_form : public form {
  public:
    main_form() {
      text("Colors example");
      start_position(form_start_position::manual);
      location({300, 200});
      client_size({640, 420});
      
      colors.parent(*this);
      colors.location({10, 10});
      colors.size({300, 400});
      colors.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::bottom);
      colors.selected_color_changed += [&] {
        editor.color(colors.selected_color());
      };
      
      editor.parent(*this);
      editor.location({330, 10});
      editor.size({300, 400});
      editor.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      
      colors.selected_index(0);
    }
    
  private:
    color_chooser colors;
    color_editor editor;
  };
}

auto main()->int {
  application::run(colors_example::main_form());
}
