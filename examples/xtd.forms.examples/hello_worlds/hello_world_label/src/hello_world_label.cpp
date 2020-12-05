#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class main_form : public form {
  public:
    main_form() {
      text("Hello world (label)");
      controls().push_back(label);

      label.dock(dock_style::fill);
      label.font(drawing::font(label.font(), 32, font_style::bold|font_style::italic));
      label.fore_color(color::green);
      label.text("Hello, World!");
      label.text_align(xtd::forms::content_alignment::middle_center);
    }
    
  private:
    forms::label label;
  };
}

int main() {
  application::run(examples::main_form());
}
