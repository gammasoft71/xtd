#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class colored_line : public user_control {
  public:
    void color(const drawing::color& color) {this->back_color(color);}
    drawing::color color() const {return this->back_color();}
  };

  class form1 : public form {
  public:
    form1() {
      this->line_separator.color(drawing::system_colors::window());
      this->line_separator.bounds({10, 10, 280, 2});

      this->line_red.color(drawing::color::red);
      this->line_red.bounds({10, 20, 2, 250});

      this->line_green.color(drawing::color::green);
      this->line_green.bounds({149, 20, 2, 250});

      this->line_blue.color(drawing::color::blue);
      this->line_blue.bounds({288, 20, 2, 250});

      this->line_separator2.color(drawing::system_colors::control_text());
      this->line_separator2.bounds({10, 278, 280, 2});

      this->text("Lines example");
      this->client_size({300, 300});
      this->controls().push_back_range({this->line_separator, this->line_red, line_green, line_blue, this->line_separator2});
    }
    
  private:
    colored_line line_separator;
    colored_line line_red;
    colored_line line_green;
    colored_line line_blue;
    colored_line line_separator2;
  };
}

int main() {
  application::run(examples::form1());
}
