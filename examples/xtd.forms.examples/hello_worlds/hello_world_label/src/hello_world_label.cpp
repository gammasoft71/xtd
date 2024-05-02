#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::forms;

namespace hello_world_label_example {
  class main_form : public form {
  public:
    main_form() {
      text("Hello world (label)");
      controls().push_back(label1);
      
      label1.dock(dock_style::fill);
      label1.font({label1.font(), 32, font_style::bold | font_style::italic});
      label1.fore_color(color::green);
      label1.shadow(true);
      label1.text("Hello, World!");
      label1.text_align(content_alignment::middle_center);
    }
    
  private:
    label label1;
  };
}

auto main()->int {
  application::run(hello_world_label_example::main_form {});
}
