#include <xtd/forms/application>
#include <xtd/forms/form>
#include "color_chooser.h"
#include "color_editor.h"

using namespace xtd::forms;

namespace colors_example {
  class main_form : public form {
  public:
    main_form() {
      text("Colors example");
      client_size({750, 630});
      minimum_client_size({750, 630});

      colors.parent(*this);
      colors.border_style(xtd::forms::border_style::rounded);
      colors.location({10, 10});
      colors.size({300, 610});
      colors.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::bottom);
      colors.selected_color_changed += [&] {
        editor.color(colors.selected_color());
      };
      
      editor.parent(*this);
      editor.border_style(xtd::forms::border_style::rounded);
      editor.location({320, 10});
      editor.size({420, 610});
      editor.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      
      colors.selected_index(0ul);
    }
    
  private:
    color_chooser colors;
    color_editor editor;
  };
}

auto main() -> int {
  application::run(colors_example::main_form {});
}
