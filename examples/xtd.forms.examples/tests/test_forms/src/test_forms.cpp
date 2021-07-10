#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::diagnostics;
using namespace xtd::forms;

class form_main : public form {
public:
  static void main() {
    xtd::forms::application::run(form_main());
  }

  form_main() {
    auto_size(true);
    auto_size_mode(forms::auto_size_mode::grow_and_shrink);
    
    label1.parent(*this);
    label1.fore_color(drawing::color::lime);
    label1.height(50);
    label1.auto_size(true);
    label1.lcd_style(forms::lcd_style::dot_matrix_display);
    label1.text("MON AMOUREUSE QUE J'AIME");
  }

private:
  lcd_label label1;
};

startup_(form_main);
