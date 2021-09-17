#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Lcd label example");
    
    numeric_up_down1.location({10, 10});
    numeric_up_down1.parent(*this);
    numeric_up_down1.set_range(0, 15000000);
    numeric_up_down1.increment(0.01);
    numeric_up_down1.decimal_place(2);
    numeric_up_down1.value_changed += [&] {
      lcd_label1.text(ustring::format("{,11:F2}", numeric_up_down1.value()));
    };
    numeric_up_down1.value(12345678.90);

    lcd_label1.location({10, 50});
    lcd_label1.parent(*this);
    lcd_label1.segment_style(segment_style::modern);
    lcd_label1.auto_size(true);
  }
  
private:
  numeric_up_down numeric_up_down1;
  lcd_label lcd_label1;
};

int main() {
  application::run(form1());
}
