#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  static void main() {
    application::run(form1());
  }
  
  form1() {
    client_size({600, 400});
    minimum_size(size());
    text("Change parent control example");

    top_panel.parent(*this);
    top_panel.dock(dock_style::fill);
    top_panel.controls().push_back_range({left_panel, right_panel});
    top_panel.control_layout_style(left_panel, {size_type::auto_size, true});
    top_panel.control_layout_style(right_panel, {size_type::auto_size, true});
    top_panel.padding(forms::padding(5, 5, 5, 0));

    left_panel.border_style(forms::border_style::fixed_3d);
    left_panel.back_color(drawing::color::blue);
    left_panel.fore_color(drawing::color::yellow);
    right_panel.border_style(forms::border_style::fixed_3d);
    right_panel.back_color(drawing::color::dark_cyan);
    right_panel.fore_color(drawing::color::black);

    label1.parent(left_panel);
    label1.text("Label text");
    label1.location({10, 10});
    label1.auto_size(true);

    list_box1.parent(left_panel);
    list_box1.location({10, 40});
    list_box1.items().push_back_range({"Apple", "Orange", "Banana", "Strawberry"});
    
    toggle_button1.parent(left_panel);
    toggle_button1.text("Toggle 1");
    toggle_button1.location({10, 150});
    
    text_box1.parent(left_panel);
    text_box1.text("Test box 1");
    text_box1.location({10, 190});

    bottom_panel.parent(*this);
    bottom_panel.height(50);
    bottom_panel.dock(dock_style::bottom);
    bottom_panel.controls().push_back_range({left_button, right_button});
    bottom_panel.control_layout_style(left_button, {size_type::auto_size, content_alignment::middle_center});
    bottom_panel.control_layout_style(right_button, {size_type::auto_size, content_alignment::middle_center});
    bottom_panel.padding(forms::padding(5));
    
    left_button.text("Move to left panel");
    left_button.enabled(false);
    left_button.click += [&] {
      left_button.enabled(false);
      right_button.enabled(true);
      
      label1.parent(left_panel);
      list_box1.parent(left_panel);
      toggle_button1.parent(left_panel);
      text_box1.parent(left_panel);
    };
    
    right_button.text("Move to right panel");
    right_button.click += [&] {
      left_button.enabled(true);
      right_button.enabled(false);

      label1.parent(right_panel);
      list_box1.parent(right_panel);
      toggle_button1.parent(right_panel);
      text_box1.parent(right_panel);
    };
  }
  
private:
  horizontal_layout_panel top_panel;
  horizontal_layout_panel bottom_panel;

  label label1;
  list_box list_box1;
  toggle_button toggle_button1;
  text_box text_box1;

  panel left_panel;
  panel right_panel;

  button left_button;
  button right_button;
};

startup_(form1);
