#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Colored Tab pages example");
    controls().push_back(tab_control_colored);
    client_size({390, 270});
    
    tab_control_colored.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
    tab_control_colored.controls().push_back_range({tab_page_light_pink, tab_page_light_green, tab_page_light_blue, tab_page_light_yellow});
    tab_control_colored.location({10, 10});
    tab_control_colored.size({370, 250});
    tab_control_colored.alignment(tab_alignment::bottom);

    tab_page_light_pink.text("Light pink");
    tab_page_light_pink.back_color(drawing::color::light_pink);

    tab_page_light_green.text("Light green");
    tab_page_light_green.back_color(drawing::color::light_green);

    tab_page_light_blue.text("Light blue");
    tab_page_light_blue.back_color(drawing::color::light_blue);

    tab_page_light_yellow.text("Light yellow");
    tab_page_light_yellow.back_color(drawing::color::light_yellow);
  }
  
private:
  tab_control tab_control_colored;
  tab_page tab_page_light_pink;
  tab_page tab_page_light_green;
  tab_page tab_page_light_blue;
  tab_page tab_page_light_yellow;
};

int main() {
  application::run(form1());
}
