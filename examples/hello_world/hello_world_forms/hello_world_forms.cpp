#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("My first application");
      client_size({300, 300});
      controls().push_back(label);

      label.auto_size(true);
      label.font(drawing::font(label.font().font_family(), 32, font_style::bold | font_style::italic));
      label.fore_color(color::green);
      label.location({5, 100});
      label.text("Hello, World!");
    }
    
  private:
    forms::label label;
  };
}

int main() {
  application::run(examples::form1());
}
