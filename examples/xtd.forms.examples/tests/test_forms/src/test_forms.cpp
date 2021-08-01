#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::windows::forms;

class form_main : public form {
public:
  static void main() {
    application::run(form_main());
  }

  form_main() {
    auto_size(true);
    auto_size_mode(forms::auto_size_mode::grow_and_shrink);
    
    label1.parent(*this);
    label1.fore_color(color::lime);
    label1.height(50);
    label1.auto_size(true);
    label1.lcd_style(lcd_style::dot_matrix_display);
    label1.text("LCD DISPLAY");
  }

private:
  lcd_label label1;
};

startup_(form_main);
