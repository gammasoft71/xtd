#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/numeric_up_down>
#include <xtd/cdebug>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace numeric_up_down_example {
  class form1 : public form {
  public:
    form1() {
      text("Numeric up down example");
      active_control(numeric_up_down1);
      
      numeric_up_down1.parent(*this);
      numeric_up_down1.location({80, 50});
      numeric_up_down1.wrapped(true);
      numeric_up_down1.value_changed += [&] {
        label1.text(ustring::format("value = {}", numeric_up_down1.value()));
      };
      numeric_up_down1.text_changed += [&] {
        cdebug << ustring::format("text = {}", numeric_up_down1.text()) << endl;
      };
      numeric_up_down1.value(50);
      
      numeric_up_down2.parent(*this);
      numeric_up_down2.location({80, 100});
      numeric_up_down2.decimal_place(2);
      numeric_up_down2.increment(.01);
      numeric_up_down2.minimum(10.0);
      numeric_up_down2.maximum(11.0);
      
      label1.parent(*this);
      label1.location({80, 150});
    }
    
  private:
    numeric_up_down numeric_up_down1;
    numeric_up_down numeric_up_down2;
    label label1;
  };
}

auto main() -> int {
  application::run(numeric_up_down_example::form1 {});
}
