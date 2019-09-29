#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      label.parent(*this);
      label.font(drawing::font("Arial", 34, font_style::bold | font_style::italic));
      label.text("Hello, World!");
      label.location({5, 100});
      label.auto_size(true);
      label.fore_color(color::green);
      
      text("My first application");
      client_size({300, 300});
    }
    
  private:
    forms::label label;
  };
}

int main() {
  application::run(examples::form1());
}
