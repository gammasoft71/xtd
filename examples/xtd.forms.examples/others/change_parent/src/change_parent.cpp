#include <xtd/forms/application>
#include <xtd/forms/check_box>
#include <xtd/forms/form>
#include <xtd/forms/horizontal_layout_panel>
#include <xtd/forms/label>
#include <xtd/forms/list_box>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
#include <xtd/forms/text_box>
#include <xtd/forms/toggle_button>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  static auto main() {
    application::run(form1 {});
  }
  
  form1() {
    client_size({600, 450});
    minimum_client_size(client_size());
    text("Change parent control example");
    
    top_panel.parent(*this);
    top_panel.dock(dock_style::fill);
    top_panel.controls().push_back_range({left_panel, right_panel});
    top_panel.control_layout_style(left_panel, {size_type::auto_size, true});
    top_panel.control_layout_style(right_panel, {size_type::auto_size, true});
    top_panel.padding(forms::padding(5, 5, 5, 0));
    
    left_panel.border_style(forms::border_style::fixed_3d);
    left_panel.back_color(drawing::color::navy);
    left_panel.fore_color(drawing::color::yellow);
    right_panel.border_style(forms::border_style::fixed_3d);
    right_panel.back_color(drawing::color::dark_cyan);
    right_panel.fore_color(drawing::color::black);
    
    label1.parent(left_panel);
    label1.text("Label text");
    label1.location({10, 12});
    label1.auto_size(true);
    
    text_box1.parent(left_panel);
    text_box1.text("Test box 1");
    text_box1.location({100, 10});
    text_box1.width(170);
    
    list_box1.parent(left_panel);
    list_box1.location({10, 50});
    list_box1.size({260, 100});
    list_box1.items().push_back_range({"Apple", "Orange", "Banana", "Strawberry"});
    list_box1.selected_index(0);
    
    toggle_button1.parent(left_panel);
    toggle_button1.text("Toggle 1");
    toggle_button1.location({10, 160});
    
    tab_control1.parent(left_panel);
    tab_control1.location({10, 210});
    tab_control1.size({260, 160});
    
    tab_page1.parent(tab_control1);
    tab_page1.text("Page 1");
    tab_page2.parent(tab_control1);
    tab_page2.text("Page 2");
    tab_page3.parent(tab_control1);
    tab_page3.text("Page 3");
    
    check_box1.parent(tab_page1);
    check_box1.text("Check box 1");
    check_box1.location({10, 10});
    
    bottom_panel.parent(*this);
    bottom_panel.height(50);
    bottom_panel.dock(dock_style::bottom);
    bottom_panel.controls().push_back_range({left_button, right_button});
    bottom_panel.control_layout_style(left_button, {size_type::auto_size, content_alignment::middle_center});
    bottom_panel.control_layout_style(right_button, {size_type::auto_size, content_alignment::middle_center});
    bottom_panel.padding(forms::padding(5));
    
    left_button.text("Move controls to left panel");
    left_button.enabled(false);
    left_button.click += [&] {
      left_button.enabled(false);
      right_button.enabled(true);
      
      label1.parent(left_panel);
      list_box1.parent(left_panel);
      toggle_button1.parent(left_panel);
      text_box1.parent(left_panel);
      tab_control1.parent(left_panel);
    };
    
    right_button.text("Move controls to right panel");
    right_button.click += [&] {
      left_button.enabled(true);
      right_button.enabled(false);
      
      label1.parent(right_panel);
      list_box1.parent(right_panel);
      toggle_button1.parent(right_panel);
      text_box1.parent(right_panel);
      tab_control1.parent(right_panel);
    };
  }
  
private:
  horizontal_layout_panel top_panel;
  horizontal_layout_panel bottom_panel;
  
  panel left_panel;
  panel right_panel;
  
  label label1;
  list_box list_box1;
  toggle_button toggle_button1;
  text_box text_box1;
  tab_control tab_control1;
  tab_page tab_page1;
  tab_page tab_page2;
  tab_page tab_page3;
  check_box check_box1;
  
  button left_button;
  button right_button;
};

startup_(form1::main);
