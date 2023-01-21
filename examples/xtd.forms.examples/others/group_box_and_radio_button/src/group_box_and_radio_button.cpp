#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Group box and radio button example");
    client_size({300, 160});
    
    layout_panel.control_layout_style(group_box1, {size_type::auto_size, true});
    layout_panel.control_layout_style(group_box2, {size_type::auto_size, true});
    layout_panel.dock(dock_style::fill);
    layout_panel.padding(10);
    
    layout_panel_group_box1.dock(dock_style::fill);
    layout_panel_group_box1.padding(5);
    
    layout_panel_group_box2.dock(dock_style::fill);
    layout_panel_group_box2.padding(5);
    
    radio_button1.checked(true);
    radio_button5.checked(true);
  }
  
private:
  horizontal_layout_panel layout_panel = create<horizontal_layout_panel>(*this);
  group_box group_box1 = create<group_box>(layout_panel, "Group 1");
  vertical_layout_panel layout_panel_group_box1 = create<vertical_layout_panel>(group_box1);
  radio_button radio_button1 = create<radio_button>(layout_panel_group_box1, "radio 1");
  radio_button radio_button2 = create<radio_button>(layout_panel_group_box1, "radio 2");
  radio_button radio_button3 = create<radio_button>(layout_panel_group_box1, "radio 3");
  group_box group_box2 = create<group_box>(layout_panel, "Group 2");
  vertical_layout_panel layout_panel_group_box2 = create<vertical_layout_panel>(group_box2);
  radio_button radio_button4 = create<radio_button>(layout_panel_group_box2, "radio 4");
  radio_button radio_button5 = create<radio_button>(layout_panel_group_box2, "radio 5");
  radio_button radio_button6 = create<radio_button>(layout_panel_group_box2, "radio 6");
};

auto main()->int {
  application::run(form1 {});
}
