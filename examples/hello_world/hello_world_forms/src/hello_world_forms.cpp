#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->label.parent(*this);
      this->label.font(drawing::font("Arial", 34, font_style::bold | font_style::italic));
      this->label.text("Hello, World!");
      this->label.location({5, 100});
      this->label.size({290, 100});
      this->label.fore_color(color::green);
      
      this->text("My first application");
      this->client_size({300, 300});
    }
    
  private:
    forms::label label;
  };
}

int main() {
  application::run(examples::form1());
}
