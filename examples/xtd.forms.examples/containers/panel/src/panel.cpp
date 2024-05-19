#include <xtd/forms/application>
#include <xtd/forms/panel>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Panel example");
    location({200, 200});
    client_size({640, 480});
    
    panel1.parent(*this);
    panel1.border_style(forms::border_style::fixed_single);
    panel1.location({10, 10});
    panel1.size({305, 460});
    panel1.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom);
    
    panel2.parent(*this);
    panel2.border_style(forms::border_style::fixed_3d);
    panel2.location({325, 10});
    panel2.size({305, 460});
    panel2.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
  }
  
private:
  panel panel1;
  panel panel2;
};

auto main() -> int {
  application::run(form1 {});
}
