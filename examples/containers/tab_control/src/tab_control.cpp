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
    
    label1.dock(dock_style::fill);
    label1.location({10, 10});
    label1.parent(tab_page1);
    label1.text("label1");
    label1.text_align(xtd::forms::content_alignment::top_left);

    tab_page2.parent(tab_control1);
    tab_page2.text("Tab page 2");
    
    label2.dock(dock_style::fill);
    label2.location({10, 10});
    label2.parent(tab_page2);
    label2.text_align(xtd::forms::content_alignment::middle_center);
    label2.text("label2");

    tab_page3.parent(tab_control1);
    tab_page3.text("Tab page 3");
    
    label3.dock(dock_style::fill);
    label3.location({10, 10});
    label3.parent(tab_page3);
    label3.text_align(xtd::forms::content_alignment::bottom_right);
    label3.text("label3");
  }
  
private:
  tab_control tab_control1;
  tab_page tab_page1;
  tab_page tab_page2;
  tab_page tab_page3;
  
  label label1;
  label label2;
  label label3;
};

int main() {
  application::run(form1());
}
