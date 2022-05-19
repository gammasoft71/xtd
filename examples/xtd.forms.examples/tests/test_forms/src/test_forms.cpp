#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::windows::forms;

class my_button : public button {
public:
  my_button() = default;
  
  void on_paint(paint_event_args& e) override {
    e.graphics().fill_rectangle(drawing2d::linear_gradient_brush(e.clip_rectangle(), color::white, color::blue, xtd::drawing::drawing2d::linear_gradient_mode::horizontal), e.clip_rectangle());
    control::on_paint(e);
  }
};

class form_main : public form {
public:
  static void main() {
    application::run(form_main());
  }
  
  form_main() {
    /*
    auto_size(true);
    auto_size_mode(forms::auto_size_mode::grow_and_shrink);
    top_most(true);
    form_border_style(forms::form_border_style::none);
    opacity(0.5);
    
    label1.parent(*this);
    label1.fore_color(color::lime);
    label1.height(50);
    label1.auto_size(true);
    label1.lcd_style(lcd_style::dot_matrix_display);
    label1.text("LCD DISPLAY");
    label1.mouse_down += [&](object & sender, const mouse_event_args & e) {
      mouse_location = e.location();
      label1.cursor(cursors::no_move_2d());
    };
    label1.mouse_up += [&](object & sender, const mouse_event_args & e) {
      mouse_location = point::empty;
      label1.cursor(cursors::default_cursor());
    };
    label1.mouse_move += [&](object & sender, const mouse_event_args & e) {
      if (mouse_location != point::empty) location(location() + e.location() - mouse_location);
    };
     */
    
    top_panel.parent(*this);
    top_panel.dock(dock_style::top);
    top_panel.height(64);
    
    button1.parent(top_panel);
    button1.dock(dock_style::left);

    choice1.parent(button1);
    choice1.items().push_back_range({"item1", "item2"});
    choice1.selected_index(0);
    button1.size(choice1.size());
  }
  
private:
  //lcd_label label1;
  //point mouse_location = point::empty;
  panel top_panel;
  my_button button1;
  choice choice1;
};

startup_(form_main);
