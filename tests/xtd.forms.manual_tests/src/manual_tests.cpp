#include <xtd/xtd.forms>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Tab control example");
    controls().push_back(tab_control1);
    client_size({390, 270});
    
    tab_control1.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
    tab_control1.location({10, 10});
    tab_control1.size({370, 250});
    
    tab_page1.parent(tab_control1);
    tab_page1.text("Tab page 1");
    
    tab_page2.parent(tab_control1);
    tab_page2.text("Tab page 2");
    //tab_page2.border_style(xtd::forms::border_style::fixed_3d);
    
    tab_page3.parent(tab_control1);
    tab_page3.text("Tab page 3");
  }
  
private:
  tab_control tab_control1;
  tab_page tab_page1;
  tab_page tab_page2;
  tab_page tab_page3;
};

int main() {
  application::run(form1());
}
